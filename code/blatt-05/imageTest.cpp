#include "image.hpp"
#include "gtest/gtest.h"

TEST(ImageTest, atX0Y0_UpdateR) {
  Image image(2, 2);
  image.update_pixel(0, 0, 255, 0, 0);
  EXPECT_EQ(image.data[0], 255);
  EXPECT_EQ(image.data[1], 0);
  EXPECT_EQ(image.data[2], 0);
}

TEST(ImageTest, atX2Y1_UpdateRGB) {
  Image image(4, 4);
  image.update_pixel(2, 1, 100, 100, 100);
  int offset = (1 * image.width * 3) + (2 * 3);
  EXPECT_EQ(image.data[offset + 0], 100);
  EXPECT_EQ(image.data[offset + 1], 100);
  EXPECT_EQ(image.data[offset + 2], 100);
}

TEST(ImageTest, atX1Y1_UpdateRGB_Multiple) {
  Image image(2, 2);
  image.update_pixel(1, 1, 50, 50, 50);
  int offset = (1 * image.width * 3) + (1 * 3);
  EXPECT_EQ(image.data[offset + 0], 50);
  EXPECT_EQ(image.data[offset + 1], 50);
  EXPECT_EQ(image.data[offset + 2], 50);

  image.update_pixel(1, 1, 100, 100, 100);
  offset = (1 * image.width * 3) + (1 * 3);
  EXPECT_EQ(image.data[offset + 0], 100);
  EXPECT_EQ(image.data[offset + 1], 100);
  EXPECT_EQ(image.data[offset + 2], 100);

  image.update_pixel(1, 1, -10, -10, -10); // negative values
  offset = (1 * image.width * 3) + (1 * 3);
  EXPECT_EQ(image.data[offset + 0], -10);
  EXPECT_EQ(image.data[offset + 1], -10);
  EXPECT_EQ(image.data[offset + 2], -10);
}
