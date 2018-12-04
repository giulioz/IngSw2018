#include "DB/Entity/WeekDay.hpp"

std::string convertWeekDayToString(const WeekDay& wd) {
  switch (wd) {
    case WeekDay::MONDAY:
      return std::string("MONDAY");
      break;
    case WeekDay::TUESDAY:
      return std::string("TUESDAY");
      break;
    case WeekDay::WEDNESDAY:
      return std::string("WEDNESDAY");
      break;
    case WeekDay::THURSDAY:
      return std::string("THURSDAY");
      break;
    case WeekDay::FRIDAY:
      return std::string("FRIDAY");
      break;
    case WeekDay::SATURDAY:
      return std::string("SATURDAY");
      break;
    case WeekDay::SUNDAY:
      return std::string("SUNDAY");
      break;
    default:
      return std::string("{{WeekDay}}");
  }
}
