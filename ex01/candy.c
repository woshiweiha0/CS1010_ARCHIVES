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
