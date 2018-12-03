#pragma once

#include <list>
#include <map>
#include <string>

#include "DB/Entity/Intrusion.hpp"
#include "DB/Entity/TimeSpan.hpp"
#include "DB/Entity/WeekDay.hpp"

class Root {
 private:
  std::map<std::string, std::string> authKeys;
  bool autoMode;
  std::map<WeekDay, std::list<TimeSpan> > autoModeConf;
  bool active;
  std::list<Intrusion> intrusions;

 public:
  Root();

  std::map<std::string, std::string> getAuthKeys() const;
  bool isAutoMode() const;
  void setAutoMode(bool);
  std::map<WeekDay, std::list<TimeSpan> > getAutoModeConf() const;
  bool isActive() const;
  void setActive(bool);
  std::list<Intrusion> getIntrusions() const;
};
