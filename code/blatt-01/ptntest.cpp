// Copyright 2023, AFL

#include <gtest/gtest.h>

#include "./ptn.cpp"

TEST(ptn, is_pythagorean_triple) {
  ASSERT_EQ(false, is_pythagorean_triple(1, false));
  ASSERT_EQ(false, is_pythagorean_triple(2, false));
  ASSERT_EQ(false, is_pythagorean_triple(3, false));
  ASSERT_EQ(false, is_pythagorean_triple(4, false));
  ASSERT_EQ(true, is_pythagorean_triple(5, false));
  ASSERT_EQ(true, is_pythagorean_triple(6, false));
  ASSERT_EQ(true, is_pythagorean_triple(7, false));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// g++ -std=c++0x ptntest.cpp -lgtest -lgtest_main -o ptntest
