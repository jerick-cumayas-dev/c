#include <iostream>

struct Node {
  int data;
  struct Node *next;
};

void displayLists(struct Node *node);
int displayMenu(struct Node *&node);
int getListLength(struct Node *node);

struct Node *createNode();
void insertAtBeginning(struct Node *&node);
void insertAtMiddle(struct Node *&node);
void insertAtEnd(struct Node *node);
void deleteAtBeginning(struct Node *&node);
void deleteAtMiddle(struct Node *&node);
void deleteAtEnd(struct Node *node);

int main() {
  int choice = 0;
  struct Node *head = NULL;
  head = createNode();

  head->data = 100;
  head->next = NULL;

  while (choice != 9) {
    choice = displayMenu(head);
  }

  displayLists(head);
  return 0;
}

int displayMenu(struct Node *&head) {
  int choice = 0;
  std::cout << "Menu:\n1. Display list\n2.Insert at beginning\n3. Insert at "
               "middle\n4. Insert at "
               "end\n5.Delete at beginning\n6.Delete at middle\n7. Delete at "
               "End\n8. Length of list\n8. Exit\nChoice: ";
  std::cin >> choice;
  std::cout << std::endl;

  switch (choice) {
  case 1:
    displayLists(head);
    break;
  case 2:
    insertAtBeginning(head);
    break;
  case 3:
    insertAtMiddle(head);
    break;
  case 4:
    insertAtEnd(head);
    break;
  case 5:
    deleteAtBeginning(head);
    break;
  case 6:
    deleteAtMiddle(head);
    break;
  case 7:
    deleteAtEnd(head);
    break;
  case 8:
    std::cout << getListLength(head) << std::endl;
    break;
  default:
    break;
  }
  return choice;
}

void displayLists(struct Node *node) {
  if (node == NULL) {
    std::cout << "List is empty." << std::endl;
    return;
  }

  std::cout << "Lists = ";
  while (node != NULL) {
    if (node->next == NULL) {
      std::cout << node->data << std::endl;
    } else {
      std::cout << node->data << ", ";
    }
    node = node->next;
  }
  std::cout << std::endl;
}

struct Node *createNode() {
  return (struct Node *)malloc(sizeof(struct Node *));
}

int getListLength(struct Node *node) {
  int counter = 0;

  while (node != NULL) {
    counter += 1;
    node = node->next;
  }

  return counter;
}

void insertAtBeginning(struct Node *&head) {
  struct Node *newNode = createNode();

  std::cout << "Input data: ";
  std::cin >> newNode->data;
  newNode->next = head;
  head = newNode;
}

void insertAtMiddle(struct Node *&node) {
  int location = 0;
  int length = getListLength(node);
  struct Node *newNode = createNode();

  std::cout << "Insert location: ";
  std::cin >> location;

  if (location > 1 && location < length) {
    struct Node *current = node;
    int ctrlNum = 1;

    while (ctrlNum != location - 1) {
      current = current->next;
      ctrlNum += 1;
    }

    std::cout << "Input data: ";
    std::cin >> newNode->data;
    newNode->next = current->next;
    current->next = newNode;
  } else {
    std::cout << "Location must be between 1 and " << length << "."
              << std::endl;
  }
}

void insertAtEnd(struct Node *node) {
  while (node->next != NULL) {
    node = node->next;
  }

  struct Node *newNode = createNode();

  std::cout << "Input data: ";
  std::cin >> newNode->data;

  newNode->next = NULL;

  node->next = newNode;
}

void deleteAtBeginning(struct Node *&node) {
  if (node == NULL) {
    std::cout << "List is empty." << std::endl;
    return;
  }

  struct Node *temp = node->next;
  node = temp;
}

void deleteAtMiddle(struct Node *&node) {
  if (node == NULL) {
    std::cout << "List is empty." << std::endl;
  }

  int location = 0;
  int length = getListLength(node);
  std::cout << "Input location to delete: ";
  std::cin >> location;

  if (location > 1 && location < length) {
    struct Node *current = node;
    int ctrlNum = 1;
    while (ctrlNum < location - 1) {
      current = current->next;
      ctrlNum += 1;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
    delete (temp);
  } else {
    std::cout << "Location should be between 1 and " << length << std::endl;
  }
}

void deleteAtEnd(struct Node *node) {
  if (node == NULL) {
    std::cout << "List is empty." << std::endl;
  }

  while (node->next->next != NULL) {
    node = node->next;
  }
  delete (node->next);
  node->next = NULL;
}
