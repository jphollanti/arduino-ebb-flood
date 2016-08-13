#include "HourTimeUnit.h"

HourTimeUnit::HourTimeUnit(long hours) {
  this->hours = hours;
}

long HourTimeUnit::getMilliseconds() {
  return this->hours * 3600000;
}
