#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
  std::string firstName;
  std::string lastName;
  int age;

public:
  Person(std::string firstName, std::string lastName, int age);
  std::string getFirstName();
  std::string getLastName();
  int getAge();
  bool isEmpty();
};

#endif
