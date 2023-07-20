#ifndef POLYNOM_HPP
#define POLYNOM_HPP

#include "complex.hpp"

class Polynom {
public:
  /// Calculates the value of the polynomial at a given complex number z
  Complex poly(Complex z);

  /// Calculates the value of the derivative of the polynomial at a given
  /// complex number z
  Complex derived_poly(Complex z);
};

#endif // POLYNOM_HPP
