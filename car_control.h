#ifndef __CAR_CONTROL_H__
#define __CAR_CONTROL_H__

#include <Arduino.h>
#include "compass.h"

#define MOTOR_PINS (uint8_t[8]){3, 4, 5, 6, A3, A2, A1, A0}
#define MOTOR_DIRECTIONS (uint8_t[4]){1, 0, 0, 1}
#define CAR_DEFAULT_POWER 80

void carBegin();
void carSetMotors(int8_t, int8_t, int8_t, int8_t);
void carForward(int8_t);
void carBackward(int8_t);
void carTurnLeft(int8_t);
void carTurnRight(int8_t);
void carLeftForword(int8_t);
void carRightForword(int8_t);
void carLeftBackward(int8_t);
void carRightBackward(int8_t);
void carLeft(int8_t);
void carRight(int8_t);
void carStop();
void carMove(int16_t, int8_t, int8_t = 0, bool drift = false);
void carMoveFieldCentric(int16_t, int8_t, int16_t = 0, bool drift = false, bool angFlag = false);
void carResetHeading();

#endif