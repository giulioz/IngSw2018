#include "UI/UI.hpp"

UI(FrameBuffer* frameBuffer) { this->frameBuffer = frameBuffer; }

void UI::drawText(int x, int y, const char* text) {
  int i;
  for (i = 0; text[i]; i++) {
    if (text[i] < ' ' || text[i] > 127) continue;
    int c_x = ((text[i] - ' ') % 16) * 8;
    int c_y = ((text[i] - ' ') / 16) * 8;
    int a;
    for (a = 0; a < 8; a++) {
      int X = x + i * 8 + a;
      if (X < 0) continue;
      if (X >= (int)EV3_X_LCD) return;
      int b;
      for (b = 0; b < 8; b++) {
        int Y = y + b;
        if (Y < 0) continue;
        if (Y >= (int)EV3_Y_LCD) break;
        if (LARGE_FONT_PIXEL(c_x + a, c_y + b)) EV3_PIXEL_SET(X, Y);
      }
    }
  }
}

void UI::clear() {}