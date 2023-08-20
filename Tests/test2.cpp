#include <iostream>

int power(int x, unsigned p) {
    int answer;
    for (answer = 1; p > 0; p--){answer *= x;}
    return answer;
}

int main(){
    #define MAX(x, y, r)  ((x > y) ? ((x > r) ? x : r) : ((y > r) ? y : r))
    std::cout << MAX(50, 20, 0);
}