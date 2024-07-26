#include <assert.h>
#include <stdio.h>
#include "CheckBatteryStatus.h"


int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 1.1));
    printf("All tests passed!\n");
    return 0;
}
