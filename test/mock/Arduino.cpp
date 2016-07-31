/*
  DSM2_tx implements the serial communication protocol used for operating
  the RF modules that can be found in many DSM2-compatible transmitters.

  Copyrigt (C) 2012  Erik Elmore <erik@ironsavior.net>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <sys/timeb.h>
#include "Arduino.h"

timeb t_start;
unsigned long millis() {
  timeb t_now;
  ftime(&t_now);
  return (t_now.time  - t_start.time) * 1000 + (t_now.millitm - t_start.millitm);
}

void delay(unsigned long ms) {
  unsigned long start = millis();
  while(millis() - start < ms){}
}

void initialize_mock_arduino() {
  ftime(&t_start);
}


uint8_t digital_pins[14] = { 0x00 };
float analog_pins[6] = { 0.0 };
uint8_t error = 0;

void pinMode(unsigned char  pin, unsigned char  mode) {
	if (pin < 0 || pin > 13) {
		error = 1;
	}
	if (mode != OUTPUT && mode != INPUT) {
		error = 1;
	}
}

void digitalWrite(unsigned char  pin, unsigned char  level) {
	if (pin < 0 || pin > 13) {
		error = 1;
	}
	if (level != LOW && level != HIGH) {
		error = 1;
	}
	digital_pins[pin] = level;
}

float analogRead(unsigned char  pin) {
	return analog_pins[pin];
}
