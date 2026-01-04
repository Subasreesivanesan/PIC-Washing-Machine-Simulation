# Washing Machine Simulation using PicsimLab

## Overview
This is a simulation-based embedded systems learning project that models the
control logic of a washing machine using a PIC microcontroller in PicsimLab.
The focus is on understanding embedded fundamentals rather than building
a physical product.

## Key Concepts Covered
- GPIO and switch handling
- LCD interfacing (16x2)
- State-based control logic (FSM concept)
- Safety mechanism using door status
- Embedded C programming
- Simulation-based validation

## Features
- Power ON / Start control
- Program selection
- Water level selection
- Door safety logic
- LCD-based status messages

## Tools & Technologies
- PIC16F877A Microcontroller
- PicsimLab
- MPLAB X IDE
- XC8 Compiler
- Embedded C

## How It Works
Switches are used to simulate user inputs and sensors. The LCD displays the
current state of operation. The project demonstrates how control logic for
an appliance can be designed and tested in simulation before moving to
real hardware.

## Future Improvements
- Implement timer interrupts instead of delay-based logic
- Add a complete finite state machine (FSM) diagram
- Replace switches with real sensors in hardware
- Extend to Arduino / STM32 platform

## Note
This project is created purely for learning and skill development in
embedded systems. It is a simulation and not a real washing machine.
