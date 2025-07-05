/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Quadratic
 *
 * Read in three doubles, a, b, and c, that represents the quadratic
 * equaltion a*x*x + b*x + c = 0 and print the two roots of this
 * equation.
 *
 * @file: quadratic.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <math.h>

int main()
{
  double a = cs1010_read_double();
  double b = cs1010_read_double();
  double c = cs1010_read_double();
  double root1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
  double root2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
  cs1010_println_double(root1);
  cs1010_println_double(root2);
}
