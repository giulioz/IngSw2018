#include <SDLFrameBuffer.hpp>

#include <exception>
#include <stdexcept>

SDLFrameBuffer::SDLFrameBuffer() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::invalid_argument("SDL_INIT failed!");
  }

  this->window = SDL_CreateWindow("WatchDoge", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, WIDTH * SCALING,
                                  HEIGHT * SCALING, SDL_WINDOW_SHOWN);

  if (!this->window) {
    throw std::invalid_argument("SDL_CreateWindow failed!");
  }
  this->tempSurface = SDL_GetWindowSurface(this->window);
  this->screenSurface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
  SDL_LockSurface(this->screenSurface);
}

SDLFrameBuffer::~SDLFrameBuffer() {
  SDL_FreeSurface(this->screenSurface);
  SDL_FreeSurface(this->tempSurface);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}

void SDLFrameBuffer::drawPixel(int i, bool value) {
  int *p = reinterpret_cast<int *>(this->screenSurface->pixels);
  p[i] = value ? 0xffffffff : 0xff000000;
}

int SDLFrameBuffer::getWidth() { return WIDTH; }

int SDLFrameBuffer::getHeight() { return HEIGHT; }

void SDLFrameBuffer::poll(bool *running) {
  SDL_UnlockSurface(this->screenSurface);

  SDL_Rect dstRect = {0, 0, 0, 0};
  dstRect.w = this->tempSurface->w;
  dstRect.h = this->tempSurface->h;

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        *running = false;
        break;
    }

    SDL_BlitScaled(this->screenSurface, NULL, this->tempSurface, &dstRect);
    SDL_UpdateWindowSurface(this->window);
  }

  SDL_LockSurface(this->screenSurface);
}
