#include <stdio.h>

void printBig(int number);


int main() {
  int array[] = { 1, 11, 2, 22, 3, 33 };
  for (int i = 0; i < 6; i++) {
    printBig(array[i]);
  }
  return 0;
}

void printBig(int number) {
  if(number > 10)
    printf("%d\n", number);
}