/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! File: frdm_stbc_agmp03_shield.h
* @brief The frdm_stbc_agmp03_shield.h file declares mapping for frmd-stbc-agmp03 shield.
*/

#ifndef _FRDM_STBC_AGMP03_SHIELD_H_
#define _FRDM_STBC_AGMP03_SHIELD_H_

/* The shield name */
#define SHIELD_NAME "FRDM-STBC-AGMP03"

// FXLS8962 Sensor Information
#ifndef FXLS8962_ON_BOARD
#define FXLS8962_I2C_INDEX      ARDUINO_UNO_I2C
#define FXLS8962_I2C_DRIVER     ARM_Driver_I2C_(FXLS8962_I2C_INDEX)
#define FXLS8962_I2C_ADDR       0x18
#define FXLS8962_SPI_INDEX      ARDUINO_UNO_SPI
#define FXLS8962_SPI_DRIVER     ARM_Driver_SPI_(FXLS8962_SPI_INDEX)
#define FXLS8962_SPI_BAUDRATE   4000000U
#define FXLS8962_SPI_CS         ARDUINO_UNO_D10
#define FXLS8962_INT1           ARDUINO_UNO_D2
#define FXLS8962_INT2           ARDUINO_UNO_D14
#endif

// FXAS21002 Sensor Information
#ifndef FXAS21002_ON_BOARD
#define FXAS21002_I2C_INDEX     ARDUINO_UNO_I2C
#define FXAS21002_I2C_DRIVER    ARM_Driver_I2C_(FXAS21002_I2C_INDEX)
#define FXAS21002_I2C_ADDR      0x20
#define FXAS21002_SPI_INDEX     ARDUINO_UNO_SPI
#define FXAS21002_SPI_DRIVER    ARM_Driver_SPI_(FXAS21002_SPI_INDEX)
#define FXAS21002_SPI_BAUDRATE  2000000U
#define FXAS21002_SPI_CS        ARDUINO_UNO_D15
#define FXAS21002_INT1          ARDUINO_UNO_D8
#define FXAS21002_INT2          ARDUINO_UNO_D16
#endif

// MPL3115 Sensor Information
#ifndef MPL3115_ON_BOARD
#define MPL3115_I2C_INDEX       ARDUINO_UNO_I2C
#define MPL3115_I2C_DRIVER      ARM_Driver_I2C_(MPL3115_I2C_INDEX)
#define MPL3115_I2C_ADDR        0x60
#define MPL3115_INT1            ARDUINO_UNO_D7
#endif

// MAG3110 Sensor Information
#ifndef MAG3110_ON_BOARD
#define MAG3110_I2C_INDEX       ARDUINO_UNO_I2C
#define MAG3110_I2C_DRIVER      ARM_Driver_I2C_(MAG3110_I2C_INDEX)
#define MAG3110_I2C_ADDR        0x0E
#define MAG3110_INT1            ARDUINO_UNO_D5
#endif

// FRDM-STBC-AGMP03 Shield Reset
#define AGMP03_RESET            ARDUINO_UNO_D17

#endif /* _FRDM_STBC_AGMP03_SHIELD_H_ */
