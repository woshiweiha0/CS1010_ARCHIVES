/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: concat
 *
 * @file: concat.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

// Defined in length.c
size_t length_of(const char *str);

char *concatenate(const char *str1, const char *str2)
{
  size_t len1 = length_of(str1);
  size_t len2 = length_of(str2);
  char *append = calloc(len1 + len2 + 1, sizeof(char));
  if (append == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < len1; i += 1) {
    append[i] = str1[i];
  }
  for (size_t i = 0; i < len2; i += 1) {
    append[len1 + i] = str2[i];
  }
  append[len1 + len2] = '\0';
  return append;
}
