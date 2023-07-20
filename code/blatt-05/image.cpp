#include "image.hpp"

#include <cmath>
#include <cstdio>

#include "complex.hpp"
#include "poly.hpp"

Image::Image(int width, int height) : width(width), height(height) {
  data = (int *)malloc(width * height * 3 * sizeof(int));
}

Image::~Image() { free(data); }

void Image::update_pixel(int x, int y, int r, int g, int b) {
  int offset = y * width * 3 + x * 3;
  data[offset + 0] = r;
  data[offset + 1] = g;
  data[offset + 2] = b;
}

void Image::write(const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (!fp)
    exit(-1);

  const char *comment = "# file created by Image class";

  fprintf(fp, "P3\n %s\n %d\n %d\n 255\n", comment, width, height);

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      int offset = y * width * 3 + x * 3;
      fprintf(fp, "%d %d %d ", data[offset + 0], data[offset + 1],
              data[offset + 2]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}

void Image::smooth() {
  const int field_size = 5;
  const int half_field_size = field_size / 2;

  int *smoothed_data = (int *)malloc(width * height * 3 * sizeof(int));

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      int sum_r = 0;
      int sum_g = 0;
      int sum_b = 0;
      int count = 0;

      for (int i = (y - half_field_size >= 0 ? y - half_field_size : 0);
           i <= (y + half_field_size <= height - 1 ? y + half_field_size
                                                   : height - 1);
           ++i) {
        for (int j = (x - half_field_size >= 0 ? x - half_field_size : 0);
             j <= (x + half_field_size <= width - 1 ? x + half_field_size
                                                    : width - 1);
             ++j) {
          int offset = i * width * 3 + j * 3;
          sum_r += data[offset + 0];
          sum_g += data[offset + 1];
          sum_b += data[offset + 2];
          count++;
        }
      }

      int offset = y * width * 3 + x * 3;
      smoothed_data[offset + 0] = sum_r / count;
      smoothed_data[offset + 1] = sum_g / count;
      smoothed_data[offset + 2] = sum_b / count;
    }
  }

  free(data);
  data = smoothed_data;
}
