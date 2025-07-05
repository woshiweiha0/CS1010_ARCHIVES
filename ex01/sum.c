/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Sum
 *
 * @file: sum.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_sum_if_positive(long x, long y)
{
  if (x < 0 && y < 0) {
    return 0;
  }
  if (x < 0) {
    return y;
  }
  if (y < 0) {
    return x;
  }
  return x + y;
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  cs1010_println_long(compute_sum_if_positive(x, y));
}
