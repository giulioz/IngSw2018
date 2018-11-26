#include "EV3lcd.hpp"

EV3Lcd::EV3Lcd() {}

EV3Lcd::~EV3Lcd() {}

void EV3Lcd::drawPixel(int i, bool value) {
  drawPixel(i % getWidth(), i / getWidth());
}

void EV3Lcd::drawPixel(int x, int y, bool value) {
  auto p = reinterpret_cast<unsigned char *>(lcd.frame_buffer());
  auto i = y / 8 * lcd.line_length() + x / 8;
  auto offset = x % 8;
  if (value) {
    p[i] |= 1 << offset;
  } else {
    p[i] ^= 1 << offset;
  }
}

void EV3Lcd::clear() { lcd.fill(0); }

int EV3Lcd::getWidth() { return lcd.resolution_x(); }

int EV3Lcd::getHeight() { return lcd.resolution_y(); }
