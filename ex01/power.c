/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Power
 *
 * @file: power.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_power(long x, long y)
{
  if (y == 0) {
    return 1;
  }
  if (x == 0) {
    return 0;
  }
  return x * compute_power(x, y - 1);
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  cs1010_println_long(compute_power(x, y));
}
