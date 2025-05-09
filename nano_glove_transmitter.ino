#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
String command = "";

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int ax = mpu.getAccelerationX();
  int ay = mpu.getAccelerationY();
  int az = mpu.getAccelerationZ();

  if (ax > 15000) command = "forward";
  else if (ax < -15000) command = "backward";
  else if (ay > 15000) command = "left";
  else if (ay < -15000) command = "right";
  else if (az < 1000) command = "stop";

  if (command != "") {
    Serial.println(command);
    delay(300);
    command = "";
  }
}