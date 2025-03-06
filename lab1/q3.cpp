void reverse(int *arr, int size) {
  if (size <= 1) {
    return;
  }

  int *start = arr;
  int *end = arr + size - 1;

  while (start < end) {
    int temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}

int main() {
  int single[] = {1};
  int odd_len[] = {1, 2, 3, 4, 5};
  int even_len[] = {1, 2, 3, 4, 5, 6};

  reverse(single, 1);
  reverse(odd_len, 5);
  reverse(even_len, 6);
}
