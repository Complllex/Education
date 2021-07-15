#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Тестовая программа, не нужно выкладывать на Github
int main(){
  char sign;
  int count = 0;
  int Value;
  printf("PassUnlocker v1 by Complllex\n");
  printf("Start? Y/N\n");
  scanf("%c", &sign);
  //printf("%d", sign);
  srand(time(0));
  Value = rand()%250;
  if(sign == 'Y'){
while (count++ != Value)
{
    printf("Pass: qG>(FNT%d\n", rand()&93);
    system("clear");
    printf("Pass: 1nfwynX%d\n", rand()&93);
    system("clear");
    printf("Pass: (VLYp_6%d\n", rand()&93);
    system("clear");
    printf("Pass: A*PY^jl%d\n", rand()&93);
    system("clear");
}
    printf("Result: qG>(FNT%d\n", rand()&93);
   // printf("%d", Value);
  }
  return 0;
}