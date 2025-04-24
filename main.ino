#include "TouchSwitch.h"

TouchSwitch mySwitch(4, 13, 12); // touch sensor on pin 4, LED on pin 13, relay on pin 12

void setup() {
  mySwitch.begin(); // to start the myswitch class
}

void loop() {
  mySwitch.update(); // to update the state saved in lastState var **REM
}
