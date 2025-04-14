#include <fstream>
#include <iostream>
#include <vector>

constexpr int SIZE = 24;

void floodFill(std::vector<std::vector<int>> &image, int x, int y,
               int oldColor) {
  if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || image[x][y] != oldColor ||
      image[x][y] == 0) {
    return;
  }

  image[x][y] = 0; // Change the color to white

  floodFill(image, x + 1, y, oldColor); // Down
  floodFill(image, x - 1, y, oldColor); // Up
  floodFill(image, x, y + 1, oldColor); // Right
  floodFill(image, x, y - 1, oldColor); // Left
}

int main(int argc, char *argv[]) {

  std::ifstream file(argv[1]);
  
  int x = std::stoi(argv[2]);
  int y = std::stoi(argv[3]);

  std::vector<std::vector<int>> image(SIZE, std::vector<int>(SIZE));

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      file >> image[i][j];
    }
  }

  file.close();

  int startColor = image[x][y];
  if (startColor != 0) {
    floodFill(image, x, y, startColor);
  }

  for (const auto &row : image) {
    for (int pixel : row) {
      std::cout << pixel << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
