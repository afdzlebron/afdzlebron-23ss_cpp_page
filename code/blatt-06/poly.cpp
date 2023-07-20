#include "poly.hpp"

#include <math.h>

#include <cstdio>

Complex Polynom::poly(Complex z) { return z * z * z - 1; }

Complex Polynom::derived_poly(Complex z) { return z * z * 3; }

// We use the squared norm instead of taking the square root.
int Polynom::classify_root(Complex a, double precision) {
  const Complex z1(1, 0);
  const Complex z2(-.5, sqrt(3) / 2.);
  const Complex z3(-.5, -sqrt(3) / 2.);

  if ((a - z1).norm2() < precision * precision) return 1;
  if ((a - z2).norm2() < precision * precision) return 2;
  if ((a - z3).norm2() < precision * precision) return 3;
  return 0;
}
