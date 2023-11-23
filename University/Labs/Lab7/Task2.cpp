// Вариант 7

// Реализовать перегрузку функции. Для натурального числа возвращать ближайший квадрат. Для дробного ­– разность целой и дробной части.

#include <iostream>

namespace task2 {

    int overfunc(int value) {
        int maxNearSquare = 0;
        int minNearSquare = 0;
        for (int i = 0; i < value; i++) {
            if (i * i >= value) {
                maxNearSquare = i * i;
                break;
            }
        }
        for (int i = value; i > 0; i--) {
            if (i * i < value) {
                minNearSquare = i * i;
                break;
            }
        }
        return (maxNearSquare - value) < (value - minNearSquare) ? maxNearSquare : minNearSquare;
    }

    double overfunc(double value) {
        return (int)value - value;
    }

}

int main() {
    std::cout << task2::overfunc(144) << std::endl;
    std::cout << task2::overfunc(5.5) << std::endl;
    return 0;
}