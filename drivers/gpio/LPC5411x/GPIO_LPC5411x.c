/*
 * Copyright (c) 2023 ARM Limited. All rights reserved.
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
 *
 * $Date:        9. February 2023
 * $Revision:    V1.0
 *
 * Project:      GPIO Driver for LPC5411x
 */

#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_gpio_ex.h"
#include "fsl_inputmux.h"
#include "fsl_iocon.h"
#include "fsl_iocon_ex.h"
#include "fsl_pint.h"

#include "GPIO_LPC5411x.h"


// Pin mapping
//    0 .. 22: PORT0  0 .. 22
//   23 .. 26: PORT0 23 .. 26 (I2C Support: Open-drain, No pull-resistor)
//   27 .. 28: not mapped
//   29 .. 31: PORT0 29 .. 31 (with ADC input)
//   32 .. 40: PORT1  0 ..  8 (with ADC input)
//   41 .. 49: PORT1  9 .. 17

#define GPIO_MAX_PORTS          2U
#define GPIO_MAX_PINS           50U

#define GPIO_MAX_IRQS           8U

// Default Pin Configuration
static const uint32_t DefaultPinConfig = (
  IOCON_PIO_FUNC(0U)      |     // Pin function  : PIO
  IOCON_PIO_MODE(0U)      |     // Function mode : Inactive (no pull resistor)
  IOCON_PIO_INVERT(0U)    |     // Input polarity: Disabled
  IOCON_PIO_DIGIMODE(1U)  |     // Select mode   : Digital
  IOCON_PIO_FILTEROFF(1U) |     // Glitch filter : Disabled
  IOCON_PIO_SLEW(0U)      |     // Slew rate     : Standard mode
  IOCON_PIO_OD(0U)              // Open drain    : Disabled
);

// PINx IRQ Numbers
static IRQn_Type const PinIRQn[GPIO_MAX_IRQS] = {
  PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn,
  PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn
};

// Clock IP Names
static clock_ip_name_t const ClockIP[GPIO_MAX_PORTS] = {
  kCLOCK_Gpio0, kCLOCK_Gpio1
};


// Number of active Event callback functions
static uint32_t SignalEventCount = 0U;

// Signal Event callback functions
static ARM_GPIO_SignalEvent_t SignalEvent[GPIO_MAX_IRQS];

// Signal Event pins
static uint8_t SignalEventPin[GPIO_MAX_IRQS];

// Pin Interrupt numbers
static uint8_t PinIntNum[GPIO_MAX_PINS];


// Common PIN_INTx IRQ Handler
static void PIN_INTx_IRQHandler (uint32_t num) {
  uint32_t event = 0U;

  if (PINT_PinInterruptGetRiseFlag(PINT, (pint_pin_int_t)num)) {
    PINT_PinInterruptClrRiseFlag(PINT, (pint_pin_int_t)num);
    event = ARM_GPIO_EVENT_RISING_EDGE;
  }
  if (PINT_PinInterruptGetFallFlag(PINT, (pint_pin_int_t)num)) {
    PINT_PinInterruptClrFallFlag(PINT, (pint_pin_int_t)num);
    event = ARM_GPIO_EVENT_FALLING_EDGE;
  }

  if (event != 0U) {
    if (SignalEvent[num] != NULL) {
      SignalEvent[num](SignalEventPin[num], event);
    }
  }
}

// Pin interrupt 0 IRQ Handler
void PIN_INT0_IRQHandler (void) {
  PIN_INTx_IRQHandler(0U);
}
// Pin interrupt 1 IRQ Handler
void PIN_INT1_IRQHandler (void) {
  PIN_INTx_IRQHandler(1U);
}
// Pin interrupt 2 IRQ Handler
void PIN_INT2_IRQHandler (void) {
  PIN_INTx_IRQHandler(2U);
}
// Pin interrupt 3 IRQ Handler
void PIN_INT3_IRQHandler (void) {
  PIN_INTx_IRQHandler(3U);
}
// Pin interrupt 4 IRQ Handler
void PIN_INT4_IRQHandler (void) {
  PIN_INTx_IRQHandler(4U);
}
// Pin interrupt 5 IRQ Handler
void PIN_INT5_IRQHandler (void) {
  PIN_INTx_IRQHandler(5U);
}
// Pin interrupt 6 IRQ Handler
void PIN_INT6_IRQHandler (void) {
  PIN_INTx_IRQHandler(6U);
}
// Pin interrupt 7 IRQ Handler
void PIN_INT7_IRQHandler (void) {
  PIN_INTx_IRQHandler(7U);
}


