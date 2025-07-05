/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Sort
 *
 * @file: sort.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void merge_v_array(const long *array, long *result, long split, size_t n)
{
  long i = split - 1;
  long j = split;
  long k = 0;
  while (i >= 0 && j < (long)n) {
    if (array[i] <= array[j]) {
      result[k] = array[i];
      i -= 1;
    } else {
      result[k] = array[j];
      j += 1;
    }
    k += 1;
  }

  while (i >= 0) {
    result[k] = array[i];
    i -= 1;
    k += 1;
  }

  while (j < (long)n) {
    result[k] = array[j];
    j += 1;
    k += 1;
  }
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *array = cs1010_read_long_array(n);
  if (array == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long split = 1;
  while (split < (long)n && array[split] <= array[split - 1]) {
    split += 1;
  }
  long *result = calloc(n, sizeof(long));
  if (result == NULL) {
    cs1010_println_string("unable to allocate");
    free(array);
    return 1;
  }
  merge_v_array(array, result, split, n);
  for (size_t i = 0; i < n; i += 1) {
    cs1010_println_long(result[i]);
  }
  free(array);
  free(result);
}
