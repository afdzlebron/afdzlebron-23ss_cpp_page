#ifndef NEWTONFRACTAL_HPP
#define NEWTONFRACTAL_HPP

#include "complex.hpp"
#include "image.hpp"
#include "newton.hpp"
#include "newton_fractal.hpp"
#include "poly.hpp"

class NewtonFractal {
public:
  double x_start;
  double x_step;
  double x_end;
  double y_start;
  double y_step;
  double y_end;
  int max_iterations;
  double precision;
  // Constructor that takes the parameters for generating the Newton fractal as
  // arguments
  NewtonFractal(double x_start, double x_step, double x_end, double y_start,
                double y_step, double y_end, int max_iterations,
                double precision);

  // Generates the Newton fractal and returns an Image object containing the
  // generated image
  Image calculate();
};

#endif // NEWTONFRACTAL_HPP
