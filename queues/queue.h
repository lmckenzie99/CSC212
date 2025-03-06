#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <typename T> class Queue {
private:
  T *elements_;
  size_t capacity_;
  size_t size_;
  size_t topVal;
  size_t bottomVal;
  size_t idx;

public:
  Queue();
  Queue(size_t capacity_);
  ~Queue();
  void push(const T& val);
  void pop();
  const T& top() const;
  size_t const size() const;
  bool empty() const;
};

#endif
