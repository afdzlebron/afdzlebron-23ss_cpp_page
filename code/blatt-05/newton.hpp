#ifndef NEWTON_HPP
#define NEWTON_HPP

#include "complex.hpp"

/// Structure representing the result of applying Newton's procedure. It
/// contains to which solution the procedure converged to and the number of
/// iterations that was required.
struct Solution {
  int sol_number;
  int number_of_iterations;
};
///  classify_root (Complex a, double precision)
int classify_root(Complex a, double precision);

/// Newton procedure to find root starting at z, until the precision is reached
/// or we run of iterals
Solution converges_to(Complex z, double precision, int max_iterations);

#endif // NEWTON_HPP