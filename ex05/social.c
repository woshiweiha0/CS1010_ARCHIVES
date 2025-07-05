/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Social
 *
 * @file: life.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

#define FRIEND '1'
#define STRANGER '0'

char **read_social_network(size_t n)
{
  char **network = calloc(n, sizeof(char *));
  if (network == NULL) {
    cs1010_println_string("unable to allocate");
    return NULL;
  }
  for (size_t i = 0; i < n; i += 1) {
    network[i] = cs1010_read_word();
    if (network[i] == NULL) {
      cs1010_println_string("unable to allocate");
      for (size_t j = 0; j < i; j += 1) {
        free(network[j]);
      }
      free(network);
      return NULL;
    }
  }
  return network;
}

char **initialize_jagged_array(size_t n)
{
  char **new_network = calloc(n, sizeof(char *));
  if (new_network == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < n; i += 1) {
    new_network[i] = calloc(i + 2, sizeof(char));
    if (new_network[i] == NULL) {
      for (size_t j = 0; j < i; j += 1) {
        free(new_network[j]);
      }
      free(new_network);
      return NULL;
    }
  }
  return new_network;
}

void free_jagged_array(char **network, size_t n)
{
  for (size_t i = 0; i < n; i += 1) {
    free(network[i]);
  }
  free(network);
}

char **compute_degree_2(char **network, size_t n)
{
  char **degree_2 = initialize_jagged_array(n);
  if (degree_2 == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < n; i += 1) {
    for (size_t j = 0; j <= i; j += 1) {
      degree_2[i][j] = network[i][j];
      for (size_t x = 0; x < n; x += 1) {
        if (x != i && x != j) {
          if ((i >= x && network[i][x] == FRIEND) &&
              (x >= j && network[x][j] == FRIEND)) {
            degree_2[i][j] = FRIEND;
            break;
          }
        }
      }
    }
    degree_2[i][i] = FRIEND;
    degree_2[i][i + 1] = '\0';
  }
  return degree_2;
}

char **compute_network(char **network, size_t n, size_t k)
{
  char **current = network;
  for (size_t degree = 2; degree <= k; degree += 1) {
    char **next = compute_degree_2(current, n);
    if (current != network) {
      free_jagged_array(current, n);
    }
    current = next;
  }
  return current;
}

int main()
{
  size_t n = cs1010_read_size_t();
  size_t k = cs1010_read_size_t();
  char **network = read_social_network(n);
  if (network == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  char **degree_k_network = compute_network(network, n, k);
  for (size_t i = 0; i < n; i += 1) {
    cs1010_println_string(degree_k_network[i]);
  }
  if (degree_k_network != network) {
    free_jagged_array(degree_k_network, n);
  }
  free_jagged_array(network, n);
}
