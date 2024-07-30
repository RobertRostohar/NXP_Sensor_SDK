/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! \file frdm_k22f.h
    \brief The \b frdm_k22f.h file defines GPIO pins for FRDM-K22F board
*/

#ifndef FRDM_K22F_H_
#define FRDM_K22F_H_

#include "fsl_smc.h"
#include "fsl_gpio_cmsis.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// FRDM-K22F Arduino Connector GPIO Pin Defintions
#define ARDUINO_UNO_D2  GPIO_PORTB(16U)
#define ARDUINO_UNO_D3  GPIO_PORTA(2U)  // LED GREEN: PA2
#define ARDUINO_UNO_D4  GPIO_PORTA(4U)
#define ARDUINO_UNO_D5  GPIO_PORTB(18U)
#define ARDUINO_UNO_D6  GPIO_PORTC(3U)
#define ARDUINO_UNO_D7  GPIO_PORTC(6U)
#define ARDUINO_UNO_D8  GPIO_PORTB(19U)
#define ARDUINO_UNO_D9  GPIO_PORTA(1U)  // LED RED: PA1
#define ARDUINO_UNO_D10 GPIO_PORTD(4U)
// #define ARDUINO_UNO_D13 GPIO_PORTD(5U)  // LED BLUE (conflict SPI1: SCK)
#define ARDUINO_UNO_D14 GPIO_PORTB(0U)
#define ARDUINO_UNO_D15 GPIO_PORTB(1U)
#define ARDUINO_UNO_D16 GPIO_PORTC(1U)
#define ARDUINO_UNO_D17 GPIO_PORTC(2U)

// FRDM-K22F Arduino Connector Alternate Function Pin Definitions
// D0  - UART2: RX   (PD2)
// D1  - UART2: TX   (PD3)
// D11 - SPI1:  COPI (PD6)
// D12 - SPI1:  CIPO (PD7)
// D13 - SPI1:  SCK  (PD5)
// D18 - I2C0:  SDA  (PB3)
// D19 - I2C0:  SCL  (PB2)
// D20 - UART1: TX   (PE0)
// D21 - UART1: RX   (PE1)

// CMSIS Driver instances on Arduino Connector
#define ARDUINO_UNO_I2C     0
#define ARDUINO_UNO_SPI     1
#define ARDUINO_UNO_UART    2

// Retarget stdio to CMSIS UART
#define RETARGET_STDIO_UART 1

// CMSIS Drivers
extern ARM_DRIVER_I2C   ARM_Driver_I2C_(ARDUINO_UNO_I2C);       // Arduino I2C
extern ARM_DRIVER_SPI   ARM_Driver_SPI_(ARDUINO_UNO_SPI);       // Arduino SPI
extern ARM_DRIVER_USART ARM_Driver_USART_(RETARGET_STDIO_UART); // OpenSDA
extern ARM_DRIVER_USART ARM_Driver_USART_(ARDUINO_UNO_UART);    // Arduino UART

// On-Board FXOS8700 Sensor Information
#ifdef  FXOS8700_ON_BOARD
#define FXOS8700_I2C_INDEX  0
#define FXOS8700_I2C_DRIVER ARM_Driver_I2C_(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_ADDR   0x1C
#define FXOS8700_INT1       GPIO_PORTD(0U)
#define FXOS8700_INT2       GPIO_PORTD(1U)
#endif

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       SMC_SetPowerModeWait(SMC)

#ifdef CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif /* FRDM_K22F_H_ */
