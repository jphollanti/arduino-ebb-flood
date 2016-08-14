#pragma once
#ifndef IrrigationControllerBuilder_h
#define IrrigationControllerBuilder_h
#include "IrrigationController.h"
#include "TimeUnit.h"
#include "WaterPump.h"

class IrrigationControllerBuilder {
private:
  WaterPump *_waterPump;
  TimeUnit *_pumpTime;
  TimeUnit *_holdTime;
  TimeUnit *_waitTime;
public:
  IrrigationControllerBuilder();
  IrrigationControllerBuilder* waterPump(WaterPump *waterPump);
  IrrigationControllerBuilder* pumpTime(TimeUnit *time);
  IrrigationControllerBuilder* holdTime(TimeUnit *time);
  IrrigationControllerBuilder* waitTime(TimeUnit *time);
  IrrigationControllerBuilder* defaults();
  IrrigationController build();
};

#endif
