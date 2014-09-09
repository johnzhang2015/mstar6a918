/*
 * Carsten Langgaard, carstenl@mips.com
 * Copyright (C) 2000, 2001, 2004 MIPS Technologies, Inc.
 * Copyright (C) 2001 Ralf Baechle
 *
 *  This program is free software; you can distribute it and/or modify it
 *  under the terms of the GNU General Public License (Version 2) as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
 *
 * Routines for generic manipulation of the interrupts found on the MIPS
 * Malta board.
 * The interrupt controller is located in the South Bridge a PIIX4 device
 * with two internal 82C95 interrupt controllers.
 */
//#include <linux/config.h>
#include <linux/init.h>
#include <linux/irq.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/kernel_stat.h>
#include <linux/random.h>

//#include <asm/i8259.h>
#include <asm/io.h>

#include <asm/mips-boards/malta.h>
#include <asm/mips-boards/maltaint.h>
#include <asm/mips-boards/piix4.h>
#include <asm/gt64120.h>
#include <asm/mips-boards/generic.h>
#include <asm/mips-boards/msc01_pci.h>
#include "chip_int.h"

#define REG(addr) (*(volatile unsigned int *)(addr))

//static raw_spinlock_t mips_irq_lock = RAW_SPIN_LOCK_UNLOCKED;

int gcmp_present = -1;
int gic_present;

static int gic_resched_int_base;
static int gic_call_int_base;
#define GIC_RESCHED_INT(cpu) (gic_resched_int_base+(cpu))
#define GIC_CALL_INT(cpu) (gic_call_int_base+(cpu))

unsigned int plat_ipi_call_int_xlate(unsigned int cpu)
{
	return GIC_CALL_INT(cpu);
}

unsigned int plat_ipi_resched_int_xlate(unsigned int cpu)
{
	return GIC_RESCHED_INT(cpu);
}
#ifdef CONFIG_ARCH_SUPPORTS_OPROFILE
extern int (*perf_irq)(void);  // defined in kernel/time.c, used in oprofile

static int handle_perf_irq(int irqn, void *junk)
{
       return perf_irq();
}

static struct irqaction irq_perf_counters = {
       handle_perf_irq, 0, { { 0, } }, "perf_ctr", NULL, NULL
};
#endif

#define DEBUG_INTR 0

#if DEBUG_INTR/*==================================================================================*/
#define DEBUG_INTR_MONITER_REG_NUM  	0xbf200a00
#define DEBUG_INTR_MONITER_REG_OUT 		0xbf200a04
#define DEBUG_INTR_MONITER(intrNum) 	__intr_moniter(intrNum)

static void __intr_moniter(unsigned long intrNum)
{
	if(*((volatile unsigned short*)DEBUG_INTR_MONITER_REG_NUM)==intrNum)
	{
		printk("kernel got intr %d\n",intrNum);
		(*((volatile unsigned short*)DEBUG_INTR_MONITER_REG_OUT))++;
	}
}
#else//DEBUG_INTR===================================================================================
#define DEBUG_INTR_MONITER(intrNum)
#endif//DEBUG_INTR==================================================================================


static unsigned int MAsm_CPU_GetTrailOne(unsigned int u32Flags)
{
    u32Flags = (~u32Flags) & (u32Flags-1);
    asm volatile
    (
        "clz %0, %0\n"
        : "=r" (u32Flags)
        : "0" (u32Flags)
    );
    return 32 - u32Flags;
}

