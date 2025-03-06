#include <algorithm>
#include <iostream>
#include <random>
void shuffler(int size) {
  // dynamically allocate memory for an array of integers
  int *numbers = new int[size];

  // create an array of pointers to integers
  int **pointers = new int *[size];

 
  for (int i = 0; i < size; i++) {
    numbers[i] = i + 1;
    pointers[i] = &numbers[i];
  }

  //create random number generator obj
  std::random_device rand;

  //use Mersenne Twister and rand to create a shuffler
  std::mt19937 gen(rand());
  
  //use shuffle alg to shuffle pointer arrays
  std::shuffle(pointers, pointers + size, gen);

  std::cout << "Original Numbers addresses/values: \n";
  for (int i = 0; i < size; i++) {
    std::cout << numbers << " "<< numbers[i]<< "\n";
  }
  
  std::cout << "Shuffled Numbers addresses/values: \n";
  for(int x = 0; x<size; x++){
    std::cout << pointers << " " << *pointers[x]<< '\n';
  }
  std::cout << '\n';

  delete[] numbers;
  delete[] pointers;
}

int main() {
  shuffler(3);
  shuffler(5);
  shuffler(10);
}
