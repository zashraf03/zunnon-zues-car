#ifndef __QMC6310_H__
#define __QMC6310_H__

#include <Wire.h>
#include <Arduino.h>

#define QMC6310_ADDR 0x1C
#define QMC6310_REG_DATA_START 0x01
#define QMC6310_REG_STATUS     0x09
#define QMC6310_REG_CONTROL_1  0x0A
#define QMC6310_REG_CONTROL_2  0x0B

#define QMC6310_VAL_MODE_NORMAL 1 << 0
#define QMC6310_VAL_ODR_200HZ   3 << 2
#define QMC6310_VAL_OSR1_8      0 << 4
#define QMC6310_VAL_OSR2_8      3 << 6
#define QMC6310_VAL_RNG_8G      2 << 2

class QMC6310 {
  public:
    QMC6310();
    void init();
    void read();
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    uint16_t getAzimuth();
    void setCalibration(int, int, int, int, int, int);
    void clearCalibration();
  private:
    void _i2cWrite(byte, byte);
    bool _i2cReadInto(byte, byte, byte*);
    bool _calibrated = false;
};

#endif