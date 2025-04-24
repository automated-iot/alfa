#include "TouchSwitch.h"

TouchSwitch::TouchSwitch(int touch, int led, int relay) {
  touchPin = touch;
  ledPin = led;
  relayPin = relay;
  ledState = false;
  lastState = LOW;
}

void TouchSwitch::begin() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);
  digitalWrite(vibrationPin, LOW);

  Serial.begin(115200);
}

void TouchSwitch::update() {
  bool currentState = digitalRead(touchPin);

  if (currentState == HIGH && lastState == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    digitalWrite(relayPin, ledState);
    digitalWrite(vibrationPin, HIGH);
    delay(200);
    digitalWrite(vibrationPin, LOW);

    Serial.println(ledState ? "ON" : "OFF");
  }

  lastState = currentState;
}
