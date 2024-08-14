#include "./headers/Doubly.h"
#include <cstdlib>
#include <cstring>

Doubly::Doubly(char *firstName, char *lastName, int age) {
  setFirstName(firstName);
  setLastName(lastName);
  setAge(age);
};

char *Doubly::getFirstName() { return this->firstName; }
char *Doubly::getLastName() { return this->lastName; }
int Doubly::getAge() { return this->age; }

void Doubly::setAge(int age) { this->age = age; }
void Doubly::setFirstName(char *firstName) {
  this->firstName = (char *)malloc(10 * sizeof(char));
  std::strcpy(this->firstName, firstName);
}
void Doubly::setLastName(char *lastName) {
  this->lastName = (char *)malloc(10 * sizeof(char));
  std::strcpy(this->lastName, lastName);
}
