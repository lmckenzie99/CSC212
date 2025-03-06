#include <iostream>
#include <string>
#include <vector>

void drawStructure(int count) {
  std::vector<std::string> outside(count, "H");
  std::vector<std::string> middle(count, "-C");

  middle[count - 1] = "-C-OH";
  std::cout << " ";
  for (int i = 0; i < count; i++) {
    std::cout << " " << outside[i];
  }
  std::cout << '\n';

  std::cout << " ";
  for (int i = 0; i < count; i++) {
    std::cout << " |";
  }
  std::cout << '\n';

  std::cout << "H";
  for (int i = 0; i < count; i++) {
    std::cout << middle[i];
  }
  std::cout << '\n';

  std::cout << " ";
  for (int i = 0; i < count; i++) {
    std::cout << " |";
  }
  std::cout << '\n';

  std::cout << " ";
  for (int i = 0; i < count; i++) {
    std::cout << " " << outside[i];
  }
}

int main() {
  int groupCount;
  std::cin >> groupCount;
  drawStructure(groupCount);
}
