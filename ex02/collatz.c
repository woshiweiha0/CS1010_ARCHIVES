/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Collatz
 *
 * @file: collatz.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>

// if input % 2 == 0, divide by 2
// else input = (input * 3) + 1

long total_stopping_time(long input)
{
  long stopping_time = 0;
  while (input != 1) {
    if ((input % 2) == 0) {
      input /= 2;
    } else {
      input = (input * 3) + 1;
    }
    stopping_time += 1;
  }
  return stopping_time;
}

int main()
{
  long m = cs1010_read_long();
  long n = cs1010_read_long();
  long stop_time_max = 0;
  long stop_time_max_number = 0;
  for (long i = m; i <= n; i += 1) {
    if (total_stopping_time(i) >= stop_time_max) {
      stop_time_max = total_stopping_time(i);
      stop_time_max_number = i;
    }
  }
  cs1010_println_long(stop_time_max);
  cs1010_println_long(stop_time_max_number);
}
