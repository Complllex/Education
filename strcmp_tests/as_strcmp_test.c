#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

int invoke_strcmp(char const *s, char const *m) { return as_strcmp(s, m); }

void test_strcmp_with_null() {
  if (g_test_subprocess()) {
    char f = invoke_strcmp(NULL, NULL);
    return;
  }
  g_test_trap_subprocess(NULL, 0, 0);
  g_test_trap_assert_failed();
}

void test_strcmp_with_empty_string() {
  int f = invoke_strcmp("asw5", "asw7519");
  g_assert_cmpfloat(f, ==, -2);
}

void test_strcmp_with_argumentscount() {
  int f = invoke_strcmp("8", "8");
  g_assert_cmpfloat(f, ==, 0);
}

void test_strcmp_with_argumentscounttwo() {
  int f = invoke_strcmp("asd545", "asd5");
  g_assert_cmpfloat(f, ==, 52);
}

void test_strcmp_with_argumentscountthree() {
  int f = invoke_strcmp("8", "745");
  g_assert_cmpfloat(f, ==, 1);
}

void test_strcmp_with_negative_float() {
  int f = invoke_strcmp("T56jasdMznx5qwqe", "T56jasdMznx5qwqe");
  g_assert_cmpfloat(f, ==, 0);
}

void test_strcmp_with_large_float() {
  int f = invoke_strcmp("340282346638528859811704183484516925440",
                        "340282346638528859811704183484516925440123123");
  g_assert_cmpfloat(f, ==, -49);
}

void test_strcmp_with_float_followed_by_characters() {
  int f = invoke_strcmp("awr55", "awr15");
  g_assert_cmpfloat(f, >=, 0);
}

void test_strcmp_with_characters_followed_by_float() {
  int f = invoke_strcmp("asv751", "asv891");
  g_assert_cmpfloat(f, <=, 0);
}

int main(int argc, char *argv[]) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/strcmp/null", test_strcmp_with_null);
  g_test_add_func("/strcmp/empty_string", test_strcmp_with_empty_string);
  g_test_add_func("/strcmp/argumentscount", test_strcmp_with_argumentscount);
  g_test_add_func("/strcmp/argumentscounttwo",
                  test_strcmp_with_argumentscounttwo);
  g_test_add_func("/strcmp/argumentscountthree",
                  test_strcmp_with_argumentscountthree);
  g_test_add_func("/strcmp/negative_float", test_strcmp_with_negative_float);
  g_test_add_func("/strcmp/large_float", test_strcmp_with_large_float);
  g_test_add_func("/strcmp/float_followed_by_characters",
                  test_strcmp_with_float_followed_by_characters);
  g_test_add_func("/strcmp/characters_followed_by_float",
                  test_strcmp_with_characters_followed_by_float);
  return g_test_run();
}