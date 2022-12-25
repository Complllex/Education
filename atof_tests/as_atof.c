#include "as_atof.h"
#include <glib.h>
#include <math.h>
#include "range.h"

#include <stdio.h>
// Character helpers

bool is_number(char c) { return c >= '0' && c <= '9'; }

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

int ctoi(char c) { return c - '0'; }

// String helpers
bool is_input_correct(char a){
return (a != '.' && a != '-');
}

const char* extract_range(const char* input, const char* delimeters, struct range* range) {
  if (*input == '\0') {
    range_init(range);
    return input;
  }
  range->begin = input;
  while (!is_delimeter(*input, delimeters)) {
    if(!is_number(*input) && is_input_correct(*input)){return input;}
    range->end = ++input;
  }
  return input;
}

struct parse_result {
  char sign;
  struct range integral;
  struct range fractional;
};

void parse_result_init(struct parse_result* result) {
  result->sign = 1;
  range_init(&result->integral);
  range_init(&result->fractional);
}

void parse(const char* input, struct parse_result* result) {
  if (*input == '-') {
    result->sign = -1;
  } else if (!is_number(*input)) {
    return;
  }
  input = extract_range(input, ".", &result->integral);
  if (*input != '\0' && *input == '.') {
    extract_range(++input, "", &result->fractional);
  }
}

double range_to_number(const struct range* range, int order) {
  if (range_is_empty(range)) {
    return 0;
  }
  double result = 0;
  const char* current = range->begin;
  while (current != range->end) {
    if (is_number(*current)) {
      result += ctoi(*current) * pow(10, order);
    }
    order--;
    current++;
  }
  return result;
}

// Public interface

double as_atof(const char* input) {
  struct parse_result parse_result;
  parse_result_init(&parse_result);
  parse(input, &parse_result);
  struct range* integral = &parse_result.integral;
  struct range* fractional = &parse_result.fractional;
  return parse_result.sign * (range_to_number(integral, (integral->end - 1) - integral->begin) +
                              range_to_number(fractional, -1));
}
