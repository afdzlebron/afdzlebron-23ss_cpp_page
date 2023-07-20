// Copyright 2023, AFL
#include <gtest/gtest.h>

#include "complex.hpp"

TEST(ComplexTest, TestEqual) {
  Complex a = {1.0, 2.0};
  Complex b = {1.0, 2.0};
  Complex c = {2.0, 1.0};

  ASSERT_EQ(equal(a, b), true);
  ASSERT_EQ(equal(a, c), false);
}

TEST(ComplexTest, TestAdd) {
  Complex a = {1.0, 2.0};
  Complex b = {3.0, 4.0};
  Complex estm = {4.0, 6.0};

  Complex result = add(a, b);

  ASSERT_EQ(result.re, estm.re);
  ASSERT_EQ(result.im, estm.im);
}

TEST(ComplexTest, TestMult) {
  Complex a = {1.0, 2.0};
  Complex b = {3.0, 4.0};
  Complex estm = {-5.0, 10.0};

  Complex result = mult(a, b);

  ASSERT_EQ(result.re, estm.re);
  ASSERT_EQ(result.im, estm.im);
}

TEST(ComplexTest, TestDiv) {
  Complex a = {1.0, 2.0};
  Complex b = {3.0, 4.0};
  Complex estm = {0.44, 0.08};

  Complex result = div(a, b);

  ASSERT_NEAR(result.re, estm.re, 0.01);
  ASSERT_NEAR(result.im, estm.im, 0.01);
}

TEST(ComplexTest, TestInverse) {
  Complex a = {1.0, 2.0};
  Complex estm = {0.2, -0.4};

  Complex result = inverse(a);

  ASSERT_NEAR(result.re, estm.re, 0.01);
  ASSERT_NEAR(result.im, estm.im, 0.01);
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
