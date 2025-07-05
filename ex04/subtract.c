/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Subtract
 *
 * @file: subtract.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <stdlib.h>
#include <string.h>

long convert_to_digit(char c)
{
  return c - '0';
}

long borrow_and_subtract(long digit_a, long digit_b, long *borrow)
{
  digit_a -= *borrow;
  if (digit_a < digit_b) {
    digit_a += 10;
    *borrow = 1;
  } else {
    *borrow = 0;
  }
  return digit_a - digit_b;
}

char *remove_leading_zeros(char *result)
{
  while (*result == '0' && *(result + 1) != '\0') {
    result += 1;
  }
  return result;
}

void subtract(char *a, char *b)
{
  size_t len_a = strlen(a);
  size_t len_b = strlen(b);
  char *result = calloc(len_a + 1, sizeof(char));
  if (result == NULL) {
    return;
  }
  long borrow = 0;
  long i = (long)len_a - 1;
  long j = (long)len_b - 1;
  while (i >= 0) {
    long digit_a = convert_to_digit(a[i]);
    long digit_b;
    if (j >= 0) {
      digit_b = convert_to_digit(b[j]);
    } else {
      digit_b = 0;
    }
    long result_digit = borrow_and_subtract(digit_a, digit_b, &borrow);
    result[i] = (char)(result_digit + '0');
    i -= 1;
    j -= 1;
  }
  char *final_result = remove_leading_zeros(result);
  cs1010_println_string(final_result);
  free(result);
}

int main()
{
  char *a = cs1010_read_word();
  char *b = cs1010_read_word();
  if (a == NULL || b == NULL) {
    return 1;
  }
  subtract(a, b);
  free(a);
  free(b);
}
