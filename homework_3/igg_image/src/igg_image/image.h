// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <memory>
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
  Image() {}
  Image(int rows, int cols, std::shared_ptr<IoStrategy> strategy_ptr): 
    rows_{rows}, cols_{cols}, strategy_ptr_{strategy_ptr} {
      Pixel black_pixel{0, 0, 0};
      data_.resize(rows * cols);
      std::fill(data_.begin(), data_.end(), black_pixel);
    }

  // get funtions
  const int& rows() const {return rows_;}
  const int& cols() const {return cols_;}
  const int& max_val() const {return max_val_;}

  // set strategy
  void SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr) {
    strategy_ptr_ = strategy_ptr;
  }

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
  std::shared_ptr<IoStrategy> strategy_ptr_ = nullptr;
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

}  // namespace igg
