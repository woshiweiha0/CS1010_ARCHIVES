/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Padovan
 *
 * @file: padovan.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long add(long a, long b)
{
  return (b + a) % 10000;
}

void sum(long n, long list[])
{
  long a = 1;
  long b = 0;
  long c = 0;
  for (long i = 0; i < (n - 100); i += 1) {
    long temp = c;
    c = add(a, b);
    a = b;
    b = temp;
  }
  list[0] = a;
  list[1] = b;
  list[2] = c;
}

void padovan_list(long list[])
{
  for (long i = 0; i < 97; i += 2) {
    list[i + 3] = (list[i + 1] + list[i]) % 10000;
    list[i + 4] = (list[i + 2] + list[i + 1]) % 10000;
  }
}

int main()
{
  long n = cs1010_read_long();
  long list[101];
  sum(n, list);
  padovan_list(list);
  for (long i = 99; i > -1; i -= 1) {
    cs1010_println_long(list[i]);
  }
}
