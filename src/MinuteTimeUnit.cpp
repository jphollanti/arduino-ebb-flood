#include "MinuteTimeUnit.h"

MinuteTimeUnit::MinuteTimeUnit(long minutes) {
  this->minutes = minutes;
}

long MinuteTimeUnit::getMilliseconds() {
  return this->minutes * 60000;
}
