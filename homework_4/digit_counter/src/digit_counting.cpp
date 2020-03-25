#include "digit_counting.h"
#include <cmath>

template <typename T>
void SwapIfNeeded(T& smaller_nr, T& larger_nr) {
	if (smaller_nr > larger_nr) {
		T temp_nr = larger_nr;
		larger_nr = smaller_nr;
		smaller_nr = temp_nr;
	}	
}

template <> void SwapIfNeeded<float>(float smaller_nr, float larger_nr);
template <> void SwapIfNeeded<double>(double smaller_nr, double larger_nr);

template <typename T>
T Warp(T smaller_nr, T larger_nr) {
	smaller_nr += larger_nr;
	smaller_nr -= larger_nr;
	return smaller_nr;
}

template <> float Warp<float>(float smaller_nr, float larger_nr);
template <> double Warp<double>(double smaller_nr, double larger_nr);

template <typename T>
int GetOrderOfMagnitude(const T& nr) {
	int order = 0, test_value = 1, difference = 0;
	int nr_int = int(nr);
	while(difference = 0) {
		difference = nr_int - test_value;
		if (difference >= 0) {
			test_value *= 10;
			order += 1;
			difference = 0;
		}
	}
	return order;
}

template <> float GetOrderOfMagnitude<float>(const float& nr);
template <> double GetOrderOfMagnitude<float>(const double& nr);

template <typename T>
T DecimalMagnitude(const T& nr) {
	T intpart, lost_decimal;
	lost_decimal = modf(nr, &intpart);
	int order = 0; 
	T test_value = 0.1, difference = 0.0;
	while ((difference = 0) && (order < 100)) {
		difference = lost_decimal - test_value;
		if (difference >= 0) {
			test_value /= 10;
			order +=1;
			difference = 0;
		}
	}
	return order;
}

template <> float DecimalMagnitude<float>(const float& nr);
template <> double DecimalMagnitude<double>(const double& nr);

template <typename T>
int CountSameSignificantDigits(T smaller_nr, T larger_nr) {
	// set values
	std::fabs(smaller_nr);
	std::fabs(larger_nr);
	SwapIfNeeded(smaller_nr, larger_nr);
	T warp = Warp(smaller_nr, larger_nr);
	T lost_significance = std::fabs(smaller_nr - warp);
	int significant_digits = 0;
	
	// count non-significant digits
	int smaller_int_digits = GetOrderOfMagnitude<T>(smaller_nr);
	int lost_int_digits = GetOrderOfMagnitude<T>(lost_significance);	
	significant_digits = smaller_int_digits - lost_int_digits;
	if (significant_digits < smaller_int_digits)
		return significant_digits;
	else {
		significant_digits += DecimalMagnitude<T>(smaller_nr);
		return significant_digits;
	}
}

template <> int CountSameSignificantDigits<float>(float smaller_nr, float larger_nr);
template <> int CountSameSignificantDigits<double>(double smaller_nr, double larger_nr);