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
