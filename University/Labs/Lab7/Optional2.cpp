#include <iostream>

#include <iostream>

void simple_divs(int num, int divisor) {
    if (num <= 1) {
        return;
    }
    
    if (num % divisor == 0) {
        std::cout << divisor << " ";
        simple_divs(num / divisor, divisor);
    } else {
        simple_divs(num, divisor + 1);
    }
}

int main() {
    int num;
    std::cin >> num;

    std::cout << "result: ";
    simple_divs(num, 2);
    
    return 0;
}