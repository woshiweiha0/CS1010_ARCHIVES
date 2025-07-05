/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Length
 *
 * @file: length.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

size_t length_of(const char *str)
{
  size_t count = 0;
  for (size_t i = 0; str[i] != '\0'; i += 1) {
    count += 1;
  }
  return count;
}
