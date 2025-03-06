
#include <iomanip>
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
int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <n> <alg>\n";
    return 1;
  }
 
}
