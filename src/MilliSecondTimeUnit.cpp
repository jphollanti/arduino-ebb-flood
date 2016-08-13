#include "MilliSecondTimeUnit.h"

MilliSecondTimeUnit::MilliSecondTimeUnit(long milliseconds) {
  this->milliseconds = milliseconds;
}

long MilliSecondTimeUnit::getMilliseconds() {
  return this->milliseconds;
}
