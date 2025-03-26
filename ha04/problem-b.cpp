#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Order {
  int shares, price;
  bool operator<(const Order &other) const { return price < other.price; }
  bool operator>(const Order &other) const { return price > other.price; }
};

int main() {
  int testCases;
  std::cin >> testCases;

  while (testCases--) {
    int n;
    std::cin >> n;

    std::priority_queue<Order> buyOrders;
    std::priority_queue<Order, std::vector<Order>, std::greater<Order>>
        sellOrders;

    int lastStockPrice = -1;
    int askPrice = -1, bidPrice = -1;

    for (int i = 0; i < n; i++) {
      std::string orderType, skipWord;
      int shares, price;
      std::cin >> orderType >> shares >> skipWord >> skipWord >> price;

      if (orderType == "buy") {
        buyOrders.push({shares, price});
      } else {
        sellOrders.push({shares, price});
      }

      while (!buyOrders.empty() && !sellOrders.empty() &&
             buyOrders.top().price >= sellOrders.top().price) {
        Order buy = buyOrders.top();
        Order sell = sellOrders.top();
        buyOrders.pop();
        sellOrders.pop();

        int tradePrice = sell.price;
        int tradeAmount = std::min(buy.shares, sell.shares);

        lastStockPrice = tradePrice;

        buy.shares -= tradeAmount;
        sell.shares -= tradeAmount;

        if (buy.shares > 0)
          buyOrders.push(buy);
        if (sell.shares > 0)
          sellOrders.push(sell);
      }

      askPrice = sellOrders.empty() ? -1 : sellOrders.top().price;
      bidPrice = buyOrders.empty() ? -1 : buyOrders.top().price;

      std::cout << (askPrice == -1 ? "-" : std::to_string(askPrice)) << " "
                << (bidPrice == -1 ? "-" : std::to_string(bidPrice)) << " "
                << (lastStockPrice == -1 ? "-" : std::to_string(lastStockPrice))
                << "\n";
    }
  }
}
