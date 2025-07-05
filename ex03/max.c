/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Max
 *
 * @file: max.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_max(const long list[], long start, long end)
{
  if (start == end - 1) {
    return list[start];
  }
  long mid = (start + end) / 2;
  long max_left = find_max(list, start, mid);
  long max_right = find_max(list, mid, end);
  if (max_left > max_right) {
    return max_left;
  }
  return max_right;
}
