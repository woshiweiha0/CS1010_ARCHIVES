/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Line
 *
 * @file: line.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  char *line = cs1010_read_line();
  if (line == NULL) {
    return 1;
  }
  cs1010_print_string(line);
  free(line);
}
