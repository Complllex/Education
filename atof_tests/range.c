#include "range.h"
#include <stdbool.h>
#include <stdio.h>

void range_init(struct range* r) {
  r->begin = NULL;
  r->end = NULL;
}

bool range_is_empty(struct range const* r) { return r->begin == NULL && r->end == NULL; }

void range_print(struct range const* r) {
  if (range_is_empty(r)) {
    printf("empty\n");
  } else {
    printf("[%c, %c]\n", *r->begin, *(r->end - 1));
  }
}
