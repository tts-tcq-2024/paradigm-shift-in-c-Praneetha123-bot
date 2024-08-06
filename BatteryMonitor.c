#include "BatteryMonitor.h"
#include "ParametersRangeChecker.h"
#include "EarlyWarning.h"
#include "RangeChecker.h"



int batteryIsOk(float temperature, float soc, float chargeRate) {
    
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
    
}
