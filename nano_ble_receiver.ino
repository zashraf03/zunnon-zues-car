#include <Arduino.h>

HardwareSerial MegaSerial(0);
String command = "";

void setup() {
  Serial.begin(9600);
  MegaSerial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      command.trim();
      if (command.length() > 0) {
        MegaSerial.println(command);
        command = "";
      }
    } else {
      command += c;
    }
  }
}