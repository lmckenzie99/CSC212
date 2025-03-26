#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int numQueries;
  long long timeFactor;
  std::cin >> numQueries >> timeFactor;

  std::unordered_set<std::string> activePatients;
  std::priority_queue<std::pair<long long, std::string>,
                      std::vector<std::pair<long long, std::string>>,
                      std::greater<>>
      priorityQueue;

  auto getNextPatient = [&]() -> std::string {
    while (!priorityQueue.empty()) {
      auto [priority, name] = priorityQueue.top();
      priorityQueue.pop();
      if (!activePatients.count(name))
        continue;
      return name;
    }
    return "doctor takes a break";
  };

  while (numQueries--) {
    int queryType, currentTime;
    std::cin >> queryType >> currentTime;

    switch (queryType) {
    case 1: {
      std::string patientName;
      long long severity;
      std::cin >> patientName >> severity;
      activePatients.insert(patientName);
      priorityQueue.emplace(-(severity - currentTime * timeFactor),
                            std::move(patientName));
      break;
    }
    case 2: {
      std::cout << getNextPatient() << std::endl;
      break;
    }
    case 3: {
      std::string patientName;
      std::cin >> patientName;
      activePatients.erase(patientName);
      break;
    }
    }
  }

  return 0;
}
