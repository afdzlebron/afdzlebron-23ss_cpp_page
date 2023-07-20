#include <gtest/gtest.h>
#include <math.h>

#include "image.hpp"

TEST(ImageTest, sizeTest) {
  Image test;
  ASSERT_EQ(test.x_size, 0);
  ASSERT_EQ(test.x_capacity, 1);

  // (5, 0)
  test.resize(5, 0);
  ASSERT_EQ(test.x_size, 6);
  ASSERT_EQ(test.x_capacity, 8);
  test.set_pixel(1, 0, 1, 1, 1);

  // (9, 0)
  test.resize(9, 0);
  ASSERT_EQ(test.x_size, 10);
  ASSERT_EQ(test.x_capacity, 16);
  test.set_pixel(7, 0, 1, 1, 1);

  // (0, 0)
  test.resize(0, 0);
  ASSERT_EQ(test.x_size, 10);
  ASSERT_EQ(test.x_capacity, 16);

  // (10, 0)
  test.resize(10, 0);
  ASSERT_EQ(test.x_size, 11);
  ASSERT_EQ(test.x_capacity, 16);

  // (130, 0)
  test.resize(130, 0);
  ASSERT_EQ(test.x_size, 131);
  ASSERT_EQ(test.x_capacity, 256);

  // Testing that pixels have not disappeared
  ASSERT_EQ(test.image[0 * test.x_size * 3 + 1 * 3 + 0], 1);
  ASSERT_EQ(test.image[0 * test.x_size * 3 + 7 * 3 + 0], 1);
}

// int main() {
//   testing::InitGoogleTest();
//   return RUN_ALL_TESTS();
// }
