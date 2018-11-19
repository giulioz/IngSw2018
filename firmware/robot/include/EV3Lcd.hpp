#pragma once
#include "UI/FrameBuffer.hpp"
#include "ev3dev.h"

class EV3Lcd : public FrameBuffer<unsigned char> {
 private:
  lcd lcd;

 public:
  EV3Lcd();
  ~EV3Lcd();

  unsigned char* getSurface() override;
  int getWidth() override;
  int getHeight() override;
  void switchBuffers() override;
};