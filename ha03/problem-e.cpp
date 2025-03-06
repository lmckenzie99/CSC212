#include <iostream>
#include <string>
#include <vector>

int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    int size, cars;
    std::cin >> size >> cars;
    size *= 100;

    std::vector<int> right;
    std::vector<int> left;
    for (int i = 0; i < cars; i++) {
      int size;
      std::string side;
      std::cin >> size >> side;
      if (side == "left") {
        left.push_back(size);
      }
      if (side == "right") {
        right.push_back(size);
      }
    }

    int trips = 0;
    while (left.size() > 0 || right.size() > 0) {
      int leftRemain = size;
      while (left.size() > 0 && left.back() <= leftRemain) {
        leftRemain -= left.back();
        left.pop_back();
      }
      trips++;
      if (left.size() == 0 && right.size() == 0) {
        break;
      }
      int rightRemain = size;
      while (right.size() > 0 && right.back() <= rightRemain) {
        rightRemain -= right.back();
        right.pop_back();
      }
      trips++;
    }
    std::cout << trips << std::endl;
  }
}
