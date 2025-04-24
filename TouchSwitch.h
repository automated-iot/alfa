#ifndef TOUCH_SWITCH_H
#define TOUCH_SWITCH_H

#include "Arduino.h"

class TouchSwitch {
public:
  TouchSwitch(int touch, int led, int relay);
  void begin();
  void update();

private:
  int touchPin;
  int ledPin;
  int relayPin;
  int vibrationPin = 14; // Default to GPIO 14
  bool ledState;
  bool lastState;
};

#endif
