#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char *firstName;
  char *lastName;
  int age;
  struct Node *next;
};

struct Node *createNode();
struct Node *initialData();
void displayNode(struct Node *node, int number);
void displayLeftToRight(struct Node *node);

int main() {
  struct Node *head = initialData();
  displayLeftToRight(head);
  return 0;
}

struct Node *createNode() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->firstName = (char *)malloc(10 * sizeof(char));
  newNode->lastName = (char *)malloc(10 * sizeof(char));
  return newNode;
}

struct Node *initialData() {
  struct Node *first = createNode();
  strcpy_s(first->firstName, 10, "Jerick");
  strcpy_s(first->lastName, 10, "Cumayas");
  first->age = 23;

  struct Node *second = createNode();
  strcpy_s(second->firstName, 10, "Charles");
  strcpy_s(second->lastName, 10, "Cumayas");
  second->age = 21;

  struct Node *third = createNode();
  strcpy_s(third->firstName, 10, "Princess");
  strcpy_s(third->lastName, 10, "Cumayas");
  third->age = 15;

  first->next = second;
  second->next = third;
  third->next = NULL;

  return first;
}

void displayNode(struct Node *node, int number) {
  printf("Node %d\n", number + 1);
  printf("First Name: %s\n", node->firstName);
  printf("Last Name: %s\n", node->lastName);
  printf("Age: %d\n\n", node->age);
}

void displayLeftToRight(struct Node *node) {
  if (node == NULL) {
    printf("List is empty.");
  }

  struct Node *current = node;
  int number = 0;
  while (current != NULL) {
    displayNode(current, number);
    number += 1;
    current = current->next;
  }
}
