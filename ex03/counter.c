/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Counter
 *
 * @file: counter.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  long n = cs1010_read_long();
  long count[10] = {0};
  if (n == 0) {
    cs1010_println_string("0: 1");
  } else {
    while (n > 0) {
      long digit = n % 10;
      count[digit] += 1;
      n /= 10;
    }
    for (long i = 0; i < 10; i += 1) {
      if (count[i] > 0) {
        cs1010_print_long(i);
        cs1010_print_string(": ");
        cs1010_println_long(count[i]);
      }
    }
  }
}
