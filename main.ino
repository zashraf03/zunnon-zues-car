#include <Arduino.h>
#include "car_control.h"

HardwareSerial GloveBLE(1);
String input = "";

void setup() {
  Serial.begin(115200);
  GloveBLE.begin(9600);
  carBegin();
  carStop();
}

void loop() {
  while (GloveBLE.available()) {
    char c = GloveBLE.read();
    if (c == '\n') {
      input.trim();
      handleCommand(input);
      input = "";
    } else {
      input += c;
    }
  }
}

void handleCommand(String cmd) {
  cmd.toLowerCase();
  if (cmd == "forward") carForward(80);
  else if (cmd == "backward") carBackward(80);
  else if (cmd == "left") carTurnLeft(80);
  else if (cmd == "right") carTurnRight(80);
  else if (cmd == "stop") carStop();
  else if (cmd == "driftleft") carMove(0, 80, -90, true);
  else if (cmd == "driftright") carMove(0, 80, 90, true);
  else if (cmd == "reset") {
    carResetHeading();
    carStop();
  }
}