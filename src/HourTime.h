#pragma once
#ifndef HourTime_h
#define HourTime_h
#include "Time.h"

class HourTime : public Time {
private:
  long hours;
public:
  HourTime(long hours);
  long getMilliseconds();
};

#endif
