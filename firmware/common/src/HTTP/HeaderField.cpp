#include "HTTP/HeaderField.hpp"

HeaderField::HeaderField(std::string key, std::string value)
    : key(key), value(value) {}

HeaderField::~HeaderField() {}
