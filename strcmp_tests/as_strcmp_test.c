#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

#include "as_strcmp.h"

int invoke_strcmp(const char* lhs, const char* rhs) { return as_strcmp(lhs, rhs); }

void test_strcmp_with_null()
{
  if (g_test_subprocess()) {
    invoke_strcmp(NULL, NULL);
    return;
  }
  g_test_trap_subprocess(NULL, 0, 0);
  g_test_trap_assert_failed();
}

void test_strcmp_with_lhs_is_less_than_rhs()
{
  int rc = invoke_strcmp("asw5", "asw7519");
  g_assert_cmpint(rc, <, 0);
}

void test_strcmp_with_inequal_multiple_characters_strings()
{
  int rc = invoke_strcmp("340282346638528859811704183484516925440", "340282346638528859811704183484516925440123123");
  g_assert_cmpint(rc, <, 0);
}

void test_strcmp_with_single_character_strings()
{
  int rc = invoke_strcmp("8", "8");
  g_assert_cmpint(rc, ==, 0);
}

void test_strcmp_with_multiple_characters_strings()
{
  int rc = invoke_strcmp("T56jasdMznx5qwqe", "T56jasdMznx5qwqe");
  g_assert_cmpint(rc, ==, 0);
}

void test_strcmp_with_rhs_is_less_than_lhs()
{
  int rc = invoke_strcmp("asd545", "asd5");
  g_assert_cmpint(rc, >, 0);
}

int main(int argc, char* argv[])
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/strcmp/null", test_strcmp_with_null);
  g_test_add_func("/strcmp/lhs_is_less_than_rhs", test_strcmp_with_lhs_is_less_than_rhs);
  g_test_add_func("/strcmp/inequal_multiple_characters_strings", test_strcmp_with_inequal_multiple_characters_strings);
  g_test_add_func("/strcmp/single_character_strings", test_strcmp_with_single_character_strings);
  g_test_add_func("/strcmp/multiple_characters_strings", test_strcmp_with_multiple_characters_strings);
  g_test_add_func("/strcmp/rhs_is_less_than_lhs", test_strcmp_with_rhs_is_less_than_lhs);
  return g_test_run();
}