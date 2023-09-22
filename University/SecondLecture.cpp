#include <iostream>

int main() {
    // Логические операции
    // ||, &&, !, ==, <, >, <=, >=, !=
    int a = 10;
    // Условные конструкции
    // if..else
    if (a < 100 && a > 0) {
        std::cout << "Consists" << std::endl;
    }
    else
    {
    std::cout << "Consists" << std::endl;
    }
    auto x = 10;
    // Тернарный оператор
    int g = 0;
    std::cout << (g == 0 ? "Zero": "Not zero") << std::endl;

    int x = 123456;
    int sum = 0;

    while (x){
        sum += x % 10;
        x /= 10;
    }
    std::cout << sum << std::endl;

    

    return 0;
}