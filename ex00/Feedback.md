# CS1010 Exercise 0
## Feedback for woshiweiha0
#### Submission
Link: https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad

---
### echo
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Echo
 *
 * Read in an integer and print it on the screen.
 *
 * @file: echo.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

int main()
{
  long echo = cs1010_read_long();
  cs1010_println_long(echo);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `echo.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `echo` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad).

---
### ones
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Ones
 *
 * @file: ones.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void print_last_digit(long input)
{
  long last_digit = input % 10;
  cs1010_println_long(last_digit);
}

void print_all_but_last_digit(long input)
{
  long all_but_last_digit = input / 10;
  cs1010_println_long(all_but_last_digit);
}

// No main function.  The main function is defined concat-main.c
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `ones.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `ones` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad).

---
### divide
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Divide
 *
 * Read in two integers and print the result of dividing the first
 * by the second to the standard output.
 *
 * @file: divide.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

int main()
{
  long x = cs1010_read_long();
  long y = cs1010_read_long();
  cs1010_println_double((double)x / (double)y);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `divide.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `divide` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad).

---
### bmi
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: BMI
 *
 * Read in two real numbers representing height and weight of
 * a person, print the BMI of the person.
 *
 * @file: bmi.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

/**
 * Calcualte the BMI.
 * @param[in] weight The weight of the person in kg
 * @param[in] height The height of the person in m
 * @return The BMI of the person
 */
double compute_bmi(double weight, double height)
{
  height = height / 100;
  return weight / (height * height);
}

int main()
{
  double height = cs1010_read_double();
  double weight = cs1010_read_double();
  double bmi = compute_bmi(weight, height);
  cs1010_println_double(bmi);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `bmi.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `bmi` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad).

---
### quadratic
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Quadratic
 *
 * Read in three doubles, a, b, and c, that represents the quadratic
 * equaltion a*x*x + b*x + c = 0 and print the two roots of this
 * equation.
 *
 * @file: quadratic.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <math.h>

int main()
{
  double a = cs1010_read_double();
  double b = cs1010_read_double();
  double c = cs1010_read_double();
  double root1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
  double root2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
  cs1010_println_double(root1);
  cs1010_println_double(root2);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `quadratic.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `quadratic` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad).

---
### cuboid
```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 0: Cuboid
 *
 * Read in three positive integer corresponding to the width,
 * height, and length of a cuboid from the standard input, and
 * print the total surface area and the length of the diagonal
 * to the standard output.
 *
 * @file: cuboid.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <math.h>

/**
 * Calculate the hypotenuse of a triangle.
 *
 * @param[in] base The base of the triangle.
 * @param[in] height The height of the tringle.
 * @return The hypotenuse of the triangle.
 */
double hypotenuse_of(double base, double height)
{
  return sqrt((base * base) + (height * height));
}

/**
 * Calculate the area of a rectangle.
 *
 * @param[in] width The width of the rectangle.
 * @param[in] height The height of the rectangle.
 * @eturn The surface area of the rectangle.
 */
long area_of_rectangle(long width, long height)
{
  return width * height;
}

int main()
{
  long width_input = cs1010_read_long();
  long length_input = cs1010_read_long();
  long height_input = cs1010_read_long();
  long surface_area = (2 * area_of_rectangle(width_input, length_input)) +
                      (2 * area_of_rectangle(length_input, height_input)) +
                      (2 * area_of_rectangle(width_input, height_input));
  double length_diagonal =
      sqrt((hypotenuse_of((double)width_input, (double)length_input) *
            hypotenuse_of((double)width_input, (double)length_input)) +
           ((double)height_input * (double)height_input));
  cs1010_println_long(surface_area);
  cs1010_println_double(length_diagonal);
}
```
#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `cuboid.c`. No warnings are generated. :confetti_ball:
#### Test Cases
- Your `cuboid` passes all test cases. :thumbsup:
#### Other Issues
- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex00-woshiweiha0/commit/11559a0492549f7f8d83be225b64b9f973d2f4ad).

## Summary
| Question | Achievement |
|----------|-------|
| echo | Excellent |
| ones | Excellent |
| divide | Excellent |
| bmi | Excellent |
| quadratic | Excellent |
| cuboid | Excellent |
