#ifndef IMAGE_HPP
#define IMAGE_HPP

/// Class storing the image as an array
class Image {
public:
  int width;
  int height;
  int *data;

  /// Constructor that takes the width and height of the image as arguments
  Image(int width, int height);

  /// Destructor that frees the memory allocated for the image data
  ~Image();

  /// Updates the RGB color values of a pixel at the given coordinates
  void update_pixel(int x, int y, int r, int g, int b);

  /// Writes the image data to a PPM file with the given filename
  void write(const char *filename);

  /// Applies a smoothing filter to the image
  void smooth();
};

#endif // IMAGE_HPP
