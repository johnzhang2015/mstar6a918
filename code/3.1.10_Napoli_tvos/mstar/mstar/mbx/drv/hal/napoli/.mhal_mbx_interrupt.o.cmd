cmd_drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o := /tools/arm/arm-2012.09/bin/arm-none-linux-gnueabi-gcc -Wp,-MD,drivers/mstar/mbx/drv/hal/napoli/.mhal_mbx_interrupt.o.d  -nostdinc -isystem /tools/arm/arm-2012.09/bin/../lib/gcc/arm-none-linux-gnueabi/4.7.2/include -I/home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -I/home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/arm-boards/generic/include/ -Iarch/arm/arm-boards/napoli//include -Iarch/arm/arm-boards/plat-mstar//include -Iarch/arm/arm-boards/napoli/ -Iarch/arm/arm-boards/plat-mstar/ -I drivers/mstar -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -marm -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/mstar/include -Idrivers/mstar/mbx/drv -Idrivers/mstar/mbx/drv/hal/napoli -DRED_LION    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(mhal_mbx_interrupt)"  -D"KBUILD_MODNAME=KBUILD_STR(mdrv_mbx)" -c -o drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.c

source_drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o := drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.c

deps_drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o := \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/include/linux/kconfig.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \
  include/linux/interrupt.h \
    $(wildcard include/config/mp/platform/arch/general.h) \
    $(wildcard include/config/mp/platform/arm.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
    $(wildcard include/config/proc/fs.h) \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /tools/arm/arm-2012.09/bin/../lib/gcc/arm-none-linux-gnueabi/4.7.2/include/stdarg.h \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/linkage.h \
  include/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/mp/debug/tool/changelist.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/posix_types.h \
  include/linux/bitops.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/bitops.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/system.h \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/irqflags.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/hwcap.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/mstar/mpatch_macro.h \
    $(wildcard include/config/mp/platform/arch/general/debug.h) \
    $(wildcard include/config/mp/platform/arm/debug.h) \
    $(wildcard include/config/mp/platform/mips.h) \
    $(wildcard include/config/mp/platform/mips/debug.h) \
    $(wildcard include/config/mp/platform/fixme.h) \
    $(wildcard include/config/mp/platform/fixme/debug.h) \
    $(wildcard include/config/mp/platform/arm/pmu.h) \
    $(wildcard include/config/mp/platform/arm/pmu/debug.h) \
    $(wildcard include/config/mp/platform/pm.h) \
    $(wildcard include/config/mp/platform/pm/debug.h) \
    $(wildcard include/config/mp/platform/arm/errata/775420.h) \
    $(wildcard include/config/mp/platform/arm/errata/775420/debug.h) \
    $(wildcard include/config/mp/platform/mstar/legancy/intr.h) \
    $(wildcard include/config/mp/platform/mstar/legancy/intr/debug.h) \
    $(wildcard include/config/mp/platform/sw/patch/l2/sram/rma.h) \
    $(wildcard include/config/mp/platform/sw/patch/l2/sram/rma/debug.h) \
    $(wildcard include/config/mp/platform/mips74k/timer.h) \
    $(wildcard include/config/mp/platform/mips74k/timer/debug.h) \
    $(wildcard include/config/mp/platform/arm/mstar/etm.h) \
    $(wildcard include/config/mp/platform/arm/mstar/etm/debug.h) \
    $(wildcard include/config/mp/platform/int/1/to/1/spi.h) \
    $(wildcard include/config/mp/platform/int/1/to/1/spi/debug.h) \
    $(wildcard include/config/mp/platform/disable/jiffies/overflow/debug.h) \
    $(wildcard include/config/mp/platform/disable/jiffies/overflow/debug/debug.h) \
    $(wildcard include/config/mp/platform/lzma/bin/compressed.h) \
    $(wildcard include/config/mp/platform/lzma/bin/compressed/debug.h) \
    $(wildcard include/config/mp/platform/cpu/setting.h) \
    $(wildcard include/config/mp/platform/cpu/setting/debug.h) \
    $(wildcard include/config/mp/platform/mips/system/call/get/version.h) \
    $(wildcard include/config/mp/platform/mips/system/call/get/version/debug.h) \
    $(wildcard include/config/mp/platform/verify/lx/mem/align.h) \
    $(wildcard include/config/mp/platform/verify/lx/mem/align/debug.h) \
    $(wildcard include/config/mp/nand/ubi.h) \
    $(wildcard include/config/mp/nand/ubi/debug.h) \
    $(wildcard include/config/mp/nand/mtd.h) \
    $(wildcard include/config/mp/nand/mtd/debug.h) \
    $(wildcard include/config/mp/nand/ubifs.h) \
    $(wildcard include/config/mp/nand/ubifs/debug.h) \
    $(wildcard include/config/mp/nand/spansion.h) \
    $(wildcard include/config/mp/nand/spansion/debug.h) \
    $(wildcard include/config/mp/nand/bbt.h) \
    $(wildcard include/config/mp/nand/bbt/debug.h) \
    $(wildcard include/config/mp/nand/bbt/size.h) \
    $(wildcard include/config/mp/nand/bbt/size/debug.h) \
    $(wildcard include/config/mp/usb/mstar.h) \
    $(wildcard include/config/mp/usb/mstar/debug.h) \
    $(wildcard include/config/mp/sd/mstar.h) \
    $(wildcard include/config/mp/sd/mstar/debug.h) \
    $(wildcard include/config/mp/sd/plug.h) \
    $(wildcard include/config/mp/sd/plug/debug.h) \
    $(wildcard include/config/mp/emmc/partition.h) \
    $(wildcard include/config/mp/emmc/partition/debug.h) \
    $(wildcard include/config/mp/emmc/mmc/patch.h) \
    $(wildcard include/config/mp/emmc/mmc/patch/debug.h) \
    $(wildcard include/config/mp/emmc/trim.h) \
    $(wildcard include/config/mp/emmc/trim/debug.h) \
    $(wildcard include/config/mp/emmc/cache.h) \
    $(wildcard include/config/mp/emmc/cache/debug.h) \
    $(wildcard include/config/mp/emmc/datatag.h) \
    $(wildcard include/config/mp/emmc/datatag/debug.h) \
    $(wildcard include/config/mp/jbd2/commit/num/limit.h) \
    $(wildcard include/config/mp/jbd2/commit/num/limit/debug.h) \
    $(wildcard include/config/mp/jbd2/reset/journal/sb.h) \
    $(wildcard include/config/mp/jbd2/reset/journal/sb/debug.h) \
    $(wildcard include/config/mp/mstar/str/base.h) \
    $(wildcard include/config/mp/mstar/str/base/debug.h) \
    $(wildcard include/config/mp/android/low/mem/killer/include/cachemem.h) \
    $(wildcard include/config/mp/android/low/mem/killer/include/cachemem/debug.h) \
    $(wildcard include/config/mp/android/dummy/mstar/rtc.h) \
    $(wildcard include/config/mp/android/dummy/mstar/rtc/debug.h) \
    $(wildcard include/config/mp/android/alarm/clock/boottime/patch.h) \
    $(wildcard include/config/mp/android/alarm/clock/boottime/patch/debug.h) \
    $(wildcard include/config/mp/android/mstar/rc/map/define.h) \
    $(wildcard include/config/mp/android/mstar/rc/map/define/debug.h) \
    $(wildcard include/config/mp/android/mstar/hardcode/lpj.h) \
    $(wildcard include/config/mp/android/mstar/hardcode/lpj/debug.h) \
    $(wildcard include/config/mp/compiler/error.h) \
    $(wildcard include/config/mp/compiler/error/debug.h) \
    $(wildcard include/config/mp/debug/tool/watchdog.h) \
    $(wildcard include/config/mp/debug/tool/watchdog/debug.h) \
    $(wildcard include/config/mp/debug/tool/codedump.h) \
    $(wildcard include/config/mp/debug/tool/codedump/debug.h) \
    $(wildcard include/config/mp/debug/tool/codedump/data/sync.h) \
    $(wildcard include/config/mp/debug/tool/codedump/data/sync/debug.h) \
    $(wildcard include/config/mp/debug/tool/coredump/path.h) \
    $(wildcard include/config/mp/debug/tool/coredump/path/debug.h) \
    $(wildcard include/config/mp/debug/tool/coredump/path/option.h) \
    $(wildcard include/config/mp/debug/tool/coredump/path/option/debug.h) \
    $(wildcard include/config/mp/debug/tool/coredump/detect/usb/plugin.h) \
    $(wildcard include/config/mp/debug/tool/coredump/detect/usb/plugin/debug.h) \
    $(wildcard include/config/mp/debug/tool/kdebug.h) \
    $(wildcard include/config/mp/debug/tool/kdebug/debug.h) \
    $(wildcard include/config/mp/debug/tool/changelist/debug.h) \
    $(wildcard include/config/mp/debug/tool/oprofile.h) \
    $(wildcard include/config/mp/debug/tool/oprofile/debug.h) \
    $(wildcard include/config/mp/debug/tool/ubi.h) \
    $(wildcard include/config/mp/debug/tool/ubi/debug.h) \
    $(wildcard include/config/mp/debug/tool/oom.h) \
    $(wildcard include/config/mp/debug/tool/oom/debug.h) \
    $(wildcard include/config/mp/debug/tool/log.h) \
    $(wildcard include/config/mp/debug/tool/log/debug.h) \
    $(wildcard include/config/mp/debug/tool/rm.h) \
    $(wildcard include/config/mp/debug/tool/rm/debug.h) \
    $(wildcard include/config/mp/debug/tool/force/ignored/core/dump/path/bootargs/when/usb/plugin.h) \
    $(wildcard include/config/mp/debug/tool/force/ignored/core/dump/path/bootargs/when/usb/plugin/debug.h) \
    $(wildcard include/config/mp/debug/tool/ramlog.h) \
    $(wildcard include/config/mp/debug/tool/ramlog/debug.h) \
    $(wildcard include/config/mp/debug/tool/rtp/trace.h) \
    $(wildcard include/config/mp/debug/tool/rtp/trace/debug.h) \
    $(wildcard include/config/mp/debug/tool/skip/pulling/running/rt/task.h) \
    $(wildcard include/config/mp/debug/tool/skip/pulling/running/rt/task/debug.h) \
    $(wildcard include/config/mp/debug/tool/interrupt/debug.h) \
    $(wildcard include/config/mp/debug/tool/interrupt/debug/debug.h) \
    $(wildcard include/config/mp/remote/control/rc/register/retry.h) \
    $(wildcard include/config/mp/remote/control/rc/register/retry/debug.h) \
    $(wildcard include/config/mp/scsi/mstar/sd/card/hotplug.h) \
    $(wildcard include/config/mp/scsi/mstar/sd/card/hotplug/debug.h) \
    $(wildcard include/config/mp/scsi/hd/suspend.h) \
    $(wildcard include/config/mp/scsi/hd/suspend/debug.h) \
    $(wildcard include/config/mp/scsi/multi/lun.h) \
    $(wildcard include/config/mp/scsi/multi/lun/debug.h) \
    $(wildcard include/config/mp/mm/mstar/3dalloc/miu0/1.h) \
    $(wildcard include/config/mp/mm/mstar/3dalloc/miu0/1/debug.h) \
    $(wildcard include/config/mp/mm/mali/mmu/notifier.h) \
    $(wildcard include/config/mp/mm/mali/mmu/notifier/debug.h) \
    $(wildcard include/config/mp/mm/mali/reserve.h) \
    $(wildcard include/config/mp/mm/mali/reserve/debug.h) \
    $(wildcard include/config/mp/mmap/bufferable.h) \
    $(wildcard include/config/mp/mmap/bufferable/debug.h) \
    $(wildcard include/config/mp/mmap/mmap/boundary/protect.h) \
    $(wildcard include/config/mp/mmap/mmap/boundary/protect/debug.h) \
    $(wildcard include/config/mp/miu/mapping.h) \
    $(wildcard include/config/mp/miu/mapping/debug.h) \
    $(wildcard include/config/mp/mips/l2/catch.h) \
    $(wildcard include/config/mp/mips/l2/catch/debug.h) \
    $(wildcard include/config/mp/wdt/off/dbg.h) \
    $(wildcard include/config/mp/wdt/off/dbg/debug.h) \
    $(wildcard include/config/mp/camera/plug/out.h) \
    $(wildcard include/config/mp/camera/plug/out/debug.h) \
    $(wildcard include/config/mp/sysattr/show.h) \
    $(wildcard include/config/mp/sysattr/show/debug.h) \
    $(wildcard include/config/mp/mips/highmem/cache/alias/patch.h) \
    $(wildcard include/config/mp/mips/highmem/cache/alias/patch/debug.h) \
    $(wildcard include/config/mp/mips/highmem/memory/present/patch.h) \
    $(wildcard include/config/mp/mips/highmem/memory/present/patch/debug.h) \
    $(wildcard include/config/mp/checkpt/boot.h) \
    $(wildcard include/config/mp/checkpt/boot/debug.h) \
    $(wildcard include/config/mp/webcam/init.h) \
    $(wildcard include/config/mp/webcam/init/debug.h) \
    $(wildcard include/config/mp/mips/mips16e/unaligned/access.h) \
    $(wildcard include/config/mp/mips/mips16e/unaligned/access/debug.h) \
    $(wildcard include/config/mp/ntfs3g/wrap.h) \
    $(wildcard include/config/mp/ntfs3g/wrap/debug.h) \
    $(wildcard include/config/mp/bdi/mstar/bdi/patch.h) \
    $(wildcard include/config/mp/bdi/mstar/bdi/patch/debug.h) \
    $(wildcard include/config/mp/smp/startup.h) \
    $(wildcard include/config/mp/smp/startup/debug.h) \
    $(wildcard include/config/mp/uart/serial/8250/riu/base.h) \
    $(wildcard include/config/mp/uart/serial/8250/riu/base/debug.h) \
    $(wildcard include/config/mp/uart/serial/open/set/baudrate.h) \
    $(wildcard include/config/mp/uart/serial/open/set/baudrate/debug.h) \
    $(wildcard include/config/mp/ntfs/ioctl.h) \
    $(wildcard include/config/mp/ntfs/ioctl/debug.h) \
    $(wildcard include/config/mp/ntfs/volume/label.h) \
    $(wildcard include/config/mp/ntfs/volume/label/debug.h) \
    $(wildcard include/config/mp/ntfs/volume/id.h) \
    $(wildcard include/config/mp/ntfs/volume/id/debug.h) \
    $(wildcard include/config/mp/ntfs/read/pages.h) \
    $(wildcard include/config/mp/ntfs/read/pages/debug.h) \
    $(wildcard include/config/mp/ntfs/refine/readdir.h) \
    $(wildcard include/config/mp/ntfs/refine/readdir/debug.h) \
    $(wildcard include/config/mp/kernel/compat/from/2/6/35/11/to/3/1/10.h) \
    $(wildcard include/config/mp/kernel/compat/from/2/6/35/11/to/3/1/10/debug.h) \
    $(wildcard include/config/mp/kernel/compat/patch/fix/inode/cluster/list.h) \
    $(wildcard include/config/mp/kernel/compat/patch/fix/inode/cluster/list/debug.h) \
    $(wildcard include/config/mp/ethernet/mstar/icmp/enhance.h) \
    $(wildcard include/config/mp/ethernet/mstar/icmp/enhance/debug.h) \
    $(wildcard include/config/mp/usb/str/patch.h) \
    $(wildcard include/config/mp/usb/str/patch/debug.h) \
    $(wildcard include/config/mp/fat/volume/label.h) \
    $(wildcard include/config/mp/fat/volume/label/debug.h) \
    $(wildcard include/config/mp/ca7/quad/core/patch.h) \
    $(wildcard include/config/mp/ca7/quad/core/patch/debug.h) \
    $(wildcard include/config/mp/ca7/hw/break/points/enable.h) \
    $(wildcard include/config/mp/ca7/hw/break/points/enable/debug.h) \
    $(wildcard include/config/mp/ca7/performance/monitor/enable.h) \
    $(wildcard include/config/mp/ca7/performance/monitor/enable/debug.h) \
    $(wildcard include/config/mp/kernel/bug/patch/remove.h) \
    $(wildcard include/config/mp/kernel/bug/patch/remove/debug.h) \
    $(wildcard include/config/mp/hid/hidraw/patch.h) \
    $(wildcard include/config/mp/hid/hidraw/patch/debug.h) \
    $(wildcard include/config/mp/hid/hidraw/opensrc.h) \
    $(wildcard include/config/mp/hid/hidraw/opensrc/debug.h) \
    $(wildcard include/config/mp/hid/hidraw/trylock.h) \
    $(wildcard include/config/mp/hid/hidraw/trylock/debug.h) \
    $(wildcard include/config/mp/blcr/compile/patch.h) \
    $(wildcard include/config/mp/blcr/compile/patch/debug.h) \
    $(wildcard include/config/mp/wireless/mstar.h) \
    $(wildcard include/config/mp/wireless/mstar/debug.h) \
    $(wildcard include/config/mp/sata/ata/core/patch.h) \
    $(wildcard include/config/mp/sata/ata/core/patch/debug.h) \
    $(wildcard include/config/mp/acp/l2.h) \
    $(wildcard include/config/mp/acp/l2/debug.h) \
    $(wildcard include/config/mp/acp/direction.h) \
    $(wildcard include/config/mp/acp/direction/debug.h) \
    $(wildcard include/config/mp/temp/debug/eiffel/netflix.h) \
    $(wildcard include/config/mp/temp/debug/eiffel/netflix/debug.h) \
    $(wildcard include/config/mp/schd/debug/re/sched/nor.h) \
    $(wildcard include/config/mp/schd/debug/re/sched/nor/debug.h) \
    $(wildcard include/config/mp/antutu/benchmark/rise/performance.h) \
    $(wildcard include/config/mp/antutu/benchmark/rise/performance/debug.h) \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/le.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/dynamic_debug.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/div64.h \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/const.h \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/string.h \
  include/linux/irqreturn.h \
  include/linux/irqnr.h \
  include/linux/hardirq.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
  include/linux/lockdep.h \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/hardirq.h \
    $(wildcard include/config/local/timers.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/irq.h \
  arch/arm/arm-boards/napoli//include/mach/irqs.h \
    $(wildcard include/config/mstar/chip.h) \
  include/linux/irq_cpustat.h \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  include/linux/errno.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/smp.h \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/pfn.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  include/linux/hrtimer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/timerfd.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/rbtree.h \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/spinlock_types.h \
  include/linux/rwlock_types.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/spinlock.h \
    $(wildcard include/config/thumb2/kernel.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/processor.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/arm/errata/754327.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/hw_breakpoint.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/inline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
    $(wildcard include/config/generic/atomic64.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/atomic.h \
  include/asm-generic/atomic-long.h \
  include/linux/math64.h \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/linux/param.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/timex.h \
  arch/arm/arm-boards/napoli//include/mach/timex.h \
  include/linux/wait.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/current.h \
  include/linux/timer.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/timerqueue.h \
  include/linux/kref.h \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  include/trace/events/irq.h \
  include/linux/tracepoint.h \
    $(wildcard include/config/tracepoints.h) \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/preempt/rt.h) \
  include/linux/completion.h \
  include/linux/rcutree.h \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  include/trace/define_trace.h \
    $(wildcard include/config/event/tracing.h) \
  include/linux/delay.h \
  /home/cax/workdir/mstar6a918/code/3.1.10_Napoli_tvos/3.1.10/arch/arm/include/asm/delay.h \
    $(wildcard include/config/arch/provides/udelay.h) \
  drivers/mstar/include/mdrv_mstypes.h \
  drivers/mstar/include/mdrv_types.h \
    $(wildcard include/config/mstar/msystem.h) \
  drivers/mstar/mbx/drv/mdrv_mbx.h \
  drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.h \
  drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt_reg.h \
  drivers/mstar/include/mdrv_types.h \
  arch/arm/arm-boards/napoli/chip_int.h \
    $(wildcard include/config/spi.h) \
    $(wildcard include/config/spi/irq.h) \
  arch/arm/arm-boards/napoli//include/mach/platform.h \

drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o: $(deps_drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o)

$(deps_drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o):
