/*
 * Copyright (c) 2023 ARM Limited. All rights reserved.
 *
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
 *
 * $Date:        10. February 2023
 * $Revision:    V1.0
 *
 * Project:      GPIO Driver definitions for Kinetis K22F
 */

#ifndef GPIO_MK22F_H_
#define GPIO_MK22F_H_

#ifdef  __cplusplus
extern "C"
{
#endif

#include "Driver_GPIO.h"

// Pin mapping
#define GPIO_PORTA(n)   (  0U + (n))
#define GPIO_PORTB(n)   ( 32U + (n))
#define GPIO_PORTC(n)   ( 64U + (n))
#define GPIO_PORTD(n)   ( 96U + (n))
#define GPIO_PORTE(n)   (128U + (n))

// PORTx IRQ Handlers
extern void PORTA_IRQHandler (void);
extern void PORTB_IRQHandler (void);
extern void PORTC_IRQHandler (void);
extern void PORTD_IRQHandler (void);
extern void PORTE_IRQHandler (void);

// GPIO0 Driver access structure
extern ARM_DRIVER_GPIO Driver_GPIO;

#ifdef  __cplusplus
}
#endif

#endif /* GPIO_MK22F_H_ */
