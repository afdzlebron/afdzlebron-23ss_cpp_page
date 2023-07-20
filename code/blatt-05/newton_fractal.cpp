#include "newton_fractal.hpp"

#include "complex.hpp"
#include "image.hpp"
#include "newton.hpp"
#include "poly.hpp"

NewtonFractal::NewtonFractal(double x_start, double x_step, double x_end,
                             double y_start, double y_step, double y_end,
                             int max_iterations, double precision)
    : x_start(x_start), x_step(x_step), x_end(x_end), y_start(y_start),
      y_step(y_step), y_end(y_end), max_iterations(max_iterations),
      precision(precision) {}

Image NewtonFractal::calculate() {
  const int x_size = (x_end - x_start) / x_step;
  const int y_size = (y_end - y_start) / y_step;

  Image image(x_size, y_size);

  for (int i = 0; i < y_size; ++i) {
    for (int j = 0; j < x_size; ++j) {
      const Complex starting_point = {
          x_start + j * x_step,
          y_start + i * y_step,
      };

      Solution sol = converges_to(starting_point, precision, max_iterations);
      int color =
          static_cast<int>(((double)max_iterations - sol.number_of_iterations) /
                           (double)max_iterations * (double)255);
      int r = 0;
      int g = 0;
      int b = 0;
      switch (sol.sol_number) {
      case 1:
        r = color;
        break;
      case 2:
        g = color;
        break;
      case 3:
        b = color;
        break;
      default:
        break;
      }

      image.update_pixel(j, i, r, g, b);
    }
  }

  return image;
}
