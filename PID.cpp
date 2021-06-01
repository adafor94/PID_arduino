#include "Arduino.h"
#include "PID.h"

double setPoint, input, output;
double kp, kd, ki;
double lastError, errorSum;
unsigned long lastTime;

PID::PID(double Kp, double Kd, double Ki) {
  kp = Kp;
  kd = Kd;
  ki = Ki;
}

double PID::calculate(double input) {
  //Time since last calculation
  unsigned long now = millis();
  unsigned long timeElapsed = now - lastTime;

  //Calcualte variables
  double error = setPoint - input;
  errorSum += error;
  double errorDerivative = (lastError-error)/timeElapsed;

  //Calculate output
  output = kp*error + kd*errorDerivative + ki*errorSum;

  //Save for next iteration
  lastError = error;
  lastTime = now;
  return output;
}
