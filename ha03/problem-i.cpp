
#include <iostream>
#include <deque>
#include <cmath>

void balance(std::deque<int> &first_half, std::deque<int> &second_half) {
    int diff = first_half.size() - second_half.size();
    int val;
    if (diff < 0) {
        double d = (double)diff / -2;
        for (int i = 0; i < std::ceil(d); i++) {
            val = second_half.front();
            second_half.pop_front();
            first_half.push_back(val);
        }
    }
    else if (diff > 1) {
        double d = (double)diff / 2;
        for (int i = 0; i < std::floor(d); i++) {
            val = first_half.back();
            first_half.pop_back();
            second_half.push_front(val);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::deque<int> first_half;
    std::deque<int> second_half;
    std::string command;
    int num;
    for (int i = 0; i < n; i++) {
        std::cin >> command >> num;
        if (command == "get") {
            if (first_half.size() > num) {
                std::cout << first_half[num] << '\n';
            }
            else {
                std::cout << second_half[num - first_half.size()] << '\n';
            }
        }
        else if (command == "push_back") {
            second_half.push_back(num);
            balance(first_half, second_half);
        }
        else if (command == "push_front") {
            first_half.push_front(num);
            balance(first_half, second_half);
        }
        else if (command == "push_middle") {
            first_half.push_back(num); 
            balance(first_half, second_half);
        }
    }

}
