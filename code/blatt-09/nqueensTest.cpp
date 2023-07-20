#include <gtest/gtest.h>

#include "nqueens.hpp"

int create_nqueens_and_count(int n) {
  NQueens queens(n);
  return queens.count_solutions();
}
TEST(NQueensTest, ValueTest) {
  ASSERT_EQ(create_nqueens_and_count(4), 2);
  ASSERT_EQ(create_nqueens_and_count(5), 10);
  ASSERT_EQ(create_nqueens_and_count(6), 4);
  ASSERT_EQ(create_nqueens_and_count(7), 40);
  ASSERT_EQ(create_nqueens_and_count(8), 92);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
