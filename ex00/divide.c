/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Divide
 *
 * Read in two integers and print the result of dividing the first
 * by the second to the standard output.
 *
 * @file: divide.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  cs1010_println_double((double)x / (double)y);
}
