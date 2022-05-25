#ifndef _ENCODER_H
#define _ENCODER_H
#include "Arduino.h"

#define CW true
#define CCW false

class ENCODER
{
private:
    /* data */
    int _ppr, _pins[2], _pulse_counter=0, _rev_counter=0, _degrees_pp;
    unsigned long _start_time = micros();
    double  _pps, _angular_velocity;
    bool direction;
public:
    ENCODER();
    ~ENCODER();
    void setup(int ppr, int pins[2]);
    double getVelocityPps();
    double getAngularVelocity();
    friend void updateCounter();
};


#endif