// Copyright 2023, AFL
#include "complex.hpp"
#include <cstdio>

bool equal(Complex z1, Complex z2) {
    return (z1.re == z2.re) && (z1.im == z2.im);
}

Complex mult(Complex z1, Complex z2) {
    Complex result;
    result.re = z1.re * z2.re - z1.im * z2.im;
    result.im = z1.re * z2.im + z1.im * z2.re;
    return result;
}

Complex div(Complex z1, Complex z2) {
    double div = z2.re * z2.re + z2.im * z2.im;
    Complex result;
    result.re = (z1.re * z2.re + z1.im * z2.im) / div;
    result.im = (z1.im * z2.re - z1.re * z2.im) / div;
    return result;
}

Complex add(Complex z1, Complex z2) {
    Complex result;
    result.re = z1.re + z2.re;
    result.im = z1.im + z2.im;
    return result;
}

Complex inverse(Complex z) {
    double div = z.re * z.re + z.im * z.im;
    Complex result;
    result.re = z.re / div;
    result.im = -z.im / div;
    return result;
}

void print(Complex z) {
    printf("(%g + %gi)", z.re, z.im);
}

// int main() {}
