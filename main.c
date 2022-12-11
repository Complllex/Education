#include <stdbool.h>
#include <stdio.h>

bool is_delimeter(char c, char const* extras) {
  if (c == '\0') {
    return true;
  }
  while (*extras != '\0') {
    if (*extras++ == c) {
      return true;
    }
  }
  return false;
}

struct range {
  const char* begin;
  const char* end;
};

void range_init(struct range* r) {
  r->begin = NULL;
  r->end = NULL;
}

bool range_is_empty(struct range const* r) { return r->begin == NULL && r->end == NULL; }

void range_print(struct range const* r) {
  if (range_is_empty(r)) {
    printf("empty\n");
  } else {
    printf("(%c, %c)\n", *r->begin, *r->end);
  }
}

const char* extract_range(const char* input, const char* delimeters, struct range* range) {
  if (*input == '\0') {
    range_init(range);
    return input;
  }
  range->begin = input;
  while (!is_delimeter(*input, delimeters)) {
    range->end = input++;
  }
  return input;
}

void split(const char* input, struct range* integral, struct range* fractional) {
  input = extract_range(input, ".", integral);
  if (*input != '\0') {
    extract_range(++input, "", fractional);
  }
}

void parse(const char* input) {
  struct range integral, fractional;
  range_init(&integral);
  range_init(&fractional);
  printf("input: %s\n", input);
  split(input, &integral, &fractional);
  printf("  integral: ");
  range_print(&integral);
  printf("  fractional: ");
  range_print(&fractional);
}

int main() {
  parse("");
  parse("123");
  parse("123.456");
  return 0;
}
