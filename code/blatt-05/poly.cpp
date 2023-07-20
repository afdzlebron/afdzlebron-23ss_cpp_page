#include "poly.hpp"

#include "complex.hpp"

Complex Polynom::poly(Complex z) {
  Complex z3 = mult(mult(z, z), z);
  Complex one = {1, 0};
  return minus(z3, one);
}

Complex Polynom::derived_poly(Complex z) {
  Complex three = {3, 0};
  Complex z2 = mult(z, z);
  Complex z3 = mult(z2, three);
  return z3;
}
