// Copyright 2023, AFL
#include "image.hpp"

#include <stdlib.h>

void print_default_image(const char *filename) {
  int max_x = 255;
  int max_y = 255;

  FILE *fp = fopen(filename, "w");
  if (!fp) {
    printf("Can not open to write file\n");
    exit(1);
  }
  fprintf(fp, "P3\n");
  fprintf(fp, "%d %d\n", max_x + 1, max_y + 1);
  fprintf(fp, "255\n");

  //   fprintf(fp, "%g %g\n", coo.x, coo.y);

  for (int y = 0; y <= max_y; ++y) {
    for (int x = 0; x <= max_x; ++x) {
      int r = 0, g = 0, b = 0;
      if (y > max_y / 2) {
        r = 0;
        g = 255 * (y - max_y / 2) / (max_y / 2);
        b = 0;
      } else {
        r = 255 * y / (max_y / 2);
        g = 255 * y / (max_y / 2);
        b = 255 * y / (max_y / 2);
      }
      fprintf(fp, "%d %d %d ", r, g, b);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}
