#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>

//Group: Liam McKenzie and Braden Hutchins
// Generates a random value between -5000 and 4999 to populate the array
// the range of values is -5000 4999

// include the prototype of the functions,
// implemented in the algorithms.cpp file
int two_sum(int *arr, int n, int target);
int three_sum(int *arr, int n, int target);

// define and implement a function to create
// an array of random integers using dynamic memory allocation
int *create_random_array(int n) {
  // dynamically allocate space for an array of n integers
  int *arr = new int[n];
  // initialize the array with random values
  for (int i = 0; i < n; i++) {
    arr[i] = (rand() % 1000) - 500;
  }
  return arr;
}

// define and implement a function to benchmark the two_sum
// and three_sum functions given an array of integers and a target
void benchmark(int *arr, int n, int target) {
  // 3. print a line that produces the following output:
  //   the length of the array, followed by a tab character,
  //   followed by the execution time of the two_sum function,
  //   followed by a tab character, followed by the execution
  //   time of the three_sum function, and finally a newline
  //   character
  // The execution time should be in seconds with 6 decimal places
  // You can use the code provided in lectures to format the output
  // accordingly.
  auto twoStart = std::chrono::high_resolution_clock::now();
  two_sum(arr, n, target);
  auto twoEnd = std::chrono::high_resolution_clock::now();

  auto threeStart = std::chrono::high_resolution_clock::now();
  three_sum(arr, n, target);
  auto threeStop = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> durationTwo(twoEnd - twoStart);
  std::chrono::duration<double> durationThree(threeStop - threeStart);
  std::cout << std::fixed;
  std::cout << std::setprecision(6) << "Length of array: " << n << "\tTwo Sum Execution time: "<< durationTwo.count() << "\t Three Sum Execution: " << durationThree.count() << '\n';
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    // error message indicating the correct usage of the program
    std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
    // return an error code to the operating system
    return 1;
  }
  // convert the input argument to an integer
  int length = std::stoi(argv[1]);
  // dynamically allocate memory for an array of integers
  // initialize the array with random values
  int *numbers = create_random_array(length);

  // run a function to benchmark and output the
  // execution time of the two_sum function and
  // the three_sum function given the length
  // provided as a command line argument
  benchmark(numbers, length, 123);

  // free the memory allocated for the array
  delete[] numbers;
  // return 0 to the operating system
  return 0;
}
