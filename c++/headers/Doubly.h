#ifndef DOUBLY_H
#define DOUBLY_H

class Doubly {
private:
  char *firstName;
  char *lastName;
  int age;
  Doubly *previous;
  Doubly *next;

public:
  Doubly(char *firstName, char *lastName, int age);
  char *getFirstName();
  char *getLastName();
  int getAge();
  void setFirstName(char *firstName);
  void setLastName(char *lastName);
  void setAge(int age);
};

#endif // !DOUBLY_H
