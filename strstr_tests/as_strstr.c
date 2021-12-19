#include "as_strstr.h"
#include <glib.h>
#include <stdio.h>

char* as_strstr(char const* text, char const* find)
{
  g_assert(text != NULL);
  g_assert(find != NULL);
  if (*find == '\0') {
    return (char*)text;
  }
  int pointer_position = 0;
  while (*text != '\0') {
    if (*find == '\0') {
      while (pointer_position != 0) {
        text--;
        pointer_position--;
      }
      return (char*)text;
    }
    if (*find == *text) {
      find++;
      text++;
      pointer_position++;
    } else {
      while (pointer_position != 0) {
        find--;
        pointer_position--;
      }
      pointer_position = 0;
      text++;
    }
  }
  return '\0';
}
