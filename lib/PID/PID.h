#ifndef _PID_H
#define _PID_H

class PID
{
private:
    int _kp, _ki, _kd;
    float _reference, _error_integral = 0, _error_previous = 0;
public:
    PID();
    ~PID();
    void setup(int kp, int ki, int kd);
    void setReference(float reference);
    float control(float input, float reference);
};


#endif