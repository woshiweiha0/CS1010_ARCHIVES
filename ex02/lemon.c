/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Lemon
 *
 * @file: lemon.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void lemon(long l, long m, long n)
{
  long i;
  for (i = 0; i < m; i += 1) {
    cs1010_println_long(l + (i * n));
  }
}

int main()
{
  long l = cs1010_read_long();
  long m = cs1010_read_long();
  long n = cs1010_read_long();
  lemon(l, m, n);
}
