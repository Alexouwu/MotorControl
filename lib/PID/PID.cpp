#include "PID.h"

PID::PID(/* args */)
{
}

PID::~PID()
{
}

void PID::setup(int kp, int ki, int kd){
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

void PID::setReference(int reference){
    _reference = reference;
    _error_integral = 0;
}

float PID::control(float input){
    float error = _reference - input;
    float _error_diff = error - _error_previous;
    _error_integral += error;
    _error_previous = error;
    float signal_controlled = _kp * error + _ki * _error_integral + _kd * _error_diff;
    return signal_controlled;
}