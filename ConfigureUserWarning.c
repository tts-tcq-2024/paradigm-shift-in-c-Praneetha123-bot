#include "ConfigureUserWarning.h"

int enableTemperatureWarning = 1;
int enableSocWarning = 1;
int enableChargeRateWarning = 1;

void configureWarnings(int tempWarning, int socWarning, int chargeRateWarning) {
    
    enableTemperatureWarning = tempWarning;
    enableSocWarning = socWarning;
    enableChargeRateWarning = chargeRateWarning;
    
}
