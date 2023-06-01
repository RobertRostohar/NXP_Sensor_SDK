/******************************************************************************
 * @file     vio_lpc54114.c
 * @brief    Virtual I/O implementation for LPCXpresso54114 Development Board
 * @version  V1.0.0
 * @date     10. May 2023
 ******************************************************************************/
/*
 * Copyright (c) 2023 Arm Limited (or its affiliates).
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

#include "cmsis_vio.h"

#include "RTE_Components.h"             // Component selection
#include CMSIS_device_header

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
#include "GPIO_LPC5411x.h"
#endif

// VIO pins
#define pinLED0         GPIO_PORT0(29U)
#define pinLED1         GPIO_PORT1(10U)
#define pinLED2         GPIO_PORT1(9U)

// VIO input, output variables
__USED uint32_t vioSignalIn;            // Memory for incoming signal
__USED uint32_t vioSignalOut;           // Memory for outgoing signal

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
  ARM_DRIVER_GPIO *pDriverGPIO = &Driver_GPIO0;
#endif

// Initialize test input, output.
void vioInit (void) {

  vioSignalIn  = 0U;
  vioSignalOut = 0U;

#if !defined CMSIS_VOUT
  #ifdef pinLED0
    pDriverGPIO->Setup(pinLED0, NULL);
    pDriverGPIO->SetOutput(pinLED0, 1U);
    pDriverGPIO->SetDirection(pinLED0, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED1
    pDriverGPIO->Setup(pinLED1, NULL);
    pDriverGPIO->SetOutput(pinLED1, 1U);
    pDriverGPIO->SetDirection(pinLED1, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED2
    pDriverGPIO->Setup(pinLED2, NULL);
    pDriverGPIO->SetOutput(pinLED2, 1U);
    pDriverGPIO->SetDirection(pinLED2, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED3
    pDriverGPIO->Setup(pinLED3, NULL);
    pDriverGPIO->SetOutput(pinLED3, 1U);
    pDriverGPIO->SetDirection(pinLED3, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED4
    pDriverGPIO->Setup(pinLED4, NULL);
    pDriverGPIO->SetOutput(pinLED4, 1U);
    pDriverGPIO->SetDirection(pinLED4, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED5
    pDriverGPIO->Setup(pinLED5, NULL);
    pDriverGPIO->SetOutput(pinLED5, 1U);
    pDriverGPIO->SetDirection(pinLED5, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED6
    pDriverGPIO->Setup(pinLED6, NULL);
    pDriverGPIO->SetOutput(pinLED6, 1U);
    pDriverGPIO->SetDirection(pinLED6, ARM_GPIO_OUTPUT);
  #endif
  #ifdef pinLED7
    pDriverGPIO->Setup(pinLED7, NULL);
    pDriverGPIO->SetOutput(pinLED7, 1U);
    pDriverGPIO->SetDirection(pinLED7, ARM_GPIO_OUTPUT);
  #endif
#endif

#if !defined CMSIS_VIN
  #ifdef pinBUTTON0
    pDriverGPIO->Setup(pinBUTTON0, NULL);
    pDriverGPIO->SetDirection(pinBUTTON0, ARM_GPIO_INPUT);
  #endif
  #ifdef pinBUTTON1
    pDriverGPIO->Setup(pinBUTTON1, NULL);
    pDriverGPIO->SetDirection(pinBUTTON1, ARM_GPIO_INPUT);
  #endif
  #ifdef pinBUTTON2
    pDriverGPIO->Setup(pinBUTTON2, NULL);
    pDriverGPIO->SetDirection(pinBUTTON2, ARM_GPIO_INPUT);
  #endif
  #ifdef pinBUTTON3
    pDriverGPIO->Setup(pinBUTTON3, NULL);
    pDriverGPIO->SetDirection(pinBUTTON3, ARM_GPIO_INPUT);
  #endif
#endif
}

// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {

  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

#if !defined CMSIS_VOUT
  // Output signals to LEDs
  #ifdef pinLED0
    if ((mask & vioLED0) != 0U) {
      pDriverGPIO->SetOutput(pinLED0, ((signal & vioLED0) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED1
    if ((mask & vioLED1) != 0U) {
      pDriverGPIO->SetOutput(pinLED1, ((signal & vioLED1) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED2
    if ((mask & vioLED2) != 0U) {
      pDriverGPIO->SetOutput(pinLED2, ((signal & vioLED2) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED3
    if ((mask & vioLED3) != 0U) {
      pDriverGPIO->SetOutput(pinLED3, ((signal & vioLED3) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED4
    if ((mask & vioLED4) != 0U) {
      pDriverGPIO->SetOutput(pinLED4, ((signal & vioLED4) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED5
    if ((mask & vioLED5) != 0U) {
      pDriverGPIO->SetOutput(pinLED5, ((signal & vioLED5) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED6
    if ((mask & vioLED6) != 0U) {
      pDriverGPIO->SetOutput(pinLED6, ((signal & vioLED6) != 0U) ? 0U : 1U);
    }
  #endif
  #ifdef pinLED7
    if ((mask & vioLED7) != 0U) {
      pDriverGPIO->SetOutput(pinLED7, ((signal & vioLED7) != 0U) ? 0U : 1U);
    }
  #endif
#endif
}

// Get signal input.
uint32_t vioGetSignal (uint32_t mask) {
  uint32_t signal;

#if !defined CMSIS_VIN
  // Get input signals from buttons
  #ifdef pinBUTTON0
    if ((mask & vioBUTTON0) != 0U) {
      if (pDriverGPIO->GetInput(pinBUTTON0) == 0U) {
        vioSignalIn |=  vioBUTTON0;
      } else {
        vioSignalIn &= ~vioBUTTON0;
      }
    }
  #endif
  #ifdef pinBUTTON1
    if ((mask & vioBUTTON1) != 0U) {
      if (pDriverGPIO->GetInput(pinBUTTON1) == 0U) {
        vioSignalIn |=  vioBUTTON1;
      } else {
        vioSignalIn &= ~vioBUTTON1;
      }
    }
  #endif
  #ifdef pinBUTTON2
    if ((mask & vioBUTTON2) != 0U) {
      if (pDriverGPIO->GetInput(pinBUTTON2) == 0U) {
        vioSignalIn |=  vioBUTTON2;
      } else {
        vioSignalIn &= ~vioBUTTON2;
      }
    }
  #endif
  #ifdef pinBUTTON3
    if ((mask & vioBUTTON3) != 0U) {
      if (pDriverGPIO->GetInput(pinBUTTON3) == 0U) {
        vioSignalIn |=  vioBUTTON3;
      } else {
        vioSignalIn &= ~vioBUTTON3;
      }
    }
  #endif
#endif

  signal = vioSignalIn;

  return (signal & mask);
}
