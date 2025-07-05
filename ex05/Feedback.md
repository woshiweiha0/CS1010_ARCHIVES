# CS1010 Exercise 5
## Feedback for woshiweiha0
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548

---
### add
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Add
 *
 * @file: add.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

#define NCOLS 3
#define NROWS 3

int main()
{
  long m[NCOLS][NROWS];
  long n[NCOLS][NROWS];
  long result[NCOLS][NROWS];
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      m[i][j] = cs1010_read_long();
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      n[i][j] = cs1010_read_long();
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      result[i][j] = m[i][j] + n[i][j];
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      cs1010_print_long(result[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_print_string("\n");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `add.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `add` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548).

---
### echo
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Echo
 *
 * @file: echo.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long **read_matrix(size_t nrows, size_t ncols)
{
  long **matrix = calloc(nrows, sizeof(long *));
  if (matrix == NULL) {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }
  matrix[0] = calloc(nrows * ncols, sizeof(long));
  if (matrix[0] == NULL) {
    cs1010_println_string("unable to allocate array");
    free(matrix);
    return NULL;
  }
  for (size_t i = 1; i < nrows; i += 1) {
    matrix[i] = matrix[i - 1] + ncols;
  }
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      matrix[i][j] = cs1010_read_long();
    }
  }
  return matrix;
}

void print_matrix(size_t nrows, size_t ncols, long **matrix)
{
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_print_string("\n");
  }
}

int main()
{
  size_t nrows = cs1010_read_size_t();
  size_t ncols = cs1010_read_size_t();
  long **matrix = read_matrix(nrows, ncols);
  if (matrix == NULL) {
    cs1010_println_string("unable to allocate array");
    return 1;
  }
  print_matrix(nrows, ncols, matrix);
  free(matrix[0]);
  free(matrix);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `echo.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `echo` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548).

---
### line
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 5: Line
 *
 * @file: line.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>

#define BLACK 0
#define WHITE 255

long **allocate_image(size_t w, size_t h)
{
  long **image = calloc(h, sizeof(long *));
  if (image == NULL) {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }
  image[0] = calloc(h * w, sizeof(long));
  if (image[0] == NULL) {
    cs1010_println_string("unable to allocate array");
    free(image);
    return NULL;
  }
  for (size_t i = 1; i < h; i += 1) {
    image[i] = image[i - 1] + w;
  }
  return image;
}

void initialize_image(size_t w, size_t h, long **image)
{
  for (size_t i = 0; i < h; i += 1) {
    for (size_t j = 0; j < w; j += 1) {
      image[i][j] = BLACK;
    }
  }
}

void draw_line(size_t w, size_t h, long x1, long y1, long x2, long y2,
               long **image)
{
  double m = (double)(y2 - y1) / (double)(x2 - x1);
  for (long x = x1; x <= x2; x += 1) {
    double y = m * (double)(x - x1) + (double)y1;
    long y_rounded = (long)round(y);
    if (x >= 0 && x < (long)w && y_rounded >= 0 && y_rounded < (long)h) {
      image[y_rounded][x] = WHITE;
    }
  }
}

void print_image(size_t w, size_t h, long **image)
{
  cs1010_println_string("P2");
  cs1010_print_size_t(w);
  cs1010_print_string(" ");
  cs1010_println_size_t(h);
  cs1010_println_long(WHITE);
  for (size_t i = 0; i < h; i += 1) {
    for (size_t j = 0; j < w; j += 1) {
      cs1010_print_long(image[i][j]);
      if (j < w - 1) {
        cs1010_print_string(" ");
      }
    }
    cs1010_println_string("");
  }
}

int main()
{
  size_t w = cs1010_read_size_t();
  size_t h = cs1010_read_size_t();
  long x1 = cs1010_read_long();
  long y1 = cs1010_read_long();
  long x2 = cs1010_read_long();
  long y2 = cs1010_read_long();
  long **image = allocate_image(w, h);
  if (image == NULL) {
    cs1010_println_string("unable to allocate array");
    return 1;
  }
  initialize_image(w, h, image);
  draw_line(w, h, x1, y1, x2, y2, image);
  print_image(w, h, image);
  free(image[0]);
  free(image);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `line.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `line` fails to pass 1 of the test cases.
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548).

---
### popular
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `popular.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `popular` fails to pass 3 of the test cases.
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548).

---
### contact
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `contact.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `contact` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548).

---
### social
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 1 (non-documentation-related) warnings for `social.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
social.c:62:8: warning: function 'compute_degree_2' exceeds recommended size/complexity thresholds [readability-function-size]
```
</details>

#### Test Cases
- Your `social` fails to pass 9 of the test cases.
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex05-woshiweiha0/commit/da83f18a9df9a437ac969e4c782d01084dedb548).

## Summary
| Question | Achievement |
|----------|-------|
| [add](#add) | Excellent |
| [echo](#echo) | Excellent |
| [line](#line) | Need Improvement |
| [popular](#popular) | Need Improvement |
| [contact](#contact) | Excellent |
| [social](#social) | Need Improvement |
