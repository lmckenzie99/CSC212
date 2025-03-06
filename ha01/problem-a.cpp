#include <iostream>
int main(){
    std::string someWord;
    int loop = 0;
    std::cin >> someWord;
    
    while(loop < 3){
        std::cout << someWord << " ";
        loop++;
    }
}
