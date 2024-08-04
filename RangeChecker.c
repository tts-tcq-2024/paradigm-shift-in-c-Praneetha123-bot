#include "RangeChecker.h"
#include "WarningMessage.h"

int isValueInRange(float value, float min, float max, const char* WarningMessage) {
    if (value < min || value > max) {
        WarningMessage(WarningMessage);
        return 0;
    }
    return 1;
}

int isChargeRateInRange(float value, float max, const char* WarningMessage) {
    if (value > max) {
        WarningMessage(WarningMessage);
        return 0;
    }
    return 1;
}
