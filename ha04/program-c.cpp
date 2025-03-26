#include <functional>
#include <iostream>
#include <queue>
#include <vector>

void addNum(
    long number,
    std::priority_queue<long, std::vector<long>, std::greater<long>> &highVals,
    std::priority_queue<long> &lowVals) {
  ((lowVals.empty()) || number < lowVals.top()) ? lowVals.push(number)
                                                : highVals.push(number);
}

void balance(
    std::priority_queue<long, std::vector<long>, std::greater<long>> &highVals,
    std::priority_queue<long> &lowVals) {
  int lowValsSize = lowVals.size();
  int highValsSize = highVals.size();

  if (lowValsSize != highValsSize) {
    if (lowValsSize - highValsSize > 1) {
      highVals.push(lowVals.top());
      lowVals.pop();
    } else if (highValsSize - lowValsSize > 1) {
      lowVals.push(highVals.top());
      highVals.pop();
    }
  }
}

long getMed(
    std::priority_queue<long, std::vector<long>, std::greater<long>> &highVals,
    std::priority_queue<long> &lowVals) {
  int lowValsSize = lowVals.size();
  int highValsSize = highVals.size();

  if (lowValsSize == highValsSize)
    return (lowVals.top() + highVals.top()) / 2;
  return (lowValsSize > highValsSize) ? lowVals.top() : highVals.top();
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  bool first = false;
  std::cin >> n;

  while (true) {
    int length;
    long num;
    std::cin >> length;
    std::vector<long> numVec;
    for (int i = 0; i < length; i++) {
      std::cin >> num;
      numVec.push_back(num);
    }

    std::priority_queue<long, std::vector<long>, std::greater<long>> highVals;
    std::priority_queue<long> lowVals;

    long median = 0;

    for (int i = 0; i < length; i++) {
      long number = numVec[i];
      addNum(number, highVals, lowVals);
      balance(highVals, lowVals);
      median += getMed(highVals, lowVals);
    }

    if (first)
      std::cout << "\n";
    first = true;
    std::cout << median;
    --n;
    if (n == 0)
      break;
  }

  return 0;
}
