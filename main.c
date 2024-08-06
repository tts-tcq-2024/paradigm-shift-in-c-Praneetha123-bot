#include <assert.h>
#include <stdio.h>
#include "BatteryMonitor.h"
#include "UserWarningsTuning.h"

int main() {
   
    // Get user input for warning configuration tuning
    getUserInput();

    assert(batteryIsOk(30, 60, 0.4)); // to check all parameters in range
    assert(!batteryIsOk(40, 18, 0.6)); // to check value less than soc lower limit value
    assert(!batteryIsOk(35, 85, 0.6)); // to check value more than soc upper limit value
    assert(!batteryIsOk(45,70,1.0)); //// to check value more than charge rate upper limit value
    assert(!batteryIsOk(-3, 70, 0.7)); // to check value less than temperature lower limit value
    assert(!batteryIsOk(46, 50, 0.5)); // to check value more than temperature upper limit value
    assert(batteryIsOk(2.25, 75, 0.6)); // to check value approaching lower temperature limit
    assert(batteryIsOk(42.75, 75, 0.6)); // to check value approaching higher temperature limit
    assert(batteryIsOk(20, 40, 0.76)); // to check value approaching higher charge rate limit
    assert(batteryIsOk(30, 22, 0.5)); // to check value approaching lower soc limit
    assert(batteryIsOk(30, 79, 0.5)); // to check value approaching higher soc limit
    
    printf("All tests passed!\n");

    return 0;
}
