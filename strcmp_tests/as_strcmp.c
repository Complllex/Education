#include <glib.h>

#include "as_strcmp.h"

int result;

char as_strcmp(char const* s, char const* m)
{
  g_assert(s != NULL);
  g_assert(m != NULL);
  g_assert(*s != '\0');
  g_assert(*m != '\0');
  if (*s == '\0') {
    return 0;
  }
  if (*m == '\0') {
    return 0;
  }
  result = 0;
  while (*s != '\0' || *m != '\0') {
    int number = *s - 96;
    int numbersecond = *m - 96;
    if (number == numbersecond) {
      ++s;
      ++m;
    } else {
      result = number - numbersecond;
      return result;
    }
  }
  return 0;
}