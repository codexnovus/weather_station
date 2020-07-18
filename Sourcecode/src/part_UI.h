
// Display element sizes
//const int wifiContX   =   0, wifiContY  =   0, wifiContW  = 400, wifiContH  =  20; // Wifi topbar
//const int hourContX   =   7, hourContY  =  24, hourContW  =  90, hourContH  = 100; // Calendar item
const int todayContX  = 123, todayContY =  50, todayContW = 181, todayContH = 190; // Today's Weather Image
const int toda2ContX  =   0, toda2ContY = 130, toda2ContW = 100, toda2ContH = 110; // Today's Weather Info
const int leftTempX   =   2, 
          centerTempX = 137,
          rightTempX  = 271, tempContY  = 248, tempContW  = 124, tempContH  =  48; // Temperature Widgets
const int tomorTopY   =  25,
          tomorMidY   =  98,
          tomorBotY   = 172, tomorContX = 320, tomorContW =  70, tomorContH =  70; // Tomorrow's weather Widgets

// Display element sizes
// Top bar (wifi display)
#define wifiContX 0
#define wifiContY 0
#define wifiContW 400
#define wifiContH 20
// Calendar
#define hourContX 7
#define hourContY 24
#define hourContW 90
#define hourContH 100

// const byte wifiContX =  0, wifiContY =  0, wifiContW = 400, wifiContH =  20;
void drawStatusBar() {
  int16_t currentX = 2, currentY = 2, newX, newY;
  uint16_t width, height;
  // We draw the wifi status icon
  display.fillRect(wifiContX, wifiContY, wifiContW, wifiContH, GxEPD_BLACK);
  display.drawBitmap(currentX + 2, currentY, wifi05, 22, 16, GxEPD_WHITE);
  display.setFont(font_chicago9);
  display.setTextColor(GxEPD_WHITE);
  currentX=30; currentY = 6;
  renderLeftString("L0-NETWORK", &currentX, &currentY, &newX, &newY, &width, &height);
  currentX = 395; currentY = 6;
  renderRightString("192.168.1.31", &currentX, &currentY, &newX, &newY, &width, &height);
}
//const byte hourContX = 10, hourContY = 30, hourContW = 100, hourContH = 116;
void drawTime() {
  int16_t currentX = hourContX + (hourContW/2), currentY = hourContY + 2, newX, newY;
  uint16_t width, height;
  display.fillRoundRect(hourContX,hourContY,hourContW,hourContH, 4, GxEPD_WHITE);
  display.fillRect(hourContX,hourContY,hourContW, 17, GxEPD_BLACK);
  display.setTextColor(GxEPD_WHITE);
  display.setFont(font_chicago9);
  renderCenterString("MI" + String(char(0xC9)) +"RCOLES", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY +=9;
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(2);
  //display.setFont(font_dialogb24);
  renderCenterString("14", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY +=5;
  display.setTextSize(1);
  renderCenterString("Septiembre", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY +=4;
  renderCenterString("2020", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY +=10;
  display.drawFastHLine(hourContX ,currentY - 6, hourContW, GxEPD_BLACK);
  display.drawFastHLine(hourContX ,currentY - 5, hourContW, GxEPD_BLACK);
  display.setTextSize(2);
  renderCenterString("00:00", &currentX, &currentY, &newX, &newY, &width, &height);
}
//const int todayContX = 110, todayContY = 30, todayContW = 220, todayContH = 200;
//const int toda2ContX = 0, toda2ContY = 130, toda2ContW = 105, toda2ContH = 110;
void drawToday() {
  int16_t currentX, currentY, newX, newY;
  uint16_t width, height;
  renderImageFromSPIFFS("/img/WERS.bmp", todayContX, todayContY);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font_chicago9);
  display.setTextSize(2);
  currentY = 22; currentX = 200;
  renderCenterString("BARCELONA", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY += 2;
  display.drawFastHLine(currentX - (width/2) - 4, currentY, width + 8, GxEPD_BLACK);
  display.drawFastHLine(currentX - (width/2) - 4, currentY+1, width + 8, GxEPD_BLACK);
  currentX = toda2ContX + (toda2ContW / 2); currentY = toda2ContY + 4;
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font_chicago9);
  display.setTextSize(1);
  renderCenterString("HOY", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY += 2;
  display.drawFastHLine(currentX - (width/2) - 4, currentY, width + 8, GxEPD_BLACK);
  display.drawFastHLine(currentX - (width/2) - 4, currentY+1, width + 8, GxEPD_BLACK);
  currentX = toda2ContX; currentY += 6;
  renderLeftString("Viento:", &currentX, &currentY, &newX, &newY, &width, &height);
  display.setFont(font_monaco7);
  currentX = toda2ContX + (toda2ContW/2) + 3; currentY -= height;
  renderLeftString("Brisa Ligera", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY += 3;
  renderLeftString("5.1 OSO", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY += 6; currentX = toda2ContX;
  display.setFont(font_chicago9);
  renderLeftString("Nubes:", &currentX, &currentY, &newX, &newY, &width, &height);
  currentX = toda2ContX + (toda2ContW/2) + 3; currentY -= height;
  display.setFont(font_monaco7);
  renderLeftString("Dispersas", &currentX, &currentY, &newX, &newY, &width, &height);
  currentY += 6; currentX = toda2ContX;
  display.setFont(font_chicago9);
  renderLeftString("Presi"+ String(char(0xF3)) +"n:", &currentX, &currentY, &newX, &newY, &width, &height);
  currentX = toda2ContX + (toda2ContW/2) + 3; currentY -= height - 1;
  display.setFont(font_monaco7);
  renderLeftString("1016 hpa", &currentX, &currentY, &newX, &newY, &width, &height);
  renderImageFromSPIFFS("/img/MWC.bmp", toda2ContX + (toda2ContW / 2) - 15, toda2ContY + toda2ContH - 27);
}
// const int leftTempX = 2, centerTempX = 145, rightTempX = 286, tempContY = 244, tempContW = 110, tempContH = 50; // Temperature Widgets
void drawTempWidget(String title, int temp, int hum, int x, int y, int w, int h) {
  int16_t currentX = x + 3, currentY = y + 3, newX, newY;
  uint16_t width, height;
  String tm;
  if (temp < -99 || temp > 99) {
    tm = "--.";
  } else if (temp < 0) {
    if (temp > -10) {
      tm = "0" + String(temp*-1) + ",";
    } else {
      tm = String(temp*-1) + ",";
    }
  } else {
    if (temp < 10) {
      tm = "0" + String(temp) + ".";
    } else {
      tm = String(temp) + ".";
    }
  }
  String hu = (hum  <   1 || hum  > 99)? "--/" : String(hum)+"/";
  display.fillRoundRect(x,y,w,h,4,GxEPD_WHITE);
  display.fillRect(x, y + h - 15, w, 15, GxEPD_BLACK);
  display.setFont(font_tempera27);
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(1);
  renderLeftString(tm, &currentX, &currentY, &newX, &newY, &width, &height);
  currentX = x + w - 3; currentY = y + 3;
  renderRightString(hu, &currentX, &currentY, &newX, &newY, &width, &height);
  currentY = y + h - 12; currentX = x + (w/2);
  display.setFont(font_chicago9);
  display.setTextColor(GxEPD_WHITE);
  renderCenterString(title, &currentX, &currentY, &newX, &newY, &width, &height);
}

void drawTemp() {
  // left widget
  drawTempWidget("INTERIOR", dht11Temp, dht11Hum, leftTempX, tempContY, tempContW, tempContH);
  drawTempWidget("INTERNET", -5, 74, centerTempX, tempContY, tempContW, tempContH);
  drawTempWidget("EXTERIOR", -100, -100, rightTempX, tempContY, tempContW, tempContH);
}

void drawTomorrowWidget(String title, String icon, int min, int max, int x, int y, int w, int h) {
  int16_t currentX = x + (w/2), currentY = y, newX, newY;
  uint16_t width, height;
  display.setFont(font_chicago9);
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(1);
  renderCenterString(title, &currentX, &currentY, &newX, &newY, &width, &height);
  currentY += 1;
  display.drawFastHLine(currentX - (width/2) - 2, currentY, width + 4, GxEPD_BLACK);
  currentY += 3;
  renderImageFromSPIFFS("/img/"+icon+"SM.bmp", currentX - 22, currentY);
  currentY += 47;
  renderCenterString(String(min) + "º - " + String(max) + "º", &currentX, &currentY, &newX, &newY, &width, &height);
}
//const int tomorTopY   =  25,
//          tomorMidY   =  97,
//          tomorBotY   = 172, tomorContX = 320, tomorContW =  70, tomorContH =  70; // Tomorrow's weather Widgets
void drawTomorrow() {
  drawTomorrowWidget("JUE","WERS", 20, 28, tomorContX, tomorTopY, tomorContW, tomorContH);
  drawTomorrowWidget("VIE","WERS", 20, 28, tomorContX, tomorMidY, tomorContW, tomorContH);
  drawTomorrowWidget("SAB","WERS", 20, 28, tomorContX, tomorBotY, tomorContW, tomorContH);
}

void drawInterface() {
  drawShadowedRoundRect(hourContX,hourContY,hourContW,hourContH);
  drawShadowedRoundRect(leftTempX,tempContY,tempContW,tempContH);
  drawShadowedRoundRect(centerTempX,tempContY,tempContW,tempContH);
  drawShadowedRoundRect(rightTempX,tempContY,tempContW,tempContH);
  display.fillRect(wifiContX, wifiContY, wifiContW, wifiContH, GxEPD_BLACK);
  display.fillRect(hourContX,hourContY,hourContW, 17, GxEPD_BLACK);
  display.drawFastHLine(hourContX ,hourContY - 21, hourContW, GxEPD_BLACK);
  display.drawFastHLine(hourContX ,hourContY - 22, hourContW, GxEPD_BLACK);
  drawTempWidget("INTERIOR", 88, 88, leftTempX, tempContY, tempContW, tempContH);
  drawTempWidget("INTERNET", 88, 88, centerTempX, tempContY, tempContW, tempContH);
  drawTempWidget("EXTERIOR", 88, 88, rightTempX, tempContY, tempContW, tempContH);
}

void initScreen() {
  display.init();
  display.eraseDisplay();
  drawInterface();
  display.update();
}