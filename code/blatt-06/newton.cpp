#include "newton.hpp"

#include <cstdio>

#include "complex.hpp"
#include "poly.hpp"

Complex next_value(Complex z) {
  return z - Polynom::poly(z) / Polynom::derived_poly(z);
}

Solution converges_to(Complex z, double precision, int max_iterations) {
  bool finished = (z == 0);
  int root = 0, i;

  for (i = 0; i < max_iterations && !finished; ++i, z = next_value(z)) {
    root = Polynom::classify_root(z, precision);
    finished = (root != 0);
  }

  return {.sol_number = root, .number_of_iterations = i};
}
