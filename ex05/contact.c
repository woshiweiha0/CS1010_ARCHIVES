/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Contact
 *
 * @file: contact.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

char **read_contacts(size_t n)
{
  char **contacts = calloc(n, sizeof(char *));
  if (contacts == NULL) {
    cs1010_println_string("unable to allocate");
    return NULL;
  }
  for (size_t i = 0; i < n; i += 1) {
    contacts[i] = cs1010_read_word();
    if (contacts[i] == NULL) {
      cs1010_println_string("unable to allocate");
      for (size_t j = 0; j < i; j += 1) {
        free(contacts[j]);
      }
      free(contacts);
      return NULL;
    }
  }
  return contacts;
}

bool is_direct_contact(char **contacts, long j, long k)
{
  if (j >= k) {
    return contacts[j][k] == '1';
  }
  return contacts[k][j] == '1';
}

long find_indirect_contact(char **contacts, size_t n, long j, long k)
{
  for (long x = 0; x < (long)n; x += 1) {
    if (x != j && x != k && is_direct_contact(contacts, j, x) &&
        is_direct_contact(contacts, k, x)) {
      return x;
    }
  }
  return -1;
}

int main()
{
  size_t n = cs1010_read_size_t();
  char **contacts = read_contacts(n);
  if (contacts == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long j = cs1010_read_long();
  long k = cs1010_read_long();
  if (is_direct_contact(contacts, j, k)) {
    cs1010_println_string("direct contact");
  } else {
    long through = find_indirect_contact(contacts, n, j, k);
    if (through != -1) {
      cs1010_print_string("contact through ");
      cs1010_println_long(through);
    } else {
      cs1010_println_string("no contact");
    }
  }
  for (size_t i = 0; i < n; i += 1) {
    free(contacts[i]);
  }
  free(contacts);
}
