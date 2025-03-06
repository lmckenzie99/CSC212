#ifndef STACK_H
#define STACK_H
#include <cstddef>
#include <iterator>

template<typename T>
class Stack{
  private:
  T* elements;
  size_t capacity_;
  size_t size_;
  size_t topVal;

  public:
  Stack();
  Stack(size_t capacity);
  ~Stack();

  void push(const T& val);
  void pop();
  const T& top() const;
  size_t const size() const;
  bool empty() const;

};

template class Stack<int>;


#endif
