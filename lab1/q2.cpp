#include <iostream>
int main(){
  char hello[] = "hello";
  int nums[] = {1,2,3,4,5};

  char *chPtr = hello;
  int *numPtr = nums;

  std::cout << "Array of char (address/value): " << '\n';
  while(*chPtr != '\0'){
    std::cout << &chPtr << " " << *chPtr << '\n';
    chPtr++;
  }
  std::cout << '\n' << "Array of nums (address/value): " << '\n';
  while(*numPtr < 6){
    std::cout << numPtr << " " << *numPtr << '\n';
    numPtr++;
  } 
}
