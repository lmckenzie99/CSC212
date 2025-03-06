#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<std::vector<int>> results;

  while (true) {
    int n;
    std::cin >> n;
    if (n == 0)
      break;

    std::vector<int> firstList(n), secondList(n);

    for (int i = 0; i < n; i++) {
      std::cin >> firstList[i];
    }

    for (int i = 0; i < n; i++) {
      std::cin >> secondList[i];
    }

    std::vector<int> sortedFirst = firstList;
    std::vector<int> sortedSecond = secondList;
    std::sort(sortedFirst.begin(), sortedFirst.end());
    std::sort(sortedSecond.begin(), sortedSecond.end());

    std::unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++) {
      mapping[sortedFirst[i]] = sortedSecond[i];
    }

    std::vector<int> reorderedList;
    for (int i = 0; i < n; i++) {
      reorderedList.push_back(mapping[firstList[i]]);
    }
    results.push_back(reorderedList);
  }

  for (size_t i = 0; i < results.size(); i++) {
    if (i > 0)
      std::cout << "\n";
    for (int num : results[i]) {
      std::cout << num << "\n";
    }
  }

 }
