# CS1010 Exercise 1
## Feedback for woshiweiha0
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce

---
### odd
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Odd
 *
 * @file: odd.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_next_odd(long n)
{
  if (n % 2 == 0) {
    return n + 1;
  }
  return n + 2;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(find_next_odd(n));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `odd.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `odd` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### sum
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Sum
 *
 * @file: sum.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_sum_if_positive(long x, long y)
{
  if (x < 0 && y < 0) {
    return 0;
  }
  if (x < 0) {
    return y;
  }
  if (y < 0) {
    return x;
  }
  return x + y;
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  cs1010_println_long(compute_sum_if_positive(x, y));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `sum.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `sum` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### candy
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Candy
 *
 * @file: candy.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_num_of_boxes(long num_of_candies, long max_candies_per_box)
{
  long num_of_boxes_needed = (num_of_candies / max_candies_per_box);
  if ((num_of_candies % max_candies_per_box) > 0) {
    return num_of_boxes_needed + 1;
  }
  return num_of_boxes_needed;
}

// No main function.  The main function is defined concat-main.c
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `candy.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `candy` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### triangle
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Triangle
 *
 * @file: triangle.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_possible_triangle(long a, long b, long c)
{
  return ((a + b > c) && (b + c > a) && (a + c > b));
}

double compute_area(long a, long b, long c)
{
  double s = ((double)a / 16) + ((double)b / 16) + ((double)c / 16);
  long x = (b - a) + c;
  long y = (a - b) + c;
  long z = (b - c) + a;
  return sqrt(s * (double)x * (double)y * (double)z);
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  long c = cs1010_read_long();
  if (is_possible_triangle(a, b, c)) {
    cs1010_println_string("Possible");
    cs1010_println_double(compute_area(a, b, c));
  } else {
    cs1010_println_string("Impossible");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `triangle.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `triangle` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### leap
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Leap
 *
 * @file: leap.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <stdbool.h>

bool is_leap_year(long year)
{
  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int main()
{
  long year = cs1010_read_long();
  if (is_leap_year(year)) {
    cs1010_print_long(year);
    cs1010_println_string(" is a leap year");
  } else {
    cs1010_print_long(year);
    cs1010_println_string(" is not a leap year");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `leap.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `leap` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### multiple
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Multiple
 *
 * @file: multiple.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"
#include <stdbool.h>
bool is_multiple(long a, long b)
{
  return ((a == 0 || b == 0) || ((a % b == 0) || (b % a == 0)));
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  if (is_multiple(a, b)) {
    cs1010_println_string("true");
  } else {
    cs1010_println_string("false");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `multiple.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `multiple` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### date
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Date
 *
 * @file: date.c
 * @author: Poh Wei Hao (Group D05) & D05's TA
 */
#include "cs1010.h"

int main()
{
  long m1 = cs1010_read_long();
  long d1 = cs1010_read_long();
  long m2 = cs1010_read_long();
  long d2 = cs1010_read_long();
  long m3 = cs1010_read_long();
  long d3 = cs1010_read_long();
  long t1 = (m1 * 100) + d1;
  long t2 = (m2 * 100) + d2;
  long t3 = (m3 * 100) + d3;
  if ((t1 < t2) && (t2 < t3)) {
    cs1010_println_string("yes");
  } else {
    cs1010_println_string("no");
  }
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `date.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `date` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### pressure
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Pressure
 *
 * @file: pressure.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_blood_pressure(long systolic, long diastolic)
{
  if ((systolic >= 140) || (diastolic >= 90)) {
    cs1010_println_string("high");
  } else if ((systolic >= 120) || (diastolic >= 80)) {
    cs1010_println_string("pre-high");
  } else if ((systolic >= 90) || (diastolic >= 60)) {
    cs1010_println_string("ideal");
  } else {
    cs1010_println_string("low");
  }
}

int main()
{
  long systolic = cs1010_read_long();
  long diastolic = cs1010_read_long();
  print_blood_pressure(systolic, diastolic);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `pressure.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `pressure` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### gcd
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: GCD
 *
 * @file: gcd.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_gcd(long a, long b)
{
  if (b == 0) {
    return a;
  }
  return compute_gcd(b, a % b);
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  cs1010_println_long(compute_gcd(a, b));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `gcd.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `gcd` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### digits
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Digits
 *
 * @file: digits.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long sum_of_digits_cubed(long n)
{
  if (n == 0) {
    return 0;
  }
  long last_digit = n % 10;
  long cube = last_digit * last_digit * last_digit;
  return cube + sum_of_digits_cubed(n / 10);
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(sum_of_digits_cubed(n));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `digits.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `digits` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### power
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Power
 *
 * @file: power.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long compute_power(long x, long y)
{
  if (y == 0) {
    return 1;
  }
  if (x == 0) {
    return 0;
  }
  return x * compute_power(x, y - 1);
}

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  cs1010_println_long(compute_power(x, y));
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `power.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `power` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### suffix
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Suffix
 *
 * @file: suffix.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

void print_with_suffix(long n)
{
  if (((n % 10) == 1) && ((n % 100) != 11)) {
    cs1010_print_long(n);
    cs1010_println_string("st");
  } else if (((n % 10) == 2) && ((n % 100) != 12)) {
    cs1010_print_long(n);
    cs1010_println_string("nd");
  } else if (((n % 10) == 3) && ((n % 100) != 13)) {
    cs1010_print_long(n);
    cs1010_println_string("rd");
  } else {
    cs1010_print_long(n);
    cs1010_println_string("th");
  }
}

int main()
{
  long n = cs1010_read_long();
  print_with_suffix(n);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `suffix.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `suffix` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

---
### taxi
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 1: Taxi
 *
 * @file: taxi.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

bool is_weekday(long day)
{
  return ((day >= 1) && (day <= 5));
}

bool is_morning_peak(long hours, long mins)
{
  long time = (hours * 100) + mins;
  return ((time >= 600) && (time <= 929));
}

bool is_evening_peak(long hours, long mins)
{
  long time = (hours * 100) + mins;
  return ((time >= 1800) && (time <= 2359));
}

bool is_midnight_peak(long hours, long mins)
{
  long time = (hours * 100) + mins;
  return ((time >= 0) && (time <= 600));
}

double basic_metered_fare(double distance)
{
  if (distance <= 1000) {
    return 3.90;
  }
  if ((distance > 1000) && (distance <= 10000)) {
    double current_fare = 3.90 + (((distance - 1000) / 400) * 0.24);
    if (((distance - 1000) % 400) > 0) {
      current_fare = current_fare + 0.24;
      return current_fare;
    }
  }
  double current_fare = 3.90 + 5.52 + (((distance - 10000) / 350) * 0.24);
  if (((distance - 10000) % 350) > 0) {
    current_fare = current_fare + 0.24;
    return current_fare;
  }
}

double surcharge(double basic_metered_fare(double distance))
{
  if ((is_weekday && is_morning_peak) || is_evening_peak) {
    return basic_metered_fare(double distance) / 4;
  }
  if (is_midnight_peak) {
    return basic_metered_fare(double distance) / 2;
  }
  return 0;
}

int main()
{
  long day = cs1010_read_long();
  long hours = cs1010_read_long();
  long mins = cs1010_read_long();
  long distance = cs1010_read_long();
  cs1010_println_double(basic_metered_fare(distance) +
                        surcharge(basic_metered_fare(distance)));
}
```
We cannot find the binary executable `taxi`. It is likely that your code did not compile successfully.
You can find [the comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex01-woshiweiha0/commit/fd061c7b91ca5de8e9c624fcecfeed6a7894c8ce).

## Summary
| Question | Achievement |
|----------|-------|
| [odd](#odd) | Excellent |
| [sum](#sum) | Excellent |
| [candy](#candy) | Excellent |
| [triangle](#triangle) | Excellent |
| [leap](#leap) | Excellent |
| [multiple](#multiple) | Excellent |
| [date](#date) | Excellent |
| [pressure](#pressure) | Excellent |
| [gcd](#gcd) | Excellent |
| [digits](#digits) | Excellent |
| [power](#power) | Excellent |
| [suffix](#suffix) | Excellent |
| [taxi](#taxi) | Insufficient Effort/Cannot Compile |
