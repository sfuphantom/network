# Data Acquisition

A Network repository for the Data Acquisition (DAQ) board for Team Phantom.

## Network Subteam CAN Implementation

This Repository features the in-development CAN interface implementation for the ESP32 DAQ model. Main driver files are located in `/lib/CanDriver/`,
The `CanInnit()` function is crucial for properly setting up the CAN connection, refer to the comments and documentation for the correct usage.
Implementation using the built-in ESP32 CAN driver : [official documentation](https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-reference/peripherals/can.html).

## VSCode

To ensure that VSCode recognizes the Arduino include paths, open the `DAQ_FW` folder.

<!-- TODO: Update readme.md -->

## Archived project

The original DAQ project was developed in Python for the Raspberry Pi 4. Due to supply shortages, the project switched to an ESP32 microcontroller. The codebase for the original project can be found in this branch: https://github.com/sfuphantom/DAQ/tree/RaspberryPi-Archive-2021
