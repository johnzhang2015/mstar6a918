cmd_drivers/mstar/mbx/mdrv-mbx.o := /tools/arm/arm-2012.09/bin/arm-none-linux-gnueabi-ld -EL    -r -o drivers/mstar/mbx/mdrv-mbx.o drivers/mstar/mbx/mdrv_mbx_io.o drivers/mstar/mbx/drv/mdrv_mbx.o drivers/mstar/mbx/drv/mdrv_mbx_msgpool.o drivers/mstar/mbx/drv/hal/napoli/mhal_mbx.o drivers/mstar/mbx/drv/hal/napoli/mhal_mbx_interrupt.o ; scripts/mod/modpost drivers/mstar/mbx/mdrv-mbx.o
