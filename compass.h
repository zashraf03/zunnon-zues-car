#ifndef __COMPASS_H__
#define __COMPASS_H__

#include <Arduino.h>

#define AVERAGE_FILTER_SIZE 30
#define EEPROM_CALIBRATION_ADDRESS 0
#define CALIBRATION_TIME 3000
#define AVERAGE_FILTER true

void compassBegin();
int16_t compassReadAngle();
int16_t compassGetAzimuth();
void compassCalibrateStart();
bool compassCalibrateLoop();
bool compassCalibrateDone();

#endif