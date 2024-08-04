#include <stdio.h>
#include "EarlyWarning.h"

void LowWarning(float value, float min, float tolerance, const char* lowWarning) {
    if (value >= min && value <= min + tolerance) {
        printf("%s\n", lowWarning);
    }
}

void HighWarning(float value, float max, float tolerance, const char* highWarning) {
    if (value >= max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}

void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning) {
    LowWarning(value, min, tolerance, lowWarning);
    HighWarning(value, max, tolerance, highWarning);
}

void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning) {
   HighWarning(value, max, tolerance, highWarning);
}
