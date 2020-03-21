#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace igg {

class Image {
public:
  	// Constructors
  	Image() {}
  	Image(int rows, int cols): rows_{rows}, cols_{cols} {
  		  // resize data_
  		  data_.reserve(rows*cols);
        for (int i = 0; i != rows*cols; ++i)
            data_.push_back(0);
  	}

  	// get funtions
  	const int& rows() const {return rows_;}
  	const int& cols() const {return cols_;}

  	// access or set individual pixel values
  	int at(const int& row, const int& col) const {return data_.at(rows_*row + col);}
  	int& at(const int& row, const int& col) {return data_.at(rows_*row + col);}

    // print data_
    void Print() const {
        for (auto it = data_.begin(); it != data_.end(); it++)
            std::cout << *it << std::endl;
    }

  	// Fill data from disk from a *.pgm file. Return true if succesful 
  	bool FillFromPgm(const std::string& file_name);
  	// Write data to a *.pgm file. 
  	void WriteToPgm(const std::string& file_name);

  	// Compute histogram over the pixels
  	std::vector<float> ComputeHistogram(const int& bins) const;

  	// resize the image using nearest neighbor algorithm
  	void DownScale(const int& scale);
  	void UpScale(const int& scale);

private:
    int rows_ = 0;
  	int cols_ = 0;
  	int max_val_ = 255;
  	std::vector<int> data_;
};

}  // namespace igg
