/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Search
 *
 * @file: search.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <string.h>

void print_position(char *s, size_t k, char **words)
{
  for (size_t i = 0; i < k; i += 1) {
    char *position = strstr(s, words[i]);
    if (position != NULL) {
      cs1010_println_long(position - s);
    } else {
      cs1010_println_string("not found");
    }
  }
}

void free_memory(char **words, size_t k, char *s)
{
  for (size_t i = 0; i < k; i += 1) {
    free(words[i]);
  }
  free(words);
  free(s);
}

char **read_input(char **s, size_t *k)
{
  *s = cs1010_read_line();
  if (*s == NULL) {
    return NULL;
  }
  *k = cs1010_read_size_t();
  char **words = calloc(*k, sizeof(char *));
  if (words == NULL) {
    free(*s);
    return NULL;
  }
  for (size_t i = 0; i < *k; i += 1) {
    words[i] = cs1010_read_word();
    if (words[i] == NULL) {
      for (size_t j = 0; j < i; j += 1) {
        free(words[j]);
      }
      free(words);
      free(*s);
      return NULL;
    }
  }
  return words;
}

int main()
{
  char *s;
  size_t k;
  char **words = read_input(&s, &k);
  if (words == NULL) {
    return 1;
  }
  print_position(s, k, words);
  free_memory(words, k, s);
}
