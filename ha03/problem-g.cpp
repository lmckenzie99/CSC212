#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void makeExpr(const std::string &s, int n, const std::vector<std::pair<int, int>> &bracketPairs, std::vector<std::string> &expressions) {
    int totalCombinations = 1 << n;
    for (int mask = 1; mask < totalCombinations; ++mask) {
        std::string temp = s;
        std::vector<bool> remove(s.size(), false);
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                remove[bracketPairs[i].first] = true;
                remove[bracketPairs[i].second] = true;
            }
        }
        std::string modified;
        for (int i = 0; i < s.size(); ++i) {
            if (!remove[i]) modified += s[i];
        }
        expressions.push_back(modified);
    }
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> bracketPairs;
    std::vector<std::string> expressions;
    std::stack<int> st;
    std::vector<bool> remove(s.size(), false);

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                bracketPairs.emplace_back(st.top(), i);
                st.pop();
            }
        }
    }

    int n = bracketPairs.size();
    makeExpr(s, n, bracketPairs, expressions);

    std::sort(expressions.begin(), expressions.end());
    expressions.erase(std::unique(expressions.begin(), expressions.end()), expressions.end());

    for (const std::string &expr : expressions) {
        std::cout << expr << std::endl;
    }

    return 0;
}

