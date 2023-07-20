// Copyright 2023, AFL

#include "complex.hpp"
#include "image.hpp"
#include "newton_fractal.hpp"
#include "poly.hpp"

int main() {
  int max_iterations = 100;
  // int max_iterations = 50;
  double precision = 1e-3;

  double x_start = -3.0;
  double x_end = 3.0;
  double x_step = 0.01;
  double y_start = -3.0;
  double y_end = 3.0;
  double y_step = 0.01;

  int size_x = (x_end - x_start) / x_step;
  int size_y = (y_end - y_start) / y_step;

  NewtonFractal fractal(x_start, x_step, x_end, y_start, y_step, y_end,
                        max_iterations, precision);
  Image img = fractal.calculate();
  img.smooth();
  img.write("newton_fractal.ppm");

  return 0;
}
