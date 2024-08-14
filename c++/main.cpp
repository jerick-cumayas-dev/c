#include "./headers/Person.h"
#include <iostream>
#include <vector>

void displayPerson(Person person);
void displayPeople(Person people[], int size);
/*void displayPeople(const std::vector<Person> &people);*/

int main() {
  /*std::vector<Person> people = {Person("Jerick", "Cumayas", 23),*/
  /*                              Person("Princess", "Cumayas", 15)};*/
  Person people[] = {Person("Jerick", "Cumayas", 23),
                     Person("Princess", "Cumayas", 15)};
  if (people[0].isEmpty()) {
    printf("No array inside");
  } else {
    displayPeople(people, sizeof(people) / sizeof(people[0]));
  }

  return 0;
}

void displayPerson(Person person) {
  std::cout << "First Name: " << person.getFirstName() << std::endl;
  std::cout << "Last Name: " << person.getLastName() << std::endl;
  std::cout << "Age: " << person.getAge() << "\n" << std::endl;
}

/*void displayPeople(const std::vector<Person> &people) {*/
/*  for (size_t i = 0; i < people.size(); i++) {*/
/*    displayPerson(people[i]);*/
/*  }*/
/*}*/

void displayPeople(Person people[], int size) {
  for (size_t i = 0; i < size; i++) {
    displayPerson(people[i]);
  }
}
