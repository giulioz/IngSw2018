#include "HTTP/Request.hpp"

Request::Request(struct http_message *hm)
    : url(hm->uri.p ? hm->uri.p : ""),
      method(hm->method.p ? hm->method.p : ""),
      body(hm->body.p ? hm->body.p : ""),
      queryString(hm->query_string.p ? hm->query_string.p : "") {
  for (size_t i = 0; hm->header_names[i].p; i++) {
    headerFields.push_back(
        HeaderField(hm->header_names[i].p, hm->header_values[i].p));
  }
}

Request::~Request() {}
