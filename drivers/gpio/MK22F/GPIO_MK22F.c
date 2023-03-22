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
 * $Date:        20. March 2023
 * $Revision:    V1.0
 *
 * Project:      GPIO Driver for Kinetis K22F
 */

#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_gpio_ex.h"
#include "fsl_port.h"
#include "fsl_port_ex.h"

#include "GPIO_MK22F.h"


// Pin mapping
//   0 ..  31: PORTA 0..31
//  32 ..  63: PORTB 0..31
//  64 ..  91: PORTC 0..31
//  96 .. 127: PORTD 0..31
// 128 .. 159: PORTE 0..31

#define GPIO_MAX_PORTS          5U
#define GPIO_MAX_PINS           160U

#if   defined(CPU_MK22FN512VDC12)
// Pin mapping: XFBGA 121 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x200FFC3FU,  // PORTA  0.. 5, 10..19, 29
  0x00FF0FCFU,  // PORTB  0.. 3,  6..11, 16..23
  0x000FFFFFU,  // PORTC  0..19
  0x0000FFFFU,  // PORTD  0..15
  0x0700007FU   // PORTE  0.. 6, 24..26
};

#elif defined(CPU_MK22FN256VDC12)
// Pin mapping: XFBGA 121 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x000FF03FU,  // PORTA  0.. 5, 12..19
  0x00FF0FCFU,  // PORTB  0.. 3,  6..11, 16..23
  0x000FFFFFU,  // PORTC  0..19
  0x000000FFU,  // PORTD  0.. 7
  0x0700007FU   // PORTE  0.. 6, 24..26
};

#elif defined(CPU_MK22FN128VDC10)
// Pin mapping: XFBGA 121 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x000FF03FU,  // PORTA  0.. 5, 12..19
  0x00FF0F0FU,  // PORTB  0.. 3,  8..11, 16..23
  0x0007FFFFU,  // PORTC  0..18
  0x000000FFU,  // PORTD  0.. 7
  0x0700007FU   // PORTE  0.. 6, 24..26
};

#elif defined(CPU_MK22FN512VLL12) || \
      defined(CPU_MK22FN256VLL12) || \
      defined(CPU_MK22FN128VLL10)
// Pin mapping: LQFP 100 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x000FF03FU,  // PORTA  0.. 5, 12..19
  0x00FF0E0FU,  // PORTB  0.. 3,  9..11, 16..23
  0x0007FFFFU,  // PORTC  0..18
  0x000000FFU,  // PORTD  0.. 7
  0x0700007FU   // PORTE  0.. 6, 24..26
};

#elif defined(CPU_MK22FN512VFX12)
// Pin mapping: QFN 88 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x000FF03FU,  // PORTA  0.. 5, 12..19
  0x000F0FCFU,  // PORTB  0.. 3,  6..11, 16..19
  0x000FF1FFU,  // PORTC  0.. 8, 12..19
  0x000000FFU,  // PORTD  0.. 7
  0x0000007FU   // PORTE  0.. 6
};

#elif defined(CPU_MK22FN512CAP12)
// Pin mapping: WLCSP 80 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x000FF03FU,  // PORTA  0.. 5, 12..19
  0x000F0C0FU,  // PORTB  0.. 3, 10..11, 16..19
  0x00030FFFU,  // PORTC  0..11, 16..17
  0x000000FFU,  // PORTD  0.. 7
  0x0000003FU   // PORTE  0.. 5
};

#elif defined(CPU_MK22FN512VLH12) || \
      defined(CPU_MK22FN256VLH12) || \
      defined(CPU_MK22FN128VLH10) || \
      defined(CPU_MK22FN512VMP12) || \
      defined(CPU_MK22FN256VMP12) || \
      defined(CPU_MK22FN128VMP10) || \
      defined(CPU_MK22FN256CAH12) || \
      defined(CPU_MK22FN128CAH12)
// Pin mapping: LQFP/MAPBGA/WLSCP 64 package
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0x000C303FU,  // PORTA  0.. 5, 12..13, 18..19
  0x000F000FU,  // PORTB  0.. 3, 16..19
  0x00000FFFU,  // PORTC  0..11
  0x000000FFU,  // PORTD  0.. 7
  0x0000003FU   // PORTE  0.. 1
};

#else
// Pin mapping: default (all pins)
static const uint32_t PinMapping[GPIO_MAX_PORTS] = {
  0xFFFFFFFFU,  // PORTA  0..31
  0xFFFFFFFFU,  // PORTB  0..31
  0xFFFFFFFFU,  // PORTC  0..31
  0xFFFFFFFFU,  // PORTD  0..31
  0xFFFFFFFFU   // PORTE  0..31
};
#endif


