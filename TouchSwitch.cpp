#include "TouchSwitch.h"

TouchSwitch::TouchSwitch(uint8_t touch, uint8_t led, uint8_t relay, uint8_t vibration)
  : touchPin(touch), ledPin(led), relayPin(relay), vibrationPin(vibration) {}

void TouchSwitch::begin() {
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);
  digitalWrite(vibrationPin, LOW);
}

void TouchSwitch::update() {
  const unsigned long vibrationDuration = 2000; // in ms
  static unsigned long lastTouchTime = 0;
  static bool vibrationActive = false;
  static unsigned long vibrationStartTime = 0;

  bool currentState = digitalRead(touchPin);

  // Debounce delay (optional)
  static unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50;

  // Detect rising edge (LOW to HIGH)
  if (currentState != lastState && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();

    if (currentState == HIGH) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      digitalWrite(relayPin, ledState);

      // Start vibration
      digitalWrite(vibrationPin, HIGH);
      vibrationStartTime = millis();
      vibrationActive = true;

      Serial.println(ledState ? "ON" : "OFF");
    }
  }

  // Turn off vibration after duration
  if (vibrationActive && (millis() - vibrationStartTime >= vibrationDuration)) {
    digitalWrite(vibrationPin, LOW);
    vibrationActive = false;
  }

  lastState = currentState;
}
