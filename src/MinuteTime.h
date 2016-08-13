#pragma once
#ifndef MinuteTime_h
#define MinuteTime_h
#include "Time.h"

class MinuteTime : public Time {
private:
  long minutes;
public:
  MinuteTime(long minutes);
  long getMilliseconds();
};

#endif
