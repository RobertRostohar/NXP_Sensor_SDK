/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*! \file frdm_k22f.h
    \brief The \b frdm_k22f.h file defines GPIO pins for FRDM-K22F board
*/

#ifndef FRDM_K22F_H_
#define FRDM_K22F_H_

#include "pin_mux.h"
#include "fsl_smc.h"
#include "MK22F51212.h"
#include "RTE_Device.h"
#include "GPIO_MK22F.h"
#include "Driver_I2C.h"
#include "Driver_SPI.h"
#include "Driver_USART.h"

// FRDM-K22F Arduino Connector Pin Defintion
#define ARDUINO_UNO_D0  GPIO_PORTD(2U)  /* UART2: RX  */
#define ARDUINO_UNO_D1  GPIO_PORTD(3U)  /* UART2: TX  */
#define ARDUINO_UNO_D2  GPIO_PORTB(16U)
#define ARDUINO_UNO_D3  GPIO_PORTA(2U)
#define ARDUINO_UNO_D4  GPIO_PORTA(4U)
#define ARDUINO_UNO_D5  GPIO_PORTB(18U)
#define ARDUINO_UNO_D6  GPIO_PORTC(3U)
#define ARDUINO_UNO_D7  GPIO_PORTC(6U)
#define ARDUINO_UNO_D8  GPIO_PORTB(19U)
#define ARDUINO_UNO_D9  GPIO_PORTA(1U)
#define ARDUINO_UNO_D10 GPIO_PORTD(4U)
#define ARDUINO_UNO_D11 GPIO_PORTD(6U)  /* SPI1:  COPI */
#define ARDUINO_UNO_D12 GPIO_PORTD(7U)  /* SPI1:  CIPO */
#define ARDUINO_UNO_D13 GPIO_PORTD(5U)  /* SPI1:  SCK  */
#define ARDUINO_UNO_D14 GPIO_PORTB(0U)
#define ARDUINO_UNO_D15 GPIO_PORTB(1U)
#define ARDUINO_UNO_D16 GPIO_PORTC(1U)
#define ARDUINO_UNO_D17 GPIO_PORTC(2U)
#define ARDUINO_UNO_D18 GPIO_PORTB(3U)  /* I2C0:  SDA */
#define ARDUINO_UNO_D19 GPIO_PORTB(2U)  /* I2C0:  SCL */
#define ARDUINO_UNO_D20 GPIO_PORTE(0U)  /* UART1: TX   */
#define ARDUINO_UNO_D21 GPIO_PORTE(1U)  /* UART1: RX   */

// FRDM-K22F Arduino CMSIS Driver instances
#define ARDUINO_UNO_I2C     0
#define ARDUINO_UNO_SPI     1
#define ARDUINO_UNO_UART    2

// FRDM-K22F RGB LED Pin Definitions
#define RED_LED         GPIO_PORTA(1U)
#define GREEN_LED       GPIO_PORTA(2U)
#define BLUE_LED        GPIO_PORTD(5U)

// CMSIS Drivers
extern ARM_DRIVER_I2C   Driver_I2C0;
extern ARM_DRIVER_SPI   Driver_SPI1;
extern ARM_DRIVER_USART Driver_USART1;
extern ARM_DRIVER_USART Driver_USART2;

// UART: Driver information for default UART to communicate with HOST PC.
#define HOST_S_DRIVER       Driver_USART1
#define HOST_S_SIGNAL_EVENT HOST_SignalEvent_t

// Bluetooth: Driver information for default UART to communicate with HOST PC.
#define HOST_B_DRIVER       Driver_USART2
#define HOST_B_SIGNAL_EVENT HOST_SignalEvent_t

// On-Board FXOS8700 Sensor Information
#define FXOS8700_I2C_INDEX  0
#define FXOS8700_I2C_DRIVER ARM_Driver_I2C_(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_EVENT  I2C_SignalEvent(FXOS8700_I2C_INDEX)
#define FXOS8700_I2C_ADDR   0x1C
#define FXOS8700_INT1       GPIO_PORTD(0U)
#define FXOS8700_INT2       GPIO_PORTD(1U)

