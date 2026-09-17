# IoT-Based Smart Energy Meter

## Project Description

Developed an IoT-based Smart Energy Meter using ESP32 to monitor voltage, current, power, and energy consumption. The project was designed and tested using Wokwi simulation and connected to the Blynk IoT platform for real-time monitoring through a mobile dashboard.

## Features

- Voltage measurement
- Current measurement
- Power calculation
- Energy consumption calculation in kWh
- Real-time Blynk dashboard monitoring
- ESP32-based IoT simulation

## Technologies Used

- ESP32
- Wokwi
- Blynk IoT
- Arduino IDE
- C/C++

## Working Principle

Two potentiometers are used in the Wokwi simulation to represent voltage and current inputs. The ESP32 reads these analog values and calculates power using:

Power = Voltage × Current

The energy consumption is calculated over time and displayed in kilowatt-hours (kWh). The measured values are sent to the Blynk IoT dashboard using virtual pins.

## Project Type

Online simulation-based IoT project developed using Wokwi and Blynk IoT.
