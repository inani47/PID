/*
 * @file PID.h
 *
 * @brief Declares Class PID
 *
 * Declares gains Kp, Kd, Ki as private members
 * Declares compute function which calculates control variable
 * Declares PID constructor
 * Declares time interval dt as public member
 *
 * @param Kp is the proportinal gain
 * @param Ki is the integral gain
 * @param Kd is the derivative gain
 * @param dt is the time interval
 * @param integral is the sum of all errors multiplied by dt
 * @param previousError is the previous error from the previous
 * time the compute method was called
 *
 * @author: Pranav Inani
 * @copyright 2017
 *
 */
#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_
class PID {
 private:
  double Kp, Kd, Ki;
  double integral;
  double previousError;
 public:
  double dt;
  PID();
  double compute(double, double);
};
#endif  // INCLUDE_PID_H_
