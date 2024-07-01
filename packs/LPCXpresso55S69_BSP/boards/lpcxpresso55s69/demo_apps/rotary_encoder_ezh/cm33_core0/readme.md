Overview
========
The rotary encoder ezh demo application provides introduction for Quad encode interface of LPC5500.
The direction and counter can be got from the signals of phaseA and phaseB of encoder sensor.
Rotary Y click carries a 15-pulse incremental rotary encoder with detents, surrounded by a ring of 16 yellow LEDs.
The encoder signal can be analyzed by QEI of LPC5500. Along with the rotation, LED lights in different positions can be lit.

SDK version
===========
- Version: 2.15.000

Toolchain supported
===================
- Keil MDK  5.38.1

Hardware requirements
=====================
- Mini/micro USB cable
- LPCXpresso55s69 board
- Personal Computer
- ROTARY Y Click board(could be purchased from the website: https://www.mikroe.com/rotary-y-click)

Board settings
==============
The jumper setting:
    Default jumpers configuration does not work,  you will need to add JP20 and JP21 (JP22 optional for ADC use)

Prepare the Demo
================
1.  Connect the ROTARY Y Click board and EVK board.
2.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (P6) on the board
3.  Open a serial terminal with the following settings:
    - 512000 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo. 


Running the demo
================
Four LEDs will be lit. 
Rotate the handle on the ROTARY Y Click.
The log below shows the output of the hello world demo in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
QEI demo.
When the QEI state changes,the counter and direction will be got.
Push the WAKEUP button on LPCXpresso55s69 board to change the LED display model.

Counter: 1 
Direction:Clockwise 

Counter: 2 
Direction:Clockwise 

Counter: 3 
Direction:Clockwise 

Counter: 4 
Direction:Clockwise
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
