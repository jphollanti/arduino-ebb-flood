#pragma once
#ifndef IrrigationController_h
#define IrrigationController_h
#include "TimeUnit.h"
#include "TriggerTimer.h"

class IrrigationController {
private:
  TriggerTimer *triggerTimer;
  int mode;
  long modeTriggerTimes[3];
  static int modeTransitions[4];

  void setPumpTime(TimeUnit *time);
  void setHoldTime(TimeUnit *time);
  void setWaitTime(TimeUnit *time);
public:
  static int PUMP;
  static int HOLD;
  static int WAIT;
  static int INIT;

  IrrigationController(TimeUnit *pumpTime, TimeUnit *holdTime, TimeUnit *waitTime);
  void initialize();
  int getMode();
  bool tick();
};

#endif
