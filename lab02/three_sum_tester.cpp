#include <cassert>

int three_sum(int *arr, int n, int target);

int main() {
  int arr1[] = {-2, 7, 11, 0};
  int arr2[] = {3, 3};
  int arr3[] = {-10, -5, 0, 5, 10, -4, -3, -2, -1, 0};

  // assert statements to test the function,
  // if the condition is false, the program will
  // terminate with an error message
  assert(three_sum(arr1, 4, 18) == 1);
  assert(three_sum(arr1, 4, 16) == 1);
  assert(three_sum(arr1, 4, -1) == 0);
  assert(three_sum(arr1, 4, 0) == 0);

  assert(three_sum(arr3, 10, -15) == 1);
  assert(three_sum(arr3, 10, 0) == 1);
  assert(three_sum(arr3, 10, 500) == 0);
  assert(three_sum(arr3, 10, -100) == 0);
  assert(three_sum(arr3, 10, 170) == 0);
}
