/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Popular
 *
 * @file: popular.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

char **read_friends(size_t n)
{
  char **friends = calloc(n, sizeof(char *));
  if (friends == NULL) {
    cs1010_println_string("unable to allocate");
    return NULL;
  }
  for (size_t i = 0; i < n; i += 1) {
    friends[i] = cs1010_read_word();
    if (friends[i] == NULL) {
      cs1010_println_string("unable to allocate");
      for (size_t j = 0; j < i; j += 1) {
        free(friends[i]);
      }
      free(friends);
      return NULL;
    }
  }
  return friends;
}

size_t count_friends(const char *row, size_t row_index)
{
  size_t count = 0;
  for (size_t i = 0; i <= row_index; i += 1) {
    if (row[i] == '1') {
      count += 1;
    }
  }
  return count;
}

size_t find_most_popular(char **friends, size_t n, size_t *max_friends)
{
  size_t most_popular = 0;
  *max_friends = count_friends(friends[0], 0);
  for (size_t i = 1; i < n; i += 1) {
    size_t friend_count = count_friends(friends[i], i);
    if (friend_count > *max_friends ||
        (friend_count == *max_friends && i < most_popular)) {
      most_popular = i;
      *max_friends = friend_count;
    }
  }
  return most_popular - 1;
}

int main()
{
  size_t n = cs1010_read_size_t();
  char **friends = read_friends(n);
  if (friends == NULL) {
    return 1;
  }
  size_t max_friends = 0;
  size_t most_popular = find_most_popular(friends, n, &max_friends);
  cs1010_println_size_t(most_popular);
  cs1010_println_size_t(max_friends - 1);
  for (size_t i = 0; i < n; i += 1) {
    free(friends[i]);
  }
  free(friends);
}
