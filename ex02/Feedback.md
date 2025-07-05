# CS1010 Exercise 2
## Feedback for woshiweiha0
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843

---
### lemon
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Lemon
 *
 * @file: lemon.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void lemon(long l, long m, long n)
{
  long i;
  for (i = 0; i < m; i += 1) {
    cs1010_println_long(l + (i * n));
  }
}

int main()
{
  long l = cs1010_read_long();
  long m = cs1010_read_long();
  long n = cs1010_read_long();
  lemon(l, m, n);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `lemon.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `lemon` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### factor
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Factor
 *
 * @file: factor.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long factor_count(long n)
{
  long count = 0;
  long i = 2;
  while (i < n) {
    if (n % i == 0) {
      count += 1;
    }
    i += 1;
  }
  return count;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(factor_count(n));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `factor.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `factor` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### parity
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Parity
 *
 * @file: parity.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_parity(long n)
{
  long odd_count = 0;
  long even_count = 0;
  while (n > 0) {
    long digit = n % 10;
    if (digit % 2 == 0) {
      even_count += 1;
    } else {
      odd_count += 1;
    }
    n /= 10;
  }
  cs1010_print_string("odd: ");
  cs1010_println_long(odd_count);
  cs1010_print_string("even: ");
  cs1010_println_long(even_count);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `parity.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `parity` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### nine
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Nine
 *
 * @file: nine.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_least_significant_9(long n)
{
  long position = 1;
  while (n > 0) {
    if (n % 10 == 9) {
      return position;
    }
    n /= 10;
    position += 1;
  }
  return 0;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(find_least_significant_9(n));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `nine.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `nine` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### hdb
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: HDB
 *
 * @file: hdb.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_row(long w)
{
  long i = 1;
  while (i < w) {
    cs1010_print_string("#");
    i += 1;
  }
  cs1010_println_string("#");
}

void print_height(long w, long h)
{
  long j = 1;
  while (j < h) {
    print_row(w);
    j += 1;
  }
}

int main()
{
  long w = cs1010_read_long();
  long h = cs1010_read_long();
  print_row(w);
  print_height(w, h);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `hdb.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `hdb` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### binary
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Binary
 *
 * @file: binary.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long decimal(long n)
{
  long sum = 0;
  long position = 1;
  do {
    long digit = n % 10;
    if (digit == 1) {
      sum += position;
    }
    position *= 2;
    n /= 10;
  } while (n > 0);
  return sum;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(decimal(n));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `binary.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `binary` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### onigiri
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Onigiri
 *
 * @file: onigiri.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void print_row(long h, long row)
{
  long num_hashes = (2 * row) - 1;
  long num_spaces = h - row;
  for (long i = 0; i < num_spaces; i += 1) {
    cs1010_print_string(" ");
  }
  for (long j = 0; j < num_hashes; j += 1) {
    cs1010_print_string("#");
  }
  for (long k = 0; k < num_spaces; k += 1) {
    cs1010_print_string(" ");
  }
  cs1010_print_string("\n");
}

void print_height(long h)
{
  for (long row = 1; row <= h; row += 1) {
    print_row(h, row);
  }
}

int main()
{
  long h = cs1010_read_long();
  print_height(h);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `onigiri.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `onigiri` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### fibonacci
```C
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
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `fibonacci.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `fibonacci` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### collatz
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Collatz
 *
 * @file: collatz.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>

// if input % 2 == 0, divide by 2
// else input = (input * 3) + 1

long total_stopping_time(long input)
{
  long stopping_time = 0;
  while (input != 1) {
    if ((input % 2) == 0) {
      input /= 2;
    } else {
      input = (input * 3) + 1;
    }
    stopping_time += 1;
  }
  return stopping_time;
}

int main()
{
  long m = cs1010_read_long();
  long n = cs1010_read_long();
  long stop_time_max = 0;
  long stop_time_max_number = 0;
  for (long i = m; i <= n; i += 1) {
    if (total_stopping_time(i) >= stop_time_max) {
      stop_time_max = total_stopping_time(i);
      stop_time_max_number = i;
    }
  }
  cs1010_println_long(stop_time_max);
  cs1010_println_long(stop_time_max_number);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `collatz.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `collatz` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### rectangle
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Rectangle
 *
 * @file: rectangle.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

#define TOP_LEFT "╔"
#define TOP_RIGHT "╗"
#define BOTTOM_RIGHT "╝"
#define BOTTOM_LEFT "╚"
#define HORIZONTAL "═"
#define VERTICAL "║"

void rectangle_top(long width)
{
  cs1010_print_string(TOP_LEFT);
  for (long i = 0; i < (width - 2); i += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_print_string(TOP_RIGHT);
  cs1010_print_string("\n");
}

void rectangle_middle(long width, long height)
{
  for (long i = 0; i < (height - 2); i += 1) {
    cs1010_print_string(VERTICAL);
    for (long j = 0; j < (width - 2); j += 1) {
      cs1010_print_string(" ");
    }
    cs1010_print_string(VERTICAL);
    cs1010_print_string("\n");
  }
}

void rectangle_bottom(long width)
{
  cs1010_print_string(BOTTOM_LEFT);
  for (long i = 0; i < (width - 2); i += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_print_string(BOTTOM_RIGHT);
  cs1010_print_string("\n");
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();
  if (width >= 2 && height >= 2) {
    rectangle_top(width);
    rectangle_middle(width, height);
    rectangle_bottom(width);
  } else {
    cs1010_print_string("Error: width and height must be >= 2");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `rectangle.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `rectangle` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### prime
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Prime
 *
 * @file: prime.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long n)
{
  if (n <= 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if ((n % 2) == 0) {
    return false;
  }
  double sqrt_n = sqrt((double)n);
  for (long i = 3; i <= (long)sqrt_n; i += 2) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

long largest_prime(long n)
{
  for (long i = n; i >= 2; i -= 1) {
    if (is_prime(i)) {
      return i;
    }
  }
  return 0;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(largest_prime(n));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `prime.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `prime` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

---
### pattern
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 2: Pattern
 *
 * @file: pattern.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long n)
{
  if (n <= 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if ((n % 2) == 0) {
    return false;
  }
  double sqrt_n = sqrt((double)n);
  for (long i = 3; i <= (long)sqrt_n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void print_pattern(long m, long h)
{
  for (long row = 1; row <= h; row += 1) {
    long leading_number = (row - 1) * m + 1;
    long leading_spaces = h - row;
    for (long i = 0; i < leading_spaces; i += 1) {
      cs1010_print_string(" ");
    }
    for (long i = 0; i < row; i += 1) {
      bool has_prime = false;
      long start = leading_number + (i * m);
      for (long j = 0; j < m; j += 1) {
        if (is_prime(start + j)) {
          has_prime = true;
          break;
        }
      }
      if (has_prime) {
        cs1010_print_string("#");
      } else {
        cs1010_print_string(".");
      }
      if (i < row - 1) {
        cs1010_print_string(" ");
      }
    }
    cs1010_print_string("\n");
  }
}

int main()
{
  long m = cs1010_read_long();
  long h = cs1010_read_long();
  print_pattern(m, h);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` generate 1 (non-documentation-related) warnings for `pattern.c`. Always fix your code so that it compiles cleanly without warnings.

<details>
<summary>Warnings from clang/clang-tidy</summary>

```
pattern.c:32:6: warning: function 'print_pattern' exceeds recommended size/complexity thresholds [readability-function-size]
```
</details>
What the warning/error messages from the compiler mean: (generated by an experimental AI and vetted by humans)

- **Function Size Exceeds Recommended Threshold**: The function `print_pattern` contains 33 statements, which exceeds the recommended limit of 20 statements. This suggests that the function may be doing too much, making it harder to read and maintain.

  

- **High Nesting Level**: The code has a nesting level of 4 in multiple places, which exceeds the recommended threshold of 3. High nesting levels can make the code more complex and difficult to follow, as it increases the cognitive load required to understand the flow of the program.

  

- **Readability Concerns**: Both the excessive function size and high nesting levels contribute to reduced readability of the code. Readability is crucial in programming, especially for collaborative projects or when revisiting code after some time. Code that is hard to read can lead to more bugs and difficulties in maintenance.

#### Test Cases
- Your `pattern` fails to pass 9 of the test cases.
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex02-woshiweiha0/commit/d0aee45d00fdc6787106a6031df912d5d1417843).

## Summary
| Question | Achievement |
|----------|-------|
| lemon | Excellent |
| factor | Excellent |
| parity | Excellent |
| nine | Excellent |
| hdb | Excellent |
| binary | Excellent |
| onigiri | Excellent |
| fibonacci | Excellent |
| collatz | Excellent |
| rectangle | Excellent |
| prime | Excellent |
| pattern | Need Improvement |
