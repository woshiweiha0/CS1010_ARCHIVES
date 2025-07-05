/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: GCD
 *
 * @file: gcd.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_gcd(long a, long b)
{
  if (b == 0) {
    return a;
  }
  return compute_gcd(b, a % b);
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  cs1010_println_long(compute_gcd(a, b));
}
