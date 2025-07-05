/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Date
 *
 * @file: date.c
 * @author: Poh Wei Hao (Group D05) & D05's TA
 */
#include "cs1010.h"

int main()
{
  long m1 = cs1010_read_long();
  long d1 = cs1010_read_long();
  long m2 = cs1010_read_long();
  long d2 = cs1010_read_long();
  long m3 = cs1010_read_long();
  long d3 = cs1010_read_long();
  long t1 = (m1 * 100) + d1;
  long t2 = (m2 * 100) + d2;
  long t3 = (m3 * 100) + d3;
  if ((t1 < t2) && (t2 < t3)) {
    cs1010_println_string("yes");
  } else {
    cs1010_println_string("no");
  }
}
