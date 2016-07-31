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

SCENARIO( "IrrigationController modes" ) {
  GIVEN( "a fresh IrrigationController") {
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
