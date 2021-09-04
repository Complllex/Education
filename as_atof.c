#include <glib.h>

#include "as_atof.h"

char const* as_end(char const* begin)
{
  if (begin == NULL || *begin == '\0') {
    return begin;
  }
  char const* result = begin;
  while (*++begin != '\0') {
    result = begin;
  }
  return result;
}

double as_atof(char const* s)
{
  g_assert(s != NULL);
  if (*s == '\0') {
    return 0;
  }
  double result = 0;
  double order = 1.0;
  double ordertwo = 1.0;
  int check = 0;
  int pointCheck = 0;
  int Bz = 0;
  int ltcheck = 0;
  char const* s_current = as_end(s);
  while (s_current >= s) {
    int number = *s_current - '0';
    if (number == -2 && pointCheck == 0) {
      result = result / order;
      check += 5;
      --s_current;
      pointCheck = 1;
    } else {
      if (number == -3) {
        Bz = 1;
        --s_current;
      } else {
        if (number >= 10 || number <= -1) {
          ltcheck = 1;
          --s_current;
        } else {
          if (check == 0) {
            result += number * order;
            order *= 10.0;
            ltcheck = 0;
            --s_current;
          } else {
            result += number * ordertwo;
            ordertwo *= 10.0;
            ltcheck = 0;
            --s_current;
          }
        }
      }
    }
  }
  if (Bz == 1) {
    result *= -1.0;
  }
  if (ltcheck == 1) {
    return 0;
  }
  return result;
}
