# Changelog:
**2.2**
* Reorganized the board layout. 
  * Now the ESP32 is at the bottom, leaving more space in the top for user-interactive elements.
  * The buttons are now on the same side of the top, and with added margin to the mounting holes.
  * The I2C header is now on the top too, as are the leds.
  * Moved the expansion port to the bottom left of the board, and the SDCard to the bottom right.
* Made more GPIOs available on the extension header after confirming with the datasheet they did not conflict with flash

**2.1:**
* Fixed positioning of the front-facing screen header
* Changed I2C pins as they conflicted with ESP32 flash boot
* Changed BME680 for SHT3 because for pricing and source code availability reasons

**2.0:**
* Initial design