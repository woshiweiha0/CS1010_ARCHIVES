/*
 * CS1010 Semester 1 AY24/25
 * Exercise 4: kendall
 *
 * @file: kendall.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

double kendall(size_t n, long *rank)
{
  size_t pairs = 0;
  size_t total_pairs = (n * (n - 1)) / 2;
  for (size_t i = 0; i < n; i += 1) {
    for (size_t j = i + 1; j < n; j += 1) {
      if (rank[i] > rank[j]) {
        pairs += 1;
      }
    }
  }
  return (double)pairs / (double)total_pairs;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *rank = cs1010_read_long_array(n);
  if (rank == NULL) {
    return 1;
  }
  cs1010_println_double(kendall(n, rank));
  free(rank);
}
