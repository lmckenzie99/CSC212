#include <iostream>
void drawLine(int a) {
  if(a <= 0) { return; }
  std::cout << "+";
  drawLine(a - 1);
}
void drawTriangle(int a, int b, int c) {
  if (a > b) {
    return;
  }

  drawLine(a);
  std::cout << '\n';
  drawTriangle(a + c, b, c);

  if (a == b) {
    drawLine(a);
    std::cout << '\n';
  }
  

  if (a != b) {
    drawLine(a);
    std::cout << '\n';
  }
}

int main() {
  drawTriangle(4, 7, 1);
  std::cout << '\n';
  drawTriangle(3, 10, 3);
}
