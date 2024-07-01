/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define PIO00_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO00_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO01_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO01_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M0P */

#define PIO011_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO011_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO012_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO012_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO013_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO013_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO04_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO04_FUNC_ALT2 0x02u         /*!<@brief Selects pin function.: Alternative connection 2. */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void SPI3_InitPins(void); /* Function assigned for the Cortex-M0P */

#define PIO011_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO011_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO012_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO012_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO013_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO013_FUNC_ALT0 0x00u        /*!<@brief Selects pin function.: Alternative connection 0. */
#define PIO04_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO04_FUNC_ALT0 0x00u         /*!<@brief Selects pin function.: Alternative connection 0. */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void SPI3_DeinitPins(void); /* Function assigned for the Cortex-M0P */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
