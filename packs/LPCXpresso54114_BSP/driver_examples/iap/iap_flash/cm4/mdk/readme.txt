Overview
========
The IAP Flash project is a simple demonstration program of the SDK IAP driver. It erases and programs 
a portion of on-chip flash memory. A message a printed on the UART terminal as various operations on 
flash memory are performed.

Toolchain supported
===================
- IAR embedded Workbench  8.50.9
- Keil MDK  5.33

Hardware requirements
=====================
- Micro USB cable
- LPCLPCXpresso54114 board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (J7) on the board
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.

Running the demo
================
1.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

The following lines are printed to the serial terminal when the demo program is executed.

IAP Flash example

Writing flash sector 1

Erasing flash sector 1

Erasing page 1 in flash sector 1

Entire flash signature

XXXXXXXX

End of IAP Flash Example
