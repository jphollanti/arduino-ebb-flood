#include "IrrigationController.h"
#include "TriggerTimer.h"
#include "TimeUnit.h"
#include "SecondTimeUnit.h"
#include "MinuteTimeUnit.h"
#include "HourTimeUnit.h"

int IrrigationController::PUMP = 1;
int IrrigationController::HOLD = 2;
int IrrigationController::WAIT = 3;

IrrigationController::IrrigationController() {
  this->triggerTimer = new TriggerTimer();

  this->pumpTime = new SecondTimeUnit(27);
  this->holdTime = new SecondTimeUnit(120);
  this->waitTime = new HourTimeUnit(6);

  this->mode = IrrigationController::PUMP;
}

int IrrigationController::getMode() {
  return IrrigationController::PUMP;
}

bool IrrigationController::tick() {
  return this->triggerTimer->isTriggered();
}

TriggerTimer* IrrigationController::getTriggerTimer() {
  return this->triggerTimer;
}

void IrrigationController::setPumpTime(TimeUnit *time) {
  this->pumpTime = time;
}
void IrrigationController::setHoldTime(TimeUnit *time) {
  this->holdTime = time;
}
void IrrigationController::setWaitTime(TimeUnit *time) {
  this->waitTime = time;
}
