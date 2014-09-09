/*
 * architecture specific file for backtrace
 */
#include <asm/uaccess.h>
#include <linux/mm.h>

#ifdef CONFIG_ELF_MODULE
#include "kdbg_elf_sym_api.h"
#endif
#include "kdbg-trace.h"

/*#define DEBUG */
#ifdef DEBUG
#define dprintk(x...) PRINT_KD(x)
#else
#define dprintk(x...)
#endif

#define CONFIG_CALL_DEPTH   (20)

#ifdef CONFIG_ELF_MODULE
static pid_t user_backtrace_tsk_pid;
#endif

/* use this variable to suppress extra prints from backtrace functions
 * (that are not required outside Kdebugd trace)
 */
int suppress_extra_prints;

/* ARM Registers */
#define ARM_FP_REGNUM 11	/* contains current frame address */
#define ARM_SP_REGNUM 13	/* contains address of top of stack */
#define ARM_LR_REGNUM 14	/* address to return to from a function call */
#define ARM_PC_REGNUM 15	/* contains program counter */

/*
 * fwd_trace_success
 * This function checks the function start address for the prolog instructions.
 * If frame pointer is found, it retrieves the sp, lr, fp from the stack.
 *
 * in   - start_addr
 *  - tsk_mm
 * in/out - fp_address
 * in/out - lr_address
 * in/out - sp_address
 *
 * return - 0, if success, addresses are modified
 *      -1, if error, previous addresses are not modified
 */
int fwd_trace_success(struct mm_struct *tsk_mm, int start_addr,
		      int *sp, int *fp, int *lr)
{
	/*
	 * check the starting address,
	 * if it saves fp, we check next instruction
	 * 1. assume current fp to be valid ??
	 * 2. calculate the lr, fp, sp
	 */
	const int STACK_PUSH_MASK = 0xe92d0800;
	const int SET_FP_MASK = 0xe28db000;	/*e28db0{Imm}   add fp, sp, #Imm */

	int first_inst = 0, second_inst = 0;
	int fp_offset_curr_frame = 0;
	int sp_offset = 0, fp_offset = 0, lr_offset = 0;
	int fp_address = *fp;
	int lr_address = *lr;
	int sp_address = *sp;

	if (!fp_address || !lr_address || !sp_address) {
		dprintk("Current sp: 0x%x, fp: 0x%x, lr: 0x%x\n",
			sp_address, fp_address, lr_address);
		return -1;
	}

	if (!tsk_mm || !start_addr) {
		dprintk("tsk_mm: %p, start_addr: 0x%x\n", tsk_mm, start_addr);
		return -1;
	}

	first_inst = get_user_value(tsk_mm, start_addr);
	second_inst = get_user_value(tsk_mm, start_addr + 4);
	dprintk("first_inst: 0x%x, second_inst: 0x%x\n",
		first_inst, second_inst);

	if (first_inst == 0xe52db004) {
		sp_offset = fp_offset = 4;
		/* lr must be valid, just move sp */
	} else if ((first_inst & 0xffff0800) == STACK_PUSH_MASK) {

		int mask = first_inst & 0xffff;
		int regno = 0;
		/* Calculate offsets of saved registers.  */
		for (regno = ARM_PC_REGNUM; regno > 0; regno--) {
			if (mask & (1 << regno)) {
				sp_offset += 4;
				if (ARM_LR_REGNUM == regno)
					lr_offset = sp_offset;
				else if (ARM_FP_REGNUM == regno)
					fp_offset = sp_offset;
			}
		}
		dprintk("offsets: sp: 0x%x, fp: 0x%x, lr: 0x%x\n",
			sp_offset, fp_offset, lr_offset);
	} else {
		dprintk("!!! function: 0x%x, first instr: 0x%x\n",
			start_addr, first_inst);
		return -1;
	}

	if ((second_inst & 0xfffff000) == SET_FP_MASK) {
		fp_offset_curr_frame = sp_offset - (second_inst & 0xfff);
		if (fp_offset_curr_frame > 8) {
			dprintk("!!!!######## Check: fp_offset = %d !!!!!\n",
				fp_offset_curr_frame);
		}
	} else {
		dprintk("Check!!!! function: 0x%x, second inst: 0x%x\n",
			start_addr, second_inst);
		return -1;
	}

	sp_address = fp_address + fp_offset_curr_frame;	/* previous stack pointer */

	if (fp_offset) {
		fp_address = get_user_value(tsk_mm, sp_address - fp_offset);
	} else {
		PRINT_KD("!!! ERRR %s:%d, fp not saved...\n",
			 __FUNCTION__, __LINE__);
		return -1;
	}

	if (lr_offset)
		lr_address = get_user_value(tsk_mm, sp_address - lr_offset);
	else
		dprintk("lr not saved...\n");

	dprintk("New sp: 0x%x, fp: 0x%x, lr: 0x%x\n",
		sp_address, fp_address, lr_address);

	if ((KDEBUGD_BT_INVALID_VAL == fp_address)
	    || (KDEBUGD_BT_INVALID_VAL == lr_address)) {
		return -1;
	}

	*sp = sp_address;
	*fp = fp_address;
	*lr = lr_address;
	return 0;
}

