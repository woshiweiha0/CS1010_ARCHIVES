/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Leap
 *
 * @file: leap.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <stdbool.h>

bool is_leap_year(long year)
{
  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int main()
{
  long year = cs1010_read_long();
  if (is_leap_year(year)) {
    cs1010_print_long(year);
    cs1010_println_string(" is a leap year");
  } else {
    cs1010_print_long(year);
    cs1010_println_string(" is not a leap year");
  }
}
