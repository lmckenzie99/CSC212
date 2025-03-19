#ifndef SL_LIST
#define SL_LIST
#include <cstddef>
#include <iterator>

template <typename T> class SLList {
private:
  struct Node {
    T data;
    Node *next;
    Node(const T &value) {
      data = value;
      next = nullptr;
    }
  };
  Node *head;
  Node *tail;
  size_t size;

public:
  SLList() {
    head = tail = nullptr;
    size = 0;
  }
  ~SLList() { clear(); }
  size_t getSize() { return size; }
  bool empty() { return size == 0; }
  void clear();
  T &front();
  T &back();
  bool search(const T &value);
  void pushFront(const T &value);
  void popFront();
  void pushBack(const T &value);
  void popBack();
  void print();
};

#endif
