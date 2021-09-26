#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

int invoke_strstr(char const* s, char const* m) { return as_strstr(s, m); }

void test_strstr_with_null()
{
  if (g_test_subprocess()) {
    char f = invoke_strstr(NULL, NULL);
    return;
  }
  g_test_trap_subprocess(NULL, 0, 0);
  g_test_trap_assert_failed();
}

void test_strstr_with_basicstring()
{
  int f = invoke_strstr("asf asn ads", "asn");
  g_assert_cmpfloat(f, ==, 1);
}

void test_strstr_with_singlenumber()
{
  int f = invoke_strstr("8", "8");
  g_assert_cmpfloat(f, ==, 1);
}

void test_strstr_with_longstring()
{
  int f = invoke_strstr("afd dfa asd dfaf jhb jahsbdy y ausdbhab ajsdbaksb", "dfaf");
  g_assert_cmpfloat(f, ==, 1);
}

void test_strstr_with_different_letters()
{
  int f = invoke_strstr("iha 78123 gha sbd ajkls## 43", "sbd");
  g_assert_cmpfloat(f, ==, 1);
}

void test_strstr_with_negative_float()
{
  int f = invoke_strstr("T56jasdMznx5qwqe", "T56jasdMznx5qwqe");
  g_assert_cmpfloat(f, ==, 0);
}

void test_strstr_with_large_float()
{
  int f = invoke_strstr("340282346638528859811704183484516925440", "340282346638528859811704183484516925440123123");
  g_assert_cmpfloat(f, ==, -49);
}

void test_strstr_with_float_followed_by_characters()
{
  int f = invoke_strstr("awr55", "awr15");
  g_assert_cmpfloat(f, >=, 0);
}

void test_strstr_with_characters_followed_by_float()
{
  int f = invoke_strstr("asv751", "asv891");
  g_assert_cmpfloat(f, <=, 0);
}

int main(int argc, char* argv[])
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/strstr/null", test_strstr_with_null);
  g_test_add_func("/strstr/basicstring", test_strstr_with_basicstring);
  g_test_add_func("/strstr/singlenumber", test_strstr_with_singlenumber);
  g_test_add_func("/strstr/longstring", test_strstr_with_longstring);
  g_test_add_func("/strstr/different_letters", test_strstr_with_different_letters);
  g_test_add_func("/strstr/negative_float", test_strstr_with_negative_float);
  g_test_add_func("/strstr/large_float", test_strstr_with_large_float);
  g_test_add_func("/strstr/float_followed_by_characters", test_strstr_with_float_followed_by_characters);
  g_test_add_func("/strstr/characters_followed_by_float", test_strstr_with_characters_followed_by_float);
  return g_test_run();
}