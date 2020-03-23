#include <gtest/gtest.h>
#include <iostream>
#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/strategy.h"
#include "../src/igg_image/io_strategies/dummy_strategy.h"
#include "../src/igg_image/io_strategies/png_strategy.h"
#include "../src/igg_image/io_strategies/ppm_strategy.h"

TEST(TestImage, ReadWriteTest) {
	igg::PpmIoStrategy ppm_io_strategy;
	igg::Image im{ppm_io_strategy};
	std::string find_path = "/home/piet/Projects/modern-cpp-course/homework_3/"
					"igg_image/data/simple_image.ppm";
	std::string save_path = "/home/piet/Projects/modern-cpp-course/homework_3/"
					"igg_image/data/simple_image_2.ppm";
	EXPECT_EQ(im.ReadFromDisk(find_path), true);
	im.Print();
	std::cout << im.rows() << ", " << im.cols() << ", " << im.max_val() << std::endl;
	EXPECT_EQ(im.WriteToDisk(save_path), true);
}