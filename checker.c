#include <stdio.h>
#include <assert.h>
 
typedef int (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    const char *message;
} Check;

int temperatureInRange(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

int SocInRange(float soc) {
    return (soc >= 20 && soc <= 80);
}

int ChargeRateInRange(float chargeRate) {
    return (chargeRate <= 0.8);
}

void printMessageofStatus(const char *message) {
    printf("%s", message);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {temperatureInRange, temperature, "Temperature out of range!\n"},
        {SocInRange, soc, "SoC out of range!\n"},
        {ChargeRateInRange, chargeRate, "Charge Rate out of range!\n"}
    };

    for (int i = 0; i < sizeof(checks) / sizeof(checks[0]); ++i) {
        if (!checks[i].check(checks[i].value)) {
            printMessageofStatus(checks[i].message);
            return 0;
        }
    }

    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(60, 70, 0));
    assert(!batteryIsOk(25, 70, 0.9));
    assert(!batteryIsOk(30, 95, 0.1));
    printf("All tests passed!\n");
    return 0;
}
