/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file lpc54114.h
 * @brief The lpc54114.h file defines GPIO pin mappings for LPCXpresso54114 board
 */

#ifndef LPC54114_H_
#define LPC54114_H_

#include "fsl_power.h"
#include "fsl_gpio_cmsis.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// LPCXpresso54114 Arduino Connector Pin Defintion
#define ARDUINO_UNO_D0  GPIO_PORT0(8U)  /* UART1: RX */
#define ARDUINO_UNO_D1  GPIO_PORT0(9U)  /* UART1: TX */
#define ARDUINO_UNO_D2  GPIO_PORT0(10U)
#define ARDUINO_UNO_D3  GPIO_PORT1(12U)
#define ARDUINO_UNO_D4  GPIO_PORT1(13U)
#define ARDUINO_UNO_D5  GPIO_PORT0(29U) /* LED RED */
#define ARDUINO_UNO_D6  GPIO_PORT1(0U)
#define ARDUINO_UNO_D7  GPIO_PORT1(14U)
#define ARDUINO_UNO_D8  GPIO_PORT1(16U)
#define ARDUINO_UNO_D9  GPIO_PORT1(15U)
#define ARDUINO_UNO_D10 GPIO_PORT1(1U)
#define ARDUINO_UNO_D11 GPIO_PORT0(20U) /* SPI5:  COPI */
#define ARDUINO_UNO_D12 GPIO_PORT0(18U) /* SPI5:  CIPO */
#define ARDUINO_UNO_D13 GPIO_PORT0(19U) /* SPI5:  SCK  */
#define ARDUINO_UNO_D14 GPIO_PORT0(30U)
#define ARDUINO_UNO_D16 GPIO_PORT1(8U)
#define ARDUINO_UNO_D18 GPIO_PORT1(4U)
#define ARDUINO_UNO_D19 GPIO_PORT1(5U)
#define ARDUINO_UNO_D20 GPIO_PORT0(26U) /* I2C4:  SDA  */
#define ARDUINO_UNO_D21 GPIO_PORT0(25U) /* I2C4:  SCL  */

// LPCXpresso54114 Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     4
#define ARDUINO_UNO_SPI     5
#define ARDUINO_UNO_UART    0

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C4;    /* Arduino I2C  */
extern ARM_DRIVER_SPI   Driver_SPI5;    /* Arduino SPI  */
extern ARM_DRIVER_USART Driver_USART0;  /* OpenSDA      */
extern ARM_DRIVER_USART Driver_USART1;  /* Arduino UART */

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       POWER_EnterSleep()

#ifdef CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif /* LPC54114_CM4_H_ */
