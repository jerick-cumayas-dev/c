#include <iostream>

class Node {
private:
  int data;
  Node *next;

public:
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  };
  int getData() { return this->data; }
  Node *getNext() { return this->next; }
};

void displayNode(Node *node);

int main() {
  Node *head = new Node(12, NULL);
  displayNode(head);
  return 0;
}

void displayNode(Node *node) {
  std::cout << "Data: " << node->getData() << std::endl;
}
