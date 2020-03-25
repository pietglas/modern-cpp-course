#include <gtest/gtest.h>
#include <cmath>
#include "../src/digit_counting.h"
//#include "../src/digit_counting.hpp"

TEST(DigitTest, Output) {
	EXPECT_EQ(CountSameSignificantDigits<float>(M_PI, 10000000), 1);
}