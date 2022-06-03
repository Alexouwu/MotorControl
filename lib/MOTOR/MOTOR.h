#ifndef _MOTOR_H
#define _MOTOR_H

#include "ENCODER.h"
#include "PID.h"
#include "PWM_ESP32.h"

class MOTOR
{
private:
    /* data */
    ENCODER _encoder;
    PID _controler;
    PWM _motor_pins[2];
    int _reduction;
    
public:
    MOTOR(/* args */);
    ~MOTOR();
    void setup(int motor_pins[2], int reduction, int encoder_pins[2], int ppr, double frequency = 10000, uint8_t bit_resolution = 8);
    void set_controler(int kp, int ki, int kd);
};


#endif