#include <stdio.h>

typedef struct {
  char * name;
  int age;
} person;

void printPerson(person person);

int main() {
  /* code */
  person john;
  john.name = "John";
  john.age = 25;
  
  printPerson(john);
  return 0;
}

void printPerson(person person) {
  printf("%s is %d years old.", person.name, person.age);
}