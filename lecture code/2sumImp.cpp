// two sum brute force which sux

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

// better solution
// sort

int two_sum_imp(int *arr, int n, int target) {
  // TODO : complete function
  // return 1 if sum of 2 digits in array = target value
  // sort
  //
  // Sort(arr, n)
  int p = 0;
  int q = n - 1;
  int sum;

  while (p < q) {
    sum = arr[p] + arr[q];
    if (sum == target) {
      return true;
    } else if (sum < target) {
      p++;
    } else {
      q--;
    }
    return false;
  }
  return 0;
}
