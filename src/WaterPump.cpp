#include "Arduino.h"
#include "WaterPump.h"

WaterPump::WaterPump(int pin1, int pin2) {
  this->pin1 = pin1;
  this->pin2 = pin2;
  analogWrite(pin2, 0);
}

void WaterPump::setPwm(float pwm) {
  analogWrite(pin1, pwm);
}

bool WaterPump::isOn() {
  return analogRead(pin1) > 0;
}
