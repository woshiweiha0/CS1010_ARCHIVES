/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Rectangle
 *
 * @file: rectangle.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

#define TOP_LEFT "╔"
#define TOP_RIGHT "╗"
#define BOTTOM_RIGHT "╝"
#define BOTTOM_LEFT "╚"
#define HORIZONTAL "═"
#define VERTICAL "║"

void rectangle_top(long width)
{
  cs1010_print_string(TOP_LEFT);
  for (long i = 0; i < (width - 2); i += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_print_string(TOP_RIGHT);
  cs1010_print_string("\n");
}

void rectangle_middle(long width, long height)
{
  for (long i = 0; i < (height - 2); i += 1) {
    cs1010_print_string(VERTICAL);
    for (long j = 0; j < (width - 2); j += 1) {
      cs1010_print_string(" ");
    }
    cs1010_print_string(VERTICAL);
    cs1010_print_string("\n");
  }
}

void rectangle_bottom(long width)
{
  cs1010_print_string(BOTTOM_LEFT);
  for (long i = 0; i < (width - 2); i += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_print_string(BOTTOM_RIGHT);
  cs1010_print_string("\n");
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();
  if (width >= 2 && height >= 2) {
    rectangle_top(width);
    rectangle_middle(width, height);
    rectangle_bottom(width);
  } else {
    cs1010_print_string("Error: width and height must be >= 2");
  }
}
