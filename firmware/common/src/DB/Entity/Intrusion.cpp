#include "DB/Entity/Intrusion.hpp"

Intrusion::Intrusion(long id, long date, bool notified) {
  this->id = id;
  this->date = date;
  this->notified = notified;
}

Intrusion::Intrusion(const Intrusion& i) {
  this->id = (&i)->id;
  this->date = (&i)->date;
  this->notified = (&i)->notified;
}

long Intrusion::getId() const { return this->id; }

long Intrusion::getDate() const { return this->date; }

bool Intrusion::isNotified() const { return this->notified; }
