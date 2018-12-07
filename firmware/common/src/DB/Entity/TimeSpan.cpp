#include "DB/Entity/TimeSpan.hpp"

#include <exception>

TimeSpan::TimeSpan(const Time& from, const Time& to) : from(from), to(to) {
  if ((&this->from)->compare(this->to) > 0) {
    throw std::invalid_argument("timespan");
  }
}

TimeSpan::TimeSpan(const TimeSpan& ts) : from((&ts)->from), to((&ts)->to) {}

Time& TimeSpan::getFrom() { return this->from; }

Time& TimeSpan::getTo() { return this->to; }

bool TimeSpan::intersects(const TimeSpan& ts) {
  return (&this->from)->compare((&ts)->to) < 0 &&
         (&this->to)->compare((&ts)->from) > 0;
}

std::string TimeSpan::toString() {
  return std::string("TimeSpan(" + this->getFrom().toString() + ", " +
                     this->getTo().toString() + ")");
}
