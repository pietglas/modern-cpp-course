#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "igg_image/io_strategies/ppm_strategy.h"

using namespace igg;

bool PpmIoStrategy::Write(const std::string& file_name, const ImageData& data) const {
	std::ofstream output(file_name);
	bool succes;
	if (output.is_open()) {
		output << "P3" << std::endl;
		output << "# file " << std::endl;
		output << data.cols << " " << data.rows << std::endl;
		output << data.max_val << std::endl;
		int ctr = 0;
		for (auto const& pixel : data.data) {
			if (ctr < 3) {
				output << pixel[0] << "  " << pixel[1] << "  " << pixel[2] << "   ";
				ctr += 1;
			}
			else {
				output << pixel[0] << "  " << pixel[1] << "  " << pixel[2] << std::endl;
				ctr = 0;
			}
		}
		output.close();
		succes = true;
	}
	else succes = false;
	return succes;
}

ImageData PpmIoStrategy::Read(const std::string& file_name) const {
	std::string line;
	int width, height, max_val, pixel_val;
	ImageData im_data;
	std::ifstream input(file_name);
	if (input.is_open()) {
		// ignore type and title
		input.ignore(70, '\n');
		input.ignore(70, '\n');
		// get width, height
		std::getline(input, line);
		std::istringstream iss(line);
		iss >> width >> height;
		// get maximum pixel value
		std::getline(input, line);
		std::istringstream iss_2(line);
		iss_2 >> max_val;

		// get the pixel data 
		std::vector<std::vector<int>> data;
		data.reserve(height*width);
		std::vector<int> pixel;
		int ctr = 0;
		while (input >> pixel_val) {
			pixel.push_back(pixel_val);
			ctr += 1;
			if (ctr == 3) {
				data.push_back(pixel);
				std::vector<int> new_pixel;
				pixel = new_pixel;
				ctr = 0;
			}
		}
		input.close();
		im_data = {height, width, max_val, data};
	}
	else {
		std::cout << "unable to open file" << std::endl;
		im_data = {0, 0, 0, {{}}};
	}
	
	return im_data;
}