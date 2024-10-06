#include <sys/types.h>

int* PointwiseSum(const int* a, const int* b, int n) {
  int* result = new int[n];
  for (uint i = 0; i < static_cast<uint>(n); ++i) {
    result[i] = a[i] + b[i];
  }

  return result;
}