#include <stdio.h>
#include <assert.h>

typedef int (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    const char *message;
} Check;

int isInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isInRange, temperature, "Temperature out of range!\n"},
        {isInRange, soc, "State of Charge out of range!\n"},
        {isInRange, chargeRate, "Charge Rate out of range!\n"}
    };

    const int numChecks = sizeof(checks) / sizeof(checks[0]);
    for (int i = 0; i < numChecks; ++i) {
        if (!checks[i].check(checks[i].value,
                             (i == 0) ? 0 : (i == 1) ? 20 : 0, // min values
                             (i == 0) ? 45 : (i == 1) ? 80 : 0)) { // max values
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
