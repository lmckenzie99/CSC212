// e number algorithm
// euler(n) to calculate approx of e
//
// euler(n){
// e = 1
// i = 0
// for i = 1 to n{
// e = e +  1/fact(i)
// } return e
// }

#include <iostream>
double euler1(int n) {
  double e = 1.0;
  for (int i = 1; i <= n; i++) {
    double fact = 1.0;
    for (int j = 1; j <= i; j++) {
      fact *= j;
    }
    e += (1.0 / fact);
  }
  return e;
}
double euler2(int n){
  double e = 1.0;
  double fact = 1.0;
  for(int i = 1; i <=n;i++){
    fact*=i;
    e+= (1.0/fact);
  }
  return e;
}
int main() {
  int n;
  std::cin >> n;
  std::cout << '\n';
  std::cout << euler1(n) << " " << euler2(n);

  return 0;
} 
