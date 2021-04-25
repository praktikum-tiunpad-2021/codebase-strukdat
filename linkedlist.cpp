#include <iostream>

template <typename L>
class Node {
private:
  L data;
public:
  Node<L> *next;
  Node<L> *prev;

  Node(L data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }

  L getData() {
    return this->data;
  }
};

template <typename L>
class LinkedList {
protected:
  Node<L> *head;
public:
  LinkedList() {
    this->head = nullptr;
  }
  ~LinkedList() {
    deleteList();
  }
  virtual void insertFirst(L value) = 0;
  virtual void deleteLast() = 0;
  virtual void deleteFirst() = 0;

  void traversal() {
    if (this->head != nullptr) {
      Node<L> *currentNode = this->head;
      while (currentNode != nullptr) {
        std::cout << currentNode->getData() << ' ';
        currentNode = currentNode->next;
      }
    }
    std::cout << '\n';
  }

  void deleteList() {
    if (this->head == nullptr)
      return;
    Node<L> *currentNode = this->head;
    Node<L> *nextNode = nullptr;
    while (currentNode != nullptr) {
      nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
    }
    this->head = nullptr;
  }
};

template <typename L>
class SinglyLinkedList : public LinkedList<L> {
public:
  SinglyLinkedList() {
    this->head = nullptr;
  }

  void insertFirst(L value) {
    Node<L> *newNode = new Node<L>(value);
    if (this->head == nullptr) {
      this->head = newNode;
    } else {
      newNode->next = this->head;
      this->head = newNode;
    }
  }

  void deleteFirst() {
    if (this->head == nullptr)
      return;
    Node<L> *tempNode = this->head;
    this->head = this->head->next;
    delete tempNode; 
  }

  void deleteLast() {
    if (this->head == nullptr) {
      return;
    } else if (this->head->next == nullptr) {
      delete this->head;
      this->head = nullptr;
    } else {
      Node<L> *pre = this->head, *last = pre->next;
      while (last->next != nullptr) {
        pre = last;
        last = last->next;
      }
      pre->next = nullptr;
      delete last;
    }
  }
};

template <typename L>
class DoublyLinkedList : public LinkedList<L> {
private:
  Node<L> *tail;
public:
  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insertFirst(L value) {
    Node<L> *newNode = new Node<L>(value);
    if (this->head == nullptr) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      newNode->next = this->head;
      this->head->prev = newNode;
      this->head = newNode;
    }
  }

  void deleteFirst() {
    if (this->head == nullptr)
      return;
    Node<L> *tempNode = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete tempNode; 
  }

  void deleteLast() {
    if (this->head == nullptr) {
      return;
    } else if (this->head->next == nullptr) {
      delete this->head;
      this->head = nullptr;
      this->tail = nullptr;
    } else {
      this->tail = this->tail->prev;
      delete tail->next;
      this->tail->next = nullptr;
    }
  }
};

int main() {
  SinglyLinkedList<char> list;
  DoublyLinkedList<char> list2;

  list.insertFirst('K');
  list.insertFirst('N');
  list.insertFirst('A');
  list.traversal();
  list.deleteLast();
  list.traversal();
  std::cout << '\n';

  list2.insertFirst('K');
  list2.insertFirst('N');
  list2.insertFirst('A');
  list2.traversal();
  list2.deleteLast();
  list2.traversal();

  return 0;
}
