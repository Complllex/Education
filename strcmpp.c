#include <stdio.h>

int result;
int result1;
int result2;
int count;
int count1;
int count2;

char as_strcmpcount(char const *s) {
  count = 0;
  while (*++s != '\0') {
    ++count;
  }
  return count;
}
char as_strcmp(char const *s) {
  if (s == NULL || *s == '\0') {
    return 0;
  }
     result = 0;
  int order = 1;
  while (*++s != '\0') {
    int number = *s - 96;
    result += number * order;
    order *= 10;
  }
  return result;
}
int main(int argc, char const *argv[]) {
  char const *text = argv[1];
  char const *find = argv[2];
  if(text == 0){return 0;}
  result1 = as_strcmp(text);
  result2 = as_strcmp(find);
  count1 = as_strcmpcount(text);
  count2 = as_strcmpcount(find);
  if(result1 == result2){
   printf("0\n");
  }else{
  if(count1 >= count2){
    printf("1\n");
  }else{printf("-1\n");}
  }
  return 0;
}
