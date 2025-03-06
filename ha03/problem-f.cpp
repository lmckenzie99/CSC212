#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> socks(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> socks[i];
    }

    std::vector<int> pairPile;  // Renamed stack to pairPile
    int moves = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (!pairPile.empty() && pairPile.back() == socks[i]) {
            pairPile.pop_back();  // Pair the socks
        } else {
            pairPile.push_back(socks[i]);  // Move to auxiliary pile
        }
        moves++;  // Every operation is a move
    }

    if (pairPile.empty()) {
        std::cout << moves << "\n";
    } else {
        std::cout << "impossible\n";
    }

    return 0;
}

