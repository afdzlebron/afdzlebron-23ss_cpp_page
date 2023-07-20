// Copyright 2023, AFL
#include "poly.hpp"

#include <cmath>
#include <cstdio>

bool equal(Complex a, Complex b) { return (a.re == b.re) && (a.im == b.im); }

Complex mult(Complex a, Complex b) {
  Complex result;
  result.re = a.re * b.re - a.im * b.im;
  result.im = a.re * b.im + a.im * b.re;
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

Complex div(Complex a, Complex b) {
  double div = b.re * b.re + b.im * b.im;
  Complex result;
  result.re = (a.re * b.re + a.im * b.im) / div;
  result.im = (a.im * b.re - a.re * b.im) / div;
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

Complex add(Complex a, Complex b) {
  Complex result;
  result.re = a.re + b.re;
  result.im = a.im + b.im;
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

Complex inverse(Complex z) {
  double div = z.re * z.re + z.im * z.im;
  Complex result;
  result.re = z.re / div;
  result.im = -z.im / div;
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

Complex sub(Complex a, Complex b) {
  Complex result;
  result.re = a.re - b.re;
  result.im = a.im - b.im;
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

void print(Complex z) { printf("(%g + %gi)", z.re, z.im); }

Complex poly(Complex z) {
  Complex minus_one = {-1, 0};
  Complex result = mult(z, mult(z, z));
  result = add(result, minus_one);
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

Complex derived_poly(Complex z) {
  Complex three = {3, 0};
  Complex result = mult(three, mult(z, z)); // 3*z^2
  if (std::isnan(result.re) && std::isnan(result.im)) {
    result.re = 0;
    result.im = 0;
  }
  return result;
}

Complex newtonMethod(Complex z) {
  Complex x = z;
  Complex fx = poly(x);
  Complex fxPrime = derived_poly(x);
  Complex fraction = div(fx, fxPrime);
  x = sub(x, fraction);
  return x;
}
int nearRoot(Complex x, double precision) {
  Complex roots[] = {{1, 0}, {-0.5, sqrt(3) / 2}, {-0.5, -sqrt(3) / 2}};
  double distance = precision * 2;
  for (int i = 0; i < 3; i++) {
    distance = sqrt((x.re - roots[i].re) * (x.re - roots[i].re) +
                    (x.im - roots[i].im) * (x.im - roots[i].im));
    if (distance <= precision) {
      return i + 1;
    }
  }
  return 0;
}

int classify_root(Complex z, double precision) {
  Complex x = z;
  Complex roots[] = {{1, 0}, {0.5, sqrt(3) / 2}, {-0.5, -sqrt(3) / 2}};
  int calc = 0;
  int steps = 0;
  const int max_steps = 20;

  while (steps < max_steps) {
    x = newtonMethod(x);
    calc = nearRoot(x, precision);
    if (calc > 0) {
      return calc;
    }
    steps++;
  }
  return 0;
}

void default_factal(const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (!fp) {
    fprintf(stderr, "could not open file %s", filename);
    exit(1);
  }
  const int x_max = 250;
  const int y_max = 250;
  const double precision = 0.000001;
  const char *comment = "# file created by AFL";
  fprintf(fp, "P3\n %s\n %d\n %d\n 255\n", comment, x_max, y_max);
  for (int y = y_max - 1; y >= 0; y--) {
    for (int x = 0; x < x_max; x++) {
      Complex z = {x * 4.0 / x_max - 2.0, y * 4.0 / y_max - 2.0};
      int root = classify_root(z, precision);
      if (root == 1) {
        fprintf(fp, "0 255 0 ");
      } else if (root == 2) {
        fprintf(fp, "0 0 255 ");
      } else if (root == 3) {
        fprintf(fp, "255 0 0 ");
      } else {
        fprintf(fp, "0 0 0 ");
      }
    }
    fprintf(fp, "\n");
  }
}

int *newton_fractal(double x_start, double x_step, double x_end, double y_start,
                    double y_step, double y_end, int max_iterations,
                    double precision) {
  int size_x = (x_end - x_start) / x_step;
  int size_y = (y_end - y_start) / y_step;
  int *image = new int[size_x * size_y * 3];

  for (int y = 0; y < size_y; y++) {
    for (int x = 0; x < size_x; x++) {
      Complex z = {x_start + x * x_step, y_start + y * y_step};
      int root = classify_root(z, precision);
      if (root == 1) {
        image[(y * size_x + x) * 3] = 0;
        image[(y * size_x + x) * 3 + 1] = 255;
        image[(y * size_x + x) * 3 + 2] = 0;
      } else if (root == 2) {
        image[(y * size_x + x) * 3] = 0;
        image[(y * size_x + x) * 3 + 1] = 0;
        image[(y * size_x + x) * 3 + 2] = 255;
      } else if (root == 3) {
        image[(y * size_x + x) * 3] = 255;
        image[(y * size_x + x) * 3 + 1] = 0;
        image[(y * size_x + x) * 3 + 2] = 0;
      } else {
        image[(y * size_x + x) * 3] = 0;
        image[(y * size_x + x) * 3 + 1] = 0;
        image[(y * size_x + x) * 3 + 2] = 0;
      }
    }
  }

  return image;
}

void drawing_ppm(const char *filename, int *image, int size_x, int size_y) {
  FILE *fp = fopen(filename, "w");
  if (!fp) {
    fprintf(stderr, "could not open file %s", filename);
    exit(1);
  }
  const char *comment = "# file created by AFL";
  fprintf(fp, "P3\n %s\n %d\n %d\n 255\n", comment, size_x, size_y);

  for (int y = size_y - 1; y >= 0; y--) {
    for (int x = 0; x < size_x; x++) {
      fprintf(fp, "%d %d %d ", image[(y * size_x + x) * 3],
              image[(y * size_x + x) * 3 + 1], image[(y * size_x + x) * 3 + 2]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}
