# CS1010 Exercise 7
## Feedback for woshiweiha0

#### Submission

Link: https://www.github.com/nus-cs1010-2425-s1/ex07-woshiweiha0/commit/3a01644d72c63518cfab3ca7add4558a3e100200

---
### walk
<details><summary>Code for  walk.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Walk
 *
 * @file: walk.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <stdlib.h>

long count_paths(long **path_counter, size_t x, size_t y)
{
  path_counter[0][0] = 1;

  for (size_t i = 0; i < y + 1; i += 1) {
    for (size_t j = 0; j < x + 1; j += 1) {
      if (i > 0) {
        path_counter[i][j] += path_counter[i - 1][j];
      }
      if (j > 0) {
        path_counter[i][j] += path_counter[i][j - 1];
      }
    }
  }

  long paths = path_counter[y][x];
  return paths;
}

int main()
{
  size_t x = cs1010_read_size_t();
  size_t y = cs1010_read_size_t();
  long **path_counter = calloc(y + 1, sizeof(long));
  if (path_counter == NULL) {
    cs1010_println_string("fail");
    return 1;
  }
  for (size_t i = 0; i < y + 1; i += 1) {
    path_counter[i] = calloc(x + 1, sizeof(long));
    if (path_counter[i] == NULL) {
      cs1010_println_string("fail");
      for (size_t j = 0; j < i; j += 1) {
        free(path_counter[j]);
      }
      free(path_counter);
      return 1;
    }
  }

  long npaths = count_paths(path_counter, x, y);
  cs1010_println_long(npaths);

  for (size_t i = 0; i < y + 1; i += 1) {
    free(path_counter[i]);
  }
  free(path_counter);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `walk.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `walk` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-woshiweiha0/commit/3a01644d72c63518cfab3ca7add4558a3e100200).

---
### maze
<details><summary>Code for  maze.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: maze
 *
 * @file: maze.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <unistd.h>

#define EMPTY '.'
#define WALL '#'
#define USER '@'

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void print_maze_row_with_color(char *maze_row)
{
  long l = (long)strlen(maze_row);
  for (long j = 0; j < l; j++) {
    if (maze_row[j] == EMPTY) {
      cs1010_print_string(BLUE);
    } else if (maze_row[j] == USER) {
      cs1010_print_string(RED);
    } else {
      cs1010_print_string(YELLOW);
    }
    putchar(maze_row[j]);
  }
  cs1010_println_string("");
  cs1010_print_string(RESET);
}

void print_maze(char **maze, long nrows, long steps)
{
  if (isatty(fileno(stdout))) {
    cs1010_clear_screen();
  }
  for (long i = 0; i < nrows; i += 1) {
    if (!isatty(fileno(stdout))) {
      cs1010_println_string(maze[i]);
    } else {
      print_maze_row_with_color(maze[i]);
    }
  }
  cs1010_println_long(steps);
  if (isatty(fileno(stdout))) {
    usleep(100 * 1000);
  }
}

char **allocate_maze(long m)
{
  char **maze = calloc((size_t)m, sizeof(char *));
  if (maze == NULL) {
    cs1010_println_string("fail");
    return NULL;
  }
  for (long i = 0; i < m; i += 1) {
    maze[i] = cs1010_read_word();
    if (maze[i] == NULL) {
      cs1010_println_string("fail");
      for (long j = 0; j < i; j += 1) {
        free(maze[j]);
      }
      free(maze);
      return NULL;
    }
  }
  return maze;
}

bool **allocate_visited(long m, long n)
{
  bool **visited = calloc((size_t)m, sizeof(bool *));
  if (visited == NULL) {
    cs1010_println_string("fail");
    return NULL;
  }
  for (long i = 0; i < m; i += 1) {
    visited[i] = calloc((size_t)n, sizeof(bool));
    if (visited[i] == NULL) {
      cs1010_println_string("fail");
      for (long j = 0; j < i; j += 1) {
        free(visited[j]);
      }
      free(visited);
      return NULL;
    }
  }
  return visited;
}

void swap_positions(char **maze, long x1, long y1, long x2, long y2)
{
  char temp = maze[x1][y1];
  maze[x1][y1] = maze[x2][y2];
  maze[x2][y2] = temp;
}

bool print_output(char **maze, long m, long n, long x, long y, long *steps,
                  bool **visited)
{
  visited[x][y] = true;
  if (x == 0 || y == 0 || x == m - 1 || y == n - 1) {
    return true;
  }

  if (maze[x - 1][y] == '.' && !visited[x - 1][y]) {
    swap_positions(maze, x, y, x - 1, y);
    *steps += 1;
    print_maze(maze, m, *steps);
    if (print_output(maze, m, n, x - 1, y, steps, visited)) {
      return true;
    }
    swap_positions(maze, x, y, x - 1, y);
    *steps += 1;
    print_maze(maze, m, *steps);
  }

  if (maze[x][y + 1] == '.' && !visited[x][y + 1]) {
    swap_positions(maze, x, y, x, y + 1);
    *steps += 1;
    print_maze(maze, m, *steps);
    if (print_output(maze, m, n, x, y + 1, steps, visited)) {
      return true;
    }
    swap_positions(maze, x, y, x, y + 1);
    *steps += 1;
    print_maze(maze, m, *steps);
  }

  if (maze[x + 1][y] == '.' && !visited[x + 1][y]) {
    swap_positions(maze, x, y, x + 1, y);
    *steps += 1;
    print_maze(maze, m, *steps);
    if (print_output(maze, m, n, x + 1, y, steps, visited)) {
      return true;
    }
    swap_positions(maze, x, y, x + 1, y);
    *steps += 1;
    print_maze(maze, m, *steps);
  }

  if (maze[x][y - 1] == '.' && !visited[x][y - 1]) {
    swap_positions(maze, x, y, x, y - 1);
    *steps += 1;
    print_maze(maze, m, *steps);
    if (print_output(maze, m, n, x, y - 1, steps, visited)) {
      return true;
    }
    swap_positions(maze, x, y, x, y - 1);
    *steps += 1;
    print_maze(maze, m, *steps);
  }
  return false;
}

int main()
{
  long m = cs1010_read_long();
  long n = cs1010_read_long();
  char **maze = allocate_maze(m);
  if (maze == NULL) {
    cs1010_println_string("fail");
    return 1;
  }

  bool **visited = allocate_visited(m, n);
  if (visited == NULL) {
    cs1010_println_string("fail");
    for (long i = 0; i < m; i += 1) {
      free(maze[i]);
    }
    free(maze);
    return 1;
  }

  long steps = 0;
  long x;
  long y;
  for (long i = 0; i < m; i += 1) {
    for (long j = 0; j < n; j += 1) {
      if (maze[i][j] == '@') {
        x = i;
        y = j;
        break;
      }
    }
  }
  print_maze(maze, m, steps);
  print_output(maze, m, n, x, y, &steps, visited);

  for (long i = 0; i < m; i += 1) {
    free(maze[i]);
    free(visited[i]);
  }
  free(maze);
  free(visited);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `maze.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `maze` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-woshiweiha0/commit/3a01644d72c63518cfab3ca7add4558a3e100200).

