// Copyright 2023, AFL
#include <gtest/gtest.h>

#include "poly.hpp"

TEST(PolyTest, OnComplex2_0) {
  Complex a = {2, 0};
  Complex expected_result{7, 0};
  EXPECT_TRUE(equal(poly(a), expected_result));
}

TEST(PolyTest, OnComplex2_3) {
  Complex b = {2, 3};
  Complex expected_result{-47, 9};
  EXPECT_TRUE(equal(poly(b), expected_result));
}

TEST(PolyTest, OnComplex2_4) {
  Complex c = {2, 4};
  Complex expected_result{-89, -16};
  EXPECT_TRUE(equal(poly(c), expected_result));
}

TEST(PolyTest, OnComplex3_2) {
  Complex d = {3, 2};
  Complex expected_result{-10, 46};
  EXPECT_TRUE(equal(poly(d), expected_result));
}

TEST(PolyTest, OnComplex6_5) {
  Complex e = {6, 5};
  Complex expected_result{-235, 415};
  EXPECT_TRUE(equal(poly(e), expected_result));
}

TEST(derived_PolyTest, OnComplex2_0) {
  Complex a = {2, 0};
  Complex expected_result{12, 0};
  EXPECT_TRUE(equal(derived_poly(a), expected_result));
}

TEST(derived_PolyTest, OnComplex2_3) {
  Complex b = {2, 3};
  Complex expected_result{-15, 36};
  EXPECT_TRUE(equal(derived_poly(b), expected_result));
}

TEST(derived_PolyTest, OnComplex2_4) {
  Complex c = {2, 4};
  Complex expected_result{-36, 48};
  EXPECT_TRUE(equal(derived_poly(c), expected_result));
}

TEST(derived_PolyTest, OnComplex3_2) {
  Complex d = {3, 2};
  Complex expected_result{15, 36};
  EXPECT_TRUE(equal(derived_poly(d), expected_result));
}

TEST(derived_PolyTest, OnComplex6_5) {
  Complex e = {6, 5};
  Complex expected_result{33, 180};
  EXPECT_TRUE(equal(derived_poly(e), expected_result));
}
