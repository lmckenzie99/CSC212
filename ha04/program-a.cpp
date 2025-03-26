#include <iostream>
#include <queue>
#include <stack>
int main() {
  int n;
  while (std::cin >> n) {
    std::queue<int> myQ;
    std::stack<int> myStack;
    std::priority_queue<int> myPQ;

    bool isBroken = false;
    bool isMyQ = true;
    bool isMyStack = true;
    bool isMyPQ = true;

    int i, op, num;
    int count = 0;
    int countTrue = 0;
    for (i = 0; i < n; i++) {
      std::cin >> op >> num;

      if (op == 1) {
        myQ.push(num);
        myStack.push(num);
        myPQ.push(num);
        count++;
        // std::cout << count << '\n';
      } else {
        if (count == 0) {
          std::cout << "impossible" << std::endl;
          isBroken = true;
          break;
        }

        if (myPQ.top() != num) {
          isMyPQ = false;
        }
        if (myQ.front() != num) {
          isMyQ = false;
        }
        if (myStack.top() != num) {
          isMyStack = false;
        }

        myPQ.pop();
        myQ.pop();
        myStack.pop();

        count--;
      }
    }
    if (isBroken) {
      for (i++; i < n; i++) {
        std::cin >> op >> num;
      }
      continue;
    }
    if (isMyPQ) {
      countTrue++;
    }
    if (isMyQ) {
      countTrue++;
    }
    if (isMyStack) {
      countTrue++;
    }

    if (countTrue > 1) {
      std::cout << "not sure\n";
    }
    if (countTrue == 1) {
      if (isMyQ) {
        std::cout << "queue\n";
      } else if (isMyStack) {
        std::cout << "stack\n";
      } else if (isMyPQ) {
        std::cout << "priority queue\n";
      }
    }
    if (countTrue < 1) {
      std::cout << "impossible";
    }
  }
}
