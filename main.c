#include <assert.h>
#include <stdio.h>
#include "BatteryMonitor.h"
#include "ParameterRangeChecker.h"

int main() {
    assert(!batteryIsOk(-1, 75, 0.6));
    assert(!batteryIsOk(46, 75, 0.6));
    assert(!batteryIsOk(30, 19, 0.6));
    assert(!batteryIsOk(30, 81, 0.6));
    assert(!batteryIsOk(30, 75, 0.9));
    assert(batteryIsOk(2.25, 75, 0.6));
    assert(batteryIsOk(42.75, 75, 0.6));
    assert(batteryIsOk(20, 24, 0.6));
    assert(batteryIsOk(20, 76, 0.6));
    assert(batteryIsOk(20, 40, 0.76));
    printf("All tests passed!\n");

    return 0;
}
