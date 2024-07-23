### README.md

# PZEM-017 Sensor Data Reader with Arduino Mega

This project demonstrates how to read sensor data from a PZEM-017 power meter using an Arduino Mega. The data includes voltage, current, power, and energy measurements, which are displayed on an I2C LCD screen and sent to the Serial Monitor.

## Table of Contents
- [Hardware Required](#hardware-required)
- [Software Required](#software-required)
- [Wiring Diagram](#wiring-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Hardware Required
- Arduino Mega 2560
- PZEM-017 Power Meter
- [TTL to RS485](https://www.tokopedia.com/akhishop/ttl-to-rs485-converter-module-automatic-flow-direction) Converter Module
- I2C LCD (16x2)
- Jumper wires

## Software Required
- Arduino IDE
- SimpleModbusMaster library
- LiquidCrystal_I2C library

## Wiring Diagram

### Arduino Mega to PZEM-017 via TTL to RS485 Converter


#### Connections:
- **Arduino Mega** to **TTL to RS485 Converter**:
  - `TX1` (pin 18) to `DI`
  - `RX1` (pin 19) to `RO`
  - `2` to `DE` and `RE` (Connect `DE` and `RE` together)
  - `GND` to `GND`
  - `5V` to `VCC`

- **TTL to RS485 Converter** to **PZEM-017**:
  - `A` to `A`
  - `B` to `B`

- **Arduino Mega** to **I2C LCD**:
  - `SDA` (pin 20) to `SDA`
  - `SCL` (pin 21) to `SCL`
  - `GND` to `GND`
  - `5V` to `VCC`

## Installation
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the `SimpleModbusMaster` library.
3. Install the `LiquidCrystal_I2C` library.
4. Open the Arduino IDE and load the provided sketch.

## Usage
1. Connect the hardware as described in the wiring diagram.
2. Open the Arduino IDE.
3. Upload the sketch to your Arduino Mega.
4. Open the Serial Monitor to view the sensor data.


## Contributing
Feel free to contribute to this project by submitting issues or pull requests.

## License
This project is licensed under the MIT License.

### Wiring Diagram
![Wiring Diagram](./wiring_diagram.png)

#### Notes:
- Ensure proper connections between the Arduino Mega, TTL to RS485 converter, and the PZEM-017 module.
- The `TxEnablePin` is used to toggle the receive/transmit pin on the RS485 driver. Adjust it if necessary based on your setup.

By following this guide, you should be able to successfully read data from a PZEM-017 power meter using an Arduino Mega, display the data on an LCD screen, and monitor it via the Serial Monitor. This project can help many people in monitoring and managing their power consumption effectively.