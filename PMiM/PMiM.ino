#include <Arduino.h>
#include <Wire.h>
#include "SystemController.h"



void setup() {
  Serial.begin(9600);
  if(Serial) {
    Serial.println("--- Uruchomienie Systemu (setup)---");
  }
  SystemController systemController;
  systemController.loop();

}

void loop() {

}
