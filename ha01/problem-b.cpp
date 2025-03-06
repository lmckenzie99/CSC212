#include <iostream>
#include <vector>
void getInput(int &problems, std::vector<int> &ratings) {
  int i = 0;
  int someNum;
  std::cin >> problems;
  while (i < problems) {
    std::cin >> someNum;
    ratings.push_back(someNum);
    i++;
  }
}

int findOdds(std::vector<int> &ratings) {
  int numOfOdds = 0;
  for (int i = 0; i < ratings.size(); i++) {
    if (ratings[i] % 2 == 1) {
      numOfOdds++;
    }
  }
  return numOfOdds;
}

int main() {
  int problems;
  std::vector<int> ratings;
  getInput(problems, ratings);
  std::cout << findOdds(ratings);
}
