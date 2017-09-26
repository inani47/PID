/*
 * @file PID.cpp
 * @brief PID class implementation
 *
 * @author Pranav Inani
 * @copyright 2017
 */

#include<PID.h>
/**
 * @brief compute function definition
 *
 * Computes new velocity for a given
 * target velocity or setpoint (sp) and
 * actual velocity or process variable (pv)
 *
 *
 * @param error is the difference between sp and pv
 * @param integral is the sum off all errors over time multiplied by dt
 * @param previousError is the previous error
 * @param nv is the new calculated velocity
 * @param v is the control variable. it is calculated by
 * muliplying error, sumError and prevError to their respective gains and then adding them
 *
 * @return nv, the new velocity
 */

double PID::compute(double sp, double pv) {
	auto error = sp -pv;
	/**
	 *This makes sure to stop computing if the actual velocity is at the target velocity
	 */
	if(error == 0) {
		integral = 0;
		previousError = 0;
		return pv;
	}

	integral = integral + error*dt;
	/**
	 *This caps the integral if it gets too large and unhelpful for the program
	 */
	if (integral > 40){
		integral = 40;
	}
	
	auto derivative = (error - previousError)/dt;
	auto v = Kp*error + Ki*integral + Kd*derivative;
	auto nv = pv+v;
	return nv;
}

/**
 * @brief constructor to take in values of Kp, Kd, Ki, dt, integral, previousError
 */
PID::PID(const double& a, const double& b, const double& c, const double& d) {
  Kp = a;
  Kd = b;
  Ki = c;
  dt = d;
  integral = 0;
  previousError = 0;
}

/**
 * @brief overloaded constructor with default values of Kp, Kd, Ki, dt, integral, previousError
 */

PID::PID() {
  Kp = .5;
  Kd = 0.1;
  Ki = 0.05;
  dt = 0.4; // should not be zero to pass test
  integral = 0;
  previousError = 0;

}
