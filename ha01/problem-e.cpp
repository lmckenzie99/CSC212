#include <iostream>

bool doMath(int wc, int hc, int ws, int hs) {
  int widthCheck = wc - 2;
  int heightCheck = hc - 2;

  if (ws <= widthCheck && hs <= heightCheck) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int wc, hc, ws, hs;
  std::cin >> wc >> hc >> ws >> hs;

  doMath(wc, hc, ws, hs) == true ? std::cout << "1" : std::cout << "0";
}
