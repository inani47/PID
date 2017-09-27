/**
 * @file PID_test.cpp
 * @brief Unit Tests for PID
 * @author Pranav Inani
 * @copyright 2017
 */
#include <gtest/gtest.h>
#include <../include/PID.h>

/**
 * @brief Unit test for compute method
 *
 * Checks if compute function returns the current velocity
 * when set point is equal to current velocity
 */

TEST(computeTest, IF_SP_EQ_PV_RET_PV) {
  PID p;
  EXPECT_EQ(23, p.compute(23, 23));
}

/**
 * @brief Unit test to check time interval dt
 *
 * test to ensure that the value of dt is not 0
 * to avoid division by zero while calculating changeError
 */

TEST(timeInterval, timeIntervalNotZero) {
  PID q;
  EXPECT_NE(0, q.dt);
}





