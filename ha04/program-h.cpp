#include <iostream>
#include <queue>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string inputPattern;

  while (std::getline(std::cin, inputPattern)) {
    int totalThrows = 0;
    for (char digit : inputPattern) {
      totalThrows += digit - '0';
    }

    if (totalThrows % inputPattern.length() != 0) {
      printf("%s: invalid # of balls\n", inputPattern.c_str());
      continue;
    }

    int ballCount = totalThrows / inputPattern.length();
    bool isInvalidPattern = false;

    std::priority_queue<int, std::vector<int>, std::greater<int>> fallTimes;

    for (int time = 0; time < inputPattern.length() * 100; time++) {
      if (inputPattern[time % inputPattern.length()] == '0') {
        if (!fallTimes.empty() && fallTimes.top() == time) {
          isInvalidPattern = true;
        }
      } else {
        if (ballCount > 0 && (fallTimes.empty() || fallTimes.top() > time)) {
          ballCount--;
          fallTimes.push(time + inputPattern[time % inputPattern.length()] -
                         '0');
          continue;
        }

        if (!fallTimes.empty()) {
          if (fallTimes.top() == time) {
            fallTimes.pop();
            isInvalidPattern = !fallTimes.empty() && fallTimes.top() == time;
          } else {
            isInvalidPattern = true;
          }
        }
        fallTimes.push(time + inputPattern[time % inputPattern.length()] - '0');
      }
    }

    if (isInvalidPattern) {
      printf("%s: invalid pattern\n", inputPattern.c_str());
    } else {
      printf("%s: valid with %d balls\n", inputPattern.c_str(),
             totalThrows / inputPattern.length());
    }
  }

  return 0;
}
