#pragma once

template <typename T>
void SwapIfNeeded(T& smaller_nr, T& larger_nr);

template <typename T>
T Warp(T number, T factor);

template <typename T>
int GetOrderOfMagnitude(const T& nr, const int& max_iter);

template <typename T>
int GetOrderOfMagnitude(const T& nr, const int& max_iter);

template <typename T>
int CountSameSignificantDigits(T a, T b);

#include "digit_counting.hpp"