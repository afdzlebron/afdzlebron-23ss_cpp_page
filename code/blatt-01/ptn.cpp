// Copyright 2023, AFL

#include <cmath>
#include <cstdio>

bool is_pythagorean_triple(int n, bool verbose) {
  for (int a = 1; a <= n; a++) {
    for (int b = a; b <= n; b++) {
      int c_square = a * a + b * b;
      int c = sqrt(c_square);
      if (c * c == c_square && c <= n) {
        if (verbose) {
          printf("%d^2 = %d^2 + %d^2\n", c, a, b);
        }
        return true;
      }
    }
  }
  return false;
}
