#include <gtest/gtest.h>
#include <vector>

#include "../src/igg_image/image.h"

TEST(TestImage1, HistogramTest) {
	// Define 2x2 image
	igg::Image im{2, 2};
	im.at(0, 0) = 63;
	im.at(0, 1) = 127;
	im.at(1, 0) = 191;
	im.at(1, 1) = 255;

	// define expected output
	std::vector<float> expec_vec_1{0.5, 0.5}, expec_vec_2{0.25, 0.25, 0.25, 0.25};
	// check expected output against output
	EXPECT_EQ(im.ComputeHistogram(2), expec_vec_1);
	EXPECT_EQ(im.ComputeHistogram(4), expec_vec_2);

	// Repeat with upscaling
	im.UpScale(3);
	EXPECT_EQ(im.ComputeHistogram(2), expec_vec_1);
	EXPECT_EQ(im.ComputeHistogram(4), expec_vec_2);

	// Repeat with downscaling
	im.DownScale(2);
	im.Print();
	EXPECT_EQ(im.ComputeHistogram(2), expec_vec_1);
	EXPECT_EQ(im.ComputeHistogram(4), expec_vec_2);

}

/*
TEST(TestImage2, UpscaleTest) {
	// Define 2x2 image
	igg::Image im{2, 2};
	im.at(0, 0) = 63;
	im.at(0, 1) = 127;
	im.at(1, 0) = 191;
	im.at(1, 1) = 255;

	// define expected output
	//std::vector<float> expec_vec_1{0.5, 0.5};
	// check expected output against output
	//EXPECT_EQ(im.ComputeHistogram(2), expec_vec_1);

	std::vector<float> expec_vec_2{0.25, 0.25, 0.25, 0.25}
	EXPECT_EQ(im.ComputeHistogram(4), expec_vec_2);

	im.UpScale(2);
	EXPECT_EQ(im.ComputeHistogram(2), expec_vec_1);
	EXPECT_EQ(im.ComputeHistogram(4), expec_vec_2);
	

}
*/