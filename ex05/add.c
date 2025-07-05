/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Add
 *
 * @file: add.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

#define NCOLS 3
#define NROWS 3

int main()
{
  long m[NCOLS][NROWS];
  long n[NCOLS][NROWS];
  long result[NCOLS][NROWS];
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      m[i][j] = cs1010_read_long();
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      n[i][j] = cs1010_read_long();
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      result[i][j] = m[i][j] + n[i][j];
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      cs1010_print_long(result[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_print_string("\n");
  }
}
