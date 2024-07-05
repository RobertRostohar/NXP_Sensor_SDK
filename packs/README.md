# Packs
This directory contains NXP CMSIS-Packs which have been updated as described below.

## IoT Sensing SDK ([ISSDK](ISSDK/))
- development pack version 3.0.0-dev based on NXP ISSDK pack version 2.0.0
- added shield layers
  - registered in pack description
  - [layer description and content](ISSDK/middleware/issdk/shields/)
- modified `systick_utils` to use CMSIS Core (not NXP specific)
  - [systick_utils.c](ISSDK/middleware/issdk/drivers/systick/systick_utils.c)
- modified I2C interface to remove reference to NXP peripheral memory map
  - [register_io_i2c.c](ISSDK/middleware/issdk/sensors/register_io_i2c.c)
  - [register_io_i2c.h](ISSDK/middleware/issdk/sensors/register_io_i2c.h)
- modified SPI interface to use GPIO CMSIS-Driver and remove reference to NXP peripheral memory map
  - [register_io_spi.c](ISSDK/middleware/issdk/sensors/register_io_spi.c)
  - [register_io_spi.h](ISSDK/middleware/issdk/sensors/register_io_spi.h)
- modified sensor drivers to use GPIO CMSIS-Driver
  - [diff_p_drv.c](ISSDK/middleware/issdk/sensors/diff_p_drv.c)
  - [diff_p_drv.h](ISSDK/middleware/issdk/sensors/diff_p_drv.h)
  - [fxas21002_drv.c](ISSDK/middleware/issdk/sensors/fxas21002_drv.c)
  - [fxas21002_drv.h](ISSDK/middleware/issdk/sensors/fxas21002_drv.h)
  - [fxlc95000_drv.c](ISSDK/middleware/issdk/sensors/fxlc95000_drv.c)
  - [fxlc95000_drv.h](ISSDK/middleware/issdk/sensors/fxlc95000_drv.h)
  - [fxls8471q_drv.c](ISSDK/middleware/issdk/sensors/fxls8471q_drv.c)
  - [fxls8471q_drv.h](ISSDK/middleware/issdk/sensors/fxls8471q_drv.h)
  - [fxls8961_drv.c](ISSDK/middleware/issdk/sensors/fxls8961_drv.c)
  - [fxls8961_drv.h](ISSDK/middleware/issdk/sensors/fxls8961_drv.h)
  - [fxls896x_drv.c](ISSDK/middleware/issdk/sensors/fxls896x_drv.c)
  - [fxls896x_drv.h](ISSDK/middleware/issdk/sensors/fxls896x_drv.h)
  - [fxls8971_drv.c](ISSDK/middleware/issdk/sensors/fxls8971_drv.c)
  - [fxls8971_drv.h](ISSDK/middleware/issdk/sensors/fxls8971_drv.h)
  - [fxls8974_drv.c](ISSDK/middleware/issdk/sensors/fxls8974_drv.c)
  - [fxls8974_drv.h](ISSDK/middleware/issdk/sensors/fxls8974_drv.h)
  - [fxos8700_drv.c](ISSDK/middleware/issdk/sensors/fxos8700_drv.c)
  - [fxos8700_drv.h](ISSDK/middleware/issdk/sensors/fxos8700_drv.h)
  - [mma9553_drv.c](ISSDK/middleware/issdk/sensors/mma9553_drv.c)
  - [mma9553_drv.h](ISSDK/middleware/issdk/sensors/mma9553_drv.h)


## EVK-MIMXRT1060 Board Support Pack ([EVK-MIMXRT1060_BSP](EVK-MIMXRT1060_BSP/))
- development pack version 18.1.0-dev based on NXP EVK-MIMXRT1060_BSP pack version 18.0.0
- added board layer
  - registered in pack description
  - [layer description and content](EVK-MIMXRT1060_BSP/boards/evkmimxrt1060/layer/)

## FRDM-K22F Board Support Pack ([FRDM-K22F_BSP](FRDM-K22F_BSP/))
- development pack version 18.1.0-dev based on NXP FRDM-K22F_BSP pack version 18.0.0
- added board layer
  - registered in pack description
  - [layer description and content](FRDM-K22F_BSP/boards/frdmk22f/layer/)

## LPCXpresso55S69 Board Support Pack ([LPCXpresso55S69_BSP](LPCXpresso55S69_BSP/))
- development pack version 18.1.0-dev based on NXP LPCXpresso55S69_BSP pack version 18.0.0
- added board layer
  - registered in pack description
  - [layer description and content](LPCXpresso55S69_BSP/boards/lpcxpresso55s69/layer/)