static int Kaiserin_EnableInterrupt (InterruptNum eIntNum)
{
    int bRet = 0;
    if (eIntNum == E_IRQ_FIQ_ALL)
    {
        REG(REG_IRQ_MASK_L) &= ~IRQL_MASK;
        REG(REG_IRQ_MASK_H) &= ~IRQH_MASK;
        REG(REG_FIQ_MASK_L) &= ~FIQL_MASK;
        REG(REG_FIQ_MASK_H) &= ~FIQH_MASK;

        REG(REG_IRQ_EXP_MASK_L) &= ~IRQEXPL_MASK;
        REG(REG_IRQ_EXP_MASK_H) &= ~IRQEXPH_MASK;
        REG(REG_FIQ_EXP_MASK_L) &= ~FIQEXPL_MASK;
        REG(REG_FIQ_EXP_MASK_H) &= ~FIQEXPH_MASK;
    }
    else if ( (eIntNum >= E_IRQL_START) && (eIntNum <= E_IRQL_END) )
    {
        REG(REG_IRQ_MASK_L) &= ~(0x1 << (eIntNum-E_IRQL_START) );
    }
    else if ( (eIntNum >= E_IRQH_START) && (eIntNum <= E_IRQH_END) )
    {
        REG(REG_IRQ_MASK_H) &= ~(0x1 << (eIntNum-E_IRQH_START) );
    }
    else if ( (eIntNum >= E_FIQL_START) && (eIntNum <= E_FIQL_END) )
    {
        REG(REG_FIQ_MASK_L) &= ~(0x1 << (eIntNum-E_FIQL_START) );
    }
    else if ( (eIntNum >= E_FIQH_START) && (eIntNum <= E_FIQH_END) )
    {
        REG(REG_FIQ_MASK_H) &= ~(0x1 << (eIntNum-E_FIQH_START) );
    }
    else if ( (eIntNum >= E_IRQEXPL_START) && (eIntNum <= E_IRQEXPL_END) )
    {
        REG(REG_IRQ_EXP_MASK_L) &= ~(0x1 << (eIntNum-E_IRQEXPL_START) );
    }
    else if ( (eIntNum >= E_IRQEXPH_START) && (eIntNum <= E_IRQEXPH_END) )
    {
        REG(REG_IRQ_EXP_MASK_H) &= ~(0x1 << (eIntNum-E_IRQEXPH_START) );
    }
    else if ( (eIntNum >= E_FIQEXPL_START) && (eIntNum <= E_FIQEXPL_END) )
    {
        REG(REG_FIQ_EXP_MASK_L) &= ~(0x1 << (eIntNum-E_FIQEXPL_START) );
    }
    else if ( (eIntNum >= E_FIQEXPH_START) && (eIntNum <= E_FIQEXPH_END) )
    {
        REG(REG_FIQ_EXP_MASK_H) &= ~(0x1 << (eIntNum-E_FIQEXPH_START) );
    }
    return bRet;
}


static int Kaiserin_DisableInterrupt (InterruptNum eIntNum)
{
    if (eIntNum == E_IRQ_FIQ_ALL)
    {
        REG(REG_IRQ_MASK_L) |= IRQL_MASK;
        REG(REG_IRQ_MASK_H) |= IRQH_MASK;
        REG(REG_FIQ_MASK_L) |= FIQL_MASK;
        REG(REG_FIQ_MASK_H) |= FIQH_MASK;

        REG(REG_IRQ_EXP_MASK_L) |= IRQEXPL_MASK;
        REG(REG_IRQ_EXP_MASK_H) |= IRQEXPH_MASK;
        REG(REG_FIQ_EXP_MASK_L) |= FIQEXPL_MASK;
        REG(REG_FIQ_EXP_MASK_H) |= FIQEXPH_MASK;
    }
    else if ( (eIntNum >= E_IRQL_START) && (eIntNum <= E_IRQL_END) )
    {
        REG(REG_IRQ_MASK_L) |= (0x1 << (eIntNum-E_IRQL_START) );
    }
    else if ( (eIntNum >= E_IRQH_START) && (eIntNum <= E_IRQH_END) )
    {
        REG(REG_IRQ_MASK_H) |= (0x1 << (eIntNum-E_IRQH_START) );
    }
    else if ( (eIntNum >= E_FIQL_START) && (eIntNum <= E_FIQL_END) )
    {
        REG(REG_FIQ_MASK_L) |= (0x1 << (eIntNum-E_FIQL_START) );
        REG(REG_FIQ_CLEAR_L) = (0x1 << (eIntNum-E_FIQL_START) );
    }
    else if ( (eIntNum >= E_FIQH_START) && (eIntNum <= E_FIQH_END) )
    {
        REG(REG_FIQ_MASK_H) |= (0x1 << (eIntNum-E_FIQH_START) );
        REG(REG_FIQ_CLEAR_H) = (0x1 << (eIntNum-E_FIQH_START) );
    }
    else if ( (eIntNum >= E_IRQEXPL_START) && (eIntNum <= E_IRQEXPL_END) )
    {
        REG(REG_IRQ_EXP_MASK_L) |= (0x1 << (eIntNum-E_IRQEXPL_START) );
    }
    else if ( (eIntNum >= E_IRQEXPH_START) && (eIntNum <= E_IRQEXPH_END) )
    {
        REG(REG_IRQ_EXP_MASK_H) |= (0x1 << (eIntNum-E_IRQEXPH_START) );
    }
    else if ( (eIntNum >= E_FIQEXPL_START) && (eIntNum <= E_FIQEXPL_END) )
    {
        REG(REG_FIQ_EXP_MASK_L) |= (0x1 << (eIntNum-E_FIQEXPL_START) );
        REG(REG_FIQ_EXP_CLEAR_L) = (0x1 << (eIntNum-E_FIQEXPL_START) );
    }
    else if ( (eIntNum >= E_FIQEXPH_START) && (eIntNum <= E_FIQEXPH_END) )
    {
        REG(REG_FIQ_EXP_MASK_H) |= (0x1 << (eIntNum-E_FIQEXPH_START) );
        REG(REG_FIQ_EXP_CLEAR_H) = (0x1 << (eIntNum-E_FIQEXPH_START) );
    }
    return 0;
}

