#include <complex>
#include <iostream>

#include "complex.hpp"
#include "image.hpp"
#include "newton_fractal.hpp"

// Für Aufgabe 2
void do_nothing(Image image) {}

int main() {
  // NB: it is important to change both values at the same time if you increase
  // the number of iterations make the precision close to zero. Remember than
  // Newton's method converges _fast_.
  const int max_iterations = 30;
  const double precision = 0.0001;

  // I changed the steps to 0.01 to make the code faster to run
  const double x_start = -2.5;
  const double x_end = 2.5;
  const double x_step = 0.01;
  const double y_start = -5;
  const double y_end = 5;
  const double y_step = 0.01;

  NewtonFractal frac(x_start, x_step, x_end, y_start, y_step, y_end,
                     max_iterations, precision);
  Image img = frac.calculate();
  img.smoothing();
  do_nothing(img);
  img.print_image("newton.ppm");

  return 0;
}