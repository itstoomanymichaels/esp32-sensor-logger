# ESP32 Environmental Sensor Logger

A firmware project for the ESP32 that reads temperature and humidity 
from a DHT22 sensor and logs data over serial. Built in C++ using 
PlatformIO and the Arduino framework.

## Hardware
- ESP32 DevKitC
- DHT22 temperature/humidity sensor
- LEDs + resistors
- Breadboard + jumper wires

## Features
- [ ] Serial logging of temperature and humidity every 5 seconds
- [ ] LED threshold alert (visual indicator when temp exceeds limit)
- [ ] Clean sensor data struct with validity flag

## Setup
1. Install PlatformIO in VS Code
2. Clone this repo
3. Open in PlatformIO and flash to ESP32

## What I learned
- Embedded C fundamentals: pointers, structs, bit manipulation
- GPIO control and serial communication
- Hardware interrupt handling

## Demo
(Video coming soon)
