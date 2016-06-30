# HudsonDuinoLED

Started out as a Hudson build status indicator,
but can display pretty much any text that's
written to the Arduino's serial port.

## Requirements

 * Arduino
 * 8x8 LED Matrix
 * Python 3
 * PySerial (http://pythonhosted.org/pyserial/)

## Usage
 * In command terminal, run: `python Python/HudsonCompanion.py <port>`
 * Optional: URL: `python Python/HudsonCompanion.py <port> <url>`
   * Where `<url>` is a Hudson remote API XML file
