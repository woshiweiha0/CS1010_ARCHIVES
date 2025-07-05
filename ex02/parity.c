/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Parity
 *
 * @file: parity.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_parity(long n)
{
  long odd_count = 0;
  long even_count = 0;
  while (n > 0) {
    long digit = n % 10;
    if (digit % 2 == 0) {
      even_count += 1;
    } else {
      odd_count += 1;
    }
    n /= 10;
  }
  cs1010_print_string("odd: ");
  cs1010_println_long(odd_count);
  cs1010_print_string("even: ");
  cs1010_println_long(even_count);
}
