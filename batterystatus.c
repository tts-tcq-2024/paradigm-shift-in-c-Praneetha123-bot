#include <assert.h>
#include "CheckBatteryStatus.h"

int main() {
    assert(batteryIsOk(25, 70, 0.7) == 1);
    assert(batteryIsOk(50, 85, 0) == 0);
    assert(batteryIsOk(-10, 23, 0.6) == 0);
    return 0;
}
