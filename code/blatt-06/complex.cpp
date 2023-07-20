#include "complex.hpp"

#include <cassert>
#include <cstdio>

// x+iy + (x'+iy') = (x+x') + i (y+y')
Complex Complex::operator+(const Complex& other) const {
  return Complex(re + other.re, im + other.im);
}
// (x+iy) * (x'+iy') = xx' - yy' + i (xy' +x'y)
Complex Complex::operator*(const Complex& other) const {
  return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}
// -(x+iy) = -x + i*(-y)
Complex unary_minus(Complex a) {
  Complex c;
  c.re = -a.re;
  c.im = -a.im;
  return c;
}

bool Complex::operator==(const Complex& b) const {
  return re == b.re && im == b.im;
}
// (x+iy) / (x'+iy') = (x+iy) * (x'-iy') / (x'^2 - y'^2)
// = (xx' + yy') / (x'^2 - y'^2) + i * (-xy' + x'y) / (x'^2 - y'^2)
Complex Complex::operator/(const Complex& b) const {
  double denominator = b.re * b.re + b.im * b.im;
  return Complex((re * b.re + im * b.im) / denominator,
                 (im * b.re - re * b.im) / denominator);
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

double Complex::norm2() { return (this->re * this->re + this->im * this->im); }

Complex Complex::operator-(const Complex& b) const {
  return Complex(re - b.re, im - b.im);
}

// namespace Complex
