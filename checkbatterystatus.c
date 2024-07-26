#include <stdio.h>
#include <string.h>
#include "CheckBatteryStatus.h"

enum battery_params
{
    TEMP_LOWER_LIMIT   = 0,
    TEMP_UPPER_LIMIT   = 45,
    SOC_LOWER_LIMIT    = 20,
    SOC_UPPER_LIMIT    = 80,
    CHARGE_LOWER_LIMIT = 0,
    CHARGE_UPPER_LIMIT = 1
};

void printMessage(const char* message)
{
    printf("%s\n", message);
}

void CheckWarningForGivenValue(float value, float LowerLimit, float UpperLimit, const char* UpperLimitWarningMessage, const char* LowerLimitWarningMessage)
{
    float UpperLimitTolerance = 0.5 * UpperLimit;
    float LowerLimitTolerance = 0.5 * LowerLimit;

    if (value >= UpperLimit - UpperLimitTolerance)
        printMessage(UpperLimitWarningMessage);

    if (value <= LowerLimit - LowerLimitTolerance)
        printMessage(LowerLimitWarningMessage);
}

int checkValueInRange(float value, float LowerLimit, float UpperLimit, const char* OutputMessage)
{
    if (value < LowerLimit || value > UpperLimit)
    {
        printMessage(OutputMessage);
        return 0;
    }

    return 1;
}

int checkTemperature(float temp)
{
    int TempStatus = checkValueInRange(temp, TEMP_LOWER_LIMIT, TEMP_UPPER_LIMIT, "Temperature out of range");
    CheckWarningForGivenValue(temp, TEMP_LOWER_LIMIT, TEMP_UPPER_LIMIT, "Approaching High Temperature", "Approaching Lower Temperature");
        
    return TempStatus;
}

int checkSoc(float soc)
{
    int SocStatus = checkValueInRange(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "State of Charge out of range");
    CheckWarningForGivenValue(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "Approaching Charge Peak", "Approaching Discharge");
    
    return SocStatus;
}

int checkChargeRate(float ChargeRate)
{
    int ChargeStatus = checkValueInRange(ChargeRate, CHARGE_LOWER_LIMIT, CHARGE_UPPER_LIMIT, "Charge Rate out of range");
    CheckWarningForGivenValue(ChargeRate, CHARGE_LOWER_LIMIT, CHARGE_UPPER_LIMIT, "Approaching Peak Charge Rate", "Approaching Lower Charge Rate");
    
    return ChargeStatus;
}

int batteryIsOk(float temperature, float soc, float ChargeRate) 
{
    int BatteryStatus = (checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(ChargeRate));

    return BatteryStatus;
}
