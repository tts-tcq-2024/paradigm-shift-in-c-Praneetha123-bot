#ifndef CHECK_BATTERY_STATUS_H
#define CHECK_BATTERY_STATUS_H

#include "WarningConfig.h"

// Function to check if the battery is OK
int batteryIsOk(float temperature, float soc, float chargeRate);

// New helper functions for warning checks
void checkUpperLimitWarning(float value, float UpperLimit, const char* UpperLimitWarningMessage);
void checkLowerLimitWarning(float value, float LowerLimit, const char* LowerLimitWarningMessage);
void CheckWarningForGivenValue(float value, float LowerLimit, float UpperLimit, const char* UpperLimitWarningMessage, const char* LowerLimitWarningMessage, BatteryParameter parameter);

int checkValueInRange(float value, float LowerLimit, float UpperLimit, const char* OutputMessage);
int checkTemperature(float temp);
int checkSoc(float soc);
int checkChargeRate(float ChargeRate);

#endif // CHECK_BATTERY_STATUS_H
