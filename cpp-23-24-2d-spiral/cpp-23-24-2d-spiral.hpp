#include <sys/types.h>

int** MakeSpiral(int n) {
  if (n <= 0) {
    return nullptr;
  }
  int** result = new int*[n];
  uint left = 0;
  uint right = n - 1;
  uint top = 0;
  uint bottom = n - 1;
  uint i;
  uint j;
  uint val = 0;

  for (i = 0; i < static_cast<uint>(n); ++i) {
    result[i] = new int[n];
  }

  while (top < bottom && left < right) {
    i = top;
    j = left;

    while (j < right) {
      result[top][j++] = ++val;
    }
    while (i < bottom) {
      result[i++][right] = ++val;
    }
    while (j > left) {
      result[bottom][j--] = ++val;
    }
    while (i > top) {
      result[i--][left] = ++val;
    }
    --right;
    ++left;
    --bottom;
    ++top;
  }
  if (n % 2 == 1) {
    result[n / 2][n / 2] = ++val;
  }

  return result;
}