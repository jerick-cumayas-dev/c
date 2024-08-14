#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
typedef struct Node Node;

Node *createNode();
Node *getTail(Node *node);
Node *initialData();
void displayNode(Node *node);
void displayStack(Node *node);
void push(Node **node, int data);

int main() {
  Node *head;
  push(&head, 100);
  displayStack(head);
  return 0;
}

Node *createNode() {
  Node *current = (Node *)malloc(sizeof(Node *));
  current->data = 0;
  current->next = NULL;
  return current;
}

void displayNode(Node *node) { printf("-> %d ", node->data); }

void displayStack(Node *node) {
  struct Node *current = node;
  while (current != NULL) {
    displayNode(node);
    current = current->next;
  }
}

void push(Node **node, int data) {
  Node *newNode = createNode();
  newNode->data = data;
  newNode->next = NULL;

  Node *current = *node;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}
