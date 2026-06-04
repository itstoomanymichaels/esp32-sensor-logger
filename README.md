# ESP32 Environmental Sensor Logger

A firmware project for the ESP32 that reads temperature and humidity 
from a DHT22 sensor and logs data over serial. Built in C++ using 
PlatformIO and the Arduino framework.

Once a configured temperature threshold is exceeded, the ESP32 alerts 
the user by driving an LED on GPIO2.

## Hardware
- ESP32 DevKitC
- DHT22 temperature/humidity sensor
- 220Ω Resistor
- LED
- Breadboard + jumper wires

## Wiring

| Component | Component Pin | ESP32 Pin |
|-----------|--------------|-----------|
| DHT22     | VCC          | 3.3V      |
| DHT22     | GND          | GND       |
| DHT22     | DATA         | GPIO4     |
| LED       | Anode (+)    | GPIO2     |
| LED       | Cathode (-)  | GND (via 220Ω resistor) |

## Software
- Build: PlatformIO
- Framework: Arduino
- Libraries: Adafruit DHT Sensor Library Vers. 1.4.7

## How to Build and Flash
1. Clone the repo  
   git clone https://github.com/itstoomanymichaels/esp32-sensor-logger.git

2. Open the project folder in PlatformIO

3. Build and upload  
   To build, click the check icon at the bottom of PlatformIO.  
   To upload, click the right arrow icon to the immediate right of the build icon.

4. Open serial monitor at 115200 baud to view output  
   Click the plug icon at the bottom of PlatformIO.  
   Baud rate is set to 115200.

## Demo
[Watch the demo on YouTube](https://youtu.be/5R83eLjjO_A)
