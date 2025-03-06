#include <iostream>
#include <stack>
#include <vector>

int main() {
  int size, card;
  std::stack<int> cardsRemain;
  std::vector<int> allCards;
  std::cin >> size;
  for (int i = 0; i < size; i++) {
    std::cin >> card;
    allCards.push_back(card);
  }

  for (int i = 0; i < size; i++) {

    if (!cardsRemain.empty() && ((allCards[i] + cardsRemain.top()) % 2 == 0)) {
      cardsRemain.pop();
    } else {
      cardsRemain.push(allCards[i]);
    }
  }
  std::cout << cardsRemain.size();
}
