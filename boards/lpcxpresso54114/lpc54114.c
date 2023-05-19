/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file lpc54114.c
 * @brief The lpc54114.c file defines GPIO pins and I2C CMSIS utilities for LPCXpresso54114 board.
 */

#include "lpc54114.h"

/*! @brief       Determines the Clock Frequency feature.
 *  @details     The Clock Frequecny computation API required by fsl_uart_cmsis.c.
 *  @param[in]   void
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      uint32_t Returns the clock frequency .
 */
uint32_t USART0_GetFreq(void)
{
    return CLOCK_GetFlexCommClkFreq(0);
}

/*! @brief       Determines the Clock Frequency feature.
 *  @details     The Clock Frequecny computation API required by fsl_i2c_cmsis.c.
 *  @param[in]   void
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      uint32_t Returns the clock frequency .
 */
uint32_t I2C4_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Fro12M);
}

/*! @brief       Determines the Clock Frequency feature.
 *  @details     The Clock Frequecny computation API required by fsl_i2c_cmsis.c.
 *  @param[in]   void
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      uint32_t Returns the clock frequency .
 */
uint32_t I2C5_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Fro12M);
}

/*! @brief       Determines the Clock Frequency feature.
 *  @details     The Clock Frequecny computation API required by fsl_spi_cmsis.c.
 *  @param[in]   void
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      uint32_t Returns the clock frequency .
 */
uint32_t SPI3_GetFreq(void)
{
    return CLOCK_GetFlexCommClkFreq(3);
}

/*! @brief       Determines the Clock Frequency feature.
 *  @details     The Clock Frequecny computation API required by fsl_spi_cmsis.c.
 *  @param[in]   void
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      uint32_t Returns the clock frequency .
 */
uint32_t SPI5_GetFreq(void)
{
    return CLOCK_GetFlexCommClkFreq(5);
}
