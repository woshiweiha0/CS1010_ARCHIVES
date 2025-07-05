/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Echo
 *
 * @file: echo.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long **read_matrix(size_t nrows, size_t ncols)
{
  long **matrix = calloc(nrows, sizeof(long *));
  if (matrix == NULL) {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }
  matrix[0] = calloc(nrows * ncols, sizeof(long));
  if (matrix[0] == NULL) {
    cs1010_println_string("unable to allocate array");
    free(matrix);
    return NULL;
  }
  for (size_t i = 1; i < nrows; i += 1) {
    matrix[i] = matrix[i - 1] + ncols;
  }
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      matrix[i][j] = cs1010_read_long();
    }
  }
  return matrix;
}

void print_matrix(size_t nrows, size_t ncols, long **matrix)
{
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_print_string("\n");
  }
}

int main()
{
  size_t nrows = cs1010_read_size_t();
  size_t ncols = cs1010_read_size_t();
  long **matrix = read_matrix(nrows, ncols);
  if (matrix == NULL) {
    cs1010_println_string("unable to allocate array");
    return 1;
  }
  print_matrix(nrows, ncols, matrix);
  free(matrix[0]);
  free(matrix);
}
