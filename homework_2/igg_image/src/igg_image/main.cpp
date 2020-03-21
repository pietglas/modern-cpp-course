#include "image.h"
#include "io_tools.h"
#include <vector>
#include <iostream>


int main(){
	igg::Image im{2, 2};
	im.at(0, 0) = 63;
	im.at(0, 1) = 127;
	im.at(1, 0) = 191;
	im.at(1, 1) = 255;
	im.Print();
	return 0;
}