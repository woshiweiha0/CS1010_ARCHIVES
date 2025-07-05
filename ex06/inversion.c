/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Inversion
 *
 * @file: inversion.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long number_of_inversions(const long *array, size_t n)
{
  size_t k = 0;
  while (k + 1 < n && array[k] < array[k + 1]) {
    k += 1;
  }
  if (k == n - 1) {
    return 0;
  }
  if (k == 0) {
    return (n * (n - 1)) / 2;
  }
  long inv_count = 0;
  size_t i = k;
  size_t j = k + 1;
  while ((long)i >= 0 && j < n) {
    if (array[i] > array[j]) {
      inv_count += (j - i);
      i -= 1;
    } else {
      j += 1;
    }
  }
  return inv_count;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *array = cs1010_read_long_array(n);
  if (array == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long inversions = number_of_inversions(array, n);
  cs1010_println_long(inversions);
  free(array);
}
