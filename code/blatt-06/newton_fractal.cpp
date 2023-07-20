#include "newton_fractal.hpp"

#include <cstdio>
#include <cstdlib>

#include "image.hpp"
#include "newton.hpp"

Image NewtonFractal::calculate() {
  const int x_size = (x_end - x_start) / x_step;
  const int y_size = (y_end - y_start) / y_step;
  printf("%d", x_size);

  Image img(x_size, y_size);

  for (int i = 0; i < y_size; ++i) {
    for (int j = 0; j < x_size; ++j) {
      const Complex starting_point(x_start + j * x_step, y_start + i * y_step);

      Solution sol = converges_to(starting_point, precision, max_iterations);
      int color =
          static_cast<int>(((double)max_iterations - sol.number_of_iterations) /
                           (double)max_iterations * (double)255);

      int red = 0;
      int green = 0;
      int blue = 0;
      switch (sol.sol_number) {
        case 1:
          red = color;
          break;
        case 2:
          green = color;
          break;
        case 3:
          blue = color;
          break;
        default:
          break;
      }

      img.set_pixel(j, i, red, green, blue);
    }
  }

  return img;
}