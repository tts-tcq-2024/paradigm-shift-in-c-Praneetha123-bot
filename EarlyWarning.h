#ifndef EARLYWARNING_H
#define EARLYWARNING_H

void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning);
void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning);

#endif 
