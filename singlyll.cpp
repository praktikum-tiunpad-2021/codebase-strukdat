#include <iostream>

struct Node {
  char data;
  Node *next;

  Node(char data) {
    this->data = data;
    this->next = nullptr;
  }
};

struct SinglyLinkedList {
  Node *head;

  SinglyLinkedList() {
    this->head = nullptr;
  }

  void insertFirst(char);
  void insertLast(char);
  void traversal();
  int length();
  char getNodeValueAt(int);
  void deleteFirst();
  void deleteLast();
  void deleteList();
};

void SinglyLinkedList::insertFirst(char value) {
  Node *newNode = new Node(value);
  if (this->head == nullptr) {
    this->head = newNode;
  } else {
    newNode->next = this->head;
    this->head = newNode;
  }
}

void SinglyLinkedList::insertLast(char value) {
  Node *newNode = new Node(value);
  if (this->head == nullptr) {
    this->head = newNode;
  } else {
    Node *currentNode = this->head;
    while (currentNode->next != nullptr) {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode; 
  }
}

void SinglyLinkedList::traversal() {
  if (this->head == nullptr)
    return;
  Node *currentNode = this->head;
  while (currentNode != nullptr) {
    std::cout << currentNode->data << ' ';
    currentNode = currentNode->next;
  }
  std::cout << '\n';
}

int SinglyLinkedList::length() {
  if (this->head == nullptr)
    return 0;
  Node *currentNode = this->head;
  int counter = 0;
  while (currentNode != nullptr) {
    counter++;
    currentNode = currentNode->next;
  }
  return counter;
}

char SinglyLinkedList::getNodeValueAt(int position) {
  int i = 0;
  Node *currentNode = this->head;
  while (currentNode != nullptr) {
    if (i == position)
      return currentNode->data;
    currentNode = currentNode->next;
    i++;
  }
  return '\0';
}

void SinglyLinkedList::deleteFirst() {
  if (this->head == nullptr) {
    return;
  } else {
    Node *tempNode = this->head;
    this->head = this->head->next;
    delete tempNode;
  }
}

void SinglyLinkedList::deleteLast() {
  if (this->head == nullptr) {
    return;
  } else if (this->head->next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    Node *pre = this->head, *tail = pre->next;
    while (tail->next != nullptr) {
      pre = tail;
      tail = tail->next;
    }
    pre->next = nullptr;
    delete tail;
  }
}

void SinglyLinkedList::deleteList() {
  if (this->head == nullptr)
    return;
  Node *currentNode = this->head;
  Node *nextNode = nullptr;
  while (currentNode != nullptr) {
    nextNode = currentNode->next;
    delete currentNode;
    currentNode = nextNode;
  }
  this->head = nullptr;
}

int main() {
  SinglyLinkedList *list = new SinglyLinkedList();

  list->insertFirst('K');
  list->insertFirst('U');
  list->insertFirst('R');
  list->insertLast('D');
  list->insertLast('A');
  list->insertFirst('T');
  list->insertLast('T');
  list->insertFirst('S');
  list->traversal();
  
  std::cout << list->length() << '\n';
  std::cout << list->getNodeValueAt(2) << '\n';
  
  list->deleteFirst();
  list->traversal();
  list->deleteLast();
  list->traversal();

  list->deleteList();
  delete list;

  return 0;
}