static unsigned int startup_Kaiserin_irq(unsigned int irq)
{
	//enable_lasat_irq(irq);
    Kaiserin_EnableInterrupt((InterruptNum)irq);
	return 0; /* never anything pending */
}

static void shutdown_Kaiserin_irq(unsigned int irq)
{
	//enable_lasat_irq(irq);
    Kaiserin_DisableInterrupt((InterruptNum)irq);
	//return 0; /* never anything pending */
}

#define enable_Kaiserin_irq startup_Kaiserin_irq
#define disable_Kaiserin_irq shutdown_Kaiserin_irq
#define mask_and_ack_Kaiserin_irq shutdown_Kaiserin_irq
#define end_Kaiserin_irq startup_Kaiserin_irq

static unsigned int startup_Kaiserin_fiq(unsigned int irq)
{
	//enable_lasat_irq(irq);
    Kaiserin_EnableInterrupt((InterruptNum)irq);
	return 0; /* never anything pending */
}

static void shutdown_Kaiserin_fiq(unsigned int irq)
{
	//enable_lasat_irq(irq);
    Kaiserin_DisableInterrupt((InterruptNum)irq);
	//return 0; /* never anything pending */
}

#define enable_Kaiserin_fiq startup_Kaiserin_fiq
#define disable_Kaiserin_fiq shutdown_Kaiserin_fiq
#define mask_and_ack_Kaiserin_fiq shutdown_Kaiserin_fiq
#define end_Kaiserin_fiq startup_Kaiserin_fiq

// Dean modify to match kernel 2.6.26
static struct irq_chip Kaiserin_irq_type = {
	.name = "Kaiserin IRQ",
	.startup = startup_Kaiserin_irq,
	.shutdown = shutdown_Kaiserin_irq,
	.enable = (void (*)(unsigned int irq))enable_Kaiserin_irq,
	.disable = disable_Kaiserin_irq,
	.ack = mask_and_ack_Kaiserin_irq,
	.mask = disable_Kaiserin_irq,
	.mask_ack = disable_Kaiserin_irq,
	.unmask = (void (*)(unsigned int irq))enable_Kaiserin_irq,
	.eoi = (void (*)(unsigned int irq))enable_Kaiserin_irq,
	.end = (void (*)(unsigned int irq))end_Kaiserin_irq
};

static struct irq_chip Kaiserin_fiq_type = {
	.name = "Kaiserin FIQ",
	.startup = startup_Kaiserin_fiq,
	.shutdown = shutdown_Kaiserin_fiq,
	.enable = (void (*)(unsigned int irq))enable_Kaiserin_fiq,
	.disable = disable_Kaiserin_fiq,
	.ack = mask_and_ack_Kaiserin_fiq,
	.mask = disable_Kaiserin_fiq,
	.mask_ack = disable_Kaiserin_fiq,
	.unmask = (void (*)(unsigned int irq))enable_Kaiserin_fiq,
	.eoi = (void (*)(unsigned int irq))enable_Kaiserin_fiq,
	.end = (void (*)(unsigned int irq))end_Kaiserin_fiq
};

void Kaiserin_hw0_irqdispatch(void)
{
    unsigned int        u16Reg = 0;
    unsigned int        u32Bit;
    InterruptNum        eIntNum;

    u16Reg = REG(REG_IRQ_PENDING_L);

    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_IRQL_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }

    u16Reg = REG(REG_IRQ_PENDING_H);
    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_IRQH_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }
    u16Reg = REG(REG_IRQ_EXP_PENDING_L);
    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_IRQEXPL_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }
    u16Reg = REG(REG_IRQ_EXP_PENDING_H);
    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_IRQEXPH_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }
}

