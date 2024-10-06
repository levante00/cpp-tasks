#include <utility>

int Abs(int n) { return (n < 0) ? -n : n; }

double Ceil(double x) {
  int int_part = static_cast<int>(x);
  return (x > int_part) ? (int_part + 1) : x;
}

std::pair<int, const int*> Range(int from, int to, int step = 1) {
  if ((step > 0 && to < from) || (step < 0 && to > from) || step == 0) {
    return std::make_pair(0, nullptr);
  }

  const unsigned int kNumberCount =
      Abs(static_cast<int>(Ceil(static_cast<double>(to - from) / step)));
  int* range = new int[kNumberCount];

  for (unsigned int i = 0; i < kNumberCount; ++i) {
    range[i] = from + step * i;
  }

  return std::make_pair(kNumberCount, range);
}
