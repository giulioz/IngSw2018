#include "UI/UI.hpp"
#include <string.h>
#include "UI/font8x8_basic.h"

void UI::drawPixel(int x, int y, bool value) {
  drawPixel(x + y * getWidth(), value);
}

void UI::clear() {
  for (int i = 0; i < getWidth() * getHeight(); i++) {
    drawPixel(i, false);
  }
}

void UI::drawChar(int px, int py, const char c) {
  for (auto y = 0; y < 8; y++) {
    for (auto x = 0; x < 8; x++) {
      auto set = font8x8_basic[c][y] & 1 << x;
      drawPixel(x + px, y + py, set);
    }
  }
}

void UI::drawText(int x, int y, const char* text) {
  auto length = strlen(text);
  for (auto k = 0; k < length; k++) {
    drawChar(x + 8 * k, y, text[k]);
  }
}
