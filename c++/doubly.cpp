#include <cstdlib>
#include <iostream>

// NOTE: To allocate memory with std::string we must use 'new Node()'
//       This allows memory allocation for std::strings
//       If you wish to use malloc, then the data type must be char *;
//       Ex: char *firstName;

struct Node {
  std::string firstName;
  std::string lastName;
  int age;
  struct Node *previous;
  struct Node *next;
};

struct Node *createNode();
void displayNode(struct Node *node, int number);
void displayLeftToRight(struct Node *node);
struct Node *initialData();

int main() {
  struct Node *head = initialData();
  displayLeftToRight(head);
}

/*struct Node *createNode() { return (struct Node *)malloc(sizeof(struct Node));
 * }*/
struct Node *createNode() { return new Node(); }

void displayNode(struct Node *node, int number) {
  std::cout << "Node " << number + 1 << std::endl;
  std::cout << "First Name: " << node->firstName << std::endl;
  std::cout << "Last Name: " << node->lastName << std::endl;
  std::cout << "Age: " << node->age << std::endl;
  std::cout << std::endl;
}

struct Node *initialData() {
  struct Node *head = createNode();
  head->firstName = "Jerick";
  head->lastName = "Cumayas";
  head->age = 23;

  struct Node *second = createNode();
  second->firstName = "Princess";
  second->lastName = "Cumayas";
  second->age = 15;

  struct Node *third = createNode();
  third->firstName = "Charles";
  third->lastName = "Cumayas";
  third->age = 21;

  third->previous = second;
  second->previous = head;
  head->previous = NULL;

  head->next = second;
  second->next = third;
  third->next = NULL;

  return head;
}

void displayLeftToRight(struct Node *node) {
  struct Node *current = node;
  if (current == NULL) {
    std::cout << "List is empty." << std::endl;
    delete (current);
    return;
  }

  int number = 0;
  while (current != NULL) {
    displayNode(current, number);
    number += 1;
    current = current->next;
  }
}
