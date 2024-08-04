#include "ParameterRangeChecker.h

int isSocOk(float soc) {
    checkEarlyWarning(soc, 20, 80, 4, "Warning: Approaching discharge", "Warning: Approaching charge-peak");
    return isValueInRange(soc, 20, 80, "State of Charge out of range!");
}

int isTemperatureOk(float temperature) {
    checkEarlyWarning(temperature, 0, 45, 2.25, "Warning: Approaching lower temperature limit", "Warning: Approaching upper temperature limit");
    return isValueInRange(temperature, 0, 45, "Temperature out of range!");
}

int isChargeRateOk(float chargeRate) {
    checkEarlyWarningForChargeRate(chargeRate, 0.8, 0.04, "Warning: Approaching maximum charge rate");
    return isChargeRateInRange(chargeRate, 0.8, "Charge Rate out of range!");
}
