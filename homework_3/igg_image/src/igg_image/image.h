// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "io_strategies/strategy.h" 

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  // Constructors. If arguments rows and cols are provided, initialize a black image. 
  Image(const IoStrategy& io_strategy): io_strategy_{io_strategy} {}
  Image(int rows, int cols, const IoStrategy& io_strategy): rows_{rows}, cols_{cols}, 
    io_strategy_{io_strategy} {
      Pixel black_pixel{0, 0, 0};
      data_.reserve(rows * cols);
      for (int i = 0; i != rows*cols; i++)
        data_.push_back(black_pixel);
    }

  // get funtions
  const int& rows() const {return rows_;}
  const int& cols() const {return cols_;}
  const int& max_val() const {return max_val_;}

  // access or set individual pixel values
  Pixel at(const int& row, const int& col) const {return data_.at(cols_*row + col);}
  Pixel& at(const int& row, const int& col) {return data_.at(cols_*row + col);}

  // print data_
  void Print() const {
    std::cout << "Printing data (order; red, green, blue): " << std::endl;
    for (auto it = data_.begin(); it != data_.end(); it++)
      std::cout << (*it).red << ", " << (*it).green << ", " << (*it).blue << std::endl;
  }

  // I/O
  bool ReadFromDisk(const std::string& file_name);
  bool WriteToDisk(const std::string& file_name) const;

  // resize the image using nearest neighbor algorithm
  void DownScale(const int& scale);
  void UpScale(const int& scale);

 private:
  const IoStrategy& io_strategy_;
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

}  // namespace igg
