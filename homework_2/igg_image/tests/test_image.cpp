#include <gtest/gtest.h>
#include <vector>

#include "../src/igg_image/image.h"

TEST(TestImage, OutputTest) {
	// Define 2x2 image
	igg::Image im{2, 2};
	im.at(0, 0) = 63;
	im.at(0, 1) = 127;
	im.at(1, 0) = 191;
	im.at(1, 1) = 255;

	std::vector<float> expec_vec{2, 2};

	EXPECT_EQ(im.ComputeHistogram(2), expec_vec);
}