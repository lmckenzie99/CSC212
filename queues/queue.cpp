#include "queue.h"
template <typename T> Queue<T>::Queue() {
  capacity_ = 10;
  size_ = 0;
  elements_ = new T[capacity_];
}

template <typename T> Queue<T>::Queue(size_t capacity) {
  capacity_ = capacity;
  size_ = 0;
  elements_ = new T[capacity];
}

template <typename T> Queue<T>::~Queue() { delete[] elements_; }
