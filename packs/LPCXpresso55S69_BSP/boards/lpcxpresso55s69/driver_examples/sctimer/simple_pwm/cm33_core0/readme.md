Overview
========
The SCTimer project is a simple demonstration program of the SDK SCTimer's driver capabiltiy to generate PWM signals.
The SCTimer project enables a 32-bit counter to output two center-aligned PWM signals with parameters set to 24kHz frequency.
The duty cycles of the two PWM signals are 50% and 20%, respectively.

SDK version
===========
- Version: 2.15.000

Toolchain supported
===================
- IAR embedded Workbench  9.40.1
- Keil MDK  5.38.1
- GCC ARM Embedded  12.2

Hardware requirements
=====================
- Micro USB cable
- LPCXpresso55s69 board
- Personal Computer

# Board settings

```
Output signal		Board location
SCT0_OUT2    		P18-11
SCT0_OUT6    		P18-13 
```

# Prepare the Demo
Note: MCUXpresso IDE project default debug console is semihost
1.  Connect a micro USB cable between the host PC and the LPC-Link USB port (P6) on the target board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The log below shows example output of the SCTimer driver simple PWM demo in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SCTimer example to output 2 center-aligned PWM signals

Probe the signal using an oscilloscope
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You'll see center-aligned PWM signals on P18_11 and P18_13 using an oscilloscope. 
