#pragma once

/**copied from original Arduino.h: ./hardware/arduino/avr/cores/arduino/Arduino.h*/
#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

/**copied from original original Arduino project: ./hardware/arduino/avr/variants/standard/pins_arduino.h*/
#define LED_BUILTIN 13

/**from: https://github.com/IronSavior/dsm2_tx/tree/master/test*/
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define lowByte(w) ((unsigned char) ((w) & 0xff))
#define highByte(w) ((unsigned char) ((w) >> 8))

typedef unsigned char byte;
typedef unsigned short int word;

unsigned long millis();
void delay(unsigned long ms);
unsigned long millis();

// WMath.cpp
long map(long, long, long, long, long);

void initialize_mock_arduino();

/**
  from: https://github.com/Mind-Studios/ardutest/blob/master/mocks/MockWProgram.hpp
  modified:
   - uint8_t types to unsigned char.
*/
#include "inttypes.h"

extern uint8_t digital_pins[14];
extern float analog_pins[6];

void pinMode(unsigned char pin, unsigned char mode);
void digitalWrite(unsigned char pin, unsigned char level);
float analogRead(unsigned char pin);

#include "FakeSerial.h"
