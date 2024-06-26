/*
 * Copyright 2018 NXP
 *
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file lpc55s69.h
 * @brief The lpc55s69.h file defines GPIO pin mappings for LPCXpresso55S69 board
*/

#ifndef LPC55S69_H_
#define LPC55S69_H_

#include "fsl_power.h"
#include "GPIO_LPC55S69.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// LPCXpresso55S69 Arduino Connector Pin Defintion
#define ARDUINO_UNO_D0  GPIO_PORT1(24U) /* UART2: RX   PIO1 Pin 24 */
#define ARDUINO_UNO_D1  GPIO_PORT0(27U) /* UART2: TX   PIO0 Pin 27 */
#define ARDUINO_UNO_D2  GPIO_PORT0(15U)
#define ARDUINO_UNO_D3  GPIO_PORT1(6U)  /* LED RED:    PIO1 Pin 6  */
#define ARDUINO_UNO_D4  GPIO_PORT1(7U)  /* LED GREEN:  PIO1 Pin 7  */
#define ARDUINO_UNO_D5  GPIO_PORT1(4U)  /* LED BLUE:   PIO1 Pin 4  */
#define ARDUINO_UNO_D6  GPIO_PORT1(10U)
#define ARDUINO_UNO_D7  GPIO_PORT1(9U)
#define ARDUINO_UNO_D8  GPIO_PORT1(8U)
#define ARDUINO_UNO_D9  GPIO_PORT1(5U)
#define ARDUINO_UNO_D10 GPIO_PORT1(1U)
#define ARDUINO_UNO_D11 GPIO_PORT0(26U) /* SPI8:  MOSI PIO0 Pin 26 */
#define ARDUINO_UNO_D12 GPIO_PORT1(3U)  /* SPI8:  MISO PIO1 Pin 3  */
#define ARDUINO_UNO_D13 GPIO_PORT1(2U)  /* SPI8:  SCK  PIO1 Pin 2  */
#define ARDUINO_UNO_D14 GPIO_PORT0(16U)
#define ARDUINO_UNO_D15 GPIO_PORT0(23U)
#define ARDUINO_UNO_D16 GPIO_PORT0(0U)
#define ARDUINO_UNO_D17 GPIO_PORT1(31U)
#define ARDUINO_UNO_D18 GPIO_PORT0(13U)
#define ARDUINO_UNO_D19 GPIO_PORT0(14U)
#define ARDUINO_UNO_D20 GPIO_PORT1(21U) /* I2C4:  SDA  PIO1 Pin 21 */
#define ARDUINO_UNO_D21 GPIO_PORT1(20U) /* I2C4:  SCL  PIO1 Pin 20 */

// LPCXpresso55S69 Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     4
#define ARDUINO_UNO_SPI     8
#define ARDUINO_UNO_UART    2

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C4;    /* Arduino I2C  */
extern ARM_DRIVER_SPI   Driver_SPI8;    /* Arduino SPI  */
extern ARM_DRIVER_USART Driver_USART0;  /* OpenSDA      */
extern ARM_DRIVER_USART Driver_USART2;  /* Arduino UART */

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       POWER_EnterSleep()

#ifdef CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif /* LPC55S69_CM4_H_ */
