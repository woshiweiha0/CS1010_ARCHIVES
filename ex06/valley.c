/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Valley
 *
 * @file: valley.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_valley(const long *array, long left, long right)
{
  while (left <= right) {
    long mid = left + (right - left) / 2;
    if ((mid == 0 || array[mid] < array[mid - 1]) &&
        (mid == right || array[mid] < array[mid + 1])) {
      return array[mid];
    }
    if (mid > 0 && array[mid] > array[mid - 1]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *array = cs1010_read_long_array(n);
  if (array == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long valley = find_valley(array, 0, (long)n - 1);
  cs1010_println_long(valley);
  free(array);
}
