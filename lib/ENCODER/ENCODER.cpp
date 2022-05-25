#include "ENCODER.h"
#include "Arduino.h"

static ENCODER *instance = NULL;

void updateCounter() {
  instance->_pulse_counter = instance->_pulse_counter + 1;
  // Serial.println("#############");
  // Serial.println(instance->_start_time);
  // Serial.println(micros());
  // Serial.println(micros() - instance->_start_time);
  // Serial.println("#############");
  instance->_pps = 1000000.0 / (micros() - instance->_start_time);
  instance->_angular_velocity = instance->_pps * instance->_degrees_pp;
  instance->direction = digitalRead(instance->_pins[0]) && digitalRead(instance->_pins[1]);
  if (instance->_pulse_counter >= instance->_ppr) {
    instance->_pulse_counter = 0;
    instance->_rev_counter++;
  }
  instance->_start_time = micros();
  // Serial.println(instance->_pulse_counter);
  // Serial.println(instance->_pps);
}

ENCODER::ENCODER() { instance = this; }

ENCODER::~ENCODER() {}

void ENCODER::setup(int ppr, int pins[2]) {
  _ppr = ppr;
  _degrees_pp = 360.0/_ppr;
  for (int i = 0; i < 2; i++) {
    _pins[i] = pins[i];
    pinMode(_pins[i], INPUT);
  }

  attachInterrupt(_pins[0], updateCounter, RISING);
}

double ENCODER::getVelocityPps() {
  return _pps;
}

double ENCODER::getAngularVelocity() {
  return _angular_velocity;
}