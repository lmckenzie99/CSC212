#include <cmath>
#include <iomanip>
#include <iostream>

const double PI = acos(-1.0);

int main() {
  int n; // Number of test cases
  std::cin >> n;

  while (n--) {
    int m;
    std::cin >> m;

    double x = 0.0, y = 0.0, angle = 0.0;

    for (int i = 1; i <= m; ++i) {
      double rotation, distance;
      std::cin >> rotation >> distance;

     
        angle += rotation;
        double rad = angle * PI / 180.0;

        y += distance * std::cos(rad);
        x -= distance * std::sin(rad);
      
    }

    std::cout << std::fixed << std::setprecision(6) << x << " " << y << "\n";
  }
}
