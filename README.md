# Bluetooth & Voice Controlled Car

A wireless robotic car controlled through Bluetooth commands sent from a smartphone application. The system uses an Arduino Nano as the main controller, an HC-05 Bluetooth module for wireless communication, and an L298N motor driver to control four BO gear motors.

## Features:

- Wireless control through Bluetooth
- Voice-based movement commands through a smartphone application
- Forward movement
- Backward movement
- Left movement
- Right movement
- Stop control
- Four-wheel drive using BO gear motors

## Components Used:

- Arduino Nano
- HC-05 Bluetooth Module
- L298N Motor Driver
- 4 × BO Gear Motors
- 4 × Lithium-Ion Cells
- Robot Car Chassis
- Smartphone with Bluetooth control application

## System Architecture:

                 Smartphone
                     |
              Voice / Control
                 Commands
                     |
                     v
                HC-05 Bluetooth
                     |
                  RX / TX
                     |
                     v
                Arduino Nano
                     |
              Motor Control
                 Signals
                     |
                     v
               L298N Driver
                     |
            +--------+--------+
            |                 |
            v                 v
       BO Gear Motors    BO Gear Motors

## Working Principle:

The car is controlled using a Bluetooth-enabled smartphone application. The user sends movement commands such as Forward, Backward, Left, Right, and Stop from the application.

The HC-05 Bluetooth module receives the commands and communicates them to the Arduino Nano through the hardware serial RX/TX interface.

The Arduino Nano processes the received command and generates the required control signals for the L298N motor driver. The motor driver then controls the four BO gear motors to produce the required movement.

## Communication Flow:
Smartphone App
      ↓
Bluetooth Communication
      ↓
HC-05 Module
      ↓
Arduino Nano
      ↓
L298N Motor Driver
      ↓
4 × BO Gear Motors

## Hardware Communication:

The HC-05 Bluetooth module communicates with the Arduino Nano through its hardware serial RX/TX interface. Commands received wirelessly from the smartphone are processed by the Arduino and converted into motor-control operations.

## Power Supply:

The system is powered using four lithium-ion cells.

## Project Status:

Completed as an embedded systems and wireless communication project.

## Technologies Used:

Arduino
Bluetooth Communication
Serial Communication
Embedded C/C++
Motor Control
