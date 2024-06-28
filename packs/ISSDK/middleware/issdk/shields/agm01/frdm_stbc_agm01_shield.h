/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! File: frdm_stbc_agm01_shield.h
* @brief The frdm_stbc_agm01_shield.h file declares mapping for frmd-stbc-agm01 shield.
*/

#ifndef _FRDM_STBC_AGM01_SHIELD_H_
#define _FRDM_STBC_AGM01_SHIELD_H_

/* The shield name */
#define SHIELD_NAME "FRDM-STBC-AGM01"

// FXOS8700 Sensor Information
#ifndef FXOS8700_ON_BOARD
#define FXOS8700_I2C_INDEX      ARDUINO_UNO_I2C
#define FXOS8700_I2C_DRIVER     ARM_Driver_I2C_(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_ADDR       0x1E
#define FXOS8700_SPI_INDEX      ARDUINO_UNO_SPI
#define FXOS8700_SPI_DRIVER     ARM_Driver_SPI_(FXOS8700_I2C_INDEX)
#define FXOS8700_SPI_BAUDRATE   1000000U
#define FXOS8700_SPI_CS         ARDUINO_UNO_D16
#define FXOS8700_INT1           ARDUINO_UNO_D2
#define FXOS8700_INT2           ARDUINO_UNO_D4
#endif

// FXAS21002 Sensor Information
#ifndef FXAS21002_ON_BOARD
#define FXAS21002_I2C_INDEX     ARDUINO_UNO_I2C
#define FXAS21002_I2C_DRIVER    ARM_Driver_I2C_(FXAS21002_I2C_INDEX)
#define FXAS21002_I2C_ADDR      0x20
#define FXAS21002_SPI_INDEX     ARDUINO_UNO_SPI
#define FXAS21002_SPI_DRIVER    ARM_Driver_SPI_(FXAS21002_SPI_INDEX)
#define FXAS21002_SPI_BAUDRATE  2000000U
#define FXAS21002_SPI_CS        ARDUINO_UNO_D7
#define FXAS21002_INT1          ARDUINO_UNO_D5
#define FXAS21002_INT2          ARDUINO_UNO_D8
#endif

// FRDM-STBC-AGM01 Shield Reset
#define AGM01_RESET             ARDUINO_UNO_D17

#endif /* _FRDM_STBC_AGM01_SHIELD_H_ */
