#include <gtest/gtest.h>

#include "complex.hpp"

#define ASSERT_COMPLEX_EQ(a, b)       \
  {                                   \
    const Complex mya = (a);          \
    const Complex myb = (b);          \
    ASSERT_DOUBLE_EQ(mya.re, myb.re); \
    ASSERT_DOUBLE_EQ(mya.im, myb.im); \
  }

TEST(complextest, add) {
  const Complex a(2, 3);
  const Complex b(3, 2);
  const Complex c = a + b;

  ASSERT_COMPLEX_EQ(a, a);
  const Complex d(6, 5);
  ASSERT_FALSE(c == d);
  const Complex e(5, 5);
  ASSERT_COMPLEX_EQ(c, e);
  ASSERT_COMPLEX_EQ(c + c, e + e);
}

TEST(complextest, mult) {
  const Complex a(2, 4);
  const Complex two(2);
  const Complex one(1);

  ASSERT_COMPLEX_EQ(a * one, a);
  ASSERT_COMPLEX_EQ(a * two, a + a);
  ASSERT_COMPLEX_EQ(a * inverse(a), one);
}

TEST(complextest, div) {
  const Complex a(2, 4);
  const Complex two(2);
  const Complex one(1);

  ASSERT_COMPLEX_EQ(a / one, a);
  ASSERT_COMPLEX_EQ(a, (a + a) / two);
  ASSERT_COMPLEX_EQ(Complex(1.) / (Complex(1.) / a), a);
}

TEST(complextest, inverse) {
  const Complex a(2, 4);
  const Complex two(2);
  const Complex one(1);

  ASSERT_COMPLEX_EQ(inverse(one), one);
  ASSERT_COMPLEX_EQ(one, a * inverse(a));
  ASSERT_COMPLEX_EQ(inverse(inverse(a)), a);
}
TEST(complextest, multdiv) {
  {
    Complex a(0, 1);
    Complex b(0, 2);
    Complex d = a / b;
    Complex e = inverse(b);
    Complex f = a * e;
    ASSERT_COMPLEX_EQ(d, f);
  }

  {
    Complex a(0, 1);
    Complex b = inverse(a);
    Complex c = a * b;
    Complex d(1);
    ASSERT_COMPLEX_EQ(c, d);
  }
}

// int main() {
//   testing::InitGoogleTest();
//   return RUN_ALL_TESTS();
// }
