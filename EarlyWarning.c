#include <stdio.h>
#include "EarlyWarning.h"


void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning) {
    printLowWarning(value, min, tolerance, lowWarning);
    printHighWarning(value, max, tolerance, highWarning);
}

void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning) {
   printHighWarning(value, max, tolerance, highWarning);
}
