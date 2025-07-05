/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Pattern
 *
 * @file: pattern.c
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
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void print_pattern(long m, long h)
{
  for (long row = 1; row <= h; row += 1) {
    long leading_number = (row - 1) * m + 1;
    long leading_spaces = h - row;
    for (long i = 0; i < leading_spaces; i += 1) {
      cs1010_print_string(" ");
    }
    for (long i = 0; i < row; i += 1) {
      bool has_prime = false;
      long start = leading_number + (i * m);
      for (long j = 0; j < m; j += 1) {
        if (is_prime(start + j)) {
          has_prime = true;
          break;
        }
      }
      if (has_prime) {
        cs1010_print_string("#");
      } else {
        cs1010_print_string(".");
      }
      if (i < row - 1) {
        cs1010_print_string(" ");
      }
    }
    cs1010_print_string("\n");
  }
}

int main()
{
  long m = cs1010_read_long();
  long h = cs1010_read_long();
  print_pattern(m, h);
}
