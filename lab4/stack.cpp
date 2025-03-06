#include "stack.h"

template <typename T> Stack<T>::Stack() {
  capacity_ = 10;
  size_ = 0;
  elements = new T[capacity_];
}

template <typename T> Stack<T>::Stack(size_t capacity) {
  capacity_ = capacity;
  size_ = 0;
  elements = new T[capacity];
}

template <typename T> Stack<T>::~Stack() { delete[] elements; }
template <typename T> void Stack<T>::push(const T &val) {
  if (size_ >= capacity_) {
    throw std::length_error("Stack is full");
  }
  elements[size_] = val;
  size_++;
}
template <typename T> void Stack<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  size_--;
}
template <typename T> const T &Stack<T>::top() const {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  return elements[size_ - 1];
}
template <typename T> const size_t Stack<T>::size() const { return size_; }

template <typename T> bool Stack<T>::empty() const { return size_ == 0; }
