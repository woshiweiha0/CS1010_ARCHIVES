/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: ID
 *
 * @file: id.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long sum_of_digits(long id)
{
  long sum = 0;
  while (id > 0) {
    long digit = id % 10;
    sum += digit;
    id /= 10;
  }
  return sum;
}

int main()
{
  long id = cs1010_read_long();
  char check_code[13] = {'Y', 'X', 'W', 'U', 'R', 'N', 'M',
                         'L', 'J', 'H', 'E', 'A', 'B'};
  long remainder = sum_of_digits(id) % 13;
  putchar(check_code[remainder]);
  putchar('\n');
}
