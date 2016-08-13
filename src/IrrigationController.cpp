#include "IrrigationController.h"
#include "TriggerTimer.h"
#include "Time.h"
#include "SecondTime.h"
#include "MinuteTime.h"
#include "HourTime.h"

int IrrigationController::PUMP = 1;
int IrrigationController::HOLD = 2;
int IrrigationController::WAIT = 3;

IrrigationController::IrrigationController() {
  this->triggerTimer = new TriggerTimer();

  this->pumpTime = new SecondTime(27);
  this->holdTime = new SecondTime(120);
  this->waitTime = new HourTime(6);

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

void IrrigationController::setPumpTime(Time *time) {
  this->pumpTime = time;
}
void IrrigationController::setHoldTime(Time *time) {
  this->holdTime = time;
}
void IrrigationController::setWaitTime(Time *time) {
  this->waitTime = time;
}
