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

#ifndef _FSL_PORT_EX_H_
#define _FSL_PORT_EX_H_

#include "fsl_common.h"
#include "fsl_port.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* PCR - Pin Control Register */
#define PORT_PCR_PV_MASK                        (PORT_PCR_PS_MASK | PORT_PCR_PE_MASK)
#define PORT_PCR_PV_SHIFT                       (0U)
#define PORT_PCR_PV(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PV_SHIFT)) & PORT_PCR_PV_MASK)


/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Gets the port PCR register.
 *
 * @param base   PORT peripheral base pointer.
 * @param pin    PORT pin number.
 * @return Port PCR register value.
 */
static inline uint32_t PORT_GetPinConfig(PORT_Type *base, uint32_t pin)
{
    return (base->PCR[pin]);
}

/*!
 * @brief Enables the port pin open drain.
 *
 * @param base      PORT peripheral base pointer.
 * @param pin       PORT pin number.
 * @param enable  PORT pin open drain configuration.
 */
static inline void PORT_EnablePinOpenDrain(PORT_Type *base, uint32_t pin, bool enable)
{
    base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_ODE_MASK) | PORT_PCR_ODE(enable);
}

/*!
 * @brief Configures the port pin pull.
 *
 * @param base      PORT peripheral base pointer.
 * @param pin       PORT pin number.
 * @param value  PORT pin pull value
 *        - kPORT_PullDisable = 0U - Internal pull-up/down resistor is disabled.
 *        - kPORT_PullDown    = 2U - Internal pull-down resistor is enabled.
 *        - kPORT_PullUp      = 3U - Internal pull-up resistor is enabled.
 */
static inline void PORT_SetPinPullConfig(PORT_Type *base, uint32_t pin, uint32_t value)
{
    base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_PV_MASK) | PORT_PCR_PV(value);
}

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_PORT_EX_H_ */
