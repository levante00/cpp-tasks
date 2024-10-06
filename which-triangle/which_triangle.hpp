#pragma once

#include <algorithm>
#include <cstdint>

/*
 * Верните 0 если и только если треугольник невозможно построить
 * Верните 1 если и только если треугольник вырожденный
 * Верните 2 если и только если треугольник остроугольный
 * Верните 3 если и только если треугольник прямоугольный
 * Верните 4 если и только если треугольник тупоугольный
 */

int WhichTriangle(int a, int b, int c) {
  if (a + b < c || a + c < b || b + c < a) {
    return 0;
  }

  if (a + b == c || a + c == b || c + b == a) {
    return 1;
  }

  const uint64_t kASquare = static_cast<uint64_t>(a) * a;
  const uint64_t kBSquare = static_cast<uint64_t>(b) * b;
  const uint64_t kCSquare = static_cast<uint64_t>(c) * c;

  if (kCSquare < kASquare + kBSquare && kBSquare < kASquare + kCSquare &&
      kASquare < kBSquare + kCSquare) {
    return 2;
  }

  if (kCSquare == kASquare + kBSquare || kBSquare == kASquare + kCSquare ||
      kASquare == kBSquare + kCSquare) {
    return 3;
  }

  return 4;
}