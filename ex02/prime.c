/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Prime
 *
 * @file: prime.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long n)
{
  if (n <= 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if ((n % 2) == 0) {
    return false;
  }
  double sqrt_n = sqrt((double)n);
  for (long i = 3; i <= (long)sqrt_n; i += 2) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

long largest_prime(long n)
{
  for (long i = n; i >= 2; i -= 1) {
    if (is_prime(i)) {
      return i;
    }
  }
  return 0;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(largest_prime(n));
}
