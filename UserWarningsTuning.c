#include "UserWarningsTuning.h"
#include "ConfigureUserWarning.h"
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
