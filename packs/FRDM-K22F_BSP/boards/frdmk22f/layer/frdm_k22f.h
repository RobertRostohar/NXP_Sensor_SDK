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

// FRDM-K22F Arduino Connector Pin Defintion
#define ARDUINO_UNO_D0  GPIO_PORTD(2U)  /* UART2: RX   */
#define ARDUINO_UNO_D1  GPIO_PORTD(3U)  /* UART2: TX   */
#define ARDUINO_UNO_D2  GPIO_PORTB(16U)
#define ARDUINO_UNO_D3  GPIO_PORTA(2U)  /* LED GREEN   */
#define ARDUINO_UNO_D4  GPIO_PORTA(4U)
#define ARDUINO_UNO_D5  GPIO_PORTB(18U)
#define ARDUINO_UNO_D6  GPIO_PORTC(3U)
#define ARDUINO_UNO_D7  GPIO_PORTC(6U)
#define ARDUINO_UNO_D8  GPIO_PORTB(19U)
#define ARDUINO_UNO_D9  GPIO_PORTA(1U)  /* LED RED     */
#define ARDUINO_UNO_D10 GPIO_PORTD(4U)
#define ARDUINO_UNO_D11 GPIO_PORTD(6U)  /* SPI1:  COPI */
#define ARDUINO_UNO_D12 GPIO_PORTD(7U)  /* SPI1:  CIPO */
#define ARDUINO_UNO_D13 GPIO_PORTD(5U)  /* SPI1:  SCK  - LED BLUE (conflict) */
#define ARDUINO_UNO_D14 GPIO_PORTB(0U)
#define ARDUINO_UNO_D15 GPIO_PORTB(1U)
#define ARDUINO_UNO_D16 GPIO_PORTC(1U)
#define ARDUINO_UNO_D17 GPIO_PORTC(2U)
#define ARDUINO_UNO_D18 GPIO_PORTB(3U)  /* I2C0:  SDA  */
#define ARDUINO_UNO_D19 GPIO_PORTB(2U)  /* I2C0:  SCL  */
#define ARDUINO_UNO_D20 GPIO_PORTE(0U)  /* UART1: TX   */
#define ARDUINO_UNO_D21 GPIO_PORTE(1U)  /* UART1: RX   */

// FRDM-K22F Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     0
#define ARDUINO_UNO_SPI     1
#define ARDUINO_UNO_UART    2

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C0;    /* Arduino I2C  */
extern ARM_DRIVER_SPI   Driver_SPI1;    /* Arduino SPI  */
extern ARM_DRIVER_USART Driver_USART1;  /* OpenSDA      */
extern ARM_DRIVER_USART Driver_USART2;  /* Arduino UART */

// On-Board FXOS8700 Sensor Information
#ifndef FXOS8700_ON_BOARD_DISABLE
#define FXOS8700_ON_BOARD
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
