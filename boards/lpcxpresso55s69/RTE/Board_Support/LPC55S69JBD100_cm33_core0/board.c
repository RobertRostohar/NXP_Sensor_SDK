/*
 * Copyright 2017-2018 NXP
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include "fsl_common.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"


/*******************************************************************************
 * Variables
 ******************************************************************************/

const uint32_t ExtClockIn = BOARD_EXTCLKINRATE;

/*******************************************************************************
 * Code
 ******************************************************************************/
// /* Initialize debug console. */
// void BOARD_InitDebugConsole(void)
// {
//     /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
//     CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    
//     RESET_ClearPeripheralReset(BOARD_DEBUG_UART_RST);

//     uint32_t uartClkSrcFreq = BOARD_DEBUG_UART_CLK_FREQ;

//     DbgConsole_Init(BOARD_DEBUG_UART_BASEADDR, BOARD_DEBUG_UART_BAUDRATE, BOARD_DEBUG_UART_TYPE, uartClkSrcFreq);
// }

/* Initialize debug console. */
status_t BOARD_InitDebugConsole(void)
{
#if ((SDK_DEBUGCONSOLE == DEBUGCONSOLE_REDIRECT_TO_SDK) || defined(SDK_DEBUGCONSOLE_UART))
    status_t result;
    RESET_PeripheralReset(BOARD_DEBUG_UART_RST);
    result = DbgConsole_Init(BOARD_DEBUG_UART_INSTANCE, BOARD_DEBUG_UART_BAUDRATE, BOARD_DEBUG_UART_TYPE,
                             BOARD_DEBUG_UART_CLK_FREQ);
    assert(kStatus_Success == result);
    return result;
#else
    return kStatus_Success;
#endif
}