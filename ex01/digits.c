/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Digits
 *
 * @file: digits.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long sum_of_digits_cubed(long n)
{
  if (n == 0) {
    return 0;
  }
  long last_digit = n % 10;
  long cube = last_digit * last_digit * last_digit;
  return cube + sum_of_digits_cubed(n / 10);
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(sum_of_digits_cubed(n));
}
