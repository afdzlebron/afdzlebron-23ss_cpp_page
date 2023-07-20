#ifndef BLATT_06_NEWTON_FRACTAL
#define BLATT_06_NEWTON_FRACTAL

#include "image.hpp"

class NewtonFractal {
 public:
  explicit NewtonFractal(double x_start_, double x_step_, double x_end_,
                         double y_start_, double y_step_, double y_end_,
                         int max_iterations_, double precision_)
      : x_start(x_start_),
        x_step(x_step_),
        x_end(x_end_),
        y_start(y_start_),
        y_step(y_step_),
        y_end(y_end_),
        max_iterations(max_iterations_),
        precision(precision_) {}

  Image calculate();

 private:
  double x_start, x_step, x_end;
  double y_start, y_step, y_end;
  int max_iterations;
  double precision;
};

#endif
