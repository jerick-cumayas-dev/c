#include "./headers/Person.h"

Person::Person(std::string firstName, std::string lastName, int age) {
  this->firstName = std::move(firstName);
  this->lastName = std::move(lastName);
  this->age = age;
}

std::string Person::getFirstName() { return this->firstName; }

std::string Person::getLastName() { return this->lastName; }

int Person::getAge() { return this->age; }

bool Person::isEmpty() {
  return this->firstName.empty() && this->lastName.empty() && this->age == 0;
}
