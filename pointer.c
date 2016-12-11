#include <stdio.h>

int main() {
  int n = 10;
  
  int * pointer_to_n = &n;
  
  *pointer_to_n += 1;
  /* code */
  if (pointer_to_n != &n) return 1;
  if (*pointer_to_n != 11) return 1;
  
  printf("value of pointer_to_n is %d\n", *pointer_to_n);
  printf("value of n is %d\n", n);
  printf("Done!\n");
  return 0;
}