void Kaiserin_hw0_fiqdispatch(void)
{
    unsigned int        u16Reg = 0;
    unsigned int        u32Bit;
    InterruptNum        eIntNum;

    u16Reg = REG(REG_FIQ_PENDING_L);
    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_FIQL_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }

    u16Reg = REG(REG_FIQ_PENDING_H);
    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_FIQH_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }
    u16Reg = REG(REG_FIQ_EXP_PENDING_L);

    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_FIQEXPL_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }
    u16Reg = REG(REG_FIQ_EXP_PENDING_H);
    while (32> (u32Bit = MAsm_CPU_GetTrailOne(u16Reg)))
    {
        eIntNum = (InterruptNum)(u32Bit+ E_FIQEXPH_START);
        DEBUG_INTR_MONITER(eIntNum);
        do_IRQ((unsigned int)eIntNum);
        u16Reg &= ~(0x1<< u32Bit);
    }
}

static inline int clz(unsigned long x)
{
	__asm__(
	"	.set	push					\n"
	"	.set	mips32					\n"
	"	clz	%0, %1					\n"
	"	.set	pop					\n"
	: "=r" (x)
	: "r" (x));

	return x;
}

/*
 * Version of ffs that only looks at bits 12..15.
 */
static inline unsigned int irq_ffs(unsigned int pending)
{
#if defined(CONFIG_CPU_MIPS32) || defined(CONFIG_CPU_MIPS64)
	return -clz(pending) + 31 - CAUSEB_IP;
#else
	unsigned int a0 = 7;
	unsigned int t0;

	t0 = s0 & 0xf000;
	t0 = t0 < 1;
	t0 = t0 << 2;
	a0 = a0 - t0;
	s0 = s0 << t0;

	t0 = s0 & 0xc000;
	t0 = t0 < 1;
	t0 = t0 << 1;
	a0 = a0 - t0;
	s0 = s0 << t0;

	t0 = s0 & 0x8000;
	t0 = t0 < 1;
	//t0 = t0 << 2;
	a0 = a0 - t0;
	//s0 = s0 << t0;

	return a0;
#endif
}

/*
 * IRQs on the SEAD board look basically are combined together on hardware
 * interrupt 0 (MIPS IRQ 2)) like:
 *
 *	MIPS IRQ	Source
 *      --------        ------
 *             0	Software (ignored)
 *             1        Software (ignored)
 *             2        UART0 (hw0)
 *             3        UART1 (hw1)
 *             4        Hardware (ignored)
 *             5        Hardware (ignored)
 *             6        Hardware (ignored)
 *             7        R4k timer (what we use)
 *
 * We handle the IRQ according to _our_ priority which is:
 *
 * Highest ----     R4k Timer
 * Lowest  ----     Combined hardware interrupt
 *
 * then we just return, if multiple IRQs are pending then we will just take
 * another exception, big deal.
 */
asmlinkage void plat_irq_dispatch(void)
{
    unsigned int pending = read_c0_cause() & read_c0_status() & ST0_IM;
    int irq;//, cpu;

    //cpu = smp_processor_id();

    irq = irq_ffs(pending);
    //printk("\nDean --> [%s] %d irq = %d\n", __FILE__, __LINE__, irq);
    //printk("\nDean --> [%s] %d cpu = %d\n", __FILE__, __LINE__, cpu);
    //if(irq != 7)
    //printk("\nirq = %d\n", irq);
    if (irq == 2)
        Kaiserin_hw0_irqdispatch();
    else if (irq == 3)
        Kaiserin_hw0_fiqdispatch();
    else if (irq >= 0)
        do_IRQ(MIPS_CPU_IRQ_BASE + irq);
    else
        spurious_interrupt();

    //printk("\nDean --> [%s] %d irq = %d\n", __FILE__, __LINE__, irq);
}

#if defined(CONFIG_MIPS_MT_SMP) /*AWU -- added*/
#define GIC_MIPS_CPU_IPI_RESCHED_IRQ    3
#define GIC_MIPS_CPU_IPI_CALL_IRQ    4

#define MIPS_CPU_IPI_RESCHED_IRQ 0    /* SW int 0 for resched */
#define C_RESCHED C_SW0
#define MIPS_CPU_IPI_CALL_IRQ 1        /* SW int 1 for resched */
#define C_CALL C_SW1

static int cpu_ipi_resched_irq, cpu_ipi_call_irq;

static void ipi_resched_dispatch(void)
{
    do_IRQ(MIPS_CPU_IRQ_BASE + MIPS_CPU_IPI_RESCHED_IRQ);
}

