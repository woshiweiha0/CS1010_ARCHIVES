/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Marks
 *
 * @file: marks.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void free_name(char ***list, size_t *marks_count, size_t i)
{
  for (size_t j = 0; j < marks_count[i]; j += 1) {
    for (size_t k = 0; k < marks_count[j]; k += 1) {
      free(list[j][k]);
    }
    free(list[j]);
  }
  free(list);
}

void read_input(char ***list, size_t *marks_count, size_t n)
{
  for (size_t i = 0; i < n; i += 1) {
    char *name = cs1010_read_word();
    if (name == NULL) {
      free_name(list, marks_count, i);
      return;
    }
    size_t score = cs1010_read_size_t();
    list[score][marks_count[score]] = name;
    marks_count[score] += 1;
  }
}

void print_names(char ***list, size_t *marks_count)
{
  for (size_t score = 0; score < 101; score += 1) {
    if (marks_count[score] > 0) {
      for (size_t j = 0; j < marks_count[score]; j += 1) {
        cs1010_print_size_t(score);
        cs1010_print_string(" ");
        cs1010_println_string(list[score][j]);
      }
    }
  }
}

int main()
{
  size_t n = cs1010_read_size_t();
  char ***list = calloc(101, sizeof(char **));
  if (list == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }

  for (size_t score = 0; score < 101; score += 1) {
    list[score] = calloc(n, sizeof(char *));
    if (list[score] == NULL) {
      cs1010_println_string("unable to allocate");
      for (size_t j = 0; j < score; j += 1) {
        free(list[j]);
      }
      free(list);
      return 1;
    }
  }

  size_t marks_count[101] = {0};
  read_input(list, marks_count, n);
  print_names(list, marks_count);

  for (size_t i = 0; i < 101; i += 1) {
    for (size_t j = 0; j < marks_count[i]; j += 1) {
      free(list[i][j]);
    }
    free(list[i]);
  }
  free(list);
}
