#include <stdio.h>

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
  if (s == NULL || *s == '\0') {
    return 0;
  }
  double result = 0;
  int order = 1;
  int ordertwo = 1;
  int check = 0;
  int pointCheck = 0;
  char const *s_current = as_end(s);
  while (s_current >= s) {
    int number = *s_current - '0';
     if(number == -2 && pointCheck == 0){
        result = result/order;
        check += 5;
        --s_current;
        pointCheck = 1;
    }else{
    if(number >= 9 || number <= 0){     
    return result;
    }else{
    if(check == 0){
    result += number * order;
    order *= 10;
    --s_current;
    }else{result += number * ordertwo;
        ordertwo *= 10;
        --s_current;}
    }
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
char const *a = argv[1];
  printf("%lf\n", as_atof(a));
  return 0;
}
