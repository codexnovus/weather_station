#include <Wire.h>
#include <SD.h>
#include <FS.h>
#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <SPIFFS.h>
#include <SimpleDHT.h>

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
  DH11
   1-wire IF    DATA  --> GPIO0  (D0)
*/

#define EPAPER_DC   22
#define EPAPER_CS   5
#define EPAPER_RST  21
#define EPAPER_BUSY 4
#define SD_CS 2
#define DHT_DATA 0
#define DEBUG false

byte dht11Temp, dht11Hum;

GxIO_Class io(SPI, EPAPER_CS, EPAPER_DC, EPAPER_RST);
GxEPD_Class display(io, EPAPER_RST, EPAPER_BUSY);

#include <graphRoutines.h>
#include <wififgx.h>
#include <temperatura27.h>
#include <Chicago9.h>
#include <Monaco7.h>
const GFXfont* font_chicago9  = &chicago9;
const GFXfont* font_monaco7   = &monaco7;
const GFXfont* font_tempera27 = &temperatura27;

// UI Drawing routines
#include <part_UI.h>
// SD Card Interface
#include <part_SD.h>
// Read the DHT11 temperature sensor
#include <part_DHT.h>



void setup() {
  Serial.begin(115200);
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
  }
  initSD();
  initScreen();
}

void loop() {
  readDHT();
  drawStatusBar();
  drawTime();
  drawToday();
  drawTemp();
  drawTomorrow();
  display.updateWindow(0,0,400,300);
  delay(10000);
};