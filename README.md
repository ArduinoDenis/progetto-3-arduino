# RFID Card Reader with LED and Relay Control

This Arduino sketch allows you to control an LED or switch a relay when a magnetic card is detected by an RFID reader. If the card is recognized, a green LED lights up and the relay switches, otherwise, a red LED indicates inaccessibility.

## Pinout:

| RC522 Module Pin | Uno/Nano Pin |
|------------------|--------------|
| SDA              | D10          |
| SCK              | D13          |
| MOSI             | D11          |
| MISO             | D12          |
| IRQ              | N/A          |
| GND              | GND          |
| RST              | D9           |
| 3.3V             | 3.3V         |

- Green LED connected to Pin 3
- Red LED connected to Pin 4
- Relay connected to Pin 2

## Installation:

1. Connect the RC522 module according to the provided pinout.
2. Upload the sketch to your Arduino board.

## Usage:

1. Pass a magnetic card over the RFID reader.
2. If the card is recognized, the green LED lights up, and the relay switches for a brief period.
3. If the card is not recognized, the red LED indicates inaccessibility.

## Installation of RFID Library:

The `RFID.zip` file is a library that should be placed in the following directory: `Documents\Arduino\libraries\paste here`.

## Version 1.0 - 2024-02-18

- Initial release.
- Implemented functionality to read RFID cards and control LEDs and relay accordingly.

## License:

This project is licensed under the [MIT License](LICENSE).
