#include <stdio.h>
#include <assert.h>

typedef int (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    const char *message;
    float min;
    float max;
} Check;

int isInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isInRange, temperature, "Temperature out of range!\n", 0, 45},
        {isInRange, soc, "State of Charge out of range!\n", 20, 80},
        {isInRange, chargeRate, "Charge Rate out of range!\n", 0, 0.8}
    };

    const int numChecks = sizeof(checks) / sizeof(checks[0]);
    for (int i = 0; i < numChecks; ++i) {
        if (!checks[i].check(checks[i].value, checks[i].min, checks[i].max)) {
            printf("%s", checks[i].message);
            return 0;
        }
    }

    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    printf("All tests passed!\n");
    return 0;
}
