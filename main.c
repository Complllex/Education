#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void parse(const char* input) {
  printf("input: %s\n", input);
  printf("  result: %f\n", atof(input));
}

int main() {
  parse("");
  parse("123");
  parse("123.456");
  return 0;
}
