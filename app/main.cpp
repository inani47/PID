/**
 * @file main.cpp
 * @brief PID controller
 *
 * Uses Proportional, Integral and derivative gains
 * to find compute control variable which is added to
 * the current velocity to achieve target velocity
 *
 * @author Pranav Inani
 * @copyright 2017
 */
#include <PID.h>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int main() {
  double SP, PV, KP, KD, KI, CV;
  std::cout << "Enter setpoint and target velocity" << std::endl;
  std::cin >> SP >> PV;
  std::cout << "Enter gain values: Kp, Kd, Ki and dt" << std::endl;
  std::cin >> KP >> KD >> KI;
  PID controller(KP, KD, KI);
  std::cout
      << "Infinite loop will start in 3 seconds. Enter EOF to exit when desired"
      << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));  // delay prgram for 3 seconds so user can view above message
  while (true) {
    CV = controller.compute(SP, PV);
    PV = SP + CV;
    std::cout << "Latest Velocity: " << PV << "   Control Variable: " << CV
              << std::endl;
  }
  return 0;
}
