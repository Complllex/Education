#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

#include "as_atof.h"

double invoke_atof(const char* s) { return as_atof(s); }

void test_atof_with_null() {
  if (g_test_subprocess()) {
    invoke_atof(NULL);
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

void test_atof_with_float_with_characters_in_the_middle() {
  float f = invoke_atof("123abc.123");
  g_assert_cmpfloat(f, ==, 123.0f);
}

int main(int argc, char* argv[]) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/atof/null", test_atof_with_null);
  g_test_add_func("/atof/empty_string", test_atof_with_empty_string);
  g_test_add_func("/atof/float", test_atof_with_float);
  g_test_add_func("/atof/negative_float", test_atof_with_negative_float);
  g_test_add_func("/atof/large_float", test_atof_with_large_float);
  g_test_add_func(
    "/atof/float_followed_by_characters",
    test_atof_with_float_followed_by_characters
  );
  g_test_add_func(
    "/atof/characters_followed_by_float",
    test_atof_with_characters_followed_by_float
  );
  g_test_add_func(
    "/atof/characters_in_the_middle",
    test_atof_with_float_with_characters_in_the_middle
  );
  return g_test_run();
}