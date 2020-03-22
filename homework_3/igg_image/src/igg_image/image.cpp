#include <vector>
#include <iostream>

#include "image.h"

using namespace igg;

// I/O
bool Image::ReadFromDisk(const std::string& file_name) {
	// Use read method from io_strategy to obtain the data
	bool return_val;
	ImageData im_data = io_strategy_.Read(file_name);
	if (im_data.rows == 0) {
		std::cout << "file not found" << std::endl;
		return_val = false;
	}
	// If the file is found, write data to image
	else {
		rows_ = im_data.rows;
		cols_ = im_data.cols;
		max_val_ = im_data.max_val;
		data_.reserve(im_data.data.size());
		for (int i = 0; i != im_data.data.size(); i++) {
			Pixel new_pixel{im_data.data[i][0], im_data.data[i][1], im_data.data[i][2]};
			data_.push_back(new_pixel);
		}	
		return_val = true;	
	}
	return return_val;
} 

bool Image::WriteToDisk(const std::string& file_name) const {
	// store the data in a container
	std::vector<std::vector<int>> data;
	data.reserve(rows_*cols_);
	for (int i = 0; i != rows_*cols_; i++) {
		std::vector<int> pixel{data_[i].red, data_[i].green, data_[i].blue};
		data.push_back(pixel);
	}
	ImageData im_data{rows_, cols_, max_val_, data};

	// use write method from io_strategy to write data to disk
	bool succes = io_strategy_.Write(file_name, im_data);
	if (succes) {
		std::cout << "data has been saved to disk " << std::endl;
	}
	else {
		std::cout << "an error occured" << std::endl;
	}
	return succes;
}


// Downscale the image. 
void Image::DownScale(const int& scale){
	// set the dimensions, neglect decimal part. 
	int new_rows = rows_ / scale;
	int new_cols = cols_ / scale;

	// declare the new data
	std::vector<Pixel> new_data;
	new_data.reserve(new_rows * new_cols);

	// Fill in the pixels by taking the average of a surrounding block
	for (int row = 0; row != new_rows; row++) {
		for (int col = 0; col != new_cols; col++) {
			int red_sum = 0, green_sum = 0, blue_sum = 0, ctr = 0;
			
			// locate the block over which we want to take the average
			for (int sub_row = row * scale; (sub_row < (row*scale + scale)) 
				&& (sub_row < rows_); sub_row++) {
				for (int sub_col = col * scale; (sub_col < (col*scale + scale))
					&& (sub_col < cols_); sub_col++) {
					red_sum += data_[sub_row*cols_ + sub_col].red;
					green_sum += data_[sub_row*cols_ + sub_col].green;
					blue_sum += data_[sub_row*cols_ + sub_col].blue;
					ctr += 1;
					//std::cout << "bdr: " << col*scale + scale << std::endl;
				}
			}
			Pixel new_pixel{red_sum/ctr, green_sum/ctr, blue_sum/ctr};
			// add the pixel 
			new_data.push_back(new_pixel);
		}
	}
	// set new values
	rows_ = new_rows;
	cols_ = new_cols;
	data_ = new_data;
}

// Upscale the image using nearest neighbor algorithm
void Image::UpScale(const int& scale){
	// set the dimensions
	int new_rows = rows_ * scale;
	int new_cols = cols_ * scale;

	// declare new data vector
	std::vector<Pixel> new_data;
	new_data.reserve(new_rows * new_cols);

	// determine the date using nearest neighbor
	for (int row = 0; row != new_rows; ++row) {
		for (int col = 0; col != new_cols; ++col) {
			// calculate which element from data_ we need to add
			int rel_row = (row-(row % scale)) / scale;
			int rel_col = (col-(col % scale)) / scale;
			new_data.push_back(data_[rel_row*cols_ + rel_col]);
		}
	}
	// set new values
	rows_ = new_rows;
	cols_ = new_cols;
	data_ = new_data;
}