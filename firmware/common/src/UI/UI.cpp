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

void UI::drawText(int x, int y, const char* text) {
  for (; y < 8; y++) {
    for (auto k = 0; k < strlen(text); k++) {
      auto i = text[k];
      for (; x < 8; x++) {
        auto set = font8x8_basic[i][1] & 1 << y;
        if (set) drawPixel(x, y, true);
      }
    }
  }
}