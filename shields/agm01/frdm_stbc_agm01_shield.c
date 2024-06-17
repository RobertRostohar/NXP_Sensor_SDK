/*---------------------------------------------------------------------------
 * Copyright (c) 2023-2024 Arm Limited (or its affiliates).
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

#include CMSIS_target_header

#include "Driver_GPIO.h"

extern ARM_DRIVER_GPIO Driver_GPIO0;

// Shield Setup (default configuration)
int shield_setup (void) {
  ARM_DRIVER_GPIO *pGpio = &Driver_GPIO0;

  // ARDUINO_UNO_D5  - INT1_21002 (FXAS21002): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D5
  pGpio->Setup(ARDUINO_UNO_D5,  NULL);
  #endif

  // ARDUINO_UNO_D8 - INT2_21002 (FXAS21002): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D8
  pGpio->Setup(ARDUINO_UNO_D8, NULL);
  #endif

  // ARDUINO_UNO_D10 - SPI_CSB (FXAS21002): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D10
  pGpio->Setup(ARDUINO_UNO_D10, NULL);
  #endif

  // ARDUINO_UNO_D17 - RST_GPIO: Input, No Pull Resistor.  D17 ON WIFI = A3
  #ifdef ARDUINO_UNO_D17
  pGpio->Setup(ARDUINO_UNO_D17, NULL);
  #endif

  return 0;
}
