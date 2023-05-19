/*---------------------------------------------------------------------------
 * Copyright (c) 2023 Arm Limited (or its affiliates). All rights reserved.
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
 *---------------------------------------------------------------------------*/

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "cmsis_vio.h"
#include "main.h"

#ifdef   CMSIS_shield_header
#include CMSIS_shield_header
__WEAK int32_t shield_setup (void) {
  return 0;
}
#endif

int main (void) {

  /*! Initialize the MCU hardware. */
  BOARD_ConfigMPU();
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  SystemCoreClockUpdate();

  vioInit();

#ifdef CMSIS_shield_header
 shield_setup();
#endif 

  return (app_main());
}
