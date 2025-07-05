/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Ones
 *
 * @file: ones.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void print_last_digit(long input)
{
  long last_digit = input % 10;
  cs1010_println_long(last_digit);
}

void print_all_but_last_digit(long input)
{
  long all_but_last_digit = input / 10;
  cs1010_println_long(all_but_last_digit);
}

// No main function.  The main function is defined concat-main.c
