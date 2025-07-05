/*
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Word
 *
 * @file: word.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  char *word = cs1010_read_word();
  if (word == NULL) {
    return 1;
  }
  cs1010_println_string(word);
  free(word);
}
