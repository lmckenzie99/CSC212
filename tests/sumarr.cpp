#include <iostream>
#include <vector>

int sum_array(std::vector<int>& arr, int n) {
    if (n == 0) return 0; // Base case: empty array, sum is 0

    int sum_rest = sum_array(arr, n - 1); // Recursive call on smaller array

    if (arr[n - 1] % 2 == 0) { // Check if current element is even
        return sum_rest + arr[n - 1]; // Include it in the sum
    } 
    return sum_rest; // Otherwise, skip it
}

int main(){
  std::vector<int> arr = {1,3,4,5,6,7};
  std::cout << sum_array(arr, arr.size());
}
