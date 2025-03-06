#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss(line);

  // Vector to store boolean values, indexed by character
  std::vector<bool> values(256, false);

  for (int i = 0; i < n; ++i) {
    std::string val;
    ss >> val;
    // Set the boolean value based on the input
    values['A' + i] = (val == "T");
  }

  std::getline(std::cin, line);
  std::stringstream ss2(line);

  std::stack<bool> tfVals;
  std::string operation;

  while (ss2 >> operation) {
    if (operation == "*") {
      bool op2 = tfVals.top();
      tfVals.pop();
      bool op1 = tfVals.top();
      tfVals.pop();
      tfVals.push(op1 && op2);
    } else if (operation == "+") {
      bool op2 = tfVals.top();
      tfVals.pop();
      bool op1 = tfVals.top();
      tfVals.pop();
      tfVals.push(op1 || op2);
    } else if (operation == "-") {
      bool op = tfVals.top();
      tfVals.pop();
      tfVals.push(!op);
    } else if (operation == "T") {
      tfVals.push(true);
    } else if (operation == "F") {
      tfVals.push(false);
    } else {
      // Use the first character of the token to index into values
      tfVals.push(values[operation[0]]);
    }
  }

  std::cout << (tfVals.top() ? "T" : "F") << std::endl;
 
}
