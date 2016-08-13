#pragma once
#ifndef IrrigationController_h
#define IrrigationController_h
#include "Time.h"
#include "TriggerTimer.h"

class IrrigationController {
private:
  TriggerTimer *triggerTimer;
  Time *pumpTime;
  Time *holdTime;
  Time *waitTime;
  int mode;
public:
  static int PUMP;
  static int HOLD;
  static int WAIT;
  IrrigationController();
  int getMode();
  bool tick();
  TriggerTimer* getTriggerTimer();
  void setPumpTime(Time *time);
  void setHoldTime(Time *time);
  void setWaitTime(Time *time);
};

#endif
