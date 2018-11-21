#pragma once

#include <mongoose.h>
#include <string>
#include <vector>
#include "Network/HeaderField.hpp"

class Request {
 private:
 public:
  std::string url;
  std::string method;
  std::string body;
  std::string queryString;
  std::vector<HeaderField> headerFields;

  Request(struct http_message *hm);
  virtual ~Request();
};
