#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "io_tools.h"
#include "image.h" 

using namespace igg;

// Fill data from disk from a *.pgm file. Return true if succesful
bool Image::FillFromPgm(const std::string& file_name) {
  	io_tools::ImageData image_data = io_tools::ReadFromPgm(file_name);	// save data in a struct

  	// If the returned struct is nonempty, set values
  	if (image_data.data.size() == 0) {
  		// set values
  		rows_ = image_data.rows;
  		cols_ = image_data.cols;
  		max_val_ = image_data.max_val;
  		data_.reserve(image_data.data.size());	// reserve memory 
  		for (int i = 0; i != data_.size(); ++i) {
  			data_.push_back(image_data.data[i]); 
  		}
  		return true;
  	}

  	// return false if the returned struct is empty 
  		else
 			return false;
}

// Write data to a *.pgm file. 
void Image::WriteToPgm(const std::string& file_name) {
	io_tools::ImageData image_data{rows_, cols_, max_val_, data_};	// save data in struct
	bool write = io_tools::WriteToPgm(image_data, file_name);	// write data to file
  		
  	// Notify if the writing did not succeed. 
  	if (!write) {
  		std::cout << "Something went wrong in the writing proces" << std::endl;
  	}
}

// Compute histogram over the pixels
std::vector<float> Image::ComputeHistogram(const int& bins) const {
	// Declare the histogram vector, allocate sufficient memory
	std::vector<float> histogram;
	histogram.reserve(bins);

	// The following vector will contain the pixels not contained in previous bins
	std::vector<int> remaining_pixels = data_;

	for (int bin_count = 0; bin_count != bins; bin_count++) {
		// this vector will contain all pixels not in this or any previous bin
		std::vector<int> remaining_pixels_updated;
		remaining_pixels_updated.reserve(remaining_pixels.size());

		// set bin_count to float to ensure that division returns proper float
		float bin_count_fl = bin_count;

		// set counters for pixels in this binary                       
		float pixels_in_this_binary = 0;
		float pixels_in_this_binary_norm = 0;

		// set upper boundary for current bin	
		float bin_upper_bound = ((bin_count_fl+1)/bins) * max_val_;
		
		// check among the remaining pixels if they belong to this bin
		for (int i : remaining_pixels) {

			// add pixel to binary if it falls within the binary region. else, add it
			// to remaining pixels.  
			if (i <= bin_upper_bound) 
				pixels_in_this_binary += 1;
			else
				remaining_pixels_updated.push_back(i);
		}
		// normalize the number of pixels in the bin
		pixels_in_this_binary_norm = pixels_in_this_binary / data_.size();
		histogram.push_back(pixels_in_this_binary_norm);

		// remove the pixels added to this bin from the remaining pixels
		remaining_pixels = remaining_pixels_updated; 
	}
	return histogram;
}

// Downscale the image. 
void Image::DownScale(const int& scale){
	// set the dimensions, neglect decimal part. 
	int new_rows = rows_ / scale;
	int new_cols = cols_ / scale;

	// declare the new data
	std::vector<int> new_data;
	new_data.reserve(new_rows * new_cols);

	// Fill in the pixels by taking the average of a surrounding block
	for (int row = 0; row != new_rows; row++) {
		for (int col = 0; col != new_cols; col++) {
			int new_pixel;
			int sum = 0, ctr = 0;
			std::cout << "row " << row << "; col " << col << std::endl;
			// locate the block over which we want to take the average
			for (int sub_row = row * scale; (sub_row < (row*scale + scale)) 
				&& (sub_row < rows_); sub_row++) {
				//std::cout << "sub row: " << sub_row << std::endl;
				for (int sub_col = col * scale; (sub_col < (col*scale + scale))
					&& (sub_col < cols_); sub_col++) {
					//std::cout << "sub col: " << sub_col << std::endl;
					sum += data_[sub_row*cols_ + sub_col];
					ctr += 1;
					//std::cout << "bdr: " << col*scale + scale << std::endl;
				}
			}
			new_pixel = sum / ctr;
			//std::cout << "pixel at row " << row << ", col " << col << ": " 
			<< new_pixel << std::endl;
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
	std::vector<int> new_data;
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