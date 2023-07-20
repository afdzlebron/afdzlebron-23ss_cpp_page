#ifndef COMPLEX_HPP
#define COMPLEX_HPP

/// Represents a complex number (CN) with real (re) and imaginary (im) parts
struct Complex {
  double re;
  double im;
};

/// Check if two CNs are equal
bool equal(Complex a, Complex b);

/// Multiply two CNs
Complex mult(Complex a, Complex b);

/// Divide two CNs
Complex div(Complex a, Complex b);

/// Add two CNs
Complex add(Complex a, Complex b);

// -z
Complex unary_minus(Complex);

/// Calculate the inverse of a CN. The argument should not be zero.
Complex inverse(Complex);

/// Print a CN with a line break
void print(Complex);

// square absolute value
double norm2(Complex);

// Subtract two CNs
Complex minus(Complex, Complex);

#endif // COMPLEX_HPP