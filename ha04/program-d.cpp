#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  float ratio;
  int n;
  auto comp = [](std::pair<int, int> a, std::pair<int, int> b) {
    return (a.first * 1.0f / a.second) < (b.first * 1.0f / b.second);
  };

  while (std::cin >> ratio >> n) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(comp)>
        pq(comp);
    float minimal = std::pow(10, 7);
    int w;

    for (int i = 0; i < n; i++) {
      std::cin >> w;
      pq.push({w, 1});
      minimal = std::min(minimal, w * 1.0f);
    }

    int res = 0;
    while (!pq.empty()) {
      auto top = pq.top();
      if (minimal / (top.first * 1.0f / top.second) >= ratio) {
        break;
      }
      pq.pop();
      pq.push({top.first, top.second + 1});
      minimal = std::min(minimal, top.first * 1.0f / (top.second + 1));
      res++;
    }

    std::cout << res << "\n";
  }
  return 0;
}
