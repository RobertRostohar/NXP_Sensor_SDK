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

#include CMSIS_board_header
#include "frdm_stbi_a8974_shield.h"
#include "Driver_GPIO.h"

extern ARM_DRIVER_GPIO Driver_GPIO0;

// Shield Setup (default configuration)
int32_t shield_setup (void) {
  ARM_DRIVER_GPIO *pGpio = &Driver_GPIO0;

  // ARDUINO_UNO_D2  - INT1 (FXLS8974): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D2
  pGpio->Setup(ARDUINO_UNO_D2,  NULL);
  #endif

  // ARDUINO_UNO_D14 - INT2 (FXLS8974): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D14
  pGpio->Setup(ARDUINO_UNO_D14, NULL);
  #endif

  // ARDUINO_UNO_D10 - SPI_CS_A (FXLS8974): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D10
  pGpio->Setup(ARDUINO_UNO_D10, NULL);
  #endif

  // ARDUINO_UNO_D5  - INTF_SEL (FXLS8974): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D5
  pGpio->Setup(ARDUINO_UNO_D5,  NULL);
  #ifdef IMX_1060
  // Manually drive pin low (shield pulldown is weaker than board pull-up)
  pGpio->SetDirection(ARDUINO_UNO_D5, ARM_GPIO_OUTPUT);
  pGpio->SetOutput(ARDUINO_UNO_D5, 0U);
  #endif
  #endif

  // ARDUINO_UNO_D6  - BT_MODE (FXLS8974): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D6
  pGpio->Setup(ARDUINO_UNO_D6,  NULL);
  #endif

  // ARDUINO_UNO_D17 - WAKEUP (FXLS8974): Input, No Pull Resistor
  #ifdef ARDUINO_UNO_D17
  pGpio->Setup(ARDUINO_UNO_D17, NULL);
  #endif

  return 0;
}
