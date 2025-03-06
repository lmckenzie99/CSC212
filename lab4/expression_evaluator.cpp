#include "stack.h"
#include "stack.cpp"
#include <iostream>
#include <string>
#include <cctype>

int evaluateExpression(const std::string &expr) {
    Stack<int> operands;
    Stack<char> operators;
    
    for (size_t i = 0; i < expr.length(); ++i) {
        char ch = expr[i];
        
        if (ch == ' ' || ch == '(') {
            continue;
        } else if (isdigit(ch)) {
            operands.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operators.push(ch);
        } else if (ch == ')') {
            char op = operators.top();
            operators.pop();
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();
            
            int result = 0;
            switch (op) {
                case '+': result = left + right; break;
                case '-': result = left - right; break;
                case '*': result = left * right; break;
                case '/': result = left / right; break;
            }
            operands.push(result);
        }
    }
    
    return operands.top();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return 1;
    }
    
    std::string expression = argv[1];
    int result = evaluateExpression(expression);
    std::cout << result << std::endl;
    return 0;
}

