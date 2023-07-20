#include "newton.hpp"
#include <cmath>
#include <cstdio>

#include "poly.hpp"

Complex next_value(Complex z) {
  Polynom p;
  Complex x = div(p.poly(z), p.derived_poly(z));
  return minus(z, x);
}

// We use the squared norm instead of taking the square root.
// Therefore, we square the precision.
int classify_root(Complex a, double precision) {
  const Complex z1 = {1, 0};
  const Complex z2 = {-.5, sqrt(3) / 2.};
  const Complex z3 = {-.5, -sqrt(3) / 2.};

  if (norm2(minus(a, z1)) < precision * precision)
    return 1;
  if (norm2(minus(a, z2)) < precision * precision)
    return 2;
  if (norm2(minus(a, z3)) < precision * precision)
    return 3;
  return 0;
}

Solution converges_to(Complex z, double precision, int max_iterations) {
  bool finished = false;
  int root = 0, i;

  for (i = 0; i < max_iterations && !finished; ++i, z = next_value(z)) {
    root = classify_root(z, precision);
    finished = (root != 0);
  }

  return {root, i};
}
