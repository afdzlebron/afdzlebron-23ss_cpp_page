// Copyright 2023, AFL
#include <cmath>
#include <cstdio>

#include "poly.hpp"

int main() {
  //   // Printing some computations
  //   Complex a_prime = {1, 0};
  //   printf("%i", classify_root(a_prime, 1e-3));
  //   printf("\n");
  //   Complex a_prime1 = {-0.5, sqrt(3) / 2};
  //   printf("%i", classify_root(a_prime1, 1e-3));
  //   printf("\n");
  //   Complex a_prime2 = {0.5, sqrt(3) / 2};
  //   printf("%i", classify_root(a_prime2, 1e-3));
  //   printf("\n");
  //   Complex a_prime3 = {.9, 0};
  //   printf("%i", classify_root(a_prime3, 1e-3));
  //   printf("\n");
  //   Complex a_prime4 = {500, 500};
  //   printf("%i", classify_root(a_prime4, 1e-3));

  //   default_factal("fractal.ppm");

  double x_start = -3.0;
  double x_step = 0.01;
  double x_end = 3.0;
  double y_start = -3.0;
  double y_step = 0.01;
  double y_end = 3.0;
  int max_iterations = 100;
  double precision = 1e-3;

  int *image = newton_fractal(x_start, x_step, x_end, y_start, y_step, y_end,
                              max_iterations, precision);

  int size_x = (x_end - x_start) / x_step;
  int size_y = (y_end - y_start) / y_step;

  drawing_ppm("newton_fractal.ppm", image, size_x, size_y);
}
