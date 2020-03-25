#pragma once

#include <cmath>
#include <iostream>

template <typename T>
void SwapIfNeeded(T& smaller_nr, T& larger_nr) {
	if (smaller_nr > larger_nr) {
		T temp_nr = larger_nr;
		larger_nr = smaller_nr;
		smaller_nr = temp_nr;
	}	
}

template <typename T>
T Warp(T smaller_nr, T larger_nr) {
	smaller_nr += larger_nr;
	smaller_nr -= larger_nr;
	return smaller_nr;
}

template <typename T>
int GetOrderOfMagnitude(const T& nr, const int& max_iter) {
	int order = 0, test_value = 1, difference = 0;
	int nr_int = int(nr);
	while((difference == 0.0) && (order < max_iter)) {
		difference = nr_int - test_value;
		if (difference >= 0) {
			test_value *= 10;
			order += 1;
			difference = 0.0;
		}
	}
	return order;
}

template <typename T>
T DecimalMagnitude(const T& nr, const int& max_iter) {
	int nr_int = int(nr);
	T lost_decimal = nr - nr_int;		// in general, this can be ill-behaved for float (?)
	std::cout << "remainder: " << lost_decimal << std::endl;
	int order = 0; 
	T test_value = 0.1, difference = 0.0;
	while ((difference == 0.0) && (order < max_iter)) {
		difference = lost_decimal - test_value;
		std::cout << "difference: " << difference << std::endl;
		if (difference < 0) {
			test_value /= 10;
			order +=1;
			difference = 0.0;
		}
	}
	return order;
}

template <typename T>
int CountSameSignificantDigits(T smaller_nr, T larger_nr) {
	// set values
	std::fabs(smaller_nr);
	std::fabs(larger_nr);
	SwapIfNeeded<T>(smaller_nr, larger_nr);
	T warp = Warp(smaller_nr, larger_nr);
	T lost_significance = std::fabs(smaller_nr - warp);
	int smaller_int_digits = GetOrderOfMagnitude<T>(smaller_nr, 100);
	int lost_int_digits = GetOrderOfMagnitude<T>(lost_significance, 100);
	int significant_digits = smaller_int_digits - lost_int_digits;
	if (significant_digits == smaller_int_digits)
		significant_digits += DecimalMagnitude<T>(smaller_nr, 100);
	
	return significant_digits;
}