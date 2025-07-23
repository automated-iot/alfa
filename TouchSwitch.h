#ifndef TOUCH_SWITCH_H
#define TOUCH_SWITCH_H

#include <Arduino.h>

class TouchSwitch {
public:
  TouchSwitch(uint8_t touch, uint8_t led, uint8_t relay, uint8_t vibration = 14);
  void begin();
  void update();
  // void setState(bool on);         // For API/WebSocket: set on/off
  // bool getState() const;          // For API/WebSocket: read state
  // void handleRemote();            // Placeholder for future API/WebSocket
private:
  const uint8_t touchPin, ledPin, relayPin, vibrationPin;
  bool ledState = false, lastState = false;
  unsigned long vibUntil = 0;
  static constexpr uint16_t TOUCH_THRESH = 40; // Tune this for your sensor!
};

#endif