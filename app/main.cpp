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
#include <unistd.h>
#include <iostream>
#include <PID.h>


int main() {
  double SP, NV;
  std::cout << "Enter target velocity and current velocity" << std::endl;
  std::cin >> SP >> NV;
  PID c;
  std::cout
      << "Infinite loop will start in 3 seconds. Enter EOF to exit when desired"
      << std::endl;
  /**
   * Delay program by 3 seconds so user can view the message
   */
  usleep(3000000);
  while (true) {
    NV = c.compute(SP, NV);
  /**
   * Delay program by 3 seconds so user can view the message
   */
  usleep(3000000);
  std::cout << "Current Velocity: " << NV << "   Target Velocity: " << SP
              << std::endl;
  }
  return 0;
}
