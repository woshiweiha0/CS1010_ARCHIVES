/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Fill
 *
 * @file: fill.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void fill_segment(long *image, size_t m, size_t n, size_t x, size_t y, long r,
                  long g, long b, long old_r, long old_g, long old_b)
{
  if (x >= m || y >= n) {
    return;
  }
  size_t idx = ((x * n) + y) * 3;
  if (image[idx] != old_r || image[idx + 1] != old_g ||
      image[idx + 2] != old_b) {
    return;
  }
  image[idx] = r;
  image[idx + 1] = g;
  image[idx + 2] = b;
  fill_segment(image, m, n, x + 1, y, r, g, b, old_r, old_g, old_b);
  fill_segment(image, m, n, x - 1, y, r, g, b, old_r, old_g, old_b);
  fill_segment(image, m, n, x, y + 1, r, g, b, old_r, old_g, old_b);
  fill_segment(image, m, n, x, y - 1, r, g, b, old_r, old_g, old_b);
}

void print_output(long *image, size_t m, size_t n)
{
  cs1010_print_string("P3 ");
  cs1010_print_size_t(n);
  cs1010_print_string(" ");
  cs1010_print_size_t(m);
  cs1010_println_string(" 255");
  for (size_t i = 0; i < m * n; i += 1) {
    cs1010_print_long(image[i * 3]);
    cs1010_print_string(" ");
    cs1010_print_long(image[i * 3 + 1]);
    cs1010_print_string(" ");
    cs1010_println_long(image[i * 3 + 2]);
  }
}

int main()
{
  size_t m = cs1010_read_size_t();
  size_t n = cs1010_read_size_t();

  long *image = calloc(3 * m * n, sizeof(long));
  if (image == NULL) {
    cs1010_println_string("fail");
    return 1;
  }

  for (size_t i = 0; i < 3 * m * n; i += 1) {
    image[i] = cs1010_read_long();
  }

  size_t q = cs1010_read_size_t();
  for (size_t i = 0; i < q; i += 1) {
    size_t x = cs1010_read_size_t();
    size_t y = cs1010_read_size_t();
    long r = cs1010_read_long();
    long g = cs1010_read_long();
    long b = cs1010_read_long();
    size_t idx = ((x * n) + y) * 3;
    long old_r = image[idx];
    long old_g = image[idx + 1];
    long old_b = image[idx + 2];
    if (old_r != r || old_g != g || old_b != b) {
      fill_segment(image, m, n, x, y, r, g, b, old_r, old_g, old_b);
    }
  }
  print_output(image, m, n);
  free(image);
}
