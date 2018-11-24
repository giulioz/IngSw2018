#include "UI/UI.hpp"

void UI::drawPixel(int x, int y, bool value) {
  drawPixel(x + y * getWidth(), value);
}

void UI::clear() {
  for (int i = 0; i < getWidth() * getHeight(); i++) {
    drawPixel(i, false);
  }
}

void UI::drawText(int x, int y, const char* text) {}
