#include <iostream>
int foo(int x, int *y){
  x = x + 10;
  *y = x *2;
  return x;
}

int *bar(int x){
  int y = 50 + x;
  return &y;
}

int main(){
  int x = 1, y= 0;
  x = foo(x, &y);
//std::cout << x << " " << y;
int *z = bar(y);
  x = *z;
  std::cout << x;



}