// Default Pin Configuration
static const port_pin_config_t DefaultPinConfig = {
  .pullSelect = kPORT_PullDisable,
  .slewRate = kPORT_FastSlewRate,
  .passiveFilterEnable = kPORT_PassiveFilterDisable,
  .openDrainEnable = kPORT_OpenDrainDisable,
  .driveStrength = kPORT_LowDriveStrength,
  .mux = kPORT_MuxAsGpio,
  .lockRegister = kPORT_UnlockRegister
};

// PORTx IRQ Numbers
static IRQn_Type const PortIRQn[GPIO_MAX_PORTS] = {
  PORTA_IRQn, PORTB_IRQn, PORTB_IRQn, PORTD_IRQn, PORTE_IRQn
};

// PORTx Base Pointers
static PORT_Type * const PortBase[GPIO_MAX_PORTS] = {
  PORTA, PORTB, PORTC, PORTD, PORTE
};

// GPIOx Base Pointers
static GPIO_Type * const GPIOBase[GPIO_MAX_PORTS] = {
  GPIOA, GPIOB, GPIOC, GPIOD, GPIOE
};

// Clock IP Names
static clock_ip_name_t const ClockIP[GPIO_MAX_PORTS] = {
  kCLOCK_PortA, kCLOCK_PortB, kCLOCK_PortC, kCLOCK_PortD, kCLOCK_PortE
};


// Signal Event callback functions
static ARM_GPIO_SignalEvent_t SignalEvent[GPIO_MAX_PORTS][32];


// Common PORTx IRQ Handler
static void PORTx_IRQHandler (uint32_t num) {
  PORT_Type *port = PortBase[num];
  uint32_t   ifsr;
  uint32_t   irqc;
  uint32_t   event;
  uint32_t   i;

  ifsr = PORT_GetPinsInterruptFlags(port);
  for (i = 0U; i < 32U; i++) {
    if (ifsr & (1U << i)) {
      if (SignalEvent[num][i] != NULL) {
        irqc = (PORT_GetPinConfig(port, i) & PORT_PCR_IRQC_MASK) >> PORT_PCR_IRQC_SHIFT;
        switch (irqc) {
          case kPORT_InterruptRisingEdge:
            event = ARM_GPIO_EVENT_RISING_EDGE;
            break;
          case kPORT_InterruptFallingEdge:
            event = ARM_GPIO_EVENT_FALLING_EDGE;
            break;
          case kPORT_InterruptEitherEdge:
            event = ARM_GPIO_EVENT_EITHER_EDGE;
            break;
          default:
            event = 0U;
            break;
        }
        if (event != 0U) {
          SignalEvent[num][i]((num << 5) | i, event);
        }
      }
    }
  }
  PORT_ClearPinsInterruptFlags(port, ifsr);
}

// PORTA IRQ Handler
void PORTA_IRQHandler (void) {
  PORTx_IRQHandler(0U);
}

// PORTB IRQ Handler
void PORTB_IRQHandler (void) {
  PORTx_IRQHandler(1U);
}

// PORTC IRQ Handler
void PORTC_IRQHandler (void) {
  PORTx_IRQHandler(2U);
}

// PORTD IRQ Handler
void PORTD_IRQHandler (void) {
  PORTx_IRQHandler(3U);
}

// PORTE IRQ Handler
void PORTE_IRQHandler (void) {
  PORTx_IRQHandler(4U);
}


// Setup GPIO Interface
static int32_t GPIO_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
  PORT_Type *port;
  GPIO_Type *gpio;
  uint32_t   pin_port;
  uint32_t   pin_num;
  int32_t    result = ARM_DRIVER_OK;

  pin_port = pin >> 5U;
  pin_num  = pin & 0x1FU;
  if ((PinMapping[pin_port] & (1U << pin_num)) != 0U) {
    port = PortBase[pin_port];
    gpio = GPIOBase[pin_port];
    CLOCK_EnableClock(ClockIP[pin_port]);
    PORT_SetPinInterruptConfig(port, pin_num, kPORT_InterruptOrDMADisabled);
    GPIO_PinSetDirection(gpio, pin_num, kGPIO_DigitalInput);
    PORT_SetPinConfig(port, pin_num, &DefaultPinConfig);
    if (cb_event != NULL) {
      SignalEvent[pin_port][pin_num] = cb_event;
      NVIC_EnableIRQ(PortIRQn[pin_port]);
    }
  } else {
    result = ARM_GPIO_ERROR_PIN;
  }

  return result;
}

