/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Dot
 *
 * @file: dot.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  long v1[4];
  long v2[4];
  v1[0] = cs1010_read_long();
  v1[1] = cs1010_read_long();
  v1[2] = cs1010_read_long();
  v1[3] = cs1010_read_long();
  v2[0] = cs1010_read_long();
  v2[1] = cs1010_read_long();
  v2[2] = cs1010_read_long();
  v2[3] = cs1010_read_long();
  long dot_product = 0;
  for (long i = 0; i < 4; i += 1) {
    dot_product += v1[i] * v2[i];
  }
  cs1010_println_long(dot_product);
}
