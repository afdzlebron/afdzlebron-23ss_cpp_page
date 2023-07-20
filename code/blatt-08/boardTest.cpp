#include <gtest/gtest.h>

#include "board.hpp"

TEST(BoardTest, nextTest) {
  Board b(3);
  b.board[0] = -1;

  ASSERT_TRUE(b.has_next(true));

  b.next(true);
  ASSERT_EQ(b.board[0], 2);

  ASSERT_TRUE(b.has_next(false));
  b.next(false);
  ASSERT_EQ(b.board[0], 2);
  ASSERT_EQ(b.board[1], -1);

  ASSERT_TRUE(b.has_next(false));
  b.next(false);
  ASSERT_EQ(b.board[0], 2);
  ASSERT_EQ(b.board[1], -2);

  ASSERT_FALSE(b.has_next(false));

  ASSERT_TRUE(b.has_next(true));
  b.next(true);
  ASSERT_EQ(b.board[0], 2);
  ASSERT_EQ(b.board[1], 3);
  ASSERT_EQ(b.size, 3);

  ASSERT_TRUE(b.has_next(true));
  b.next(true);
  ASSERT_EQ(b.board[0], 2);
  ASSERT_EQ(b.board[1], 3);
  ASSERT_EQ(b.board[2], 1);
  ASSERT_EQ(b.size, 3);
}

TEST(BoardTest, stringTest) {
  Board b(3);
  b.board[0] = 3;
  b.board[1] = 1;
  b.board[2] = 2;

  std::stringstream b_position;
  b_position << b;
  ASSERT_EQ(b_position.str(), "| |d| |\n"
                              "| | |d|\n"
                              "|d| | |\n");
  b.board[0] = -3;
  b.board[1] = 1;
  b.board[2] = 2;

  std::stringstream c_position;
  c_position << b;
  ASSERT_EQ(c_position.str(), "|.|d| |\n"
                              "|.| |d|\n"
                              "|.| | |\n");
}

TEST(BoardTest, validTest) {
  Board b(4);
  b.board[0] = 3;
  b.board[1] = 1;
  b.board[2] = 4;
  b.board[3] = 2;
  ASSERT_TRUE(b.is_valid());

  b.board[3] = -2;
  ASSERT_TRUE(b.is_valid());

  b.board[3] = 1;
  ASSERT_FALSE(b.is_valid());

  b.board[0] = 1;
  b.board[1] = -1;
  b.board[2] = -4;
  b.board[3] = 4;
  ASSERT_FALSE(b.is_valid());

  b.board[0] = 4;
  b.board[1] = 2;
  b.board[2] = 0;
  b.board[3] = 0;
  ASSERT_TRUE(b.is_valid());

  b.board[0] = 4;
  b.board[1] = 1;
  b.board[2] = 0;
  b.board[3] = 0;
  ASSERT_TRUE(b.is_valid());
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
