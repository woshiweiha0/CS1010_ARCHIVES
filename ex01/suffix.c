/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Suffix
 *
 * @file: suffix.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_with_suffix(long n)
{
  if (((n % 10) == 1) && ((n % 100) != 11)) {
    cs1010_print_long(n);
    cs1010_println_string("st");
  } else if (((n % 10) == 2) && ((n % 100) != 12)) {
    cs1010_print_long(n);
    cs1010_println_string("nd");
  } else if (((n % 10) == 3) && ((n % 100) != 13)) {
    cs1010_print_long(n);
    cs1010_println_string("rd");
  } else {
    cs1010_print_long(n);
    cs1010_println_string("th");
  }
}

int main()
{
  long n = cs1010_read_long();
  print_with_suffix(n);
}
