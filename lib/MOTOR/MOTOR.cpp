#include "MOTOR.h"

MOTOR::MOTOR(/* args */)
{
}

MOTOR::~MOTOR()
{
}

void MOTOR::setup(int motor_pins[2], int reduction, int encoder_pins[2], int ppr, double frequency = 10000, uint8_t bit_resolution = 8)
{
    _encoder.setup(ppr, encoder_pins);
    _reduction = reduction;
    for (int i = 0; i < 2; i++)
    {
        _motor_pins[i].setup(motor_pins[i], i, frequency, bit_resolution);
    }
    
}

void MOTOR::set_controler(int kp, int ki, int kd)
{
    _controler.setup(kp, ki, kd);
}