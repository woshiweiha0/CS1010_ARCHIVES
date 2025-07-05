/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: BMI
 *
 * Read in two real numbers representing height and weight of
 * a person, print the BMI of the person.
 *
 * @file: bmi.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

/**
 * Calcualte the BMI.
 * @param[in] weight The weight of the person in kg
 * @param[in] height The height of the person in m
 * @return The BMI of the person
 */
double compute_bmi(double weight, double height)
{
  height = height / 100;
  return weight / (height * height);
}

int main()
{
  double height = cs1010_read_double();
  double weight = cs1010_read_double();
  double bmi = compute_bmi(weight, height);
  cs1010_println_double(bmi);
}
