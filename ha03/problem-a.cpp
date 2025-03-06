#include <iostream>
#include <queue>

void getInput(std::queue<int> &opTime, int &maxTime) {
  int tasks, time, counter;
  counter = 0;
  std::cin >> tasks >> maxTime;
  do {
    std::cin >> time;
    opTime.push(time);
    counter++;
  } while (counter < tasks);
}
int calcOps(std::queue<int> opTime, int maxTime) {
  int time, taskCount;
  int totalTime = 0;
  taskCount = 0;
  while (!opTime.empty() && totalTime < maxTime) {
    time = opTime.front();
    opTime.pop();


    if (totalTime + time <= maxTime) {
      totalTime += time;
      taskCount++;
    } else {
      break; 
    }
  }

  return taskCount;
}
int main() {
  std::queue<int> opTime;
  int maxTime, total;

  getInput(opTime, maxTime);
  total = calcOps(opTime, maxTime);
  std::cout << total;
}
