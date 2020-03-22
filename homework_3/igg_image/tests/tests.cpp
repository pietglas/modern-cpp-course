#include <gtest/gtest.h>
#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/strategy.h"
#include "../src/igg_image/io_strategies/dummy_strategy.h"
#include "../src/igg_image/io_strategies/png_strategy.h"

TEST(TestImage, ReadWriteTest) {
	igg::DummyIoStrategy dummy_io_strategy;
	igg::Image im{2, 2, dummy_io_strategy};
	EXPECT_EQ(im.WriteToDisk("hoi"), true);
}