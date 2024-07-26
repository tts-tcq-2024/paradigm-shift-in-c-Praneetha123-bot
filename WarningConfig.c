#include "WarningConfig.h"

// Initial warning settings (all enabled by default)
static int warningSettings[NUM_PARAMETERS] = {1, 1, 1};

void setWarningEnabled(BatteryParameter parameter, int enabled) {
    if (parameter >= 0 && parameter < NUM_PARAMETERS) {
        warningSettings[parameter] = enabled;
    }
}

int isWarningEnabled(BatteryParameter parameter) {
    if (parameter >= 0 && parameter < NUM_PARAMETERS) {
        return warningSettings[parameter];
    }
    return 0; // Default to disabled if parameter is out of range
}
