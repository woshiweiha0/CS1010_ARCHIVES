# CS1010 Exercise 6
## Feedback for woshiweiha0

#### Submission

Link: https://www.github.com/nus-cs1010-2425-s1/ex06-woshiweiha0/commit/0617eaa11f72cee94efcc926eb3ddf2210689c71

---
### sort
<details><summary>Code for  sort.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Sort
 *
 * @file: sort.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void merge_v_array(const long *array, long *result, long split, size_t n)
{
  long i = split - 1;
  long j = split;
  long k = 0;
  while (i >= 0 && j < (long)n) {
    if (array[i] <= array[j]) {
      result[k] = array[i];
      i -= 1;
    } else {
      result[k] = array[j];
      j += 1;
    }
    k += 1;
  }

  while (i >= 0) {
    result[k] = array[i];
    i -= 1;
    k += 1;
  }

  while (j < (long)n) {
    result[k] = array[j];
    j += 1;
    k += 1;
  }
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *array = cs1010_read_long_array(n);
  if (array == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long split = 1;
  while (split < (long)n && array[split] <= array[split - 1]) {
    split += 1;
  }
  long *result = calloc(n, sizeof(long));
  if (result == NULL) {
    cs1010_println_string("unable to allocate");
    free(array);
    return 1;
  }
  merge_v_array(array, result, split, n);
  for (size_t i = 0; i < n; i += 1) {
    cs1010_println_long(result[i]);
  }
  free(array);
  free(result);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `sort.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `sort` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-woshiweiha0/commit/0617eaa11f72cee94efcc926eb3ddf2210689c71).

---
### valley
<details><summary>Code for  valley.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Valley
 *
 * @file: valley.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long find_valley(const long *array, long left, long right)
{
  while (left <= right) {
    long mid = left + (right - left) / 2;
    if ((mid == 0 || array[mid] < array[mid - 1]) &&
        (mid == right || array[mid] < array[mid + 1])) {
      return array[mid];
    }
    if (mid > 0 && array[mid] > array[mid - 1]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *array = cs1010_read_long_array(n);
  if (array == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long valley = find_valley(array, 0, (long)n - 1);
  cs1010_println_long(valley);
  free(array);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `valley.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `valley` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-woshiweiha0/commit/0617eaa11f72cee94efcc926eb3ddf2210689c71).

---
### inversion
<details><summary>Code for  inversion.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Inversion
 *
 * @file: inversion.c
 * @author: Poh Wei Hao (Group D05)
 */
#include "cs1010.h"

long number_of_inversions(const long *array, size_t n)
{
  size_t k = 0;
  while (k + 1 < n && array[k] < array[k + 1]) {
    k += 1;
  }
  if (k == n - 1) {
    return 0;
  }
  if (k == 0) {
    return (n * (n - 1)) / 2;
  }
  long inv_count = 0;
  size_t i = k;
  size_t j = k + 1;
  while ((long)i >= 0 && j < n) {
    if (array[i] > array[j]) {
      inv_count += (j - i);
      i -= 1;
    } else {
      j += 1;
    }
  }
  return inv_count;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *array = cs1010_read_long_array(n);
  if (array == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }
  long inversions = number_of_inversions(array, n);
  cs1010_println_long(inversions);
  free(array);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `inversion.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `inversion` fails to pass 2 of the test cases.
<details><summary>Hidden test cases that cause your `inversion` to fail include the following:</summary>
 
```
5
4 5 3 2 1
```
 
```
5
2 3 4 5 1
```
</details>


#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-woshiweiha0/commit/0617eaa11f72cee94efcc926eb3ddf2210689c71).

---
### marks
<details><summary>Code for  marks.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 6: Marks
 *
 * @file: marks.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void free_name(char ***list, size_t *marks_count, size_t i)
{
  for (size_t j = 0; j < marks_count[i]; j += 1) {
    for (size_t k = 0; k < marks_count[j]; k += 1) {
      free(list[j][k]);
    }
    free(list[j]);
  }
  free(list);
}

void read_input(char ***list, size_t *marks_count, size_t n)
{
  for (size_t i = 0; i < n; i += 1) {
    char *name = cs1010_read_word();
    if (name == NULL) {
      free_name(list, marks_count, i);
      return;
    }
    size_t score = cs1010_read_size_t();
    list[score][marks_count[score]] = name;
    marks_count[score] += 1;
  }
}

void print_names(char ***list, size_t *marks_count)
{
  for (size_t score = 0; score < 101; score += 1) {
    if (marks_count[score] > 0) {
      for (size_t j = 0; j < marks_count[score]; j += 1) {
        cs1010_print_size_t(score);
        cs1010_print_string(" ");
        cs1010_println_string(list[score][j]);
      }
    }
  }
}

int main()
{
  size_t n = cs1010_read_size_t();
  char ***list = calloc(101, sizeof(char **));
  if (list == NULL) {
    cs1010_println_string("unable to allocate");
    return 1;
  }

  for (size_t score = 0; score < 101; score += 1) {
    list[score] = calloc(n, sizeof(char *));
    if (list[score] == NULL) {
      cs1010_println_string("unable to allocate");
      for (size_t j = 0; j < score; j += 1) {
        free(list[j]);
      }
      free(list);
      return 1;
    }
  }

  size_t marks_count[101] = {0};
  read_input(list, marks_count, n);
  print_names(list, marks_count);

  for (size_t i = 0; i < 101; i += 1) {
    for (size_t j = 0; j < marks_count[i]; j += 1) {
      free(list[i][j]);
    }
    free(list[i]);
  }
  free(list);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `marks.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `marks` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex06-woshiweiha0/commit/0617eaa11f72cee94efcc926eb3ddf2210689c71).

## Summary
| Question | Achievement |
|----------|-------|
| [sort](#sort) | Excellent |
| [valley](#valley) | Excellent |
| [inversion](#inversion) | Need Improvement |
| [marks](#marks) | Excellent |

Note: The achievement badges for this exercise take the running time of your solution into consideration.  See [the grader's comments](https://www.github.com/nus-cs1010-2425-s1/ex06-woshiweiha0/commit/0617eaa11f72cee94efcc926eb3ddf2210689c71) for details.
