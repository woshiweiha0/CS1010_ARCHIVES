/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Fibonacci
 *
 * @file: fibonacci.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long fibonacci(long n)
{
  if (n <= 2) {
    return 1;
  }
  long a = 1;
  long b = 1;
  long nth_fibo = 0;
  for (long i = 3; i <= n; i += 1) {
    nth_fibo = a + b;
    a = b;
    b = nth_fibo;
  }
  return nth_fibo;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(fibonacci(n));
}
