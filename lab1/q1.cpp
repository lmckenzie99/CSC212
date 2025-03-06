#include <iostream>
int main(){
  int someInt = 6;
  int *someIntP = &someInt;

  double someDouble = 6.1;
  double *someDoubleP = &someDouble;

  std::cout << "Int value: " << someInt << " Int address: " << someIntP << '\n';
  std::cout << "Double value: " << someDouble << " Double address: " << someDoubleP << '\n';

}
