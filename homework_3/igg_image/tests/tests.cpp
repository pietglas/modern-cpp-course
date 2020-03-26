#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/strategy.h"
#include "../src/igg_image/io_strategies/dummy_strategy.h"
#include "../src/igg_image/io_strategies/png_strategy.h"
#include "../src/igg_image/io_strategies/ppm_strategy.h"

TEST(TestImage, ReadWriteTest) {
	igg::PpmIoStrategy ppm_io_strategy;
	auto strategy_ptr = std::make_shared<igg::PpmIoStrategy>(ppm_io_strategy);
	igg::Image im;
	im.SetIoStrategy(strategy_ptr);
	std::string find_path = "/home/piet/Projects/modern-cpp-course/homework_3/"
					"igg_image/data/sign_1.ppm";
	std::string save_path = "/home/piet/Projects/modern-cpp-course/homework_3/"
					"igg_image/data/sign_2.ppm";
	EXPECT_EQ(im.ReadFromDisk(find_path), true);
	EXPECT_EQ(im.WriteToDisk(save_path), true);
}