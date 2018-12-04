#pragma once

#include <string>

enum class WeekDay {
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
};

std::string convertWeekDayToString(const WeekDay&);
