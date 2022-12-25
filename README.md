# PICO-PIO-74HC165

An implementation using PICOs programmable input/output block (PIO) to connect to 
SN74HC165 8-bit parallel-load shift registers device.

If you are also interested in its output counterpart have a look at [PICO-PIO-74HC595](https://github.com/Gerhard-Vienna/PICO-PIO-74HC595)

It supports chains of up to 4 devices.

As soon as an imput on a device changes it's state, the state of all inputs it written to the PIOs RX-Fifo.
See the included file main.cpp for an example

## How to use in your application:
1. Copy sn74165.pio into the directory that holds your applications 
2. Add:
	#include "sn74165.pio.h"
to your code.
3. Add the line:
	pico_generate_pio_header(test ${CMAKE_CURRENT_LIST_DIR}/sn74165.pio)
to the CMakeLists.txt file

## How to build the example (main.cpp):

1. Follow the instructions in [Getting started with Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf): 
"Chapter 8. Creating your own Project" to create a directory for your project.
2. Copy main.cpp, sn74165.pio and CMakeLists.txt from this repository into the newly created directory.
3. Copy the pico_sdk_import.cmake file from the external folder in your pico-sdk installation to your project directory.
4. Create the build subfolder, cd into it 
5. run "cmake .." followed by "make"