---
### fill
<details><summary>Code for  fill.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Fill
 *
 * @file: fill.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"

void fill_segment(long *image, size_t m, size_t n, size_t x, size_t y, long r,
                  long g, long b, long old_r, long old_g, long old_b)
{
  if (x >= m || y >= n) {
    return;
  }
  size_t idx = ((x * n) + y) * 3;
  if (image[idx] != old_r || image[idx + 1] != old_g ||
      image[idx + 2] != old_b) {
    return;
  }
  image[idx] = r;
  image[idx + 1] = g;
  image[idx + 2] = b;
  fill_segment(image, m, n, x + 1, y, r, g, b, old_r, old_g, old_b);
  fill_segment(image, m, n, x - 1, y, r, g, b, old_r, old_g, old_b);
  fill_segment(image, m, n, x, y + 1, r, g, b, old_r, old_g, old_b);
  fill_segment(image, m, n, x, y - 1, r, g, b, old_r, old_g, old_b);
}

void print_output(long *image, size_t m, size_t n)
{
  cs1010_print_string("P3 ");
  cs1010_print_size_t(n);
  cs1010_print_string(" ");
  cs1010_print_size_t(m);
  cs1010_println_string(" 255");
  for (size_t i = 0; i < m * n; i += 1) {
    cs1010_print_long(image[i * 3]);
    cs1010_print_string(" ");
    cs1010_print_long(image[i * 3 + 1]);
    cs1010_print_string(" ");
    cs1010_println_long(image[i * 3 + 2]);
  }
}

