# Bill of Materials for Shield Board

| Schematic Label |  Component | Description | LCSC Part |
| --- | --- | --- | --- |
| C1 | 220nF C0805 | | C5378 |
| C2,C5,C6 | 10nF C0805 | | C1710 |
| C3,C8,C9,C10,C11,C12,C13,C14 | 100nF C0805 | | C49678 |
| C4,C7 | 10uF C0805 | | C15850 |
| D1 | B5819W | Protection diode | C8598 |
| LED1, LED2 | LED0805 | Current part is Red | C84256 |
| Q1, Q2 | S8050 | NPN Transistor | C2146 |
| R1,R2,R3 | 10kΩ R0805 | | C17414 |
| R4,R5,R6,R7,R13 |2kΩ R0805 | | C17604 |
| R8,R9,R10,R11,R12 | 3.3kΩ R0805 | | C26010 |
| SW1, SW2, SW3 | PTS645VH39-2LFS | Right Angle TH Tactile Switch | C221887 |
| U1 | ESP32-WROOM-32DC | | C473013 |
| U2 | AMS1117-3.3 | LDO Voltage Regulator | C6186 |
| U3 | CP2102-GMR | USB-to-UART bridge | C6568 |
| U4 | SHTC3 | I2C Temperature sensor | C194656 |
| U5 | SN74LVC125APWR | Bus Transceiver | C7813 |
| H1,H2 | BBL-108-G-E | Low Profile Male 2.54mm 1x8 Header | Mouser: 200-BBL108GE |
| H3 | CES-104-02-T-S-RA | Right angle Female 2.54 1x8 Housing | Mouser: 200-SSQ10404SSRA |
| H4 | SSQ-107-02-T-D-RA | Right angle Female 2.54 2x7 Housing | Mouser: 200-SSQ10702TDRA |
| USB1 | 10118194-0001LF | Micro USB B Female Connector | C132563 |
| SDCARD2 | TF-15×15 | MicroSD Housing w/ ejector | C111196 |



---
## Notes 

LCSC does not offer low profile Headers, but with normal profile the space between the screen and the board is quite large. I put references for SAMTEC low profile headers, that are not expensive, but any 2.54mm pitch appropiate header can be used without issue.

* H1,H2: Only one is needed (solder the one that matches your preferred board orienation). It is meant to mate with Samtec Low profile Female header SLW-108-01-T-S. 
* H3: Can be replaced by TSW-104-08-T-S-RA (Right Angle Male Header), Mouser Part: 200-TSW10408TSRA
* H4: Can be replaced by TSW-107-08-T-D-RA (Right Angle Male Header), Mouser Part: 200-TSW10708TDRA

