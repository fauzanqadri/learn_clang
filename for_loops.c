#include <stdio.h>

int main() {
  /* code */
  
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int factorial = 1;
  
  for (int i = 0; i < 10; i++) {
    factorial *= arr[i];
    
    printf("factorial %d is %d\n", (i+1), factorial);
  }
  return 0;
}
