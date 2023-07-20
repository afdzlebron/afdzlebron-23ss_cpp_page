#include "image.hpp"

#include <stdio.h>

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "newton.hpp"

unsigned Image::find_max() const {
  int curr_max = 0;
  for (int y = 0; y < y_size; ++y) {
    for (int x = 0; x < x_size; ++x) {
      curr_max = std::max(curr_max, image[y * x_size * 3 + x * 3 + 0]);
      curr_max = std::max(curr_max, image[y * x_size * 3 + x * 3 + 1]);
      curr_max = std::max(curr_max, image[y * x_size * 3 + x * 3 + 2]);
    }
  }
  return curr_max;
}

void Image::print_image(const char *filename) const {
  FILE *fp = fopen(filename, "w");

  const char *comment = "# file created by Mathias Fleury";

  unsigned int curr_max = find_max();
  const int max_bound = 65535;

  const char *format = "P3";
  fprintf(fp, "%s\n %s\n %d %d\n %d\n", format, comment, x_size, y_size,
          max_bound);

  for (int y = 0; y < y_size; ++y) {
    for (int x = 0; x < x_size; ++x) {
      const int r = image[y * x_size * 3 + x * 3 + 0] * max_bound / curr_max;
      const int g = image[y * x_size * 3 + x * 3 + 1] * max_bound / curr_max;
      const int b = image[y * x_size * 3 + x * 3 + 2] * max_bound / curr_max;
      fprintf(fp, "%d %d %d ", r, g, b);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}

// resize the underlying array, copies the old content to the new array and
// delete the old one.

void Image::resize(int x, int y) {
  if (x >= x_size || y >= y_size) {
    int new_x_size = std::max(x + 1, x_size);
    int new_y_size = std::max(y + 1, y_size);

    while (new_x_size > x_capacity) {
      x_capacity *= 2;
    }
    while (new_y_size > y_capacity) {
      y_capacity *= 2;
    }
    int *new_image = (int *)malloc(x_capacity * y_capacity * 3 * sizeof(int));
    for (int i = 0; i < y_size; ++i) {
      for (int j = 0; j < x_size; ++j) {
        for (int k = 0; k < 3; ++k) {
          new_image[(i * x_capacity + j) * 3 + k] =
              image[(i * x_size + j) * 3 + k];
        }
      }
    }
    free(image);
    x_size = new_x_size;
    y_size = new_y_size;
    image = new_image;
  }
}

// setting the pixel and resizing if needed.
void Image::set_pixel(int x, int y, int r, int g, int b) {
  // Aufgabe 2 und 3
  // TODO
  resize(x, y);

  // Alte Code

  image[y * x_size * 3 + x * 3 + 0] = r;
  image[y * x_size * 3 + x * 3 + 1] = g;
  image[y * x_size * 3 + x * 3 + 2] = b;
}

// Calculate the average of the neightboling offset.  To be safe, we do not
// assume that we have at least one cell (e.g., if the given point (x,y) is
// outside of the picture.
unsigned Image::average(int x, int y, int offset) const {
  assert(offset < 3);
  int cells = 0;
  int number_of_cells = 0;
  const int size_per_side = 10;
  for (int i = x - size_per_side; i <= x + size_per_side; ++i) {
    if (i < 0 || i >= x_size) continue;
    for (int j = y - size_per_side; j <= y + size_per_side; ++j) {
      if (j < 0 || j >= y_size) continue;
      ++number_of_cells;
      cells += image[j * x_size * 3 + i * 3 + offset];
    }
  }
  return number_of_cells ? cells / number_of_cells : 0;
}

// very stupid smoothing, by simply taking the average, but makes the edges less
// sharp
void Image::smoothing() {
  int *new_image = (int *)malloc(x_size * y_size * 3 * sizeof(int));

  for (int i = 0; i < x_size; ++i) {
    for (int j = 0; j < y_size; ++j) {
      for (int col = 0; col < 3; ++col)
        new_image[j * x_size * 3 + i * 3 + col] = average(i, j, col);
    }
  }

  free(image);
  image = new_image;
}