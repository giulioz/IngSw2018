#include "DB/Entity/Root.hpp"

Root::Root() : authKeys(), autoModeConf(), intrusions() {
  this->autoMode = false;
  this->active = false;
}

std::map<std::string, std::string> Root::getAuthKeys() const {
  return this->authKeys;
}

bool Root::isAutoMode() const { return this->autoMode; }

void Root::setAutoMode(bool autoMode) { this->autoMode = autoMode; }

std::map<WeekDay, std::list<TimeSpan> > Root::getAutoModeConf() const {
  return this->autoModeConf;
}

bool Root::isActive() const { return this->active; }

void Root::setActive(bool active) { this->active = active; }

std::list<Intrusion> Root::getIntrusions() const { return this->intrusions; }
