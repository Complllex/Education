#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

// Finds the first occurrence of the null-terminated byte string pointed to by substr
// in the null-terminated byte string pointed to by str. The terminating null characters
// are not compared.

// The behavior is undefined if either str or substr is not a pointer to a null-terminated
// byte string.
//
// Parameters
// str 	    - 	pointer to the null-terminated byte string to examine
// substr 	- 	pointer to the null-terminated byte string to search for
//
// Return value
// Pointer to the first character of the found substring in str, or a null pointer if such
// substring is not found. If substr points to an empty string, str is returned.

// char *strstr(const char* str, const char* substr);
// char as_strstr(char const* text, char const* find)

//     a  a+1 a+2 a+3 ...
//   ----------------------------
//   | a | s | f | a | s | n | ...
//   ----------------------------
//     ^           ^
//     |           |
//     |         substr
//     |
//    str
// +------------------------+
// | sizeof(char *) == 2^64 |
// | sizeof(char) == 1      |
// +------------------------+
//

char* invoke_strstr(char const* str, char const* substr) { return strstr(str, substr); }

void test_strstr_with_null()
{
  if (g_test_subprocess()) {
    invoke_strstr(NULL, NULL);
    return;
  }
  g_test_trap_subprocess(NULL, 0, 0);
  g_test_trap_assert_failed();
}

void test_strstr_finds_first_occurrence()
{
  char const* const str = "asfasnadsasn";
  char const* const substr = invoke_strstr(str, "asn");
  g_assert_cmpint(substr - str, ==, 3);
}

void test_strstr_can_not_find_substr()
{
  char const* s = invoke_strstr("asfasnadsasn", "vbn");
  g_assert_null(s);
}

void test_strstr_with_empty_substr()
{
  char const* const str = "asfasnadsasn";
  char const* const substr = invoke_strstr(str, "");
  g_assert_cmpstr(substr, ==, str);
}

/*
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

void test_strstr_with_special_letters()
{
  int f = invoke_strstr("wwwwaf!@#$af asdds ds avdsve", "ds");
  g_assert_cmpfloat(f, ==, 1);
}

void test_strstr_with_letter()
{
  int f = invoke_strstr("aff gdf wth", "wth");
  g_assert_cmpfloat(f, ==, 1);
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
*/
int main(int argc, char* argv[])
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/strstr/null", test_strstr_with_null);
  g_test_add_func("/strstr/finds_first_occurrence", test_strstr_finds_first_occurrence);
  g_test_add_func("/strstr/can_not_find_substr", test_strstr_can_not_find_substr);
  g_test_add_func("/strstr/empty_substr", test_strstr_with_empty_substr);
  return g_test_run();
}