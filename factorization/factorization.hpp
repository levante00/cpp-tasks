#pragma once
#include <cmath>
#include <vector>

std::vector<int> Factorize(int n) {
  std::vector<int> number_factors;
  number_factors.reserve(static_cast<uint>(log2(n)));
  uint number = static_cast<uint>(n);

  for (uint i = 2; i * i <= number; ++i) {
    while (number % i == 0) {
      number_factors.push_back(static_cast<int>(i));
      number /= i;
    }
  }

  if (number != 1) {
    number_factors.push_back(number);
  }

  return number_factors;
}
