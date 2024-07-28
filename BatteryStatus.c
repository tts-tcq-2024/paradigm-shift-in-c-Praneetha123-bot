#include <assert.h>
#include <stdio.h>
#include "CheckBatteryStatus.h"
#include "WarningConfig.h"

int main() {
    // Set warning configurations (for example, disable SOC warnings)
    setWarningEnabled(SOC, 0);
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9)); // Changed from 1.1 to 0.9 to fit the new upper limit
    printf("All tests passed!\n");

    return 0;
}
