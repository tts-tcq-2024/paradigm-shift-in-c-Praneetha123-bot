#include "BatteryMonitor.h"
#include "ParametersRangeChecker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
