#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

void getInput(int &numElem, std::string &prog, std::deque<int> &numDeq) {
  int tempNum;
  char comma;

  std::cin >> prog;
  std::cin >> numElem;
  std::cin.ignore();
  std::string numStr;
  std::getline(std::cin, numStr);

  numDeq.clear(); // Reset deque for each test case

  numStr.erase(std::remove(numStr.begin(), numStr.end(), '['), numStr.end());
  numStr.erase(std::remove(numStr.begin(), numStr.end(), ']'), numStr.end());

  std::stringstream ss(numStr);
  while (ss >> tempNum) {
    numDeq.push_back(tempNum);
    ss >> comma; // Discard commas
  }
}

bool runProg(const std::string &prog, std::deque<int> &numDeq) {
  bool isReversed = false;

  for (char command : prog) {
    if (command == 'R') {
      isReversed = !isReversed; // Toggle reversed state
    } else if (command == 'D') {
      if (numDeq.empty())
        return false;
      if (isReversed) {
        numDeq.pop_back();
      } else {
        numDeq.pop_front();
      }
    }
  }

  if (isReversed) {
    std::reverse(numDeq.begin(), numDeq.end());
  }

  return true;
}

void printDeque(const std::deque<int> &numDeq) {
  std::cout << "[";
  for (size_t i = 0; i < numDeq.size(); ++i) {
    if (i > 0)
      std::cout << ",";
    std::cout << numDeq[i];
  }
  std::cout << "]";
}

int main() {
  int numCase;
  std::cin >> numCase;

  while (numCase--) {
    int numElem;
    std::string prog;
    std::deque<int> numDeq;

    getInput(numElem, prog, numDeq);
    if (runProg(prog, numDeq)) {
      printDeque(numDeq);
    } else {
      std::cout << "error";
    }
    std::cout << "\n"; // Ensure correct formatting
  }
}
