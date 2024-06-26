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
#include "GPIO_iMXRT1060.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// i.MXRT1060 EVK Arduino Connector Pin Defintion
#define ARDUINO_UNO_D0  GPIO_PORT1(23U) /* LPUART3: RX */
#define ARDUINO_UNO_D1  GPIO_PORT1(22U) /* LPUART3: TX */
#define ARDUINO_UNO_D2  GPIO_PORT1(11U)
#define ARDUINO_UNO_D3  GPIO_PORT1(24U)
#define ARDUINO_UNO_D4  GPIO_PORT1(9U)
#define ARDUINO_UNO_D5  GPIO_PORT1(10U)
#define ARDUINO_UNO_D6  GPIO_PORT1(18U)
#define ARDUINO_UNO_D7  GPIO_PORT1(19U)
#define ARDUINO_UNO_D8  GPIO_PORT1(3U)
#define ARDUINO_UNO_D9  GPIO_PORT1(2U)
#define ARDUINO_UNO_D10 GPIO_PORT3(13U)
#define ARDUINO_UNO_D11 GPIO_PORT3(14U) /* LPSPI1: MOSI */
#define ARDUINO_UNO_D12 GPIO_PORT3(15U) /* LPSPI1: MISO */
#define ARDUINO_UNO_D13 GPIO_PORT3(12U) /* LPSPI1: SCK  */
#define ARDUINO_UNO_D14 GPIO_PORT1(26U)
#define ARDUINO_UNO_D15 GPIO_PORT1(27U)
#define ARDUINO_UNO_D16 GPIO_PORT1(20U)
#define ARDUINO_UNO_D17 GPIO_PORT1(21U)
#define ARDUINO_UNO_D18 GPIO_PORT1(17U) /* LPI2C1: SDA, Shared with D20 */
#define ARDUINO_UNO_D19 GPIO_PORT1(16U) /* LPI2C1: SCL, Shared with D21 */
#define ARDUINO_UNO_D20 GPIO_PORT1(17U) /* LPI2C1: SDA, Shared with D18 */
#define ARDUINO_UNO_D21 GPIO_PORT1(16U) /* LPI2C1: SCL, Shared with D19 */

// i.MXRT1060 EVK Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     1
/*
#define ARDUINO_UNO_SPI     1
*/
#define ARDUINO_UNO_UART    3

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C1;    /* Arduino I2C  */
/*
extern ARM_DRIVER_SPI   Driver_SPI1;    // Arduino SPI
*/
extern ARM_DRIVER_USART Driver_USART1;  /* OpenSDA      */
extern ARM_DRIVER_USART Driver_USART3;  /* Arduino UART */

// On-Board FXOS8700 Sensor Information
#ifndef FXOS8700_ON_BOARD_DISABLE
#define FXOS8700_ON_BOARD
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
