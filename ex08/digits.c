/**
 * CS1010 Semester 1 AY24/25
 * Exercise 8: Digits
 *
 * @file: digits.c
 * @author: Poh Wei Hao (Group D05) with help of Jerry (C06)
 */

#include "cs1010.h"

#define NCOLS 28
#define NROWS 28
#define WHITE '.'
#define BLACK '#'
#define K 5

typedef struct {
  char content[NROWS][NCOLS];
  long digit;
} image;

typedef struct {
  const image *samples[K];
  long distances[K];
} k_closest;

long calc_distance(const image *i1, const image *i2, long max_dis)
{
  long dis = 0;
  for (size_t i = 0; i < NROWS; i += 1) {
    for (size_t j = 0; j < NCOLS; j += 1) {
      dis += (i1->content[i][j] != i2->content[i][j]);
      if (dis > max_dis) {
        return dis;
      }
    }
  }
  return dis;
}

void read_sample(image *img)
{
  img->digit = cs1010_read_long();
  for (size_t i = 0; i < NROWS; i += 1) {
    for (size_t j = 0; j < NCOLS; j += 1) {
      char c = (char)getchar();
      if (c != WHITE && c != BLACK) {
        j -= 1;
      } else {
        img->content[i][j] = c;
      }
    }
  }
}

void init_closest(k_closest *c)
{
  for (size_t i = 0; i < K; i += 1) {
    c->samples[i] = NULL;
    c->distances[i] = NROWS * NCOLS + 1;
  }
}

bool need_replace(long old_dis, long old_digit, long new_dis, long new_digit)
{
  return new_dis < old_dis || (new_dis == old_dis && new_digit < old_digit);
}

size_t cmp_which_to_replace(const k_closest *c, size_t i, size_t j)
{
  if (c->samples[i] == NULL) {
    return i;
  }
  if (c->samples[j] == NULL) {
    return j;
  }
  if (c->distances[i] > c->distances[j]) {
    return i;
  }
  if (c->distances[i] < c->distances[j]) {
    return j;
  }
  if (c->samples[i]->digit > c->samples[j]->digit) {
    return i;
  }
  if (c->samples[i]->digit < c->samples[j]->digit) {
    return j;
  }
  if (j > i) {
    return j;
  }
  return i;
}

size_t find_replace_idx(const k_closest *c)
{
  if (c->samples[0] == NULL) {
    return 0;
  }
  size_t curr = 0;
  for (size_t i = 1; i < K; i += 1) {
    curr = cmp_which_to_replace(c, curr, i);
  }
  return curr;
}

void get_k_closest(const image *sample, const image *test, size_t sample_size,
                   k_closest *result)
{
  init_closest(result);
  for (size_t i = 0; i < sample_size; i += 1) {
    size_t to_replace = find_replace_idx(result);
    long curr_max_dis = result->distances[to_replace];
    long dis = calc_distance(sample + i, test, curr_max_dis);
    if (result->samples[to_replace] == NULL ||
        need_replace(curr_max_dis, result->samples[to_replace]->digit, dis,
                     sample[i].digit)) {
      result->samples[to_replace] = sample + i;
      result->distances[to_replace] = dis;
    }
  }
}

size_t get_closest(const k_closest *c)
{
  long freq[10] = {0};
  long smallest[10];
  for (size_t i = 0; i < 10; i += 1) {
    smallest[i] = NROWS * NCOLS + 1;
  }
  for (size_t i = 0; i < K; i += 1) {
    if (c->samples[i] == NULL) {
      continue;
    }
    long idx = c->samples[i]->digit;
    freq[idx] += 1;
    if (c->distances[i] < smallest[idx]) {
      smallest[idx] = c->distances[i];
    }
  }
  long curr_max = freq[0];
  size_t curr_max_idx = 0;
  for (size_t i = 0; i < 10; i += 1) {
    if (freq[i] > curr_max ||
        (freq[i] == curr_max && smallest[i] < smallest[curr_max_idx])) {
      curr_max = freq[i];
      curr_max_idx = i;
    }
  }
  return curr_max_idx;
}

bool check(const image *sample, const image *test, size_t sample_size)
{
  k_closest c;
  get_k_closest(sample, test, sample_size, &c);
  long result = (long)get_closest(&c);
  cs1010_print_long(test->digit);
  putchar(' ');
  cs1010_println_long(result);
  return test->digit == result;
}

int main()
{
  size_t sample_size = cs1010_read_size_t();
  image *sample = malloc(sample_size * sizeof(image));
  if (sample == NULL) {
    return 1;
  }
  for (size_t i = 0; i < sample_size; i += 1) {
    read_sample(sample + i);
  }
  size_t test_size = cs1010_read_size_t();
  image *test = malloc(test_size * sizeof(image));
  if (test == NULL) {
    free(sample);
    return 1;
  }
  size_t correct = 0;
  for (size_t i = 0; i < test_size; i += 1) {
    read_sample(test + i);
    correct += check(sample, test + i, sample_size);
  }
  cs1010_println_double(100.0 * (double)correct / (double)test_size);
  free(sample);
  free(test);
}
