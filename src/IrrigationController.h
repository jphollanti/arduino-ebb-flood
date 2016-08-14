#pragma once
#ifndef IrrigationController_h
#define IrrigationController_h
#include "TimeUnit.h"
#include "TriggerTimer.h"
#include "WaterPump.h"
#include "ModeAction.h"

class IrrigationController {
private:
  TriggerTimer *triggerTimer;
  int mode;
  long modeTriggerTimes[3];
  static int modeTransitions[4];
  static ModeAction* modeActions[3];
  WaterPump *waterPump;

  void setPumpTime(TimeUnit *time);
  void setHoldTime(TimeUnit *time);
  void setWaitTime(TimeUnit *time);
public:
  static int PUMP;
  static int HOLD;
  static int WAIT;
  static int INIT;

  IrrigationController(WaterPump *waterPump, TimeUnit *pumpTime, TimeUnit *holdTime, TimeUnit *waitTime);
  void initialize();
  int getMode();
  bool tick();
};

#endif
