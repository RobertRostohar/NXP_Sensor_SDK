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

#ifndef _FSL_IOCON_EX_H_
#define _FSL_IOCON_EX_H_

#include "fsl_common.h"
#include "fsl_iocon.h"


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
 * @brief   Enables the PIO pin open drain
 * @param   base        : The base of IOCON peripheral on the chip
 * @param   port        : GPIO port to mux
 * @param   pin         : GPIO pin to mux
 * @param   enable      : PIO pin open drain configuration.
 */
static inline void IOCON_EnablePinOpenDrain (IOCON_Type *base, uint32_t port, uint32_t pin, bool enable)
{
    base->PIO[port][pin] = (base->PIO[port][pin] & ~IOCON_PIO_OD_MASK) | IOCON_PIO_OD(enable);
}

/*!
 * @brief   Configures the icon pin pull
 * @param   base        : The base of IOCON peripheral on the chip
 * @param   port        : GPIO port to mux
 * @param   pin         : GPIO pin to mux
 * @param   value       : PORT pin pull value
 *        - IOCON_MODE_INACT    = 0U - Internal pull-up/down resistor is disabled.
 *        - IOCON_MODE_PULLDOWN = 1U - Internal pull-down resistor is enabled.
 *        - IOCON_MODE_PULLUP   = 2U - Internal pull-up resistor is enabled.
 *        - IOCON_MODE_REPEATER = 3U - Internal repeater mode.
 */
static inline void IOCON_SetPinPullConfig (IOCON_Type *base, uint32_t port, uint32_t pin, uint32_t value)
{
    base->PIO[port][pin] = (base->PIO[port][pin] & ~IOCON_PIO_MODE_MASK) | IOCON_PIO_FUNC(value);
}

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_IOCON_EX_H_ */
