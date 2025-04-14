#include "doublylinkedlist.h"
#include <exception>
#include <iostream>
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList() {
  // TOOD: Implement the constructor
  head = tail = nullptr;
  n_nodes = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
  // TOOD: Implement the destructor
  clear();
}

void DoublyLinkedList::push_back(int v) {
  // TOOD: Implement the push_back method
  Node *newNode = new Node(v);
  if (empty()) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  n_nodes++;
}

void DoublyLinkedList::push_front(int v) {
  // TOOD: Implement the push_front method
  Node *newNode = new Node(v);
  if (empty()) {
    head = tail = newNode;
  } else {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }
  n_nodes++;
}

void DoublyLinkedList::push_at(int idx, int v) {
  // TOOD: Implement the push_at method

  if (idx < 0 || idx > n_nodes) {
    throw std::out_of_range("Index out of range");
  }

  if (idx == 0) {
    push_front(v);
    return;
  }
  if (idx == n_nodes) {
    push_back(v);
    return;
  }

  Node *newNode = new Node(v);
  Node *current = head;
  for (int i = 0; i < idx; i++) {
    current = current->next;
  }
  newNode->prev = current->prev;
  newNode->next = current;
  current->prev->next = newNode;
  current->prev = newNode;
  n_nodes++;
}

void DoublyLinkedList::pop_back() {
  // TOOD: Implement the pop_back method
  if (empty()) {
    throw std::runtime_error("List is empty");
  }

  Node *toPop = tail;

  if (n_nodes == 1) {
    head = tail = nullptr;
  } else {
    tail = tail->prev;
    tail->next = nullptr;
  }

  delete toPop;
  n_nodes--;
}

void DoublyLinkedList::pop_front() {
  // TOOD: Implement the pop_front method
  if (empty()) {
    throw std::runtime_error("List is empty");
  }

  Node *toPop = head;

  if (n_nodes == 1) {
    head = tail = nullptr;
  } else {
    head = head->next;
    head->prev = nullptr;
  }

  delete toPop;
  n_nodes--;
}

void DoublyLinkedList::pop_at(int idx) {
  // TOOD: Implement the pop_at method
  if (idx < 0 || idx >= n_nodes) {
    throw std::out_of_range("Index out of range");
  }

  if (idx == 0) {
    pop_front();
    return;
  }
  if (idx == n_nodes - 1) {
    pop_back();
    return;
  }

  Node *current = head;
  for (int i = 0; i < idx; i++) {
    current = current->next;
  }

  // Update links and delete
  current->prev->next = current->next;
  current->next->prev = current->prev;

  delete current;
  n_nodes--;
}

int DoublyLinkedList::back() {
  // TOOD: Implement the back method
  // replace the line below accordingly
  if (empty()) {
    throw std::runtime_error("List is empty");
  }
  return tail->data;
}

int DoublyLinkedList::front() {
  // TOOD: Implement the front method
  // replace the line below accordingly
  if (empty()) {
    throw std::runtime_error("List is empty");
  }

  return head->data;
}

int DoublyLinkedList::at(int idx) {
  // TOOD: Implement the at method
  // replace the line below accordingly
  if (idx >= n_nodes) {
    throw std::out_of_range("Index out of range");
  }
  if (idx >= 0) {
    Node *current = head;
    for (int i = 0; i < idx; i++) {
      current = current->next;
    }

    return current->data;
  }
  int realIdx = n_nodes + idx;

  if (realIdx < 0) {
    throw std::out_of_range("Negative index out of range");
  }

  Node *current = tail;
  for (int i = -1; i > idx; i--) {
    current = current->prev;
  }
  return current->data;
}

int DoublyLinkedList::size() {
  // TOOD: Implement the size method
  // replace the line below accordingly
  return n_nodes;
}

bool DoublyLinkedList::empty() {
  // TOOD: Implement the empty method
  // replace the line below accordingly
  return n_nodes == 0;
}

void DoublyLinkedList::clear() {
  // TOOD: Implement the clear method
  while (!empty()) {
    pop_front();
  }
}

void DoublyLinkedList::print() {
  // TOOD: Implement the print method
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
}

bool DoublyLinkedList::contains(int v) {
  // TOOD: Implement the contains method
  // replace the line below accordingly
  Node *current = head;
  while (current != nullptr) {
    if (current->data == v) {
      return true;
    }
    current = current->next;
  }
  return false;
}
