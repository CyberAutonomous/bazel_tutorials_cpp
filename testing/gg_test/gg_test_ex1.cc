#include "gtest/gtest.h"
#include "libs/calc.h"

TEST(taitn, calculate) {
	int input = 1;
	int output = 2;
	calculate(&input);
  	EXPECT_EQ(input, output);
}