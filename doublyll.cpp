#include <iostream>

struct Node {
  char data;
  Node *next, *prev;

  Node(char data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

struct DoublyLinkedList {
  Node *head;

  DoublyLinkedList() {
    this->head = nullptr;
  }

  void insertFirst(char);
  void insertLast(char);
  void insertBefore(char, char);
  void traversal();
  int length();
  Node *search(char);
  char getNodeValueAt(int);
  void deleteFirst();
  void deleteLast();
  void deleteByKey(char);
  void deleteList();
};

void DoublyLinkedList::insertFirst(char value) {
  Node *newNode = new Node(value);
  if (this->head == nullptr) {
    this->head = newNode;
  } else {
    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
  }
}

void DoublyLinkedList::insertLast(char value) {
  Node *newNode = new Node(value);
  if (this->head == nullptr) {
    this->head = newNode;
  } else {
    Node *currentNode = this->head;
    while (currentNode->next != nullptr) {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
  }
}

void DoublyLinkedList::traversal() {
  if (this->head == nullptr)
    return;
  Node *currentNode = this->head;
  while (currentNode != nullptr) {
    std::cout << currentNode->data << ' ';
    currentNode = currentNode->next;
  }
  std::cout << '\n';
}

int DoublyLinkedList::length() {
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

char DoublyLinkedList::getNodeValueAt(int position) {
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

Node *DoublyLinkedList::search(char key) {
  Node *searchNode = this->head;
  while (searchNode != nullptr) {
    if (searchNode->data == key)
      break;
    searchNode = searchNode->next;
  }
  return searchNode;
}

void DoublyLinkedList::insertBefore(char value, char key) {
  Node *searchNode = this->search(key);
  Node *newNode = new Node(value);
  if (this->head == nullptr || searchNode == nullptr) {
    std::cout << "Node tidak ditemukan!\n";
    delete newNode;
  } else if (this->head->next == nullptr) {
    this->head = newNode;
    newNode->next = searchNode;
    searchNode->prev = newNode;
  } else {
    newNode->next = searchNode;
    newNode->prev = searchNode->prev;
    searchNode->prev->next = newNode;
    searchNode->prev = newNode;
  }
}

void DoublyLinkedList::deleteByKey(char key) {
  Node *searchNode = this->search(key);
  if (head == nullptr || searchNode == nullptr) {
    std::cout << "Node yang dicari tidak ditemukan\n";
  } else {
    if (searchNode == this->head) {
      this->head = this->head->next;
      searchNode->next = nullptr;
    } else if (searchNode->next == nullptr) {
      searchNode->prev->next = nullptr;
      searchNode->prev = nullptr;
    } else {
      searchNode->prev->next = searchNode->next;
      searchNode->next->prev = searchNode->prev;
      searchNode->next = nullptr;
      searchNode->prev = nullptr;
    }
    delete searchNode;
  }
}

void DoublyLinkedList::deleteFirst() {
  if (this->head == nullptr) {
    return;
  } else {
    Node *tempNode = this->head;
    this->head = this->head->next;
    tempNode->next = nullptr;
    if (this->head != nullptr)
      this->head->prev = nullptr;
    delete tempNode;
  }
}

void DoublyLinkedList::deleteLast() {
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

void DoublyLinkedList::deleteList() {
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
  DoublyLinkedList *list = new DoublyLinkedList();

  list->insertFirst('K');
  list->insertFirst('U');
  list->insertFirst('R');
  list->insertLast('D');
  list->insertLast('A');
  list->insertFirst('T');
  list->insertLast('T');
  list->insertFirst('S');
  list->traversal();
  list->insertBefore('L', 'R');
  list->traversal();
  
  std::cout << list->length() << '\n';
  std::cout << list->getNodeValueAt(2) << '\n';
  
  list->deleteFirst();
  list->traversal();
  list->deleteLast();
  list->traversal();
  list->deleteByKey('L');
  list->traversal();

  list->deleteList();
  delete list;

  return 0;
}
