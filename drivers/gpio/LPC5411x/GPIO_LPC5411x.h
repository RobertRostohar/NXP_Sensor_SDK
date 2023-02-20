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
 * $Date:        9. February 2023
 * $Revision:    V1.0
 *
 * Project:      GPIO Driver definitions for LPC5411x
 */

#ifndef GPIO_LPC5411X_H_
#define GPIO_LPC5411X_H_

#ifdef  __cplusplus
extern "C"
{
#endif

#include "Driver_GPIO.h"

// Pin mapping
#define GPIO_PORT0(n)   ( 0U + (n))
#define GPIO_PORT1(n)   (32U + (n))

// PORTx IRQ Handlers
void PIN_INT0_IRQHandler (void);
void PIN_INT1_IRQHandler (void);
void PIN_INT2_IRQHandler (void);
void PIN_INT3_IRQHandler (void);
void PIN_INT4_IRQHandler (void);
void PIN_INT5_IRQHandler (void);
void PIN_INT6_IRQHandler (void);
void PIN_INT7_IRQHandler (void);

// GPIO Driver access structure
extern ARM_DRIVER_GPIO Driver_GPIO0;

#ifdef  __cplusplus
}
#endif

#endif /* GPIO_LPC5411X_H_ */

