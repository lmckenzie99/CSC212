#include "pqueue.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> vals, result;
  int value;
  int k = std::stoi(argv[1]);

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " k";
    return 1;
  }

  if (k <= 0) {
    std::cerr << "Error: Positive k value must be entered!";
    return 1;
  }
  while (std::cin >> value) {
    vals.push_back(value);
  }

  PriorityQueue<int> pq(vals.size());
  pq.make_heap(vals);

  for (int i = 0; i < k; i++) {
    result.push_back(pq.front());
    pq.dequeue();
  }
//sorting is for redundancy of output, in theory it should have no affect on time complexity
  std::sort(result.begin(), result.end(), std::greater<int>());

  for (int value : result) {
    std::cout << value << " ";
  }

  return 0;
}
