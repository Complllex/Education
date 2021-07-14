#include <stdio.h>
#include <stdlib.h>
//#include <math.h> 

double main(int argc, char const *argv[]) { 
  double texts, finds;
  double result;
  char const *text = argv[1];
  int chechtext = *text - 'A';
  if(chechtext == 40){
   printf("[2021] MathCalc 1.0 (alpha build 1.5)\nSupported commands: info\n");
   return 0;
  }
  char const *sign = argv[2];
  char const *find = argv[3];
  texts = atof(text);
  finds = atof(find);
  if(*sign == '+'){
   result = texts + finds;
  }
  if(*sign == '/'){
   result = texts / finds;
  }
  if(*sign == 'x'){
   result = texts * finds;
  }
  printf("\nResult: %g\n\n", result);
  return 0;
}