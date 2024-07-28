#include <stdio.h>
#include <string.h>
#include "CheckBatteryStatus.h"
#include "WarningConfig.h"

#define TEMP_LOWER_LIMIT   0
#define TEMP_UPPER_LIMIT   45
#define SOC_LOWER_LIMIT    20
#define SOC_UPPER_LIMIT    80
#define CHARGE_LOWER_LIMIT 0
#define CHARGE_UPPER_LIMIT 0.8

void printMessage(const char* message) {
    printf("%s\n", message);
}

void checkUpperLimitWarning(float value, float UpperLimit, const char* UpperLimitWarningMessage) {
    float UpperLimitTolerance = 0.5 * UpperLimit;
    if (value >= UpperLimit - UpperLimitTolerance) {
        printMessage(UpperLimitWarningMessage);
    }
}

void checkLowerLimitWarning(float value, float LowerLimit, const char* LowerLimitWarningMessage) {
    float LowerLimitTolerance = 0.5 * LowerLimit;
    if (value <= LowerLimit + LowerLimitTolerance) {
        printMessage(LowerLimitWarningMessage);
    }
}

void CheckWarningForGivenValue(float value, float LowerLimit, float UpperLimit, const char* UpperLimitWarningMessage, const char* LowerLimitWarningMessage, BatteryParameter parameter) {
    if (isWarningEnabled(parameter)) {
        checkUpperLimitWarning(value, UpperLimit, UpperLimitWarningMessage);
        checkLowerLimitWarning(value, LowerLimit, LowerLimitWarningMessage);
    }
}

int checkValueInRange(float value, float LowerLimit, float UpperLimit, const char* OutputMessage) {
    if (value < LowerLimit || value > UpperLimit) {
        printMessage(OutputMessage);
        return 0;
    }
    return 1;
}

int checkTemperature(float temp) {
    int TempStatus = checkValueInRange(temp, TEMP_LOWER_LIMIT, TEMP_UPPER_LIMIT, "Temperature out of range");
    CheckWarningForGivenValue(temp, TEMP_LOWER_LIMIT, TEMP_UPPER_LIMIT, "Approaching High Temperature", "Approaching Lower Temperature", TEMPERATURE);
    return TempStatus;
}

int checkSoc(float soc) {
    int SocStatus = checkValueInRange(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "State of Charge out of range");
    CheckWarningForGivenValue(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "Approaching Charge Peak", "Approaching Discharge", SOC);
    return SocStatus;
}

int checkChargeRate(float ChargeRate) {
    int ChargeStatus = checkValueInRange(ChargeRate, CHARGE_LOWER_LIMIT, CHARGE_UPPER_LIMIT, "Charge Rate out of range");
    CheckWarningForGivenValue(ChargeRate, CHARGE_LOWER_LIMIT, CHARGE_UPPER_LIMIT, "Approaching Peak Charge Rate", "Approaching Lower Charge Rate", CHARGE_RATE);
    return ChargeStatus;
}

int batteryIsOk(float temperature, float soc, float ChargeRate) {
    int BatteryStatus = (checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(ChargeRate));
    return BatteryStatus;
}