// Setup GPIO Interface
static int32_t GPIO_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
  uint32_t pin_port;
  uint32_t pin_num;
  uint32_t n;
  int32_t  result = ARM_DRIVER_ERROR;

  if ((pin < GPIO_MAX_PINS) && ((cb_event == NULL) || (SignalEventCount < GPIO_MAX_IRQS))) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    CLOCK_EnableClock(ClockIP[pin_port]);
    CLOCK_EnableClock(kCLOCK_Iocon);
    GPIO_PinSetDirection(GPIO, pin_port, pin_num, kGPIO_DigitalInput);
    IOCON_PinMuxSet(IOCON, (uint8_t)pin_port, (uint8_t)pin_num, DefaultPinConfig);
    if (cb_event != NULL) {
      n = SignalEventCount++;
      PinIntNum[pin] = (uint8_t)n;
      SignalEvent[n] = cb_event;
      SignalEventPin[n] = (uint8_t)pin;
      CLOCK_EnableClock(kCLOCK_InputMux);
      INPUTMUX_AttachSignal(INPUTMUX, (pint_pin_int_t)n, pin + (PINTSEL_PMUX_ID << PMUX_SHIFT));
      CLOCK_DisableClock(kCLOCK_InputMux);
      CLOCK_EnableClock(kCLOCK_Pint);
      PINT_PinInterruptConfig(PINT, (pint_pin_int_t)n, kPINT_PinIntEnableNone, NULL);
      NVIC_EnableIRQ(PinIRQn[n]);
    }
    result = ARM_DRIVER_OK;
  }

  return result;
}

// Set GPIO Direction
static int32_t GPIO_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
  uint32_t pin_port;
  uint32_t pin_num;
  int32_t  result = ARM_DRIVER_ERROR;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    if (direction == ARM_GPIO_OUTPUT) {
      GPIO_PinSetDirection(GPIO, pin_port, pin_num, kGPIO_DigitalOutput);
    } else {
      GPIO_PinSetDirection(GPIO, pin_port, pin_num, kGPIO_DigitalInput);
    }
    result = ARM_DRIVER_OK;
  }

  return result;
}

// Set GPIO Output Mode
static int32_t GPIO_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
  uint32_t pin_port;
  uint32_t pin_num;
  int32_t  result = ARM_DRIVER_ERROR;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    if (mode == ARM_GPIO_OPEN_DRAIN) {
      IOCON_EnablePinOpenDrain(IOCON, pin_port, pin_num, true);
    } else {
      IOCON_EnablePinOpenDrain(IOCON, pin_port, pin_num, false);
    }
    result = ARM_DRIVER_OK;
  }

  return result;
}

// Set GPIO Pull Resistor
static int32_t GPIO_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
  uint32_t pin_port;
  uint32_t pin_num;
  int32_t  result = ARM_DRIVER_ERROR;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    switch (resistor) {
      case ARM_GPIO_PULL_NONE:
        IOCON_SetPinPullConfig(IOCON, pin_port, pin_num, IOCON_MODE_INACT);
        result = ARM_DRIVER_OK;
        break;
      case ARM_GPIO_PULL_UP:
        IOCON_SetPinPullConfig(IOCON, pin_port, pin_num, IOCON_MODE_PULLDOWN);
        result = ARM_DRIVER_OK;
        break;
      case ARM_GPIO_PULL_DOWN:
        IOCON_SetPinPullConfig(IOCON, pin_port, pin_num, IOCON_MODE_PULLUP);
        result = ARM_DRIVER_OK;
        break;
      default:
        break;
    }
  }

  return result;
}

// Set GPIO Event Trigger
static int32_t GPIO_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
  uint32_t pint;
  int32_t  result = ARM_DRIVER_ERROR;

  if (pin < GPIO_MAX_PINS) {
    pint = PinIntNum[pin];
    switch (trigger) {
      case ARM_GPIO_TRIGGER_NONE:
        PINT_PinInterruptConfig(PINT, (pint_pin_int_t)pint, kPINT_PinIntEnableNone, NULL);
        result = ARM_DRIVER_OK;
        break;
      case ARM_GPIO_TRIGGER_RISING_EDGE:
        PINT_PinInterruptConfig(PINT, (pint_pin_int_t)pint, kPINT_PinIntEnableRiseEdge, NULL);
        result = ARM_DRIVER_OK;
        break;
      case ARM_GPIO_TRIGGER_FALLING_EDGE:
        PINT_PinInterruptConfig(PINT, (pint_pin_int_t)pint, kPINT_PinIntEnableFallEdge, NULL);
        result = ARM_DRIVER_OK;
        break;
      case ARM_GPIO_TRIGGER_EITHER_EDGE:
        PINT_PinInterruptConfig(PINT, (pint_pin_int_t)pint, kPINT_PinIntEnableBothEdges, NULL);
        result = ARM_DRIVER_OK;
        break;
      default:
        break;
    }
  }

  return result;
}

// Set GPIO Output Level
static void GPIO_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
  uint32_t pin_port;
  uint32_t pin_num;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    GPIO_PinWrite(GPIO, pin_port, pin_num, (uint8_t)val);
  }
}

// Get GPIO Input Level
static uint32_t GPIO_GetInput (ARM_GPIO_Pin_t pin) {
  uint32_t pin_port;
  uint32_t pin_num;
  uint32_t val = 0U;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    val = GPIO_PinRead(GPIO, pin_port, pin_num);
  }

  return val;
}


// GPIO Driver access structure
ARM_DRIVER_GPIO Driver_GPIO0 = {
  GPIO_Setup,
  GPIO_SetDirection,
  GPIO_SetOutputMode,
  GPIO_SetPullResistor,
  GPIO_SetEventTrigger,
  GPIO_SetOutput,
  GPIO_GetInput
};