/*
* user_bt
* This function get the register value of last function and start backtrace
* on the basis of prologue instruction.
*/

static unsigned int
user_bt(struct kdbgd_bt_regs *tsk_regs, struct mm_struct *tsk_mm)
{
	unsigned int addr = 0, sp = 0;
	unsigned int inst = 0, lr_address = 0, fp_address = 0, last_lr = 0;
	unsigned int sp_offset = 0, lr_offset = 0, fp_offset = 0;
	unsigned int call_depth = 0, start_addr = 0, end_addr =
	    0, no_start_jump = 0;
	int do_fwd_trace = 0;
	int fp_updated = 0, lr_updated = 0;

#ifdef CONFIG_ELF_MODULE
	struct aop_symbol_info symbol_info;
#ifdef CONFIG_DWARF_MODULE
	static struct aop_df_info df_info;
#endif

	char *sym_name = NULL, *lib_name = NULL;
	sym_name = (char *)KDBG_MEM_DBG_KMALLOC(KDBG_MEM_KDEBUGD_MODULE,
						KDBG_ELF_SYM_NAME_LENGTH_MAX,
						GFP_KERNEL);
	if (!sym_name)
		goto exit_free;

	lib_name = (char *)KDBG_MEM_DBG_KMALLOC(KDBG_MEM_KDEBUGD_MODULE,
						KDBG_ELF_SYM_MAX_SO_LIB_PATH_LEN,
						GFP_KERNEL);
	if (!lib_name)
		goto exit_free;
#endif /* CONFIG_ELF_MODULE */

	if (!tsk_regs || !tsk_mm) {
		PRINT_KD("Error: tsk_regs: %p, tsk_mm: %p\n", tsk_regs, tsk_mm);
		goto exit_free;
	}

	addr = tsk_regs->pc;
	sp = tsk_regs->sp;

	lr_address = tsk_regs->lr;
	fp_address = tsk_regs->fp;
	end_addr = tsk_regs->sp_end;

#ifdef CONFIG_ELF_MODULE
	symbol_info.pfunc_name = sym_name;
#ifdef CONFIG_DWARF_MODULE
	symbol_info.df_info_flag = 1;
	symbol_info.pdf_info = &df_info;
#endif /* CONFIG_DWARF_MODULE */
	if (kdbg_elf_get_symbol_and_lib_by_pid(user_backtrace_tsk_pid,
					       addr, lib_name, &symbol_info,
					       &start_addr)) {
#ifdef CONFIG_DWARF_MODULE
		if (symbol_info.pdf_info->df_line_no != 0)
			PRINT_KD("#%d  0x%08x in %s () at %s:%d\n", call_depth,
				 addr, symbol_info.pfunc_name,
				 symbol_info.pdf_info->df_file_name,
				 symbol_info.pdf_info->df_line_no);
		else
			PRINT_KD("#%d  0x%08x in %s () from %s\n", call_depth,
				 addr, sym_name, lib_name);
		symbol_info.pdf_info = NULL;

#else
		PRINT_KD("#%d  0x%08x in %s () from %s\n", call_depth, addr,
			 sym_name, lib_name);
#endif
		do_fwd_trace = 1;
	} else {
		start_addr = 0;
		PRINT_KD("#%d  0x%08x in ?? ()\n", call_depth, addr);
	}
#else
	PRINT_KD("#%d  0x%08x in ?? ()\n", call_depth, addr);
#endif
	call_depth++;

	dprintk("0x%x  SP %x   END %x lr %x FP %x\n",
		addr, sp, end_addr, lr_address, fp_address);

	/* this case comes for built in addresses.
	 * e.g. __aeabi_read_tp
	 */
	if (addr > 0xffff0000) {
		addr = lr_address;
#ifdef CONFIG_ELF_MODULE
		symbol_info.pfunc_name = sym_name;
#ifdef CONFIG_DWARF_MODULE
		symbol_info.df_info_flag = 1;
		symbol_info.pdf_info = &df_info;
#endif /* CONFIG_DWARF_MODULE */
		if (kdbg_elf_get_symbol_and_lib_by_pid(user_backtrace_tsk_pid,
						       addr, lib_name,
						       &symbol_info,
						       &start_addr)) {
#ifdef CONFIG_DWARF_MODULE
			if (symbol_info.pdf_info->df_line_no != 0)
				PRINT_KD("#%d  0x%08x in %s () at %s:%d\n",
					 call_depth, addr,
					 symbol_info.pfunc_name,
					 symbol_info.pdf_info->df_file_name,
					 symbol_info.pdf_info->df_line_no);
			else
				PRINT_KD("#%d  0x%08x in %s () from %s\n",
					 call_depth, addr, sym_name, lib_name);
			symbol_info.pdf_info = NULL;

#else
			PRINT_KD("#%d  0x%08x in %s () from %s\n", call_depth,
				 addr, sym_name, lib_name);
#endif /* CONFIG_DWARF_MODULE */
		} else {
			start_addr = 0;
			PRINT_KD("#%d 0x%08x in ?? ()\n", call_depth, addr);
		}
#endif /* CONFIG_ELF_MODULE */
		call_depth++;
		/*
		 * We are not able to trace further.
		 * gdb also doesn't show beyond this
		 */
		goto exit_stop_bt;
	}
	/*consider the current pc inst as not executed
	 * This is based on the observation we had when PC was pointing
	 * to the first inst inside a function, push {fp, lr} , but
	 * both fp and lr was not in the stack.
	 */
	while (1) {
		if (do_fwd_trace) {
			if (fwd_trace_success(tsk_mm, start_addr,
					      &sp, &fp_address, &lr_address)) {
				do_fwd_trace = 0;
				continue;
			}
		} else {
			inst = get_user_value(tsk_mm, addr);

			dprintk("%s:%d, instruction: %x\n", __FUNCTION__,
				__LINE__, inst);
			if (inst == KDEBUGD_BT_INVALID_VAL) {
				dprintk("user_bt : addr %x, inst %08x\n", addr,
					inst);
				goto exit_stop_bt;
			}
			if ((inst & 0xfffff000) == 0xe24dd000) {	/* sub sp,sp, size */
				unsigned imm = inst & 0xff;	/* immediate value */
				unsigned rot = (inst & 0xf00) >> 7;	/* rotate amount */
				imm = (imm >> rot) | (imm << (32 - rot));

				dprintk("inst: %x, before sp_offset: %d\n",
					inst, sp_offset);
				sp_offset += imm;
				dprintk("inst: %x, after sp_offset: %d\n", inst,
					sp_offset);

			} else if ((inst & 0xfffff000) == 0xe28dd000) {
				/* add     sp, sp, #immediate */
				unsigned imm = inst & 0xff;	/* immediate value */
				unsigned rot = (inst & 0xf00) >> 7;	/* rotate amount */
				imm = (imm >> rot) | (imm << (32 - rot));

				dprintk("inst: %x, before sp_offset: %d\n",
					inst, sp_offset);
				sp_offset -= imm;
				dprintk("inst: %x, after sp_offset: %d\n", inst,
					sp_offset);

			} else if ((inst & 0xffffafff) == 0xe52da004) {
				/* push lr or push fp */
				int is_it_lr = (inst == 0xe52de004) ? 1 : 0;

				if (is_it_lr) {
					lr_offset += sp_offset;
					lr_updated = 1;
				} else {
					fp_offset = sp_offset;
					fp_updated = 1;
				}
				sp_offset += 4;
				dprintk("instruction: %x, stack offset: %d\n",
					inst, sp_offset);
				if (0 == start_addr)
					no_start_jump = 1;
			} else if ((inst & 0xffff0000) == 0xe92d0000) {
				/* stmfd sp!, {..., fp, ip, lr, pc}
				   or
				   stmfd sp!, {a1, a2, a3, a4}
				   or
				   push {...fp,ip,lr,pc}
				 */
				int mask = inst & 0xffff;
				int regno = 0;
				/* Calculate offsets of saved registers.  */
				for (regno = 0; regno <= ARM_PC_REGNUM; regno++) {
					if (mask & (1 << regno)) {
						if (ARM_LR_REGNUM == regno) {
							/* lr is pushed in stack so read lr */
							lr_offset += sp_offset;
							lr_updated = 1;
						} else if (ARM_FP_REGNUM ==
							   regno) {
							/* fp is pushed in stack so read fp */
							fp_offset = sp_offset;
							fp_updated = 1;
						}
						sp_offset += 4;
					}
				}
				dprintk
				    ("########## Check next print ########\n");
				dprintk
				    ("instruction: %x, offsets: sp: %d, fp: %d, lr: %d\n",
				     inst, sp_offset, fp_offset, lr_offset);
				if (0 == start_addr)
					no_start_jump = 1;
			} else if ((inst & 0xffff0000) == 0xe8bd0000) {
				/* Instruction comes if the function have
				 * multiple brench instruction
				 */
				/* e8bdxxxx pop {r0, r1} */
				int mask = inst & 0xffff;
				int regno = 0;
				for (regno = ARM_PC_REGNUM; regno >= 0; regno--) {
					if (mask & (1 << regno))
						sp_offset -= 4;

					/* if pop pc comes, we assume that lr was saved */
					if (ARM_PC_REGNUM == regno)
						lr_offset -= sp_offset;
				}
				dprintk
				    ("instruction: 0x%x, Stack offset: %d, lr_offset: %d\n",
				     inst, sp_offset, lr_offset);
			}
			/* Skip rest of the instructions */
			addr--;
			if (!addr)
				goto exit_stop_bt;
		}

		/*
		 * Either function boundary is crossed,
		 * or
		 * there was no start address, so we jump
		 * or
		 * forward tracing was successful
		 */
		if (do_fwd_trace || no_start_jump || (addr < start_addr)) {
			dprintk
			    ("end:: stack_size %d, addr %08x, inst %08x FP %08x\n",
			     sp_offset, addr, inst, fp_address);
			dprintk("sp_offset: %d, lr_offset: %d, fp_offset: %d\n",
				sp_offset, lr_offset, fp_offset);

			dprintk("Previous SP: %x, fp: %x, lr: %x\n", sp,
				fp_address, lr_address);

			if (!do_fwd_trace) {
				if (fp_updated)
					fp_address =
					    get_user_value(tsk_mm,
							   sp + fp_offset);
				else
					dprintk("fp not saved\n");
				if (lr_updated)
					lr_address =
					    get_user_value(tsk_mm,
							   sp + lr_offset);
				else
					dprintk("lr not saved, lr is valid\n");

				if ((KDEBUGD_BT_INVALID_VAL == fp_address)
				    || (KDEBUGD_BT_INVALID_VAL == lr_address))
					goto exit_stop_bt;

				sp = sp + sp_offset;
			}
			sp_offset = 0;
			fp_offset = 0;
			lr_offset = 0;
			lr_updated = 0;
			fp_updated = 0;
			do_fwd_trace = 0;
			dprintk("New SP: %x, fp: %x, lr: %x\n", sp, fp_address,
				lr_address);

			/* pc points to the next instruction */
			addr = lr_address - 4;

			/* if found last function or stack has corrupt
			 * and getting same lr again. come out from bt
			 */
			if (lr_address == last_lr)
				goto exit_stop_bt;

#ifdef CONFIG_ELF_MODULE
			symbol_info.pfunc_name = sym_name;
#ifdef CONFIG_DWARF_MODULE
			symbol_info.df_info_flag = 1;
			/* No need to check for poniter existence already take care inside the function */
			symbol_info.pdf_info = &df_info;
#endif /* CONFIG_DWARF_MODULE */
			if (kdbg_elf_get_symbol_and_lib_by_pid
			    (user_backtrace_tsk_pid, addr, lib_name,
			     &symbol_info, &start_addr)) {
#ifdef CONFIG_DWARF_MODULE
				if (symbol_info.pdf_info->df_line_no != 0)
					PRINT_KD
					    ("#%d  0x%08x in %s () at %s:%d\n",
					     call_depth, addr,
					     symbol_info.pfunc_name,
					     symbol_info.pdf_info->df_file_name,
					     symbol_info.pdf_info->df_line_no);
				else
					PRINT_KD
					    ("#%d  0x%08x in %s () from %s\n",
					     call_depth, lr_address, sym_name,
					     lib_name);
				symbol_info.pdf_info = NULL;

#else
				PRINT_KD("#%d  0x%08x in %s () from %s\n",
					 call_depth, lr_address, sym_name,
					 lib_name);

#endif /* CONFIG_DWARF_MODULE */
			} else {
				start_addr = 0;
				PRINT_KD("#%d 0x%08x in ?? ()\n", call_depth,
					 lr_address);
			}
#else
			dprintk("#%d 0x%x\n", call_depth, addr);
			PRINT_KD("#%d  0x%08x in ?? ()\n", call_depth,
				 lr_address);
#endif
			if ((addr > end_addr)
			    || ((addr & 0xFFF00000) == (sp & 0xFFF00000)))
				goto exit_stop_bt;

			dprintk("-->: addr %08x, lr_address %08x\n", addr,
				lr_address);

			last_lr = lr_address;
			no_start_jump = 0;
			call_depth++;
			/* limit call depth */
			if (call_depth > CONFIG_CALL_DEPTH) {
				PRINT_KD("call_depth %d\n", call_depth);
				goto exit_stop_bt;
			}

			if (start_addr)
				do_fwd_trace = 1;
			dprintk("New address: 0x%x, start_address: 0x%x\n",
				addr, start_addr);
		}
	}

exit_stop_bt:
	if (!suppress_extra_prints)
		PRINT_KD("Backtrace Stop\n");

exit_free:
#ifdef CONFIG_ELF_MODULE
	if (sym_name)
		KDBG_MEM_DBG_KFREE(sym_name);
	if (lib_name)
		KDBG_MEM_DBG_KFREE(lib_name);
#endif /* CONFIG_ELF_MODULE */
	return call_depth;

}

