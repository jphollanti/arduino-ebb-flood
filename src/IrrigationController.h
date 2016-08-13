#pragma once
#ifndef IrrigationController_h
#define IrrigationController_h
#include "TimeUnit.h"
#include "TriggerTimer.h"

class IrrigationController {
private:
  TriggerTimer *triggerTimer;
  TimeUnit *pumpTime;
  TimeUnit *holdTime;
  TimeUnit *waitTime;
  int mode;
public:
  static int PUMP;
  static int HOLD;
  static int WAIT;
  static int INIT;
  IrrigationController();
  void setDefaults();
  void initialize();
  int getMode();
  bool tick();
  TriggerTimer* getTriggerTimer();
  void setPumpTime(TimeUnit *time);
  void setHoldTime(TimeUnit *time);
  void setWaitTime(TimeUnit *time);
};

#endif
