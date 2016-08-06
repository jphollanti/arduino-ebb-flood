#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "mock/Arduino.h"
#include <IrrigationController.h>

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

SCENARIO( "process at certain intervals" ) {
  GIVEN( "a fresh instance" ) {
    IrrigationController c;
    WHEN( "tick called after creation" ) {
      bool first = c.tick();
      THEN( "returns true" ) {
        REQUIRE( first );
      }
    }
    WHEN( "tick called after 1 second" ) {
      bool first = c.tick(); // returns true, resets timer
      delay(1100);
      bool second = c.tick();
      THEN( "returns true" ) {
        REQUIRE( second );
      }
    }
    WHEN( "tick called immediately after successful call" ) {
      c.tick();
      bool third = c.tick();
      THEN( "return false" ) {
        REQUIRE( !third );
      }
    }
    WHEN( "when created" ) {
      THEN( "timer is set to default" ) {
        long triggerTime = c.getTriggerTimer()->getTriggerTime();
        REQUIRE( triggerTime == 1000 );
      }
    }
  }
}

SCENARIO( "modes" ) {
  GIVEN( "a fresh instances") {
    IrrigationController c;
    WHEN( "get mode" ) {
      int mode = c.getMode();
      THEN ( "mode is pump" ) {
        REQUIRE( IrrigationController::PUMP );
      }
    }

    /*
    WHEN( "pump mode is done" ) {
      c.setPumpForSeconds(1);

      THEN( "next is hold mode" ) {

      }

    }*/
  }
}
