#include "stack.h"
#include <iostream>
#include <stdexcept>

int main() {

  Stack<int> s1(100);
  Stack<int> s2;

  for (int i = 0; i < 100; ++i) {
    s1.push(i);
  }
  for (int i = 0; i < 90; ++i) {
    s1.pop();
  }

  while (!s1.empty()) {
    std::cout << s1.top() << " ";
    s1.pop();
  }
  std::cout << std::endl;

  try {
    // this loop should break the program
    for (int i = 0; i < 100; ++i) {
      s2.push(i);
    }

    return 0;
  } catch (std::length_error& e) {
    std::cout << "Too long";
    return 1;
  }
}
