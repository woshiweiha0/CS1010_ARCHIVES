# CS1010 Exercise 4
## Feedback for woshiweiha0
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2

---
### word
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `word.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `word` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### line
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Line
 *
 * @file: line.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  char *line = cs1010_read_line();
  if (line == NULL) {
    return 1;
  }
  cs1010_print_string(line);
  free(line);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `line.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `line` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### up
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Up
 *
 * @file: up.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void convert_to_upper(char *line)
{
  for (size_t i = 0; i < strlen(line); i += 1) {
    if (line[i] >= 'a' && line[i] <= 'z') {
      line[i] = line[i] + ('A' - 'a');
    }
  }
}

int main()
{
  char *line = cs1010_read_line();
  convert_to_upper(line);
  cs1010_print_string(line);
  free(line);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `up.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `up` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### list
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: List
 *
 * @file: list.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  size_t k = cs1010_read_size_t();
  long *list = cs1010_read_long_array(k);
  if (list == NULL) {
    return 1;
  }
  for (size_t i = k; i > 0; i -= 1) {
    cs1010_println_long(list[i - 1]);
  }
  free(list);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `list.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `list` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### length
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Length
 *
 * @file: length.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

size_t length_of(const char *str)
{
  size_t count = 0;
  for (size_t i = 0; str[i] != '\0'; i += 1) {
    count += 1;
  }
  return count;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `length.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `length` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### concat
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: concat
 *
 * @file: concat.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

// Defined in length.c
size_t length_of(const char *str);

char *concatenate(const char *str1, const char *str2)
{
  size_t len1 = length_of(str1);
  size_t len2 = length_of(str2);
  char *append = calloc(len1 + len2 + 1, sizeof(char));
  if (append == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < len1; i += 1) {
    append[i] = str1[i];
  }
  for (size_t i = 0; i < len2; i += 1) {
    append[len1 + i] = str2[i];
  }
  append[len1 + len2] = '\0';
  return append;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `concat.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `concat` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### search
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 4: Search
 *
 * @file: search.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <string.h>

void print_position(char *s, size_t k, char **words)
{
  for (size_t i = 0; i < k; i += 1) {
    char *position = strstr(s, words[i]);
    if (position != NULL) {
      cs1010_println_long(position - s);
    } else {
      cs1010_println_string("not found");
    }
  }
}

void free_memory(char **words, size_t k, char *s)
{
  for (size_t i = 0; i < k; i += 1) {
    free(words[i]);
  }
  free(words);
  free(s);
}

char **read_input(char **s, size_t *k)
{
  *s = cs1010_read_line();
  if (*s == NULL) {
    return NULL;
  }
  *k = cs1010_read_size_t();
  char **words = calloc(*k, sizeof(char *));
  if (words == NULL) {
    free(*s);
    return NULL;
  }
  for (size_t i = 0; i < *k; i += 1) {
    words[i] = cs1010_read_word();
    if (words[i] == NULL) {
      for (size_t j = 0; j < i; j += 1) {
        free(words[j]);
      }
      free(words);
      free(*s);
      return NULL;
    }
  }
  return words;
}

int main()
{
  char *s;
  size_t k;
  char **words = read_input(&s, &k);
  if (words == NULL) {
    return 1;
  }
  print_position(s, k, words);
  free_memory(words, k, s);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `search.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `search` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### kendall
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `kendall.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `kendall` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

---
### subtract
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `subtract.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `subtract` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex04-woshiweiha0/commit/af6ab46989a6227d2390b78872d63b304182c7c2).

## Summary
| Question | Achievement |
|----------|-------|
| [word](#word) | Excellent |
| [line](#line) | Excellent |
| [up](#up) | Excellent |
| [list](#list) | Excellent |
| [length](#length) | Excellent |
| [concat](#concat) | Excellent |
| [search](#search) | Excellent |
| [kendall](#kendall) | Excellent |
| [subtract](#subtract) | Excellent |
