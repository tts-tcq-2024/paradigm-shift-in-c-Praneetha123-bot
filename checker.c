#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool isTemperatureInRange(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

bool isSocInRange(float soc) {
    return (soc >= 20 && soc <= 80);
}

bool isChargeRateInRange(float chargeRate) {
    return (chargeRate <= 0.8);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    bool temperatureOk = isTemperatureInRange(temperature);
    bool socOk = isSocInRange(soc);
    bool chargeRateOk = isChargeRateInRange(chargeRate);

    if (!temperatureOk) {
        printf("Temperature out of range!\n");
    }
    if (!socOk) {
        printf("State of Charge out of range!\n");
    }
    if (!chargeRateOk) {
        printf("Charge Rate out of range!\n");
    }

    return temperatureOk && socOk && chargeRateOk;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    printf("All tests passed!\n");
    return 0;
}


