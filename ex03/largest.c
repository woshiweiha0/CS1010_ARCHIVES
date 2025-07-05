/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Largest
 *
 * @file: largest.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void count_digits(long n, long counter[10])
{
  while (n != 0) {
    long digit = n % 10;
    counter[digit] += 1;
    n /= 10;
  }
}

long find_largest(long n)
{
  long counter[10] = {0};
  long is_negative = 0;
  if (n < 0) {
    is_negative = 1;
    n *= -1;
  }
  count_digits(n, counter);
  long largest = 0;
  if (is_negative == 1) {
    for (long i = 1; i <= 9; i += 1) {
      while (counter[i] > 0) {
        largest = largest * 10 + i;
        counter[i] -= 1;
      }
    }
    largest *= -1;
  } else {
    for (long i = 9; i >= 0; i -= 1) {
      while (counter[i] > 0) {
        largest = largest * 10 + i;
        counter[i] -= 1;
      }
    }
  }
  return largest;
}
