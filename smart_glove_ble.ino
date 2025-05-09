#include <ArduinoBLE.h>
#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

const int thumbPin = A0;
const int indexPin = A1;
const int middlePin = A2;
const int ringPin = A3;

BLEService gloveService("180C");
BLECharacteristic gloveDataChar("2A56", BLERead | BLENotify, 64);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Wire.begin();
  if (mpu.begin() != 0) {
    while (1);
  }
  mpu.calcOffsets();

  if (!BLE.begin()) {
    while (1);
  }

  BLE.setLocalName("SmartGlove");
  BLE.setAdvertisedService(gloveService);
  gloveService.addCharacteristic(gloveDataChar);
  BLE.addService(gloveService);

  gloveDataChar.writeValue("Glove ready");
  BLE.advertise();
}

void loop() {
  BLEDevice central = BLE.central();

  if (central) {
    while (central.connected()) {
      mpu.update();

      int T = analogRead(thumbPin);
      int I = analogRead(indexPin);
      int M = analogRead(middlePin);
      int R = analogRead(ringPin);
      float X = mpu.getAngleX();
      float Y = mpu.getAngleY();

      char data[64];
      snprintf(data, sizeof(data), "T:%d I:%d M:%d R:%d X:%.2f Y:%.2f", T, I, M, R, X, Y);

      gloveDataChar.writeValue(data);
      delay(200);
    }
  }
}