/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! File: frdm_stbc_agm01_shield.h
* @brief The frdm_stbc_agm01_shield.h file declares mapping of the Kinetis
         Device peripherals to the frmd-k22f and frmd-stbc-agm01 shield
*/

#ifndef _FRDM_STBC_AGM01_SHIELD_H_
#define _FRDM_STBC_AGM01_SHIELD_H_

/* The shield name */
#define SHIELD_NAME "FRDM-STBC-AGM01"

// FXOS8700 Sensor Information
// #define FXOS8700_I2C_ADDR   0x1E
// #define FXOS8700_INT1       ARDUINO_UNO_D2
// #define FXOS8700_INT2       ARDUINO_UNO_D4
// #define FXOS8700_CS         ARDUINO_UNO_D16     // A2 ON UNO WIFI

// FXAS21002 Sensor Information
#define FXAS21002_I2C_INDEX     ARDUINO_UNO_I2C
#define FXAS21002_I2C_DRIVER    ARM_Driver_I2C_(FXAS21002_I2C_INDEX)
#define FXAS21002_I2C_EVENT     I2C_SignalEvent(FXAS21002_I2C_INDEX)
#define FXAS21002_I2C_ADDR      0x20
#define FXAS21002_SPI_INDEX     ARDUINO_UNO_SPI
#define FXAS21002_SPI_DRIVER    ARM_Driver_SPI_(FXAS21002_SPI_INDEX)
#define FXAS21002_SPI_EVENT     SPI_SignalEvent(FXAS21002_SPI_INDEX)
#define FXAS21002_SPI_BAUDRATE  2000000U
#define FXAS21002_CS            ARDUINO_UNO_D10
#define FXAS21002_INT1          ARDUINO_UNO_D5

// FRDM-STBC-AGM01 Shield Reset
#define RESET_GPIO              ARDUINO_UNO_D17  // A3 ON UNO WIFI

///@name Shield Parameters
/// Use this section to define the shield board: 3 bit code 0 to 7 inclusive
/// transmitted in bits 7-5 for display purposes only.
///@{
#define SHIELD_MULTIB   0
#define SHIELD_NONE     1
#define SHIELD_AGM01    2
#define SHIELD_AGM02    3
#define SHIELD_AGMP03   4
#define SHIELD_AGM04    5
#define THIS_SHIELD     SHIELD_AGM01

// spare 5 to 7 inclusive
///@}

// Shield Setup (default configuration)
extern int32_t shield_setup (void);

#endif /* _FRDM_STBC_AGM01_SHIELD_H_ */
