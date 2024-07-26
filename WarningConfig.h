#ifndef WARNING_CONFIG_H
#define WARNING_CONFIG_H

typedef enum {
    TEMPERATURE,  
    SOC,          
    CHARGE_RATE,  
    NUM_PARAMETERS  // Helps in ensuring the size of the array matches the number of parameters
} BatteryParameter;


void setWarningEnabled(BatteryParameter parameter, int enabled);
int isWarningEnabled(BatteryParameter parameter);

#endif 
