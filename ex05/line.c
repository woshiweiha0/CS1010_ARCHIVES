/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Line
 *
 * @file: line.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>

#define BLACK 0
#define WHITE 255

long **allocate_image(size_t w, size_t h)
{
  long **image = calloc(h, sizeof(long *));
  if (image == NULL) {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }
  image[0] = calloc(h * w, sizeof(long));
  if (image[0] == NULL) {
    cs1010_println_string("unable to allocate array");
    free(image);
    return NULL;
  }
  for (size_t i = 1; i < h; i += 1) {
    image[i] = image[i - 1] + w;
  }
  return image;
}

void initialize_image(size_t w, size_t h, long **image)
{
  for (size_t i = 0; i < h; i += 1) {
    for (size_t j = 0; j < w; j += 1) {
      image[i][j] = BLACK;
    }
  }
}

void draw_line(size_t w, size_t h, long x1, long y1, long x2, long y2,
               long **image)
{
  double m = (double)(y2 - y1) / (double)(x2 - x1);
  for (long x = x1; x <= x2; x += 1) {
    double y = m * (double)(x - x1) + (double)y1;
    long y_rounded = (long)round(y);
    if (x >= 0 && x < (long)w && y_rounded >= 0 && y_rounded < (long)h) {
      image[y_rounded][x] = WHITE;
    }
  }
}

void print_image(size_t w, size_t h, long **image)
{
  cs1010_println_string("P2");
  cs1010_print_size_t(w);
  cs1010_print_string(" ");
  cs1010_println_size_t(h);
  cs1010_println_long(WHITE);
  for (size_t i = 0; i < h; i += 1) {
    for (size_t j = 0; j < w; j += 1) {
      cs1010_print_long(image[i][j]);
      if (j < w - 1) {
        cs1010_print_string(" ");
      }
    }
    cs1010_println_string("");
  }
}

int main()
{
  size_t w = cs1010_read_size_t();
  size_t h = cs1010_read_size_t();
  long x1 = cs1010_read_long();
  long y1 = cs1010_read_long();
  long x2 = cs1010_read_long();
  long y2 = cs1010_read_long();
  long **image = allocate_image(w, h);
  if (image == NULL) {
    cs1010_println_string("unable to allocate array");
    return 1;
  }
  initialize_image(w, h, image);
  draw_line(w, h, x1, y1, x2, y2, image);
  print_image(w, h, image);
  free(image[0]);
  free(image);
}
