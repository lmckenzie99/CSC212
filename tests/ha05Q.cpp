#include <iostream>
#include <queue>
int find_max(std::queue<int>& Q){
int tempMax = Q.front();
    for(int i = 0; i < Q.size(); i++){
    int val = Q.front();
    Q.pop();
    if(tempMax < val){tempMax = val;}
    Q.push(val);
  }
  return tempMax;
}

int main(){
  std::queue<int> Q;
  Q.push(3);
  Q.push(1);
  Q.push(7);
  Q.push(2);
  std::cout << find_max(Q);
}
