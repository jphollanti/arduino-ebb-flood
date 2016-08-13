#include "SecondTimeUnit.h"

SecondTimeUnit::SecondTimeUnit(long seconds) {
  this->seconds = seconds;
}

long SecondTimeUnit::getMilliseconds() {
  return this->seconds * 1000;
}
