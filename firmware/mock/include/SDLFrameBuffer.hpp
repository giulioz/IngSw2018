#pragma once

#include <SDL.h>
#include <UI/FrameBuffer.hpp>

#define WIDTH 178
#define HEIGHT 128
#define SCALING 4

typedef struct SDLColor {
  unsigned char b, g, r, a;
} SDLColor;

class SDLFrameBuffer : public FrameBuffer<SDLColor> {
 private:
  SDL_Window *window;
  SDL_Surface *screenSurface, *tempSurface;

 public:
  SDLFrameBuffer();
  virtual ~SDLFrameBuffer() override;

  virtual SDLColor *getSurface() override;
  virtual int getWidth() override;
  virtual int getHeight() override;

  void poll(bool *running);
};
