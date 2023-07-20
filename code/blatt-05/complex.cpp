#include "complex.hpp"

#include <cstdio>

// x+iy + (x'+iy') = (x+x') + i (y+y')
Complex add(Complex a, Complex b) {
  Complex c;
  c.im = a.im + b.im;
  c.re = a.re + b.re;
  return c;
}

// (x+iy) * (x'+iy') = xx' - yy' + i (xy' +x'y)
Complex mult(Complex a, Complex b) {
  Complex c;
  c.re = a.re * b.re - a.im * b.im;
  c.im = a.re * b.im + a.im * b.re;
  return c;
}

// -(x+iy) = -x + i*(-y)
Complex unary_minus(Complex a) {
  Complex c;
  c.re = -a.re;
  c.im = -a.im;
  return c;
}

bool equal(Complex a, Complex b) { return (a.re == b.re) && (a.im == b.im); }

// (x+iy) / (x'+iy') = (x+iy) * (x'-iy') / (x'^2 - y'^2)
// = (xx' + yy') / (x'^2 - y'^2) + i * (-xy' + x'y) / (x'^2 - y'^2)
Complex div(Complex a, Complex b) {
  Complex c;
  const double norm = (b.re * b.re + b.im * b.im);
  c.re = (a.re * b.re + a.im * b.im) / norm;
  c.im = (-a.re * b.im + a.im * b.re) / norm;
  return c;
}

// 1/ (x+iy) = (x-iy) / (x^2 - y^2)
Complex inverse(Complex a) {
  Complex c;
  const double norm = (a.re * a.re + a.im * a.im);
  c.re = a.re / norm;
  c.im = -a.im / norm;
  return c;
}

void print(Complex a) { printf("%f +i * %f\n", a.re, a.im); }

double norm2(Complex a) { return (a.re * a.re + a.im * a.im); }

Complex minus(Complex a, Complex b) { return add(a, unary_minus(b)); }