/*
 * Function Name: show_user_backtrace_task
 * This function read the task pt_regs (fp, pc, lr,sp),
 * take_struct(SSP) (SSP ==> stack end pointer)  using call task_pt_regs,
 * Validate the user memory and call the aop library function to get user
 * stack memory and last call the function user_bt to start backtrace.
 */
void show_user_backtrace_task(struct task_struct *tsk, int load_elf)
{
	struct pt_regs *regs;
	struct vm_area_struct *vma;
	struct mm_struct *tsk_mm;
	unsigned long pc;
	unsigned long tsk_user_ssp;
	pid_t tsk_pid;
	struct kdbgd_bt_regs tsk_regs;

	BUG_ON(!tsk);		/* validity should be insured in caller */

	PRINT_KD("\n\nPid: %d, comm: %20s", tsk->pid, tsk->comm);
#ifdef CONFIG_SMP
	PRINT_KD("[%d]", task_cpu(tsk));
#endif
	PRINT_KD("\n");

	task_lock(tsk);
	regs = task_pt_regs(tsk);
	pc = instruction_pointer(regs);
	tsk_mm = tsk->mm;
	tsk_user_ssp = tsk_mm->start_stack;
	tsk_pid = tsk->pid;

	task_unlock(tsk);

	if (tsk_user_ssp < regs->ARM_sp) {
		PRINT_KD("Invalid Stack Address\n");
		PRINT_KD("REGS: FP: 0x%08lx, PC: 0x%08lx, LR: 0x%08lx, SP: 0x%08lx, \
				Stack End: 0x%08lx\n",
				regs->ARM_fp, pc, regs->ARM_lr, regs->ARM_sp, tsk_user_ssp);
		return;
	}


	vma = find_vma(tsk_mm, tsk_user_ssp);
	if (vma) {
		if (!suppress_extra_prints) {
			PRINT_KD
				("task stack info : pid(%d) stack area (0x%08lx ~ 0x%08lx)\n",
				 (int)tsk_pid, vma->vm_start, vma->vm_end);
		}
#ifdef CONFIG_ELF_MODULE
		user_backtrace_tsk_pid = tsk_pid;
		if (load_elf) {
			kdbg_elf_load_elf_db_by_pids(&user_backtrace_tsk_pid,
					1);
		}
#endif /* CONFIG_ELF_MODULE */

#ifdef DEBUG
		if (regs->ARM_sp < vma->vm_start) {
			PRINT_KD("pid(%d) : seems stack overflow.\n"
					"  sp(%lx), stack vma (0x%08lx ~ 0x%08lx)\n",
					(int)tsk_pid, regs->ARM_sp, vma->vm_start,
					vma->vm_end);
		}

		PRINT_KD("\n");
		PRINT_KD
			("================================================================================\n");
		PRINT_KD("Stack area (0x%08lx to 0x%08lx)\n", regs->ARM_sp,
				vma->vm_end);
		PRINT_KD
			("================================================================================\n");
		kdbg_dump_mem("dump user stack", regs->ARM_sp, tsk_user_ssp);

#endif

		/* set up the registers for user_bt */
		tsk_regs.fp = regs->ARM_fp;
		tsk_regs.pc = pc;
		tsk_regs.lr = regs->ARM_lr;
		tsk_regs.sp = regs->ARM_sp;
		tsk_regs.sp_end = tsk_user_ssp;

		if (!suppress_extra_prints) {
			PRINT_KD
				("===============================================================================\n");
			PRINT_KD("kdebugd back trace\n");
			PRINT_KD
				("===============================================================================\n");
			PRINT_KD("REGS: FP: 0x%08x, PC: 0x%08x, RA: 0x%08x,"
					"SP: 0x%08x, Stack End: 0x%08x\n", tsk_regs.fp,
					tsk_regs.pc, tsk_regs.lr, tsk_regs.sp,
					tsk_regs.sp_end);
		}

		user_bt(&tsk_regs, tsk_mm);
		PRINT_KD
			("===============================================================================\n");
	}
}
