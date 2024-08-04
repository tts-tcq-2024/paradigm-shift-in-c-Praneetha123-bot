#include "BatteryMonitor.h"
#include "ParametersRangeChecker.h"
#include "EarlyWarning.h"
#include "RangeChecker.h"
#include "UserWarningsTuning.h"
#include <stdio.h>


void getUserInput() {
    int tempWarning, socWarning, chargeRateWarning;

    printf("Enable Temperature Warning? (1 for yes, 0 for no): ");
    scanf("%d", &tempWarning);
    printf("Enable SOC Warning? (1 for yes, 0 for no): ");
    scanf("%d", &socWarning);
    printf("Enable Charge Rate Warning? (1 for yes, 0 for no): ");
    scanf("%d", &chargeRateWarning);

    configureWarnings(tempWarning, socWarning, chargeRateWarning);
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
