#ifndef _PID_H
#define _PID_H

class PID
{
private:
    int _kp, _ki, _kd, _reference;
    float  _error_integral = 0, _error_previous = 0;
public:
    PID();
    ~PID();
    void setup(int kp, int ki, int kd);
    void setReference(int reference);
    float control(float input);
};


#endif