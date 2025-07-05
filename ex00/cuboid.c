/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Cuboid
 *
 * Read in three positive integer corresponding to the width,
 * height, and length of a cuboid from the standard input, and
 * print the total surface area and the length of the diagonal
 * to the standard output.
 *
 * @file: cuboid.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <math.h>

/**
 * Calculate the hypotenuse of a triangle.
 *
 * @param[in] base The base of the triangle.
 * @param[in] height The height of the tringle.
 * @return The hypotenuse of the triangle.
 */
double hypotenuse_of(double base, double height)
{
  return sqrt((base * base) + (height * height));
}

/**
 * Calculate the area of a rectangle.
 *
 * @param[in] width The width of the rectangle.
 * @param[in] height The height of the rectangle.
 * @eturn The surface area of the rectangle.
 */
long area_of_rectangle(long width, long height)
{
  return width * height;
}

int main()
{
  long width_input = cs1010_read_long();
  long length_input = cs1010_read_long();
  long height_input = cs1010_read_long();
  long surface_area = (2 * area_of_rectangle(width_input, length_input)) +
                      (2 * area_of_rectangle(length_input, height_input)) +
                      (2 * area_of_rectangle(width_input, height_input));
  double length_diagonal =
      sqrt((hypotenuse_of((double)width_input, (double)length_input) *
            hypotenuse_of((double)width_input, (double)length_input)) +
           ((double)height_input * (double)height_input));
  cs1010_println_long(surface_area);
  cs1010_println_double(length_diagonal);
}
