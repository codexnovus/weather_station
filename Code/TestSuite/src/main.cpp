// CONFIGURATION FLAGS
// Set it to false to disable testing for...
#define USE_EPAPER true  // the e-ink screen
#define USE_SD     true  // the sd card
#define USE_SHT    false  // the temperature sensor
#define USE_SW     true  // the gpio switches


// Ideally, you don't need to touch anything below that

/* Device map
   DEVICE PORT  NAME  --> BUS     PIN
  EPAPER                  
   Data In      DIN   --> VSPID   (D23)
   Data Clock   CLK   --> VSPICLK (D18)
   Chip Select  CS    --> VSPICS0 (D5)
   Data/Command DC    --> VSPIWP  (D22)
   Reset        RST   --> VSPIHD  (D21)
   Busy         BUSY  --> GPIO4   (D4)
  SD CARD
   Chip Select  CS    --> GPIO2   (D2)
   Data Clock   SCK   --> VSPICLK (D18)
   Data Out     MOSI  --> VSPID   (D23)
   Data In      MISO  --> VSPIQ   (D19)
  I2C
   I2C Data     SDA   --> IO16    (D16)
   I2C Clock    SCL   --> IO17    (D17)
  USER INPUTS
   BOOT         BOOT  --> BOOT    (D0)
   USER         USER  --> IO15    (D15)
*/
#if USE_EPAPER
#define EPAPER_DC  22
#define EPAPER_CS   5
#define EPAPER_RST 21
#define EPAPER_BSY  4
#endif
#if USE_SD
#define SD_CS       26
#endif
#if USE_SW
#define SW_BOOT     0
#define SW_USER    15
#endif
#if USE_SHT
#define I2C_SCL    17
#define I2C_SDA    16
#endif
 

// Libraries
#include <Arduino.h>
#include <Wire.h>

#if USE_EPAPER
#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <temperatura27.h>
#include <Monaco7.h>

GxIO_Class io(SPI, EPAPER_CS, EPAPER_DC, EPAPER_RST);
GxEPD_Class display(io, EPAPER_RST, EPAPER_BSY);

const GFXfont* font_monaco      = &monaco7;
const GFXfont* font_temperatura = &temperatura27;
byte refreshCount = 0;
#endif

#if USE_SD
#include <SD.h>
#include <FS.h>
#endif

#if USE_SHT
#include "SparkFun_SHTC3.h"
byte TempSensorT = 0;
byte TEMPSensorH = 0;
#endif


void setup() {
  Serial.begin(115200);
  Serial.println("Test program initialization start.");

  #if USE_SD
  SD.begin(SD_CS);
  if(!SD.begin(SD_CS)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }
  Serial.println("SD Card initialized.");
  #endif

  #if USE_EPAPER
  display.init();
  display.eraseDisplay(); 
  display.update();
  #endif
  Serial.println("Epaper initialized. Should have been a brief flashing on the screen as it redrawed.");

  #if USE_SHT
  Wire.begin(I2C_SDA,I2C_SCL);
  SHTC3 TempSensor;
  #endif
  Serial.println("I2C and temperature Sensor libraries loaded.");

  

  #if USE_SW
  pinMode(SW_BOOT, INPUT_PULLUP);
  pinMode(SW_USER, INPUT_PULLUP);
  #endif
  Serial.println("Buttons initialized. Starting main loop.");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}