#include <cassert>

int two_sum(int *arr, int n, int target) {
  // TODO : complete function
  // return 1 if sum of 2 digits in array = target value
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == target) {
        return 1;
      }
    }
  }
  return 0;
}

int three_sum(int *arr, int n, int target) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (arr[i] + arr[j] + arr[k] == target) {
          return 1;
        }
      }
    }
  }
  return 0;
}
