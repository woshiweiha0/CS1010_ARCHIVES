/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Pressure
 *
 * @file: pressure.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_blood_pressure(long systolic, long diastolic)
{
  if ((systolic >= 140) || (diastolic >= 90)) {
    cs1010_println_string("high");
  } else if ((systolic >= 120) || (diastolic >= 80)) {
    cs1010_println_string("pre-high");
  } else if ((systolic >= 90) || (diastolic >= 60)) {
    cs1010_println_string("ideal");
  } else {
    cs1010_println_string("low");
  }
}

int main()
{
  long systolic = cs1010_read_long();
  long diastolic = cs1010_read_long();
  print_blood_pressure(systolic, diastolic);
}
