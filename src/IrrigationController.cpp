#include "IrrigationController.h"
#include "TriggerTimer.h"
#include "TimeUnit.h"
#include "SecondTimeUnit.h"
#include "MinuteTimeUnit.h"
#include "HourTimeUnit.h"
#include "ModeAction.h"
#include "PumpModeAction.h"
#include "HoldModeAction.h"
#include "WaitModeAction.h"

int IrrigationController::PUMP = 0;
int IrrigationController::HOLD = 1;
int IrrigationController::WAIT = 2;
int IrrigationController::INIT = 3;

int IrrigationController::modeTransitions[4] = {
  IrrigationController::HOLD, // from pump
  IrrigationController::WAIT, // from hold
  IrrigationController::PUMP, // from wait
  IrrigationController::PUMP  // from init
};

ModeAction* IrrigationController::modeActions[3] = {
  new PumpModeAction(),
  new HoldModeAction(),
  new WaitModeAction()
};


IrrigationController::IrrigationController(WaterPump *waterPump, TimeUnit *pumpTime, TimeUnit *holdTime, TimeUnit *waitTime) {
  this->waterPump = waterPump;
  this->setPumpTime(pumpTime);
  this->setHoldTime(holdTime);
  this->setWaitTime(waitTime);
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
    IrrigationController::modeActions[this->mode]->setMode(this->waterPump);
    return true;
  } else {
    return false;
  }
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
