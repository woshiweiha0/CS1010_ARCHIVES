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
