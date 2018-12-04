#include "DB/Entity/Root.hpp"

Root::Root() : authKeys(), autoModeConf(), intrusions() {
  this->autoMode = false;
  this->active = false;
}

std::map<std::string, std::string>& Root::getAuthKeys() {
  return this->authKeys;
}

bool Root::isAutoMode() { return this->autoMode; }

void Root::setAutoMode(bool autoMode) { this->autoMode = autoMode; }

std::map<WeekDay, std::list<TimeSpan>>& Root::getAutoModeConf() {
  return this->autoModeConf;
}

bool Root::isActive() { return this->active; }

void Root::setActive(bool active) { this->active = active; }

std::list<Intrusion>& Root::getIntrusions() { return this->intrusions; }

std::string Root::toString() {
  std::string s("");
  s.append("Root(");
  s.append("{");
  for (std::map<std::string, std::string>::iterator it =
           this->getAuthKeys().begin();
       it != this->getAuthKeys().end(); ++it) {
    s.append("\"" + it->first + "\" => \"" + it->second + "\", ");
  }
  s.append("}, ");
  s.append((this->isAutoMode() ? "true" : "false"));
  s.append(", ");
  s.append("{");
  for (std::map<WeekDay, std::list<TimeSpan>>::iterator it =
           this->getAutoModeConf().begin();
       it != this->getAutoModeConf().end(); ++it) {
    s.append(convertWeekDayToString(it->first) + " => [");
    for (std::list<TimeSpan>::iterator it1 = it->second.begin();
         it1 != it->second.end(); ++it1) {
      s.append(it1->toString() + ", ");
    }
    s.append("], ");
  }
  s.append("}, ");
  s.append(this->isActive() ? "true" : "false");
  s.append(", [");
  for (std::list<Intrusion>::iterator it = this->getIntrusions().begin();
       it != this->getIntrusions().end(); ++it) {
    s.append(it->toString() + ", ");
  }
  s.append("])");
  return s;
}
