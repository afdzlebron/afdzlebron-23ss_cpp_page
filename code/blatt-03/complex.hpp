// Copyright 2023, AFL
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
#include <iostream>

struct Complex {
  double re;
  double im;
};

bool equal(Complex a, Complex b);
Complex mult(Complex a, Complex b);
Complex div(Complex a, Complex b);
Complex add(Complex a, Complex b);
Complex inverse(Complex z);
void print(Complex z);

#endif  // COMPLEX_HPP