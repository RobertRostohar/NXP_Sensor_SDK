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
 */

#ifndef _FSL_GPIO_EX_H_
#define _FSL_GPIO_EX_H_

#include "fsl_common.h"
#include "fsl_gpio.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Sets the direction of GPIO pin.
 *
 * @param base      GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param pin       GPIO pin number
 * @param direction GPIO pin direction.
 *        - kGPIO_DigitalInput  = 0U - Set current pin as digital input
 *        - kGPIO_DigitalOutput = 1U - Set current pin as digital output
 */
static inline void GPIO_PinSetDirection(GPIO_Type *base, uint32_t pin, gpio_pin_direction_t direction)
{
    if (direction == kGPIO_DigitalOutput)
    {
        base->PDDR |=  (1UL << pin);
    }
    else
    {
        base->PDDR &= ~(1UL << pin);
    }
}

#if defined(__cplusplus)
}
#endif


#endif /* _FSL_GPIO_EX_H_*/
