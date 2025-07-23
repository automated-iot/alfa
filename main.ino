#include <Arduino.h>
#include "TouchSwitch.h"

// Example: touchPin = T0 (GPIO4), ledPin = 13, relayPin = 12
TouchSwitch mySwitch(T0, 13, 12);

void setup() {
  mySwitch.begin();
}

void loop() {
  mySwitch.update();
  // No delay! Keeps the loop fast and responsive.
}