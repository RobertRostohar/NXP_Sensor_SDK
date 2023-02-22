/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! File: frdm_stbi_a8974_shield.h
* @brief The frdm_stbi_a8974_shield.h file declares arduino pin mapping for frdm_stbi_a8974_shield.
*/

#ifndef _FRDM_STBI_A8974_SHIELD_H_
#define _FRDM_STBI_A8974_SHIELD_H_

/* The shield name */
#define SHIELD_NAME "FRDM-STBI-A8974"

// FXLS8974 Sensor Information
#define FXLS8974_I2C_INDEX      ARDUINO_UNO_I2C
#define FXLS8974_I2C_DRIVER     ARM_Driver_I2C_(FXLS8974_I2C_INDEX)
#define FXLS8974_I2C_EVENT      I2C_SignalEvent(FXLS8974_I2C_INDEX)
#define FXLS8974_I2C_ADDR       0x18
#define FXLS8974_SPI_INDEX      ARDUINO_UNO_SPI
#define FXLS8974_SPI_DRIVER     ARM_Driver_SPI_(FXLS8974_SPI_INDEX)
#define FXLS8974_SPI_EVENT      SPI_SignalEvent(FXLS8974_SPI_INDEX)
#define FXLS8974_SPI_BAUDRATE   4000000U
#define FXLS8974_CS             ARDUINO_UNO_D10
#define FXLS8974_MOSI           ARDUINO_UNO_D11
#define FXLS8974_MISO           ARDUINO_UNO_D12
#define FXLS8974_SCLK           ARDUINO_UNO_D13
#define FXLS8974_INT1           ARDUINO_UNO_D2
#define FXLS8974_INT2           ARDUINO_UNO_D14

// FRDM-STBI-A8974 Shield Reset
#define RESET_GPIO              ARDUINO_UNO_D17

#endif /* _FRDM_STBI_A8974_SHIELD_H_ */
