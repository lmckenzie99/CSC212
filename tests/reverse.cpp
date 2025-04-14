
#include <iostream>
#include <vector>

void reverse_array(std::vector<int> &arr, int n) {
  if (n <= arr.size() / 2)
    return; // Base case: stop when reaching the middle
  int i = arr.size() - n;
  // Swap manually without std::swap
  int temp = arr[i];
  arr[i] = arr[arr.size() - 1 - i];
  arr[n - 1] = temp;

  reverse_array(arr, n - 1); // Recursive call, moving towards the center
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};
  reverse_array(arr, arr.size());

  for (int num : arr) {
    std::cout << num << " ";
  }
  return 0;
}
