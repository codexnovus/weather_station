
uint16_t read16(File& f) {
  // BMP data is stored little-endian, same as Arduino.
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(File& f) {
  // BMP data is stored little-endian, same as Arduino.
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}

void renderCenterString (String str, int16_t *cX, int16_t *cY, int16_t *nX, int16_t *nY, uint16_t *W, uint16_t *H) {
  display.getTextBounds(str, 0, 0, nX, nY, W, H);
  *cY += *H;
  display.setCursor(*cX-(*W/2),*cY);
  display.print(str);
}

void renderLeftString (String str, int16_t *cX, int16_t *cY, int16_t *nX, int16_t *nY, uint16_t *W, uint16_t *H) {
  display.getTextBounds(str, 0, 0, nX, nY, W, H);
  *cY += *H;
  display.setCursor(*cX, *cY);
  display.print(str);
}

void renderRightString (String str, int16_t *cX, int16_t *cY, int16_t *nX, int16_t *nY, uint16_t *W, uint16_t *H) {
  display.getTextBounds(str, 0, 0, nX, nY, W, H);
  *cY += *H;
  display.setCursor(*cX-*W, *cY);
  display.print(str);
}

void renderImageFromSPIFFS (String path, int16_t x, int16_t y) {
  uint8_t input_buffer[60];
  uint8_t mono_palette_buffer[32];
  bool flip = true;
  if (!path.endsWith("bmp")) {
    Serial.println(path + " is not a valid filename!");
    return;
  }
  File image = SPIFFS.open(path, FILE_READ);
  if (!image) {
    Serial.println("Error loading " + path);
    return;
  }
  if (read16(image) == 0x4D42) {
    uint32_t fileSize = read32(image);
    uint32_t creatorBytes = read32(image);
    uint32_t imageOffset = read32(image); // Start of image data
    uint32_t headerSize = read32(image);
    uint32_t width  = read32(image);
    uint32_t height = read32(image);
    uint16_t planes = read16(image);
    uint16_t depth = read16(image); // bits per pixel
    uint32_t format = read32(image);
    if ((planes == 1) && ((format == 0) || (format == 3))) {
      # if DEBUG
      Serial.print("File size: "); Serial.println(fileSize);
      Serial.print("Image Offset: "); Serial.println(imageOffset);
      Serial.print("Header size: "); Serial.println(headerSize);
      Serial.print("Bit Depth: "); Serial.println(depth);
      Serial.print("CreatorBytes: "); Serial.println(creatorBytes);
      Serial.print("Image size: ");
      Serial.print(width);
      Serial.print("x");
      Serial.println(height);
      # endif
      if (depth != 1) {
        Serial.println("Image is not black & white. Will not read.");
        return;
      }
      uint32_t rowSize = ((width * depth + 8 - depth) / 8 + 3) & ~3;
      if (height < 0) {
        height = -height;
        flip = false;
      }
      uint16_t w = width;
      uint16_t h = height;
      if ((x + w - 1) >= display.width())  w = display.width()  - x;
      if ((y + h - 1) >= display.height()) h = display.height() - y;
      uint8_t bitmask = 0xFF;
      uint8_t bitshift = 8 - depth;
      uint16_t red, green, blue;
      bool whitish;
      bitmask >>= depth;
      image.seek(imageOffset - (4 << depth));
      for (uint16_t pn = 0; pn < (1 << depth); pn++) {
        blue  = image.read();
        green = image.read();
        red   = image.read();
        image.read();
        whitish = ((red + green + blue) > 3 * 0x80); // whitish
        if (0 == pn % 8) mono_palette_buffer[pn / 8] = 0;
        mono_palette_buffer[pn / 8] |= whitish << pn % 8;
      }
      display.fillRect(x, y, width, height, GxEPD_WHITE);
      uint32_t rowPosition = flip ? imageOffset + (height - h) * rowSize : imageOffset;
      for (uint16_t row = 0; row < h; row++, rowPosition += rowSize) {
        uint32_t in_remain = rowSize;
        uint32_t in_idx = 0;
        uint32_t in_bytes = 0;
        uint8_t in_byte = 0; // for depth <= 8
        uint8_t in_bits = 0; // for depth <= 8
        uint16_t color = GxEPD_WHITE;
        image.seek(rowPosition);
        for (uint16_t col = 0; col < w; col++) {
          if (in_idx >= in_bytes) {
            in_bytes = image.read(input_buffer, in_remain > sizeof(input_buffer) ? sizeof(input_buffer) : in_remain);
            in_remain -= in_bytes;
            in_idx = 0;
          }
          if (0 == in_bits) {
            in_byte = input_buffer[in_idx++];
            in_bits = 8;
          }
          uint16_t pn = (in_byte >> bitshift) & bitmask;
          whitish = mono_palette_buffer[pn / 8] & (0x1 << pn % 8);
          in_byte <<= depth;
          in_bits -= depth;
          color = whitish ? GxEPD_WHITE : GxEPD_BLACK;
          uint16_t yrow = y + (flip ? h - row - 1 : row);
          display.drawPixel(x + col, yrow, color);
        }
      }
    }
  }
}

void drawShadowedRoundRect (int x, int y, int w, int h) {
  display.fillRoundRect(x-2, y-2, w+4, h+4, 5, GxEPD_BLACK);
  display.fillRoundRect(  x,   y, w+4, h+4, 5, GxEPD_BLACK);
  display.fillRoundRect(  x,   y,   w,   h, 4, GxEPD_WHITE);
}

void drawPlaceHolder (int x, int y, int w, int h) {
  display.fillRect(x,y,w,h,GxEPD_WHITE);
  display.drawRect(x, y, w, h, GxEPD_BLACK);
  display.drawLine(x,y,x+w,y+h, GxEPD_BLACK);
  display.drawLine(x,y+h,x+w,y, GxEPD_BLACK);
}
