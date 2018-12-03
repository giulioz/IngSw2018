#include "DB/Entity/TimeSpan.hpp"

TimeSpan::TimeSpan(const Time& from, const Time& to) : from(from), to(to) {
  if ((&this->from)->compare(this->to) > 0) {
    throw "Invalid argument.";
  }
}

TimeSpan::TimeSpan(const TimeSpan& ts) : from((&ts)->from), to((&ts)->to) {}

Time TimeSpan::getFrom() const { return this->from; }

Time TimeSpan::getTo() const { return this->to; }

bool TimeSpan::intersects(const TimeSpan& ts) const {
  return (&this->from)->compare((&ts)->to) < 0 &&
         (&this->to)->compare((&ts)->from) > 0;
}
