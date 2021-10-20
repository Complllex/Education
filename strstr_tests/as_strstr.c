#include <glib.h>
#include <stdio.h>
#include "as_strstr.h"

char as_strstr(char const* text, char const* find)
{
  int result = 0;
  int result2 = 0;
  char const* findforreturn = find;
  g_assert(text != NULL);
  g_assert(find != NULL);
  while (*find != '\0') {
    int numberfind = *find - 96;
    result += numberfind;
    *find++;
  }
  while (*text != '\0') {
    int numbertext = *text - 96;
    if (numbertext == -64) {
      if (result2 == result) {
        printf("return: %s%s\n", findforreturn, text);
        return 1;
      } else {
        result2 = 0;
        *text++;
      }
    } else {
      result2 += numbertext;
      *text++;
    }
  }
  if (*text == '\0') {
    if (result2 == result) {
      printf("return: %s\n", findforreturn);
      return 1;
    }
  }
  return NULL;
}
