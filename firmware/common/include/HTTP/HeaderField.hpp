#pragma once

#include <string>

class HeaderField {
 private:
 public:
  std::string key;
  std::string value;

  HeaderField(std::string key, std::string value);
  virtual ~HeaderField();
};
