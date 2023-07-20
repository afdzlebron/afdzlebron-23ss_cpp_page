#ifndef BLATT_06_POLY
#define BLATT_06_POLY

#include <gtest/gtest.h>

#include "complex.hpp"

// Encompasses all calculation related to a polynom.
// We use static to avoid create a dummy object, but
// creating the object would work too.
class Polynom {
 public:
  // p: z -> z^3 - 1
  static Complex poly(Complex);
  // p: z -> 3*z^2
  static Complex derived_poly(Complex);

  // returns the number of the root
  static int classify_root(Complex a, double precision);

  FRIEND_TEST(PolyTest, poly);
  FRIEND_TEST(PolyTest, derived_poly);
  FRIEND_TEST(PolyTest, classify_root);
};

#endif
