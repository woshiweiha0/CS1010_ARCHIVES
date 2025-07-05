/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Walk
 *
 * @file: walk.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <stdlib.h>

long count_paths(long **path_counter, size_t x, size_t y)
{
  path_counter[0][0] = 1;

  for (size_t i = 0; i < y + 1; i += 1) {
    for (size_t j = 0; j < x + 1; j += 1) {
      if (i > 0) {
        path_counter[i][j] += path_counter[i - 1][j];
      }
      if (j > 0) {
        path_counter[i][j] += path_counter[i][j - 1];
      }
    }
  }

  long paths = path_counter[y][x];
  return paths;
}

int main()
{
  size_t x = cs1010_read_size_t();
  size_t y = cs1010_read_size_t();
  long **path_counter = calloc(y + 1, sizeof(long));
  if (path_counter == NULL) {
    cs1010_println_string("fail");
    return 1;
  }
  for (size_t i = 0; i < y + 1; i += 1) {
    path_counter[i] = calloc(x + 1, sizeof(long));
    if (path_counter[i] == NULL) {
      cs1010_println_string("fail");
      for (size_t j = 0; j < i; j += 1) {
        free(path_counter[j]);
      }
      free(path_counter);
      return 1;
    }
  }

  long npaths = count_paths(path_counter, x, y);
  cs1010_println_long(npaths);

  for (size_t i = 0; i < y + 1; i += 1) {
    free(path_counter[i]);
  }
  free(path_counter);
}
