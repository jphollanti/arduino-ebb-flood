#pragma once
#ifndef MilliSecondTimeUnit_h
#define MilliSecondTimeUnit_h
#include "TimeUnit.h"

class MilliSecondTimeUnit : public TimeUnit {
private:
  long milliseconds;
public:
  MilliSecondTimeUnit(long milliseconds);
  long getMilliseconds();
};

#endif
