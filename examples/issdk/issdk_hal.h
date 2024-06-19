/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! \file issdk_hal.h
    \brief Wrapper for Hardware Abstraction Layer (HAL)

    This file simply provides one level of indirection for the developer
    to select the particular Hardware Abstraction Layer they would like to use.
*/

#ifndef __ISSDK_HAL_H__
#define __ISSDK_HAL_H__

#ifdef   CMSIS_target_header
#include CMSIS_target_header
#endif

#ifndef PRINTF
#define PRINTF  printf
#endif
#ifndef GETCHAR
#define GETCHAR getchar
#endif

/* @brief  Ask use input to resume after specified samples have been processed. */
#define ASK_USER_TO_RESUME(x)                                                          \
    static bool askResume            = true;                                           \
    static uint16_t samplesToProcess = x - 1;                                          \
    if (askResume && !samplesToProcess--)                                              \
    {                                                                                  \
        PRINTF("\r\n Specified samples processed, press any key to continue... \r\n"); \
        GETCHAR();                                                                     \
        askResume = false;                                                             \
    }

#endif // __ISSDK_HAL_H__
