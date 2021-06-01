#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID {
public:
        PID(double, double, double);
        double calculate(double);
};
#endif