int main()
{
  size_t m = cs1010_read_size_t();
  size_t n = cs1010_read_size_t();

  long *image = calloc(3 * m * n, sizeof(long));
  if (image == NULL) {
    cs1010_println_string("fail");
    return 1;
  }

  for (size_t i = 0; i < 3 * m * n; i += 1) {
    image[i] = cs1010_read_long();
  }

  size_t q = cs1010_read_size_t();
  for (size_t i = 0; i < q; i += 1) {
    size_t x = cs1010_read_size_t();
    size_t y = cs1010_read_size_t();
    long r = cs1010_read_long();
    long g = cs1010_read_long();
    long b = cs1010_read_long();
    size_t idx = ((x * n) + y) * 3;
    long old_r = image[idx];
    long old_g = image[idx + 1];
    long old_b = image[idx + 2];
    if (old_r != r || old_g != g || old_b != b) {
      fill_segment(image, m, n, x, y, r, g, b, old_r, old_g, old_b);
    }
  }
  print_output(image, m, n);
  free(image);
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `fill.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `fill` passes all test cases. :thumbsup:

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-woshiweiha0/commit/3a01644d72c63518cfab3ca7add4558a3e100200).

---
### sudoku
<details><summary>Code for  sudoku.c </summary>

```C
/**
 * CS1010 Semester 1 AY24/25
 * Exercise 7: Sudoku
 *
 * @file: sudoku.c
 * @author: Poh Wei Hao (Group D05)
 */

#include "cs1010.h"
#include <unistd.h>

#define EMPTY '.'

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void print_row_file(char *row)
{
  for (int i = 0; i < 9; i += 1) {
    putchar(row[i]);
    if (i == 2 || i == 5) {
      cs1010_print_string("│");
    }
  }
  putchar('\n');
}

void print_row_screen(char *row)
{
  for (int i = 0; i < 9; i += 1) {
    if (row[i] == EMPTY) {
      cs1010_print_string(YELLOW);
      putchar(row[i]);
      cs1010_print_string(RESET);
    } else {
      putchar(row[i]);
    }
    if (i == 2 || i == 5) {
      cs1010_print_string(RED);
      cs1010_print_string("│");
      cs1010_print_string(RESET);
    }
  }
  putchar('\n');
}

void print_sudoku_file(char *puzzle[9])
{
  for (int i = 0; i < 9; i += 1) {
    print_row_file(puzzle[i]);
    if (i == 2 || i == 5) {
      cs1010_println_string("───┼───┼───");
    }
  }
}

void print_sudoku_screen(char *puzzle[9])
{
  cs1010_clear_screen();
  for (int i = 0; i < 9; i += 1) {
    print_row_screen(puzzle[i]);
    if (i == 2 || i == 5) {
      cs1010_print_string(RED);
      cs1010_println_string("───┼───┼───");
      cs1010_print_string(RESET);
    }
  }
  usleep(10 * 1000);
}

void print_sudoku(char *puzzle[9])
{
  if (isatty(fileno(stdout))) {
    print_sudoku_screen(puzzle);
  } else {
    print_sudoku_file(puzzle);
  }
}

bool is_valid(char puzzle[9][9], long row, long col, char num)
{
  for (long i = 0; i < 9; i += 1) {
    if (puzzle[row][i] == num || puzzle[i][col] == num) {
      return false;
    }
  }

  long start_row = (row / 3) * 3;
  long start_col = (col / 3) * 3;
  for (long i = 0; i < 3; i += 1) {
    for (long j = 0; j < 3; j += 1) {
      if (puzzle[start_row + i][start_col + j] == num) {
        return false;
      }
    }
  }
  return true;
}

bool solve_sudoku(char puzzle[9][9])
{
  long row = -1;
  long col = -1;
  bool empty_found = false;

  for (long i = 0; i < 9 && !empty_found; i += 1) {
    for (long j = 0; j < 9; j += 1) {
      if (puzzle[i][j] == EMPTY) {
        row = i;
        col = j;
        empty_found = true;
        break;
      }
    }
  }

  if (!empty_found) {
    return true;
  }

  for (char num = '1'; num <= '9'; num += 1) {
    if (is_valid(puzzle, row, col, num)) {
      puzzle[row][col] = num;
      char *puzzle_ptr[9];
      for (int i = 0; i < 9; i++) {
        puzzle_ptr[i] = puzzle[i];
      }
      print_sudoku(puzzle_ptr);
      if (solve_sudoku(puzzle)) {
        return true;
      }
      puzzle[row][col] = EMPTY;
      print_sudoku(puzzle_ptr);
    }
  }

  return false;
}

int main()
{
  char puzzle[9][9];
  for (long i = 0; i < 9; i += 1) {
    char *line = cs1010_read_line();
    if (line == NULL) {
      cs1010_println_string("fail");
      return 1;
    }
    for (long j = 0; j < 9; j += 1) {
      puzzle[i][j] = line[j];
    }
    free(line);
  }

  char *puzzle_ptr[9];
  for (int i = 0; i < 9; i += 1) {
    puzzle_ptr[i] = puzzle[i];
  }

  print_sudoku(puzzle_ptr);

  if (!solve_sudoku(puzzle)) {
    cs1010_println_string("no solution");
  }
}
```

</details>

#### Compiler/Linter Warnings
- `clang` and `clang-tidy` are happy with your `sudoku.c`. No warnings are generated. :confetti_ball:

#### Test Cases

- Your `sudoku` fails to pass 5 of the test cases.

#### Other Issues

- You can find [other comments from your tutor (if any) here](https://www.github.com/nus-cs1010-2425-s1/ex07-woshiweiha0/commit/3a01644d72c63518cfab3ca7add4558a3e100200).

## Summary
| Question | Achievement |
|----------|-------|
| [walk](#walk) | Excellent |
| [maze](#maze) | Excellent |
| [fill](#fill) | Excellent |
| [sudoku](#sudoku) | Need Improvement |

Note: The achievement badges for this exercise take the running time of your solution into consideration.  See [the grader's comments](https://www.github.com/nus-cs1010-2425-s1/ex07-woshiweiha0/commit/3a01644d72c63518cfab3ca7add4558a3e100200) for details.
