cmd_drivers/mstar/sc/mdrv-sc.o := /tools/arm/arm-2012.09/bin/arm-none-linux-gnueabi-ld -EL    -r -o drivers/mstar/sc/mdrv-sc.o drivers/mstar/sc/mdrv_sc.o drivers/mstar/sc/mdrv_sc_io.o drivers/mstar/sc/napoli/mhal_sc.o ; scripts/mod/modpost drivers/mstar/sc/mdrv-sc.o
