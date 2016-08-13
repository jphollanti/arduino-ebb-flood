#include "IrrigationController.h"
#include "TriggerTimer.h"
#include "TimeUnit.h"
#include "SecondTimeUnit.h"
#include "MinuteTimeUnit.h"
#include "HourTimeUnit.h"

int IrrigationController::PUMP = 0;
int IrrigationController::HOLD = 1;
int IrrigationController::WAIT = 2;
int IrrigationController::INIT = 3;

IrrigationController::IrrigationController() {
  this->modeTransitions[IrrigationController::PUMP] = IrrigationController::HOLD;
  this->modeTransitions[IrrigationController::HOLD] = IrrigationController::WAIT;
  this->modeTransitions[IrrigationController::WAIT] = IrrigationController::PUMP;
  this->modeTransitions[IrrigationController::INIT] = IrrigationController::PUMP;

  this->setDefaults();
}

void IrrigationController::setDefaults() {
  this->setPumpTime(new SecondTimeUnit(27));
  this->setHoldTime(new SecondTimeUnit(120));
  this->setWaitTime(new HourTimeUnit(6));
}

void IrrigationController::initialize() {
  this->triggerTimer = new TriggerTimer();
  this->triggerTimer->setTriggerTime(1);
  this->triggerTimer->initialize();
  this->mode = IrrigationController::INIT;
}

int IrrigationController::getMode() {
  return this->mode;
}

bool IrrigationController::tick() {
  if (this->triggerTimer->isTriggered()) {
    this->mode = IrrigationController::modeTransitions[this->mode];
    this->triggerTimer->setTriggerTime(this->modeTriggerTimes[this->mode]);
    return true;
  } else {
    return false;
  }
}

TriggerTimer* IrrigationController::getTriggerTimer() {
  return this->triggerTimer;
}

void IrrigationController::setPumpTime(TimeUnit *time) {
  this->modeTriggerTimes[IrrigationController::PUMP] = time->getMilliseconds();
}
void IrrigationController::setHoldTime(TimeUnit *time) {
  this->modeTriggerTimes[IrrigationController::HOLD] = time->getMilliseconds();
}
void IrrigationController::setWaitTime(TimeUnit *time) {
  this->modeTriggerTimes[IrrigationController::WAIT] = time->getMilliseconds();
}
