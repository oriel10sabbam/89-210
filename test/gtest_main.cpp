/*
 * gtest_main.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: oriel
 */

#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
