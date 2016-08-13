#pragma once
#ifndef IrrigationControllerBuilder_h
#define IrrigationControllerBuilder_h
#include "IrrigationController.h"
#include "TimeUnit.h"

class IrrigationControllerBuilder {
private:
  TimeUnit *pump;
  TimeUnit *hold;
  TimeUnit *wait;
public:
  IrrigationControllerBuilder();
  IrrigationControllerBuilder* pumpTime(TimeUnit *time);
  IrrigationControllerBuilder* holdTime(TimeUnit *time);
  IrrigationControllerBuilder* waitTime(TimeUnit *time);
  IrrigationControllerBuilder* defaults();
  IrrigationController build();
};

#endif
