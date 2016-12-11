#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;

void printPoint (point * point);

int main() {
  point * mypoint;
  mypoint = malloc(sizeof(point));
  
  mypoint->x = 10;
  mypoint->y = 5;
  
  printPoint(mypoint);
  free(mypoint);
  return 0;
}

void printPoint (point * p) {
  printf("mypoint coordinates: %d, %d\n", p->x, p->y);
}