/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file evkmimxrt1060.h
 * @brief The evkmimxrt1060.h file defines GPIO pin mappings for evkmimxrt1060 board
 */

#ifndef EVKBIMX1060_H_
#define EVKBIMX1060_H_

#include "clock_config.h"
#include "fsl_clock.h"
#include "fsl_gpio_cmsis.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// i.MXRT1060 EVK Arduino Connector Pin Defintions
#define ARDUINO_UNO_D2  GPIO_PORT1(11U)
#define ARDUINO_UNO_D3  GPIO_PORT1(24U)
#define ARDUINO_UNO_D4  GPIO_PORT1(9U)
#define ARDUINO_UNO_D5  GPIO_PORT1(10U)
#define ARDUINO_UNO_D6  GPIO_PORT1(18U)
#define ARDUINO_UNO_D7  GPIO_PORT1(19U)
#define ARDUINO_UNO_D8  GPIO_PORT1(3U)
#define ARDUINO_UNO_D9  GPIO_PORT1(2U)
#define ARDUINO_UNO_D10 GPIO_PORT3(13U)
#define ARDUINO_UNO_D14 GPIO_PORT1(26U)
#define ARDUINO_UNO_D15 GPIO_PORT1(27U)
#define ARDUINO_UNO_D16 GPIO_PORT1(20U)
#define ARDUINO_UNO_D17 GPIO_PORT1(21U)

// i.MXRT1060 EVK Arduino Connector Alternate Function Pin Defintions
// D0  - LPUART3: RX   (PIO1 Pin 23)
// D1  - LPUART3: TX   (PIO1 Pin 22)
// D11 - LPSPI1:  MOSI (PIO3 Pin 14)
// D12 - LPSPI1:  MISO (PIO3 Pin 15)
// D13 - LPSPI1:  SCK  (PIO3 Pin 12)
// D18 - LPI2C1:  SDA  (PIO1 Pin 17), Shared with D20
// D19 - LPI2C1:  SCL  (PIO1 Pin 16), Shared with D21
// D20 - LPI2C1:  SDA  (PIO1 Pin 17), Shared with D18
// D21 - LPI2C1:  SCL  (PIO1 Pin 16), Shared with D19

// CMSIS Driver instances on Arduino Connector
#define ARDUINO_UNO_I2C     1
// #define ARDUINO_UNO_SPI     1
#define ARDUINO_UNO_UART    3

// Retarget stdio to CMSIS UART
#define RETARGET_STDIO_UART 1

// CMSIS Drivers
extern ARM_DRIVER_I2C   ARM_Driver_I2C_(ARDUINO_UNO_I2C);       // Arduino I2C
// extern ARM_DRIVER_SPI   ARM_Driver_SPI_(ARDUINO_UNO_SPI);       // Arduino SPI
extern ARM_DRIVER_USART ARM_Driver_USART_(RETARGET_STDIO_UART); // OpenSDA
extern ARM_DRIVER_USART ARM_Driver_USART_(ARDUINO_UNO_UART);    // Arduino UART

// On-Board FXOS8700 Sensor Information
#ifdef  FXOS8700_ON_BOARD
#define FXOS8700_I2C_INDEX  1
#define FXOS8700_I2C_DRIVER ARM_Driver_I2C_(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_ADDR   0x1E
#define FXOS8700_INT1       GPIO_PORT1(10U)
#define FXOS8700_INT2       GPIO_PORT1(11U)
#endif

/* Compatibility definitions for evkmimxrt1060 */
#define I2C1                LPI2C1
#define SPI1                LPSPI1

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       LPM_EnterSleepMode(kCLOCK_ModeWait)

extern void LPM_EnterSleepMode(clock_mode_t mode);

#ifdef CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif /* EVKBIMX1060_H_ */
