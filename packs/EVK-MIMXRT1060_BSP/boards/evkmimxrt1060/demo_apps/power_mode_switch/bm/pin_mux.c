/*
 * Copyright 2019-2020 ,2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MIMXRT1062xxxxA
package_id: MIMXRT1062DVL6A
mcu_data: ksdk2_0
processor_version: 9.0.1
board: MIMXRT1060-EVK
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: L6, peripheral: GPIO5, signal: 'gpio_io, 00', pin_signal: WAKEUP, direction: INPUT, gpio_interrupt: kGPIO_IntRisingEdge, software_input_on: no_init,
    open_drain: no_init, drive_strength: no_init, slew_rate: no_init}
  - {pin_num: G13, peripheral: ARM, signal: arm_trace_swo, pin_signal: GPIO_AD_B0_10, slew_rate: Fast}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           
  CLOCK_EnableClock(kCLOCK_IomuxcSnvs);       

  /* GPIO configuration of SD_PWREN on WAKEUP (pin L6) */
  gpio_pin_config_t SD_PWREN_config = {
      .direction = kGPIO_DigitalInput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_IntRisingEdge
  };
  /* Initialize GPIO functionality on WAKEUP (pin L6) */
  GPIO_PinInit(GPIO5, 0U, &SD_PWREN_config);
  /* Enable GPIO pin interrupt on WAKEUP (pin L6) */
  GPIO_PortEnableInterrupts(GPIO5, 1U << 0U);

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_ARM_TRACE_SWO, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_SNVS_WAKEUP_GPIO5_IO00, 0U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_10_ARM_TRACE_SWO, 0x90B1U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0x10B0U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0x10B0U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_Init_PMIC_STBY_REQ:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: L7, peripheral: GPIO5, signal: 'gpio_io, 02', pin_signal: PMIC_STBY_REQ, direction: OUTPUT, gpio_init_state: 'false', software_input_on: Disable, hysteresis_enable: Disable,
    pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_Init_PMIC_STBY_REQ
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_Init_PMIC_STBY_REQ(void) {
  CLOCK_EnableClock(kCLOCK_IomuxcSnvs);       

  /* GPIO configuration of PERI_PWREN on PMIC_STBY_REQ (pin L7) */
  gpio_pin_config_t PERI_PWREN_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on PMIC_STBY_REQ (pin L7) */
  GPIO_PinInit(GPIO5, 2U, &PERI_PWREN_config);

  IOMUXC_SetPinMux(IOMUXC_SNVS_PMIC_STBY_REQ_GPIO5_IO02, 0U); 
  IOMUXC_SetPinConfig(IOMUXC_SNVS_PMIC_STBY_REQ_GPIO5_IO02, 0x10B0U); 
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
