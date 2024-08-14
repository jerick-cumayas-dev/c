#include <stdio.h>
#include <stdlib.h>

struct Node {
  char *firstName;
  char *lastName;
  int age;
  struct Node *previous;
  struct Node *next;
};

struct Node *createNode();
struct Node *getTail(struct Node *node);
struct Node *initialData();
void displayNode(struct Node *node, int number);
void displayLeftToRight(struct Node *node);
void displayRightToLeft(struct Node *node);

int main() {
  struct Node *head = initialData();
  printf("Display left to right: \n");
  displayLeftToRight(head);
  printf("Display right to left: \n");
  displayRightToLeft(getTail(head));
  free(head);
  head = NULL;
  displayLeftToRight(head);
  return 0;
}

struct Node *createNode() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->firstName = (char *)malloc(10 * sizeof(char));
  newNode->lastName = (char *)malloc(10 * sizeof(char));
  newNode->age = 0;
  newNode->previous = NULL;
  newNode->next = NULL;
  return newNode;
}

struct Node *getTail(struct Node *node) {
  struct Node *current = node;
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}

struct Node *initialData() {
  struct Node *first = createNode();
  struct Node *second = createNode();
  struct Node *third = createNode();

  first->firstName = "Jerick";
  first->lastName = "Cumayas";
  first->age = 23;
  first->previous = NULL;

  second->firstName = "Charles";
  second->lastName = "Cumayas";
  second->age = 21;
  second->previous = first;

  third->firstName = "Princess";
  third->lastName = "Cumayas";
  third->age = 15;
  third->previous = second;
  third->next = NULL;

  first->next = second;
  second->next = third;

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
    printf("List is empty.\n");
    return;
  }

  struct Node *current = node;
  int number = 0;
  while (current != NULL) {
    displayNode(current, number);
    number += 1;
    current = current->next;
  }
  free(current);
}

void displayRightToLeft(struct Node *node) {
  if (node == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node *current = node;
  int number = 0;
  while (current != NULL) {
    displayNode(current, number);
    number += 1;
    current = current->previous;
  }

  free(current);
}
