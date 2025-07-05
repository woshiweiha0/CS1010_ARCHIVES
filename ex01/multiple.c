/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Multiple
 *
 * @file: multiple.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <stdbool.h>
bool is_multiple(long a, long b)
{
  return ((a == 0 || b == 0) || ((a % b == 0) || (b % a == 0)));
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  if (is_multiple(a, b)) {
    cs1010_println_string("true");
  } else {
    cs1010_println_string("false");
  }
}
