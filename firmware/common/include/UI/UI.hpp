#pragma once
#include "FrameBuffer.hpp"

template <typename T>
class UI {
 private:
  FrameBuffer<T>* frameBuffer;

 public:
  UI(FrameBuffer<T>* frameBuffer);
  ~UI();

  void drawText(int x, int y, const char* text);
  void clear();
};
