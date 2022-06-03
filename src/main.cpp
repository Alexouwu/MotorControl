#include "ENCODER.h"
#include <Arduino.h>

ENCODER encoder;
int pins[] = {25, 27};
double start_time, dt = 100;
bool flag = true;
int ppr = 11;
int initial_pulses = 0;

void setup() {
  // put your setup code here, to run once:
  encoder.setup(5, pins);
  Serial.begin(115200);
  pinMode(26, OUTPUT);
  digitalWrite(26, LOW);
  start_time = millis();
}

void loop() {
  // Serial.println("EKISDEEEEE");
  if (millis() - start_time > dt) {
    
  }
}