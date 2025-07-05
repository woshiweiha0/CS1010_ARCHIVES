/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Up
 *
 * @file: up.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void convert_to_upper(char *line)
{
  for (size_t i = 0; i < strlen(line); i += 1) {
    if (line[i] >= 'a' && line[i] <= 'z') {
      line[i] = line[i] + ('A' - 'a');
    }
  }
}

int main()
{
  char *line = cs1010_read_line();
  convert_to_upper(line);
  cs1010_print_string(line);
  free(line);
}
