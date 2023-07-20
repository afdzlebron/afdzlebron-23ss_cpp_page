// Copyright 2023, AFL
#ifndef POLY_HPP
#define POLY_HPP

struct Complex {
  double re;
  double im;
};

bool equal(Complex, Complex);

Complex mult(Complex, Complex);

Complex div(Complex, Complex);

Complex add(Complex, Complex);

Complex inverse(Complex);

Complex sub(Complex a, Complex b);

void print(Complex);

Complex poly(Complex);

Complex derived_poly(Complex);

Complex newtonMethod(Complex z);

int nearRoot(Complex x, double precision);

int classify_root(Complex z, double precision);

void default_factal(const char *filename);

int *newton_fractal(double x_start, double x_step, double x_end, double y_start,
                    double y_step, double y_end, int max_iterations,
                    double precision);

void drawing_ppm(const char *filename, int *image, int size_x, int size_y);

#endif // POLY_HPP
