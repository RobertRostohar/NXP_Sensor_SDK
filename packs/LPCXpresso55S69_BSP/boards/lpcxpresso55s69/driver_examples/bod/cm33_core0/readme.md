Overview
========
The bod example shows how to use LPC BOD(Brown-out detector) in the simplest way.
To run this example, user should remove the jumper for the power source selector,
and connect the adjustable input voltage to the MCU's Vin pin.
If the input voltage of the Vin pin is lower than the threshold voltage, the BOD interrupt
will be asserted.

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
- Mini/micro USB cable
- LPCXpresso55S69 board
- Personal Computer

Board settings
==============
Remove jumper for P4, connect the external input voltage to P4_2.

Prepare the Demo
================
Note: MCUXpresso IDE project default debug console is semihost
1.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (P6) on the board
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The log below shows the output of the BOD demo in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BOD INTERRUPT EXAMPLE.
Please adjust input voltage low than 2.0V to trigger BOD interrupt.

BOD interrupt occurred, input voltage is low than 2.0V.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
