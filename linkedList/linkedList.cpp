#include "linkedlist.h"
#include <iostream>

template <typename T> void SLList<T>::clear() {
  // TODO:
  // write method to clear lists
}

template <typename T> bool SLList<T>::search(const T &value) {
  Node *current = head;
  while (current != nullptr) {
    if (current->data == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

template <typename T> void SLList<T>::pushFront(const T &value) {
  // TODO:
  // push front
  // adds value to beginning of SLL
}
template <typename T> void SLList<T>::popFront() {
  // TODO:
  // pop front
  // removes value at beginning of SLL
}
template <typename T> void SLList<T>::pushBack(const T &value) {
  // TODO:
  // push back
  // adds value to end of SLL
}
template <typename T> void SLList<T>::popBack() {
  // TODO:
  // pop back
  // removes value at end of SLL
}
template <typename T> void SLList<T>::print() {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
}
