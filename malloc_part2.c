#include <stdio.h>
#include <stdlib.h>

int main() {
  int * arr = malloc(sizeof(int));
  
  for (int i = 0; i < 1000; i++) {
    arr[i] = i * 2;
  }
  
  for (int i = 0; i < 1000; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}