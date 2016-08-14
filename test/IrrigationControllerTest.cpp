#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "mock/Arduino.h"
#include <IrrigationController.h>
#include <IrrigationControllerBuilder.h>
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

SCENARIO( "mode transitions" ) {
  GIVEN( "a fresh instances") {
    WaterPump *p = new WaterPump(1,2);
    IrrigationControllerBuilder builder;
    IrrigationController c =
        builder.waterPump(p)
             ->pumpTime(new MilliSecondTimeUnit(100))
             ->holdTime(new MilliSecondTimeUnit(100))
             ->waitTime(new MilliSecondTimeUnit(100))
             ->build();

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

  GIVEN( "an instance with different times for pump, hold and wait") {
    WaterPump *p = new WaterPump(1,2);
    IrrigationControllerBuilder builder;
    IrrigationController c =
        builder.waterPump(p)
             ->pumpTime(new MilliSecondTimeUnit(100))
             ->holdTime(new MilliSecondTimeUnit(200))
             ->waitTime(new MilliSecondTimeUnit(300))
             ->build();
    c.tick(); // from init to pump

    WHEN( "tick called repeatedly before pump time expires" ) {
      for (int i=0; i<9; i++) {
        delay(10);
        c.tick();
      }
      THEN( "mode is still pump" ) {
        REQUIRE( c.getMode() == IrrigationController::PUMP );
      }
    }

    WHEN( "tick called after pump time expires" ) {
      for (int i=0; i<11; i++) {
        delay(10);
        c.tick();
      }
      THEN( "mode is hold" ) {
        REQUIRE( c.getMode() == IrrigationController::HOLD );
      }
    }

    WHEN( "tick called after pump and hold times expire" ) {
      // pump time is passed at 11th pass (11 * 10 ms > 100ms) and timer is
      // reset only then.
      //
      // hold time is passed when 21 more passes occur (21 * 10ms > 200ms)
      // and timer is reset only then.
      //
      // so we lose 2 (20ms) passes per state transition. hence, we need to
      // iterate 32 times in order to reach wait mode.
      //
      // this is okay, given the mechanism of how the timer is triggered.
      for (int i=0; i<32; i++) {
        delay(10);
        c.tick();
      }
      THEN( "mode is wait" ) {
        REQUIRE( c.getMode() == IrrigationController::WAIT );
      }
    }

    WHEN( "tick called after pump, hold and wait times expire" ) {
      // this time around, we'll need to allow 30 ms for transitions.
      for (int i=0; i<63; i++) {
        delay(10);
        c.tick();
      }
      THEN( "mode is pump" ) {
        REQUIRE( c.getMode() == IrrigationController::PUMP );
      }
    }

    // let's test that the timers still roll properly after one loop
    WHEN( "after one loop and pump mode expiration time" ) {
      for (int i=0; i<74; i++) {
        delay(10);
        c.tick();
      }
      THEN( "mode is hold" ) {
        REQUIRE( c.getMode() == IrrigationController::HOLD );
      }
    }
  }
}