## LPCXpresso54114 Board Support Pack ([LPCXpresso54114_BSP](LPCXpresso54114_BSP/))
- development pack version 13.1.0-dev based on NXP LPCXpresso54114_BSP pack version 13.0.0
- added board layer
  - registered in pack description
  - [layer description and content](LPCXpresso54114_BSP/layer/)

## MIMXRT1062 Device Familly Pack ([MIMXRT1062_DFP](MIMXRT1062_DFP/))
- development pack version 18.1.0-dev based on NXP MIMXRT1062_DFP pack version 18.0.0
- added GPIO CMSIS-Driver
  - registered NXP::CMSIS-Driver:GPIO:gpio_cmsis component in pack description
  - added implementation (requires fsl extensions):
    - [fsl_gpio_cmsis.c](MIMXRT1062_DFP/devices/MIMXRT1062/cmsis_drivers/fsl_gpio_cmsis.c)
    - [fsl_gpio_cmsis.h](MIMXRT1062_DFP/devices/MIMXRT1062/cmsis_drivers/fsl_gpio_cmsis.h)
  - added fsl extensions:
    - [fsl_gpio_ex.h](MIMXRT1062_DFP/devices/MIMXRT1062/drivers/fsl_gpio_ex.h)
    - [fsl_iomuxc_ex.h](MIMXRT1062_DFP/devices/MIMXRT1062/drivers/fsl_iomuxc_ex.h)

## MK22F51212 Device Familly Pack ([MK22F51212_DFP](MK22F51212_DFP/))
- development pack version 18.1.0-dev based on NXP MK22F51212_DFP pack version 18.0.0
- added GPIO CMSIS-Driver
  - registered NXP::CMSIS-Driver:GPIO:gpio_cmsis component in pack description
  - added implementation (requires fsl extensions):
    - [fsl_gpio_cmsis.c](MK22F51212_DFP/devices/MK22F51212/cmsis_drivers/fsl_gpio_cmsis.c)
    - [fsl_gpio_cmsis.h](MK22F51212_DFP/devices/MK22F51212/cmsis_drivers/fsl_gpio_cmsis.h)
  - added fsl extensions:
    - [fsl_gpio_ex.h](MK22F51212_DFP/devices/MK22F51212/drivers/fsl_gpio_ex.h)
    - [fsl_port_ex.h](MK22F51212_DFP/devices/MK22F51212/drivers/fsl_port_ex.h)

## LPC55S69 Device Familly Pack ([LPC55S69_DFP](LPC55S69_DFP/))
- development pack version 18.1.0-dev based on NXP LPC55S69_DFP pack version 18.0.0
- added GPIO CMSIS-Driver
  - registered NXP::CMSIS-Driver:GPIO:gpio_cmsis component in pack description
  - added implementation (requires fsl extensions):
    - [fsl_gpio_cmsis.c](LPC55S69_DFP/devices/LPC55S69/cmsis_drivers/fsl_gpio_cmsis.c)
    - [fsl_gpio_cmsis.h](LPC55S69_DFP/devices/LPC55S69/cmsis_drivers/fsl_gpio_cmsis.h)
  - added fsl extensions:
    - [fsl_gpio_ex.h](LPC55S69_DFP/devices/LPC55S69/drivers/fsl_gpio_ex.h)
    - [fsl_iocon_ex.h](LPC55S69_DFP/devices/LPC55S69/drivers/fsl_iocon_ex.h)

## LPC54114 Device Familly Pack ([LPC54114_DFP](LPC54114_DFP/))
- development pack version 13.1.0-dev based on NXP LPC54114_DFP pack version 13.0.0
- added GPIO CMSIS-Driver
  - registered NXP::CMSIS-Driver:GPIO:gpio_cmsis component in pack description
  - added implementation (requires fsl extensions):
    - [fsl_gpio_cmsis.c](LPC54114_DFP/cmsis_drivers/fsl_gpio_cmsis.c)
    - [fsl_gpio_cmsis.h](LPC54114_DFP/cmsis_drivers/fsl_gpio_cmsis.h)
  - added fsl extensions:
    - [fsl_gpio_ex.h](LPC54114_DFP/drivers/fsl_gpio_ex.h)
    - [fsl_iocon_ex.h](LPC54114_DFP/drivers/fsl_iocon_ex.h)
