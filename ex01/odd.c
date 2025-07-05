/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Odd
 *
 * @file: odd.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_next_odd(long n)
{
  if (n % 2 == 0) {
    return n + 1;
  }
  return n + 2;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(find_next_odd(n));
}
