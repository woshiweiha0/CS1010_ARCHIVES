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