static void ipi_call_dispatch(void)
{
    do_IRQ(MIPS_CPU_IRQ_BASE + MIPS_CPU_IPI_CALL_IRQ);
}

static irqreturn_t ipi_resched_interrupt(int irq, void *dev_id)
{
    return IRQ_HANDLED;
}

static irqreturn_t ipi_call_interrupt(int irq, void *dev_id)
{
    smp_call_function_interrupt();

    return IRQ_HANDLED;
}

static struct irqaction irq_resched = {
    .handler    = ipi_resched_interrupt,
    .flags        = IRQF_DISABLED|IRQF_PERCPU,
    .name        = "IPI_resched"
};

static struct irqaction irq_call = {
    .handler    = ipi_call_interrupt,
    .flags        = IRQF_DISABLED|IRQF_PERCPU,
    .name        = "IPI_call"
};
#endif

extern void __init mips_cpu_irq_init(void);
void __init arch_init_irq(void)
{
    int i;
    //set_except_vector(0, mipsIRQ);
    //mips_cpu_irq_init(0);
#if 0
	for (i = 0; i <= MSTAR_CHIP_INT_END; i++) {
		irq_desc[i].status	= IRQ_DISABLED;
		irq_desc[i].action	= 0;
		irq_desc[i].depth	= 1;
		if ( i <64)
                irq_desc[i].chip    = &Kaiserin_irq_type;
		   //irq_desc[i].handler	= &Kaiserin_irq_type;
		else
                irq_desc[i].chip    = &Kaiserin_fiq_type;
		   //irq_desc[i].handler  = &Kaiserin_fiq_type;
	}

#endif
#if defined(CONFIG_MIPS_MT_SMP) /*AWU -- added*/
    // Samuel,20090330: cpu_has_vint is needed in SMP.
    //     For this we have to setup vi hander. And we have to know that the
    //     ebase is not fixed, it is allocated by linux system in trap.c

    mips_cpu_irq_init();

    if (cpu_has_vint) {

        set_vi_handler(2, Kaiserin_hw0_irqdispatch);
        set_vi_handler(3, Kaiserin_hw0_fiqdispatch);

        set_vi_handler (MIPS_CPU_IPI_RESCHED_IRQ, ipi_resched_dispatch);
        set_vi_handler (MIPS_CPU_IPI_CALL_IRQ, ipi_call_dispatch);

    }

    cpu_ipi_resched_irq = MIPS_CPU_IRQ_BASE + MIPS_CPU_IPI_RESCHED_IRQ;
    cpu_ipi_call_irq = MIPS_CPU_IRQ_BASE + MIPS_CPU_IPI_CALL_IRQ;

    setup_irq(cpu_ipi_resched_irq, &irq_resched);
    setup_irq(cpu_ipi_call_irq, &irq_call);

    set_irq_handler(cpu_ipi_resched_irq, handle_percpu_irq);
    set_irq_handler(cpu_ipi_call_irq, handle_percpu_irq);

    for (i = MSTAR_INT_BASE; i <= (KAISERIN_INT_END+MSTAR_INT_BASE); i++) {
        if ( i < 64 + MSTAR_INT_BASE)
            set_irq_chip_and_handler(i, &Kaiserin_irq_type, handle_level_irq);
        else
            set_irq_chip_and_handler(i, &Kaiserin_fiq_type, handle_level_irq);
    }
    //disable all
    Kaiserin_DisableInterrupt(E_IRQ_FIQ_ALL);

#else
    for (i = MSTAR_INT_BASE; i <= (KAISERIN_INT_END+MSTAR_INT_BASE); i++) {
        if ( i < 64 + MSTAR_INT_BASE)
            set_irq_chip_and_handler(i, &Kaiserin_irq_type, handle_level_irq);
        else
            set_irq_chip_and_handler(i, &Kaiserin_fiq_type, handle_level_irq);
    }
    set_irq_chip_and_handler(0, &Kaiserin_fiq_type, handle_level_irq);
    set_irq_chip_and_handler(1, &Kaiserin_fiq_type, handle_level_irq);
    //disable all
    Kaiserin_DisableInterrupt(E_IRQ_FIQ_ALL);

    mips_cpu_irq_init();
#endif
#ifdef CONFIG_ARCH_SUPPORTS_OPROFILE
    setup_irq(MIPS_CPU_IRQ_BASE + 4, &irq_perf_counters);  // this is HW2 int, for perf counter
#endif
}
