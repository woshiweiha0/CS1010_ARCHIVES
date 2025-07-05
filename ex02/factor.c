/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Factor
 *
 * @file: factor.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long factor_count(long n)
{
  long count = 0;
  long i = 2;
  while (i < n) {
    if (n % i == 0) {
      count += 1;
    }
    i += 1;
  }
  return count;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(factor_count(n));
}
