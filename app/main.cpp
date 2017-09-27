/**
 * @file main.cpp
 * @brief PID controller
 *
 * Uses Proportional, Integral and derivative gains
 * to find compute control variable which is added to
 * the current velocity to achieve target velocity
 * The controller runs infinitely till EOF is encountered
 *
 * @author Pranav Inani
 * @copyright 2017
 */
#include <PID.h>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int main() {
  double SP, NV;
  std::cout << "Enter target velocity and current velocity" << std::endl;
  std::cin >> SP >> NV;
  PID c;
  std::cout
      << "Infinite loop will start in 3 seconds. Enter EOF to exit when desired"
      << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));  // delay program for 3 seconds so user can view above message
  while (true) {
    NV = c.compute(SP, NV);
    std::this_thread::sleep_for(std::chrono::seconds(1));  // delay program for 1 second to view output
    std::cout << "Current Velocity: " << NV << "   Target Velocity: " << SP
              << std::endl;
  }
  return 0;
}