// Set GPIO Direction
static int32_t GPIO_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
  GPIO_Type *gpio;
  uint32_t   pin_port;
  uint32_t   pin_num;
  int32_t    result = ARM_DRIVER_OK;

  pin_port = pin >> 5U;
  pin_num  = pin & 0x1FU;
  if ((PinMapping[pin_port] & (1U << pin_num)) != 0U) {
    gpio = GPIOBase[pin_port];
    switch (direction) {
      case ARM_GPIO_INPUT:
        GPIO_PinSetDirection(gpio, pin_num, kGPIO_DigitalInput);
        break;
      case ARM_GPIO_OUTPUT:
        GPIO_PinSetDirection(gpio, pin_num, kGPIO_DigitalOutput);
        break;
      default:
        result = ARM_DRIVER_ERROR_PARAMETER;
        break;
    }
  } else {
    result = ARM_GPIO_ERROR_PIN;
  }
 
  return result;
}

// Set GPIO Output Mode
static int32_t GPIO_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
  PORT_Type *port;
  uint32_t   pin_port;
  uint32_t   pin_num;
  int32_t    result = ARM_DRIVER_OK;

  pin_port = pin >> 5U;
  pin_num  = pin & 0x1FU;
  if ((PinMapping[pin_port] & (1U << pin_num)) != 0U) {
    port = PortBase[pin_port];
    switch (mode) {
      case ARM_GPIO_PUSH_PULL:
        PORT_EnablePinOpenDrain(port, pin_num, false);
        break;
      case ARM_GPIO_OPEN_DRAIN:
        PORT_EnablePinOpenDrain(port, pin_num, true);
        break;
      default:
        result = ARM_DRIVER_ERROR_PARAMETER;
        break;
    }
  } else {
    result = ARM_GPIO_ERROR_PIN;
  }
 
  return result;
}

// Set GPIO Pull Resistor
static int32_t GPIO_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
  PORT_Type *port;
  uint32_t   pin_port;
  uint32_t   pin_num;
  int32_t    result = ARM_DRIVER_OK;

  pin_port = pin >> 5U;
  pin_num  = pin & 0x1FU;
  if ((PinMapping[pin_port] & (1U << pin_num)) != 0U) {
    port = PortBase[pin_port];
    switch (resistor) {
      case ARM_GPIO_PULL_NONE:
        PORT_SetPinPullConfig(port, pin_num, kPORT_PullDisable);
        break;
      case ARM_GPIO_PULL_UP:
        PORT_SetPinPullConfig(port, pin_num, kPORT_PullUp);
        break;
      case ARM_GPIO_PULL_DOWN:
        PORT_SetPinPullConfig(port, pin_num, kPORT_PullDown);
        break;
      default:
        result = ARM_DRIVER_ERROR_PARAMETER;
        break;
    }
  } else {
    result = ARM_GPIO_ERROR_PIN;
  }
 
  return result;
}

// Set GPIO Event Trigger
static int32_t GPIO_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
  PORT_Type *port;
  uint32_t   pin_port;
  uint32_t   pin_num;
  int32_t    result = ARM_DRIVER_OK;

  pin_port = pin >> 5U;
  pin_num  = pin & 0x1FU;
  if ((PinMapping[pin_port] & (1U << pin_num)) != 0U) {
    port = PortBase[pin_port];
    switch (trigger) {
      case ARM_GPIO_TRIGGER_NONE:
        PORT_SetPinInterruptConfig(port, pin_num, kPORT_InterruptOrDMADisabled);
        break;
      case ARM_GPIO_TRIGGER_RISING_EDGE:
        PORT_SetPinInterruptConfig(port, pin_num, kPORT_InterruptRisingEdge);
        break;
      case ARM_GPIO_TRIGGER_FALLING_EDGE:
        PORT_SetPinInterruptConfig(port, pin_num, kPORT_InterruptFallingEdge);
        break;
      case ARM_GPIO_TRIGGER_EITHER_EDGE:
        PORT_SetPinInterruptConfig(port, pin_num, kPORT_InterruptEitherEdge);
        break;
      default:
        result = ARM_DRIVER_ERROR_PARAMETER;
        break;
    }
  } else {
    result = ARM_GPIO_ERROR_PIN;
  }
 
  return result;
}

// Set GPIO Output Level
static void GPIO_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
  GPIO_Type *gpio;
  uint32_t   pin_port;
  uint32_t   pin_num;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    gpio = GPIOBase[pin_port];
    GPIO_PinWrite(gpio, pin_num, (uint8_t)val);
  }
}

// Get GPIO Input Level
static uint32_t GPIO_GetInput (ARM_GPIO_Pin_t pin) {
  GPIO_Type *gpio;
  uint32_t   pin_port;
  uint32_t   pin_num;
  uint32_t   val = 0U;

  if (pin < GPIO_MAX_PINS) {
    pin_port = pin >> 5U;
    pin_num  = pin & 0x1FU;
    gpio = GPIOBase[pin_port];
    val = GPIO_PinRead(gpio, pin_num);
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
