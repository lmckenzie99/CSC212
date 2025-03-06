#include <iostream>
#include <stack>
#include <string>

bool isMatching(char opening, char closing) {
  return (opening == '(' && closing == ')') ||
         (opening == '[' && closing == ']') ||
         (opening == '{' && closing == '}');
}

bool isOpening(char c) { return c == '(' || c == '[' || c == '{'; }

bool isClosing(char c) { return c == ')' || c == ']' || c == '}'; }

int main() {
  int inputLen;
  std::cin >> inputLen;

  std::string program;
  std::cin.ignore();
  std::getline(std::cin, program);

  std::stack<std::pair<char, int>> delimiterStack;
  for (int i = 0; i < program.length(); i++) {
    char currentChar = program[i];

    if (isOpening(currentChar)) {
      delimiterStack.push({currentChar, i});
    } else if (isClosing(currentChar)) {
      if (delimiterStack.empty() ||
          !isMatching(delimiterStack.top().first, currentChar)) {
        std::cout << currentChar << " " << i;
        return 0;
      } else {
        delimiterStack.pop();
      }
    }
  }

  std::cout << "ok so far"; 
}
