// Шаталов 4 вариант - 1 задача
#include <iostream>
#include <iomanip>

int main(){
    double R = 0.0;
    std::cin >> R;
    long double result = 3.141592653 * R * R;
    std::cout << std::fixed << std::setprecision(9) << result;
}