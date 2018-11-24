#pragma once

#include <SDL.h>
#include <UI/UI.hpp>

#define WIDTH 178
#define HEIGHT 128
#define SCALING 4

class SDLFrameBuffer : public UI {
 private:
  SDL_Window *window;
  SDL_Surface *screenSurface, *tempSurface;

 public:
  SDLFrameBuffer();
  virtual ~SDLFrameBuffer() override;

  virtual void drawPixel(int i, bool value) override;
  virtual int getWidth() override;
  virtual int getHeight() override;

  void poll(bool *running);
};
