#include <stdio.h>
#include <assert.h>
 
int isInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (!isInRange(temperature, 0, 45)) {
        printf("Temperature out of range!\n");
        return 0;
    }
    if (!isInRange(soc, 20, 80)) {
        printf("State of Charge out of range!\n");
        return 0;
    }
    if (!isInRange(chargeRate, 0, 0.8)) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    printf("All tests passed!\n");
    return 0;
}
