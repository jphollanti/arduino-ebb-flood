#include "IrrigationControllerBuilder.h"
#include "SecondTimeUnit.h"
#include "HourTimeUnit.h"

IrrigationControllerBuilder::IrrigationControllerBuilder() {
}

IrrigationControllerBuilder* IrrigationControllerBuilder::waterPump(WaterPump *waterPump) {
  this->_waterPump = waterPump;
  return this;
}

IrrigationControllerBuilder* IrrigationControllerBuilder::pumpTime(TimeUnit *time) {
  this->_pumpTime = time;
  return this;
};

IrrigationControllerBuilder* IrrigationControllerBuilder::holdTime(TimeUnit *time) {
  this->_holdTime = time;
  return this;
};

IrrigationControllerBuilder* IrrigationControllerBuilder::waitTime(TimeUnit *time) {
  this->_waitTime = time;
  return this;
};

IrrigationControllerBuilder* IrrigationControllerBuilder::defaults() {
  this->pumpTime(new SecondTimeUnit(27));
  this->holdTime(new SecondTimeUnit(120));
  this->waitTime(new HourTimeUnit(6));
  return this;
}

IrrigationController IrrigationControllerBuilder::build() {
  IrrigationController c(this->_waterPump, this->_pumpTime, this->_holdTime, this->_waitTime);
  c.initialize();
  return c;
};
