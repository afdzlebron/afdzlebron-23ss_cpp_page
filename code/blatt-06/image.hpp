#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <gtest/gtest.h>

#include <cstdlib>

// Very simple class to contain Image
//
// It supports setting a pixel directly and then some image specific
// transformation (smoothing and writing to a PPM file)
//
// Internally it uses the malloc-approach from the last lecture instead of new
// and delete.
class Image {
 public:
  explicit Image()
      : image(nullptr), x_size(0), x_capacity(1), y_size(0), y_capacity(1) {}

  explicit Image(int x_size_, int y_size_)
      : x_size(x_size_),
        x_capacity(x_size_),
        y_size(y_size_),
        y_capacity(y_size_) {
    image = (int *)malloc(x_size * y_size * 3 * sizeof(int));
  }

  // Copy-Konstruktor
  Image(const Image &img) {
    x_size = img.x_size;
    x_capacity = img.x_capacity;
    y_size = img.y_size;
    y_capacity = img.y_capacity;
    image = (int *)malloc(x_size * y_size * 3 * sizeof(int));
    std::copy(img.image, img.image + x_size * y_size * 3, image);
  }

  // Destruktor
  ~Image() { free(image); }

  // write a PPM image from the pixel matrix with the given size.
  //
  // It does not free the array representing the image.
  void print_image(const char *) const;

  // destructive opteration: average the pixels over the entire picture.
  void smoothing();

  // set the pixel (x,y) with the color given by the (r,g,b) as RGB encoding
  void set_pixel(int x, int y, int r, int g, int b);

 private:
  /// array containing the image
  int *image;
  // max x of the image
  int x_size, x_capacity;
  // max y of the image
  int y_size, y_capacity;

  // returns the maximum of the image
  unsigned find_max() const;

  // average at pixel at color offset
  unsigned average(int x, int y, int offset) const;

  // resize the internal image to the new size and sets the size large enough
  // according to the policy (Aufgabe 2 -> tight fit; Aufgabe 3 -> doubling the
  // capacity)
  void resize(int, int);

  // reserve enough memory
  void reserve(int new_x_capacity, int new_y_capacity) {
    if (new_x_capacity > x_capacity || new_y_capacity > y_capacity) {
      x_capacity = new_x_capacity;
      y_capacity = new_y_capacity;

      int *new_image = (int *)malloc(x_capacity * y_capacity * 3 * sizeof(int));

      for (int i = 0; i < y_size; ++i) {
        for (int j = 0; j < x_size; ++j) {
          for (int k = 0; k < 3; ++k) {
            new_image[(i * x_capacity + j) * 3 + k] =
                image[(i * x_capacity + j) * 3 + k];
          }
        }
      }

      free(image);

      image = new_image;
    }
  }

  FRIEND_TEST(ImageTest, sizeTest);
};

#endif