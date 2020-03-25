#pragma once

template <typename T>
void SwapIfNeeded(T& smaller_nr, T& larger_nr);

extern template <> void SwapIfNeeded<float>(float smaller_nr, float larger_nr);
extern template <> void SwapIfNeeded<double>(double smaller_nr, double larger_nr);

template <typename T>
double Warp(T number, T factor);

extern template <> float Warp<float>(float smaller_nr, float larger_nr);
extern template <> double Warp<double>(double smaller_nr, double larger_nr);

template <typename T>
int GetOrderOfMagnitude(const T& nr);

extern template <> float GetOrderOfMagnitude<float>(const float& nr);
extern template <> double GetOrderOfMagnitude<float>(const double& nr);

template <typename T>
int GetOrderOfMagnitude(const T& nr);

extern template <> float DecimalMagnitude<float>(const float& nr);
extern template <> double DecimalMagnitude<double>(const double& nr);

template <typename T>
int CountSameSignificantDigits(T a, T b);

extern template <> int CountSameSignificantDigits<float>(float smaller_nr, float larger_nr);
extern template <> int CountSameSignificantDigits<double>(double smaller_nr, double larger_nr);