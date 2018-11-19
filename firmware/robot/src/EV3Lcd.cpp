#include "EV3lcd.hpp"

EV3Lcd() { this->lcd.init(); }

int getWidth() { return lcd.resolution_x(); }

int getHeight() { return lcd.resolution_y(); }

unsigned char* getSurface() {}

void switchBuffers() {}