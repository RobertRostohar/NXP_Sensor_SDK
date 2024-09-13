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

// LPCXpresso54114 Arduino Connector GPIO Pin Defintions
#define ARDUINO_UNO_D2  GPIO_PORT0(10U)
#define ARDUINO_UNO_D3  GPIO_PORT1(12U)
#define ARDUINO_UNO_D4  GPIO_PORT1(13U)
#define ARDUINO_UNO_D5  GPIO_PORT0(29U) // LED RED: PIO0 Pin 29
#define ARDUINO_UNO_D6  GPIO_PORT1(0U)
#define ARDUINO_UNO_D7  GPIO_PORT1(14U)
#define ARDUINO_UNO_D8  GPIO_PORT1(16U)
#define ARDUINO_UNO_D9  GPIO_PORT1(15U)
#define ARDUINO_UNO_D10 GPIO_PORT1(1U)
#define ARDUINO_UNO_D14 GPIO_PORT0(30U)
#define ARDUINO_UNO_D16 GPIO_PORT1(8U)
#define ARDUINO_UNO_D18 GPIO_PORT1(4U)
#define ARDUINO_UNO_D19 GPIO_PORT1(5U)

// LPCXpresso54114 Arduino Connector Alternate Function Pin Definitions
// D0  - UART1: RX   (PIO0 Pin 8)
// D1  - UART1: TX   (PIO0 Pin 9)
// D11 - SPI5:  COPI (PIO0 Pin 20)
// D12 - SPI5:  CIPO (PIO0 Pin 18)
// D13 - SPI5:  SCK  (PIO0 Pin 19)
// D20 - I2C4:  SDA  (PIO0 Pin 26)
// D21 - I2C4:  SCL  (PIO0 Pin 25)

// CMSIS Driver instances on Arduino Connector
#define ARDUINO_UNO_I2C     4
#define ARDUINO_UNO_SPI     5
#define ARDUINO_UNO_UART    1

// Retarget stdio to CMSIS UART
#define RETARGET_STDIO_UART 0

// CMSIS Drivers
extern ARM_DRIVER_I2C   ARM_Driver_I2C_(ARDUINO_UNO_I2C);       // Arduino I2C
extern ARM_DRIVER_SPI   ARM_Driver_SPI_(ARDUINO_UNO_SPI);       // Arduino SPI
extern ARM_DRIVER_USART ARM_Driver_USART_(RETARGET_STDIO_UART); // OpenSDA
extern ARM_DRIVER_USART ARM_Driver_USART_(ARDUINO_UNO_UART);    // Arduino UART

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       POWER_EnterSleep()

#ifdef CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif /* LPC54114_CM4_H_ */
