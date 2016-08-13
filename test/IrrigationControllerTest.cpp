#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "mock/Arduino.h"
#include <IrrigationController.h>
#include <MilliSecondTimeUnit.h>
#include <TimeUnit.h>
#include <SecondTimeUnit.h>
#include <MinuteTimeUnit.h>
#include <HourTimeUnit.h>

using namespace std;

/* kept for example purposes
SCENARIO( "irrigation controller dummy tests", "[IrrigationController]" ) {

    GIVEN( "an IrrigationController" ) {
        IrrigationController c;

        // REQUIRE( v.size() == 5 );
        // REQUIRE( v.capacity() >= 5 );

        WHEN( "called on the dummy method" ) {
            bool rval = c.dummy();

            THEN( "it returns true" ) {
                REQUIRE( rval == true );
            }
        }
    }
}
*/

/*
SCENARIO( "mock tests" ) {
  GIVEN( "millis" ) {
    unsigned long start = millis();
    THEN( "after delay, millis returns something intelligible" ) {
      while( millis() - start < 10000 ) {
        cout << millis() << endl;
        delay(250);
      }
      unsigned long end = millis();
      cout << "End of test - duration: " << end - start << "ms" << endl;
    }
  }
}
*/

SCENARIO( "modes" ) {
  GIVEN( "a fresh instances") {
    IrrigationController c;
    c.setPumpTime(new MilliSecondTimeUnit(100));
    c.setHoldTime(new MilliSecondTimeUnit(100));
    c.setWaitTime(new MilliSecondTimeUnit(100));
    c.initialize();

    WHEN( "get mode" ) {
      int mode = c.getMode();
      THEN( "mode is init" ) {
        REQUIRE( c.getMode() == IrrigationController::INIT );
      }
    }

    WHEN( "started" ) {
      c.tick(); // mode from init to pump
      int mode = c.getMode();
      THEN( "mode is pump" ) {
        REQUIRE( c.getMode() == IrrigationController::PUMP );
      }
    }

    WHEN( "pump mode is done" ) {
      c.tick(); // mode from init to pump
      delay(110);
      bool modeChanged = c.tick(); // mode from pump to hold
      bool triggeredImmediatelyAfter = c.tick();

      THEN( "mode change is triggered" ) {
        REQUIRE( modeChanged );
      }
      THEN( "should not trigger again immediately after" ) {
        REQUIRE( !triggeredImmediatelyAfter );
      }
      THEN( "mode is hold" ) {
        REQUIRE( c.getMode() == IrrigationController::HOLD );
      }
    }

    WHEN( "hold mode is done" ) {
      c.tick(); // mode from init to pump
      delay(110);
      c.tick(); // mode from pump to hold
      delay(110);
      c.tick(); // mode from hold to wait

      THEN( "mode is wait" ) {
        REQUIRE( c.getMode() == IrrigationController::WAIT );
      }
    }

    WHEN( "wait mode is done" ) {
      c.tick(); // mode from init to pump
      delay(110);
      c.tick(); // mode from pump to hold
      delay(110);
      c.tick(); // mode from hold to wait
      delay(110);
      c.tick(); // mode from wait to pump

      THEN( "mode is pump again" ) {
        REQUIRE( c.getMode() == IrrigationController::PUMP );
      }
    }
  }
}
