/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Triangle
 *
 * @file: triangle.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_possible_triangle(long a, long b, long c)
{
  return ((a + b > c) && (b + c > a) && (a + c > b));
}

double compute_area(long a, long b, long c)
{
  double s = ((double)a / 16) + ((double)b / 16) + ((double)c / 16);
  long x = (b - a) + c;
  long y = (a - b) + c;
  long z = (b - c) + a;
  return sqrt(s * (double)x * (double)y * (double)z);
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  long c = cs1010_read_long();
  if (is_possible_triangle(a, b, c)) {
    cs1010_println_string("Possible");
    cs1010_println_double(compute_area(a, b, c));
  } else {
    cs1010_println_string("Impossible");
  }
}
