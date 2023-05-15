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
#include "MIMXRT1062.h"
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
#ifdef  ARDUINO_UNO_SPI_PINS
#define ARDUINO_UNO_D10 GPIO_PORT3(13U)
#define ARDUINO_UNO_D11 GPIO_PORT3(14U) /* SPI: MOSI */
#define ARDUINO_UNO_D12 GPIO_PORT3(15U) /* SPI: MISO */
#define ARDUINO_UNO_D13 GPIO_PORT3(12U) /* SPI: SCK  */
#endif
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
#ifdef  ARDUINO_UNO_SPI_PINS
#define ARDUINO_UNO_SPI     1
#endif
#define ARDUINO_UNO_UART    3

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C1;
#ifdef  ARDUINO_UNO_SPI_PINS
extern ARM_DRIVER_SPI   Driver_SPI1;
#endif
extern ARM_DRIVER_USART Driver_USART1;
extern ARM_DRIVER_USART Driver_USART3;

// On-Board FXOS8700 Sensor Information
#define FXOS8700_I2C_INDEX  1
#define FXOS8700_I2C_DRIVER ARM_Driver_I2C_(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_EVENT  I2C_SignalEvent(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_ADDR   0x1E
#define FXOS8700_INT1       GPIO_PORT1(10U)
#define FXOS8700_INT2       GPIO_PORT1(11U)

/* Compatibility definitions for evkmimxrt1060 */
#define I2C1                LPI2C1
#define I2C_Type            LPI2C_Type
#define I2C_BASE_PTRS       LPI2C_BASE_PTRS
#define SPI1                LPSPI1
#define SPI_Type            LPSPI_Type
#define SPI_BASE_PTRS       LPSPI_BASE_PTRS

// I2C/SPI Communication Idle Task and Argument
#define COMM_IDLE_TASK      NULL //SMC_SetPowerModeVlpr
#define COMM_IDLE_ARG       NULL

// Enter Sleep (Power Down)
void LPM_EnterSleepMode(clock_mode_t mode);
#define ENTER_SLEEP()       LPM_EnterSleepMode(kCLOCK_ModeWait);

#endif /* EVKBIMX1060_H_ */
