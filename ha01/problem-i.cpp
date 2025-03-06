#include <iostream>
#include <string>

int main() {
    int k;
    std::string myAnswers, friendAnswers;
    
    std::cin >> k >> myAnswers >> friendAnswers;
    
    int n = myAnswers.size();
    int matchCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (myAnswers[i] == friendAnswers[i]) {
            matchCount++;
        }
    }

    int maxScore = std::min(matchCount, k) + std::min(n - matchCount, n - k);
    
    std::cout << maxScore;

    return 0;
}

