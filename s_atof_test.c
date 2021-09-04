#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

// g_assert(s != NULL);

char const *as_end(char const *begin) {
  if (begin == NULL || *begin == '\0') {
    return begin;
  }
  char const *result = begin;
  while (*++begin != '\0') {
    result = begin;
  }
  return result;
}

double as_atof(char const *s) {
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
  char const *s_current = as_end(s);
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

double invoke_atof(const char *s) { return as_atof(s); }

void test_atof_with_null() {
  if (g_test_subprocess()) {
    float f = invoke_atof(NULL);
    return;
  }
  g_test_trap_subprocess(NULL, 0, 0);
  g_test_trap_assert_failed();
}

void test_atof_with_empty_string() {
  float f = invoke_atof("");
  g_assert_cmpfloat(f, ==, .0f);
}

void test_atof_with_float() {
  float f = invoke_atof("123.123");
  g_assert_cmpfloat(f, ==, 123.123f);
}

void test_atof_with_negative_float() {
  float f = invoke_atof("-123.123");
  g_assert_cmpfloat(f, ==, -123.123f);
}

void test_atof_with_large_float() {
  float f = invoke_atof("340282346638528859811704183484516925440");
  g_assert_cmpfloat(f, ==, 340282346638528859811704183484516925440.0f);
}

void test_atof_with_float_followed_by_characters() {
  float f = invoke_atof("123.123abc");
  g_assert_cmpfloat(f, ==, 123.123f);
}

void test_atof_with_characters_followed_by_float() {
  float f = invoke_atof("abc123.123");
  g_assert_cmpfloat(f, ==, .0f);
}

int main(int argc, char *argv[]) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/atof/null", test_atof_with_null);
  g_test_add_func("/atof/empty_string", test_atof_with_empty_string);
  g_test_add_func("/atof/float", test_atof_with_float);
  g_test_add_func("/atof/negative_float", test_atof_with_negative_float);
  g_test_add_func("/atof/large_float", test_atof_with_large_float);
  g_test_add_func("/atof/float_followed_by_characters",
                  test_atof_with_float_followed_by_characters);
  g_test_add_func("/atof/characters_followed_by_float",
                  test_atof_with_characters_followed_by_float);
  return g_test_run();
}