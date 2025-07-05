/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: HDB
 *
 * @file: hdb.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_row(long w)
{
  long i = 1;
  while (i < w) {
    cs1010_print_string("#");
    i += 1;
  }
  cs1010_println_string("#");
}

void print_height(long w, long h)
{
  long j = 1;
  while (j < h) {
    print_row(w);
    j += 1;
  }
}

int main()
{
  long w = cs1010_read_long();
  long h = cs1010_read_long();
  print_row(w);
  print_height(w, h);
}
