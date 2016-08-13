#include "IrrigationControllerBuilder.h"
#include "SecondTimeUnit.h"
#include "HourTimeUnit.h"

IrrigationControllerBuilder::IrrigationControllerBuilder() {
}

IrrigationControllerBuilder* IrrigationControllerBuilder::pumpTime(TimeUnit *time) {
  this->pump = time;
  return this;
};

IrrigationControllerBuilder* IrrigationControllerBuilder::holdTime(TimeUnit *time) {
  this->hold = time;
  return this;
};

IrrigationControllerBuilder* IrrigationControllerBuilder::waitTime(TimeUnit *time) {
  this->wait = time;
  return this;
};

IrrigationControllerBuilder* IrrigationControllerBuilder::defaults() {
  this->pumpTime(new SecondTimeUnit(27));
  this->holdTime(new SecondTimeUnit(120));
  this->waitTime(new HourTimeUnit(6));
  return this;
}

IrrigationController IrrigationControllerBuilder::build() {
  IrrigationController c(this->pump, this->hold, this->wait);
  c.initialize();
  return c;
};
