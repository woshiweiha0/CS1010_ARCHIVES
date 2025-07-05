/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Binary
 *
 * @file: binary.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long decimal(long n)
{
  long sum = 0;
  long position = 1;
  do {
    long digit = n % 10;
    if (digit == 1) {
      sum += position;
    }
    position *= 2;
    n /= 10;
  } while (n > 0);
  return sum;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(decimal(n));
}
