#pragma once
#include "FrameBuffer.hpp"

template <typename T>
class UI {
 private:
  FrameBuffer* frameBuffer;

 public:
  UI(FrameBuffer* frameBuffer);
  ~UI();

  void drawText(int x, int y, const char* text);
  void clear();
};