#include <ArduinoBLE.h>

BLEDevice glove;
BLECharacteristic gloveChar;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!BLE.begin()) {
    while (1);
  }

  BLE.scanForName("SmartGlove");
}

void loop() {
  if (!glove) {
    glove = BLE.available();

    if (glove && glove.localName() == "SmartGlove") {
      if (glove.connect()) {
        if (glove.discoverAttributes()) {
          gloveChar = glove.characteristic("2A56");
          if (gloveChar) {
            gloveChar.subscribe();
          } else {
            glove.disconnect();
          }
        } else {
          glove.disconnect();
        }
      } else {
        BLE.scanForName("SmartGlove");
      }
    }
  }

  if (glove && glove.connected() && gloveChar) {
    if (gloveChar.valueUpdated()) {
      int len = gloveChar.valueLength();
      const uint8_t* buffer = gloveChar.value();
      char data[len + 1];
      memcpy(data, buffer, len);
      data[len] = '\0';
      Serial.println(data);
    }
  }
}