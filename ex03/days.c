/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Days
 *
 * @file: days.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long days(long m, long d, long days_in_month[12])
{
  long days_so_far = 0;
  for (long i = 0; i < m - 1; i += 1) {
    days_so_far += days_in_month[i];
  }
  days_so_far += d;
  return days_so_far;
}

int main()
{
  long m = cs1010_read_long();
  long d = cs1010_read_long();
  long days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cs1010_println_long(days(m, d, days_in_month));
}
