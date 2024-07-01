/*
 * Copyright 2018-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file evkmimxrt1060.c
 * @brief The evkmimxrt1060.c file defines GPIO pins and I2C CMSIS utilities for
 * evkmimxrt1060 board.
 */

#include "evkmimxrt1060.h"

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

void LPM_EnterSleepMode(clock_mode_t mode)
{
    static uint32_t g_savedPrimask;
    assert(mode != kCLOCK_ModeRun);

    g_savedPrimask = DisableGlobalIRQ();
    __DSB();
    __ISB();

    if (mode == kCLOCK_ModeWait)
    {
        /* Clear the SLEEPDEEP bit to go into sleep mode (WAIT) */
        SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    }
    else
    {
        /* Set the SLEEPDEEP bit to enable deep sleep mode (STOP) */
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    }
    /* WFI instruction will start entry into WAIT/STOP mode */
    __WFI();

    EnableGlobalIRQ(g_savedPrimask);
    __DSB();
    __ISB();
}

// Callbacks for LPUART1 Driver
uint32_t LPUART1_GetFreq(void)
{ 
    return BOARD_BOOTCLOCKRUN_UART_CLK_ROOT;
}
void LPUART1_InitPins(void) {
    /* Done in BOARD_InitDEBUG_UART function */
}
void LPUART1_DeinitPins(void) {
    /* Not implemented */
}

// Callbacks for LPUART3 Driver
uint32_t LPUART3_GetFreq(void) {
    return BOARD_BOOTCLOCKRUN_UART_CLK_ROOT;
}
void LPUART3_InitPins(void) {
    /* Done in BOARD_InitDEBUG_UART function */
}
void LPUART3_DeinitPins(void) {
    /* Not implemented */
}

// Callbacks for LPI2C1 Driver
uint32_t LPI2C1_GetFreq(void) {
    return BOARD_BOOTCLOCKRUN_LPI2C_CLK_ROOT;
}
void LPI2C1_InitPins(void) {
    /* Done in BOARD_InitDEBUG_UART function */
}
void LPI2C1_DeinitPins(void) {
    /* Not implemented */
}
