/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Onigiri
 *
 * @file: onigiri.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void print_row(long h, long row)
{
  long num_hashes = (2 * row) - 1;
  long num_spaces = h - row;
  for (long i = 0; i < num_spaces; i += 1) {
    cs1010_print_string(" ");
  }
  for (long j = 0; j < num_hashes; j += 1) {
    cs1010_print_string("#");
  }
  for (long k = 0; k < num_spaces; k += 1) {
    cs1010_print_string(" ");
  }
  cs1010_print_string("\n");
}

void print_height(long h)
{
  for (long row = 1; row <= h; row += 1) {
    print_row(h, row);
  }
}

int main()
{
  long h = cs1010_read_long();
  print_height(h);
}
