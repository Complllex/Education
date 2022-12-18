#include <stdbool.h>

struct range {
  const char* begin;
  const char* end;
};

void range_init(struct range* r);
bool range_is_empty(struct range const* r);
void range_print(struct range const* r);