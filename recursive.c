#include <stdio.h>

int factorial (int i);

int main() {
  /* code */
  printf("1! = %i\n", factorial(1));
  printf("3! = %i\n", factorial(3));
  printf("5! = %i\n", factorial(5));
  return 0;
}

int factorial (int i){
  int temp;
  if(i <= 1) return 1;
  temp = i * factorial(i - 1);
  return temp;
}