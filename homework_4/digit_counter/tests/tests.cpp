#include <gtest/gtest.h>
#include "../src/digit_counting.h"

TEST(DigitTest, Output) {
	EXPECT_EQ(CountSameSignificantDigits<float>(3.14, 10000000), 1);
}