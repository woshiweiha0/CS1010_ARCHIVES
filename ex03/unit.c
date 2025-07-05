/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Unit
 *
 * @file: unit.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>

void find_unit_vector(const long v[3], double unit[3])
{
  double sum_of_square = 0;
  for (long i = 0; i < 3; i += 1) {
    unit[i] = (double)v[i];
    sum_of_square += unit[i] * unit[i];
  }
  if (sum_of_square > 0) {
    double magnitude = sqrt(sum_of_square);
    for (long i = 0; i < 3; i += 1) {
      unit[i] /= magnitude;
      cs1010_println_double(unit[i]);
    }
  } else {
    for (long i = 0; i < 3; i += 1) {
      cs1010_println_double(0.0);
    }
  }
}

int main()
{
  long v[3] = {0};
  double unit[3] = {0};
  for (long i = 0; i < 3; i += 1) {
    v[i] = cs1010_read_long();
  }
  find_unit_vector(v, unit);
}
