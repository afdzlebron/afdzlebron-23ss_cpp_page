#include <gtest/gtest.h>

#include "board.hpp"
#include "stack.hpp"

TEST(StackTest, pushTest) {
  const Board a(4);
  const Board b(5);
  Stack<Board> s;

  ASSERT_TRUE(s.empty());
  s.push(a);
  assert(s.stack[0] == a);

  ASSERT_FALSE(s.empty());
  s.push(b);

  assert(s.stack[0] == a);
  ASSERT_EQ(s.stack[0], a);
  ASSERT_EQ(s.stack[1], b);

  const Board c = s.top();
  ASSERT_EQ(b, c);
  s.pop();

  const Board d = s.top();
  ASSERT_EQ(d, a);
  s.pop();

  ASSERT_TRUE(s.empty());
  s.pop();
  ASSERT_TRUE(s.empty());
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