// Sensor Communication Idle Task and Argument
#define SENSOR_IDLE_TASK    SMC_SetPowerModeVlpr
#define SENSOR_IDLE_ARG     SMC

/// @name Wired UART Parameters
/// Sensor Fusion aliases are defined in terms of specific hardware features
/// defined in MK22F51212.h.
///@{
#define WIRED_UART            UART1                  ///< KSDK instance name for the debug UART
#define WIRED_UART_PORT_CLKEN kCLOCK_PortE           ///< KDSK handle for the pin port clock enable
#define WIRED_UART_PORT       PORTE                  ///< KDSK handle for the pin port associated with this UART
#define WIRED_UART_RX_PIN     1U                     ///< The port number associated with RX
#define WIRED_UART_TX_PIN     0U                     ///< The port number associated with TX
#define WIRED_UART_MUX        kPORT_MuxAlt3          ///< KDSK pin mux selector
#ifndef USE_ORIENT_APP_CONTROL                       ///< If Using Orient App then use Host I/O
#define WIRED_UART_IRQHandler UART1_RX_TX_IRQHandler ///< KDSK-specified IRQ handler name
#endif
#define WIRED_UART_IRQn   UART1_RX_TX_IRQn ///< The interrupt number associated with this IRQ
#define WIRED_UART_CLKSRC UART1_CLK_SRC    ///< KSDK instance name for the clock feeding this module
#define WIRED_UART_IRQn   UART1_RX_TX_IRQn ///< KSDK interrupt vector number
///@}

/// @name Wireless UART Parameters
/// Sensor Fusion aliases are defined in terms of specific hardware features
/// defined in MK22F51212.h.
///@{
#define WIRELESS_UART            UART2                  ///< KSDK instance name for the debug UART
#define WIRELESS_UART_PORT_CLKEN kCLOCK_PortD           ///< KDSK handle for the pin port clock enable
#define WIRELESS_UART_PORT       PORTD                  ///< KDSK handle for the pin port associated with this UART
#define WIRELESS_UART_RX_PIN     2U                     ///< The port number associated with RX
#define WIRELESS_UART_TX_PIN     3U                     ///< The port number associated with TX
#define WIRELESS_UART_MUX        kPORT_MuxAlt3          ///< KDSK pin mux selector
#define WIRELESS_UART_IRQHandler UART2_RX_TX_IRQHandler ///< KDSK-specified IRQ handler name
#define WIRELESS_UART_IRQn       UART2_RX_TX_IRQn       ///< The interrupt number associated with this IRQ
#define WIRELESS_UART_CLKSRC     UART2_CLK_SRC          ///< KSDK instance name for the clock feeding this module
#define WIRELESS_UART_IRQn       UART2_RX_TX_IRQn       ///< KSDK interrupt vector number
///@}

///@name Miscellaneous Hardware Configuration Parameters
///@{
#define THIS_BOARD                 9          ///< FRDM_K22F
#define CORE_SYSTICK_HZ            80000000   ///< core and systick clock rate (Hz)
#define CALIBRATION_NVM_ADDR       0x0007F800 ///< start of final 2K (sector size) of 512K flash
#define ADS_NVM_ADDR               0x0007F000 ///< start of the next to last 2K (sector size) of the 512K flash
#define FLASH_SECTOR_SIZE_PROPERTY kFLASH_PropertyPflash0SectorSize
#define FLASH_ERASE_KEY            kFTFx_ApiEraseKey

// offsets from start of NVM block for calibration coefficients
#define MAG_NVM_OFFSET   0   // 68 bytes used
#define GYRO_NVM_OFFSET  100 // 16 bytes used
#define ACCEL_NVM_OFFSET 140 // 88 bytes used
///@}

#endif /* FRDM_K22F_H_ */
