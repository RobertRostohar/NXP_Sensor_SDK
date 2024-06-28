/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file frdm_stbc_p3115_shield.h
* @brief The frdm_stbc_p3115_shield.h file declares mapping for frmd-stbc-p3115 shield.
*/

#ifndef _FRDM_STBC_P3115_SHIELD_H_
#define _FRDM_STBC_P3115_SHIELD_H_

/* The shield name */
#define SHIELD_NAME "FRDMSTBC-P3115"

// MPL3115 Sensor Information
#ifndef MPL3115_ON_BOARD
#define MPL3115_I2C_INDEX       ARDUINO_UNO_I2C
#define MPL3115_I2C_DRIVER      ARM_Driver_I2C_(MPL3115_I2C_INDEX)
#define MPL3115_I2C_ADDR        0x60
#define MPL3115_INT1            ARDUINO_UNO_D5
#define MPL3115_INT2            ARDUINO_UNO_D2
#endif

#endif /* _FRDM_STBC_P3115_SHIELD_H_ */
