/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Echo
 *
 * Read in an integer and print it on the screen.
 *
 * @file: echo.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

int main()
{
  long echo = cs1010_read_long();
  cs1010_println_long(echo);
}
