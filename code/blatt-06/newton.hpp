#ifndef BLATT_06_NEWTON
#define BLATT_06_NEWTON

#include "complex.hpp"

// Structure representing the result of applying Newton's procedure. It contains
// to which solution the procedure converged to and the number of iterations
// that was required.
struct Solution {
  int sol_number;
  int number_of_iterations;
};

// Newton procedure to find root starting at z, until the precision is reached
// or we run of iterals
Solution converges_to(Complex z, double precision, int max_iterations);

#endif
