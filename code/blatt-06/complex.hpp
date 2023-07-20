#ifndef BLATT_06_COMPLEX_HPP
#define BLATT_06_COMPLEX_HPP

// very simple modelisation of complex numbers with a real part and an imaginary
// part. We put into a namespace to avoid issue with std::equal...
class Complex {
 public:
  Complex(double real, double imaginary) : re(real), im(imaginary) {}
  Complex(double real) : re(real), im(0) {}
  Complex() : re(0), im(0) {}
  // square absolute value
  double re;
  double im;
  double norm2();

  Complex operator*(const Complex&) const;
  Complex operator+(const Complex&) const;
  Complex operator-(const Complex&) const;
  bool operator==(const Complex&) const;
  Complex operator/(const Complex&) const;
};

Complex unary_minus(Complex);

/// inverse of complex numbers. The second should not be zero.
Complex inverse(Complex);

#endif
