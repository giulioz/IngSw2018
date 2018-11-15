#include "HTTP/Route.hpp"
#include <string>

Route::Route(const char *path) { this->path = path; }

Route::~Route() {}

static bool _matchParam(const char *path, const char *toMatch) {
  while (*toMatch != '/' && *toMatch) {
    toMatch++;
  }

  while (*path != '/' && *path) {
    path++;
  }

  return _match(path, toMatch);
}

static bool _match(const char *path, const char *toMatch) {
  if (!*path && !*toMatch) {
    return true;
  } else if (!*path && *toMatch) {
    return false;
  } else if (*path && !*toMatch) {
    return true;
  } else if (*toMatch == ':') {
    return _matchParam(path, toMatch);
  } else if (*path == *toMatch) {
    return _match(path + 1, toMatch + 1);
  }
}

bool Route::match(const char *path) { return _match(path, this->path); }

void Route::handle() {}
