# Packs
This directory contains NXP CMSIS-Packs which have been updated as described below.

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
