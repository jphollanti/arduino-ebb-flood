#pragma once
#ifndef IrrigationController_h
#define IrrigationController_h
#include "TriggerTimer.h"

class IrrigationController {
private:
  TriggerTimer *triggerTimer;
public:
  IrrigationController();
  static int PUMP;
  int getMode();
  bool tick();
  TriggerTimer* getTriggerTimer();
};

#endif
