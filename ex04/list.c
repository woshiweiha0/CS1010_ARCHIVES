/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: List
 *
 * @file: list.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  size_t k = cs1010_read_size_t();
  long *list = cs1010_read_long_array(k);
  if (list == NULL) {
    return 1;
  }
  for (size_t i = k; i > 0; i -= 1) {
    cs1010_println_long(list[i - 1]);
  }
  free(list);
}
