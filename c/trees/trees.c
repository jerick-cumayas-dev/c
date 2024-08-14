#include <stdio.h>
#include <stdlib.h>

struct Direction {
  struct Node *left;
  struct Node *right;
};
typedef struct Direction Direction;

struct Node {
  int data;
  Direction directions;
};
typedef struct Node Node;

struct Node *createNode();
struct Node *initialData();
void displayNode(struct Node *node);
void preorderTraversal(struct Node *node);
void inorderTraversal(struct Node *node);
void postorderTraversal(struct Node *node);
void levelorderTraversal(struct Node *node);

int main() {
  Node *root = initialData();
  printf("Inorder Traversal:\n");
  inorderTraversal(root);
  printf("\nPreorder Traversal:\n");
  preorderTraversal(root);
  printf("\nPostorder Traversal:\n");
  postorderTraversal(root);
  printf("\nLevel order Traversal:\n");
  levelorderTraversal(root);
  return 0;
}

struct Node *createNode() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = 0;
  newNode->directions.left = NULL;
  newNode->directions.right = NULL;
  return newNode;
}

struct Node *initialData() {
  struct Node *first = createNode();
  struct Node *second = createNode();
  struct Node *third = createNode();
  struct Node *fourth = createNode();
  struct Node *fifth = createNode();
  struct Node *sixth = createNode();
  struct Node *seventh = createNode();

  first->data = 1;
  second->data = 2;
  third->data = 3;
  fourth->data = 4;
  fifth->data = 5;
  sixth->data = 6;
  seventh->data = 7;

  first->directions.left = second;
  first->directions.right = third;

  second->directions.left = fourth;
  second->directions.right = fifth;

  third->directions.left = sixth;
  third->directions.right = seventh;

  fourth->directions.left = NULL;
  fourth->directions.right = NULL;

  fifth->directions.left = NULL;
  fifth->directions.right = NULL;

  sixth->directions.left = NULL;
  sixth->directions.right = NULL;

  seventh->directions.left = NULL;
  seventh->directions.right = NULL;

  return first;
}

void displayNode(struct Node *node) { printf("-> %d ", node->data); }

void inorderTraversal(struct Node *node) {
  if (node->directions.left != NULL) {
    inorderTraversal(node->directions.left);
  }

  displayNode(node);

  if (node->directions.right != NULL) {
    inorderTraversal(node->directions.right);
  }
}

void preorderTraversal(struct Node *node) {
  displayNode(node);

  if (node->directions.left != NULL) {
    preorderTraversal(node->directions.left);
  }

  if (node->directions.right != NULL) {
    preorderTraversal(node->directions.right);
  }
}

void postorderTraversal(struct Node *node) {
  if (node->directions.left != NULL) {
    postorderTraversal(node->directions.left);
  }

  if (node->directions.right != NULL) {
    postorderTraversal(node->directions.right);
  }

  displayNode(node);
}

void levelorderTraversal(struct Node *node) {
  displayNode(node);

  if (node->directions.left != NULL) {
    displayNode(node->directions.left);
  }
  if (node->directions.right != NULL) {
    displayNode(node->directions.right);
  }

  levelorderTraversal(node->directions.left);
  levelorderTraversal(node->directions.right);
}
