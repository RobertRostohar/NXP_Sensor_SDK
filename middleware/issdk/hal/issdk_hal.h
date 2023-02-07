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

#ifdef   TARGET_HEADER
#include TARGET_HEADER
#else
#include BOARD_HEADER               //Include appropriate MCU board header file
#include SHIELD_HEADER              //Include appropriate sensor shield board header file
#endif

#endif // __ISSDK_HAL_H__
