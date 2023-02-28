/*---------------------------------------------------------------------------
 * Copyright (c) 2023 Arm Limited (or its affiliates).
 * All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

/**
 * @file B-U585I-IOT02A.h
 * @brief The B-U585I-IOT02A.h file defines GPIO pin mappings for B-U585I-IOT02A board
 */

#ifndef B_U585I_IOT02A_H_
#define B_U585I_IOT02A_H_

#include "stm32u5xx_hal.h"
#include "GPIO_STM32U5xx.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// B-U585I-IOT02A Arduino Connector Pin Defintions
#define ARDUINO_UNO_D0  GPIO_PORTD(9U)  /* USART3: RX */
#define ARDUINO_UNO_D1  GPIO_PORTD(8U)  /* USART3: TX */
#define ARDUINO_UNO_D2  GPIO_PORTD(15U)
#define ARDUINO_UNO_D3  GPIO_PORTB(2U)
#define ARDUINO_UNO_D4  GPIO_PORTE(7U)
#define ARDUINO_UNO_D5  GPIO_PORTE(0U)
#define ARDUINO_UNO_D6  GPIO_PORTB(6U)
#define ARDUINO_UNO_D7  GPIO_PORTF(13U)
#define ARDUINO_UNO_D8  GPIO_PORTC(1U)
#define ARDUINO_UNO_D9  GPIO_PORTA(8U)
#define ARDUINO_UNO_D10 GPIO_PORTE(12U)
#define ARDUINO_UNO_D11 GPIO_PORTE(15U) /* SPI1: MOSI */
#define ARDUINO_UNO_D12 GPIO_PORTE(14U) /* SPI1: MISO */
#define ARDUINO_UNO_D13 GPIO_PORTE(13U) /* SPI1: SCK  */
#define ARDUINO_UNO_D14 GPIO_PORTC(0U)
#define ARDUINO_UNO_D15 GPIO_PORTC(2U)
#define ARDUINO_UNO_D16 GPIO_PORTC(4U)
#define ARDUINO_UNO_D17 GPIO_PORTC(5U)
#define ARDUINO_UNO_D18 GPIO_PORTA(7U)
#define ARDUINO_UNO_D19 GPIO_PORTB(0U)
#define ARDUINO_UNO_D20 GPIO_PORTB(8U)  /* I2C1: SDA  */
#define ARDUINO_UNO_D21 GPIO_PORTB(9U)  /* I2C1: SCL  */

// B-U585I-IOT02A Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     1
#define ARDUINO_UNO_SPI     1
#define ARDUINO_UNO_UART    3

// B-U585I-IOT02A LED Pin Definitions
#define RED_LED         GPIO_PORTH(6U)
#define GREEN_LED       GPIO_PORTH(7U)

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C1;
extern ARM_DRIVER_SPI   Driver_SPI1;
extern ARM_DRIVER_USART Driver_USART1;
extern ARM_DRIVER_USART Driver_USART3;

// UART: Driver information for default UART to communicate with HOST PC.
#define HOST_S_DRIVER       Driver_USART3
#define HOST_S_SIGNAL_EVENT HOST_SignalEvent_t
#define HOST_B_DRIVER       Driver_USART1
#define HOST_B_SIGNAL_EVENT HOST_SignalEvent_t

// I2C/SPI Communication Idle Task and Argument
#define COMM_IDLE_TASK      NULL
#define COMM_IDLE_ARG       NULL

// Enter Sleep (Power Down)
#define ENTER_SLEEP()       HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI)

#endif /* B_U585I_IOT02A_H_ */
