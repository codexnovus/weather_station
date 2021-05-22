# Bill of Materials for Shield Board

**Note:** Mouser part number and amazon links only for reference. Except for the AZ Delivery ESP32 Kit, the rest of the parts can be substituted by equivalents. I get no comission from either of them. If you don't mind making it more permanent you can skip the headers and solder the components directly onto the board.

## Soldered on Board

| Schematic Label | Board Label | Component | Notes | Mouser Ref |
| --- | --- | --- | --- | --- |
| H1 | Screen | Male Header 2.54mm pitch 1x8 | Must be mounted pointing below the board | 649-1012937890801BLF |
| H2 | SDCard | Female Header 2.54mm pitch 1x6 | | 437-3108710641001101 |
| H3 | I2C | Female Header 2.54mm pitch 1x4 | | 437-3108310441001101 |
| H4 | Expansion | Female Header 2.54mm pitch 2x7 | Optional | 200-CES10701TD |
| USER | USER/G15| 6mm Tactile Button Switch, TH | Optional | 706-95C06B3T |
| C3 | 100nF | 100nF ceramic capacitor | Optional | 594-K104K15X7RF53H5 |
| U1 | ESP32 | 2x Female Header 2.54mm pitch 1x19 | 1x19 headers are difficult to find cheap so you can either clip a 1x20 header or solder it completely. I added an extra hole for that. | 437-3108711941001101 |

## Mounted on Board
| Mount Location | Component Description | Where to get it? |
| --- | --- |---|
| Screen | Waveshare 4.2 inch 400x300 e-ink with embedded controller | [Amazon](www.amazon.es/Module-Resolution-Electronic-Controller-Communicating/dp/B074NR1SW2/) |
| SDCard | AZDelivery SPI Reader for Arduino | [Amazon](www.amazon.es/azdelivery-Reader-Tarjeta-memoria-Arduino/dp/B06X1DX5WS/) |
| I2C | Dollatek SHTC3 Digital Temperature Kit | [Amazon](www.amazon.es/DollaTek-medición-precisión-Temperatura-comunicación/dp/B081JMRLD8/)
| ESP32 | AZDelivery ESP32 Dev Kit C V4 | [Amazon](www.amazon.es/AZDelivery-NodeMCU-desarollo-versión-incluido/dp/B08BTS62L7) |