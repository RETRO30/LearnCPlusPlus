// Шаталов Вариант 7
#include <iostream>
#include <iomanip>

int main(){
    // Блок 1.
    short int short_integer = 10; // -2^15 .. 2^15-1
    unsigned short int unsigned_short_integer = 10; // 0..2^16-1
    int integer = -10; // -2^31 .. 2^31-1
    unsigned int unsigned_integer = 10; //  0 .. 2^32-1
    long long large_integer = 56165489; // -2^63 .. 2^63-1
    unsigned long long very_large_integer = 56165489000; // 0 .. 2^64-1
    float with_point = 10.518F; // 3,4E +/- 38
    double with_point_but_large = 10.5165484; // 1,7E +/- 308



    // Блок 2.
    unsigned int S = 0; // Площадь, целое, неотрицательное
    unsigned int h = 0; // Высота, целое, неотрицательное
    std::cout << "Enter area num: ";
    std::cin >> S;
    std::cout << "Enter height: ";
    std::cin >> h;
    long double result = 0.0; // Объём, дробное, максимальный int * максимальный int ->
    //  -> понадобится больше памяти
    result = (S*h)/3;
    std::cout << "Result: " << result;  // Вывод результата
}