/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Nine
 *
 * @file: nine.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_least_significant_9(long n)
{
  long position = 1;
  while (n > 0) {
    if (n % 10 == 9) {
      return position;
    }
    n /= 10;
    position += 1;
  }
  return 0;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(find_least_significant_9(n));
}
