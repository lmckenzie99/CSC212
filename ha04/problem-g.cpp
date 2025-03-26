#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct MedianHeap {
  std::priority_queue<int> maxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  void insert(int value) {
    if (maxHeap.empty() || value <= maxHeap.top()) {
      maxHeap.push(value);
    } else {
      minHeap.push(value);
    }
    balanceHeaps();
  }

  int extractMedian() {
    int median;
    if (maxHeap.size() == minHeap.size()) {
      median = minHeap.top();
      minHeap.pop();
    } else {
      median = maxHeap.top();
      maxHeap.pop();
    }
    balanceHeaps();
    return median;
  }

  void balanceHeaps() {
    while (maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
    while (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::string inputLine;
  MedianHeap medianHeap;

  while (std::getline(std::cin, inputLine)) {
    if (inputLine[0] == '#') {
      std::cout << medianHeap.extractMedian() << std::endl;
    } else {
      medianHeap.insert(std::stoi(inputLine));
    }
  }
  return 0;
}
