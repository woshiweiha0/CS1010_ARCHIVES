# CS1010 Exercise 3
## Feedback for woshiweiha0
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4

---
### counter
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Counter
 *
 * @file: counter.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  long n = cs1010_read_long();
  long count[10] = {0};
  if (n == 0) {
    cs1010_println_string("0: 1");
  } else {
    while (n > 0) {
      long digit = n % 10;
      count[digit] += 1;
      n /= 10;
    }
    for (long i = 0; i < 10; i += 1) {
      if (count[i] > 0) {
        cs1010_print_long(i);
        cs1010_print_string(": ");
        cs1010_println_long(count[i]);
      }
    }
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `counter.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `counter` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### dot
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Dot
 *
 * @file: dot.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

int main()
{
  long v1[4];
  long v2[4];
  v1[0] = cs1010_read_long();
  v1[1] = cs1010_read_long();
  v1[2] = cs1010_read_long();
  v1[3] = cs1010_read_long();
  v2[0] = cs1010_read_long();
  v2[1] = cs1010_read_long();
  v2[2] = cs1010_read_long();
  v2[3] = cs1010_read_long();
  long dot_product = 0;
  for (long i = 0; i < 4; i += 1) {
    dot_product += v1[i] * v2[i];
  }
  cs1010_println_long(dot_product);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `dot.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `dot` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### unit
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Unit
 *
 * @file: unit.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>

void find_unit_vector(const long v[3], double unit[3])
{
  double sum_of_square = 0;
  for (long i = 0; i < 3; i += 1) {
    unit[i] = (double)v[i];
    sum_of_square += unit[i] * unit[i];
  }
  if (sum_of_square > 0) {
    double magnitude = sqrt(sum_of_square);
    for (long i = 0; i < 3; i += 1) {
      unit[i] /= magnitude;
      cs1010_println_double(unit[i]);
    }
  } else {
    for (long i = 0; i < 3; i += 1) {
      cs1010_println_double(0.0);
    }
  }
}

int main()
{
  long v[3] = {0};
  double unit[3] = {0};
  for (long i = 0; i < 3; i += 1) {
    v[i] = cs1010_read_long();
  }
  find_unit_vector(v, unit);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `unit.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `unit` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### largest
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Largest
 *
 * @file: largest.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void count_digits(long n, long counter[10])
{
  while (n != 0) {
    long digit = n % 10;
    counter[digit] += 1;
    n /= 10;
  }
}

long find_largest(long n)
{
  long counter[10] = {0};
  long is_negative = 0;
  if (n < 0) {
    is_negative = 1;
    n *= -1;
  }
  count_digits(n, counter);
  long largest = 0;
  if (is_negative == 1) {
    for (long i = 1; i <= 9; i += 1) {
      while (counter[i] > 0) {
        largest = largest * 10 + i;
        counter[i] -= 1;
      }
    }
    largest *= -1;
  } else {
    for (long i = 9; i >= 0; i -= 1) {
      while (counter[i] > 0) {
        largest = largest * 10 + i;
        counter[i] -= 1;
      }
    }
  }
  return largest;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `largest.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `largest` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### days
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Days
 *
 * @file: days.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long days(long m, long d, long days_in_month[12])
{
  long days_so_far = 0;
  for (long i = 0; i < m - 1; i += 1) {
    days_so_far += days_in_month[i];
  }
  days_so_far += d;
  return days_so_far;
}

int main()
{
  long m = cs1010_read_long();
  long d = cs1010_read_long();
  long days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cs1010_println_long(days(m, d, days_in_month));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `days.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `days` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### id
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `id.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `id` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### max
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 3: Max
 *
 * @file: max.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_max(const long list[], long start, long end)
{
  if (start == end - 1) {
    return list[start];
  }
  long mid = (start + end) / 2;
  long max_left = find_max(list, start, mid);
  long max_right = find_max(list, mid, end);
  if (max_left > max_right) {
    return max_left;
  }
  return max_right;
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `max.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `max` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

---
### padovan
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `padovan.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `padovan` fails to pass 1 of the test cases.
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex03-woshiweiha0/commit/8cece32c1a194b71a1d708fcc9c0c6013ce7adb4).

## Summary
| Question | Achievement |
|----------|-------|
| [counter](#counter) | Excellent |
| [dot](#dot) | Excellent |
| [unit](#unit) | Excellent |
| [largest](#largest) | Excellent |
| [days](#days) | Excellent |
| [id](#id) | Excellent |
| [max](#max) | Excellent |
| [padovan](#padovan) | Need Improvement |
