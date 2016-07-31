#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "mock/Arduino.h"
#include "main.h"

using namespace std;

SCENARIO( "blink test" ) {
  GIVEN( "main program" ) {
    unsigned long start = millis();
    WHEN ( "first called loop() ") {
      loop();
      THEN( "LED_BUILTIN pin is on" ) {
        REQUIRE( digital_pins[LED_BUILTIN] == HIGH );
      }
    }
  }
}
