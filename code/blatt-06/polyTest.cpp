#include <gtest/gtest.h>
#include <math.h>

#include "poly.hpp"

#define ASSERT_COMPLEX_EQ(a, b)       \
  {                                   \
    const Complex mya = (a);          \
    const Complex myb = (b);          \
    ASSERT_DOUBLE_EQ(mya.re, myb.re); \
    ASSERT_DOUBLE_EQ(mya.im, myb.im); \
  }

TEST(PolyTest, poly) {
  const Complex zero(0);
  const Complex z1(1);
  const Complex z2(-.5, sqrt(3) / 2.);
  const Complex z3(-.5, -sqrt(3) / 2.);
  ASSERT_COMPLEX_EQ(Polynom::poly(z1), zero);
  ASSERT_TRUE(Polynom::poly(z2).norm2() < 0.00000000001);
  ASSERT_TRUE(Polynom::poly(z3).norm2() < 0.00000000001);
}

TEST(PolyTest, derived_poly) {
  ASSERT_COMPLEX_EQ(Polynom::derived_poly(1), 3);
  ASSERT_COMPLEX_EQ(Polynom::derived_poly(0), 0);
}

TEST(PolyTest, classify_root) {
  const Complex z1(1);
  const Complex z2(-.5, sqrt(3) / 2.);
  const Complex z3(-.5, -sqrt(3) / 2.);
  const double precision = 0.00001;
  const int r1 = Polynom::classify_root(z1, precision);
  const int r2 = Polynom::classify_root(z2, precision);
  const int r3 = Polynom::classify_root(z3, precision);
  ASSERT_TRUE(r1 != r2);
  ASSERT_TRUE(r1 != r3);
  ASSERT_TRUE(r2 != r3);
  const int r4 = Polynom::classify_root(z3 + z3, precision);
  ASSERT_TRUE(r4 == 0);
}

// int main() {
//   testing::InitGoogleTest();
//   return RUN_ALL_TESTS();
// }
