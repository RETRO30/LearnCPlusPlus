#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>


// Вариант 7
// Дана последовательность вещественных чисел {A1, A2, …, AN}. Найти произведение всех чисел из интервала [1; 12.45], наименьшее из таких чисел и его номер в последовательности.
// Дано целое число X <10^9. Найти сумму наименьшей и наибольшей цифр.


// Доп.
// Для последовательности первого пункта посчитать значение выражения S(AI), в которое суммируются все числа на нечетных позициях последовательности и вычитаются числа, стоящие на четных позициях.
// Пред. пункт + не учитывать все нули, которые вводит пользователь.
// Для пункта 2 вывести цифру, которая встречается больше всего раз. (Массивы не использовать)

int main(){
    // Пункт 1
    std::cout << "Task 1. Enter n and array after:\n";
    int n;
    std::cin >> n;

    double x;
    double result = 1;
    double min = 14;
    int min_i = 0;
    bool flag = false;
    double even_sum = 0, odd_sum = 0, even_sum_ = 0, odd_sum_ = 0;
    int fault = 0;

    for (int i = 0; i < n; i++){
        std::cin >> x;
        if (1.0 <= x && x <= 12.45){
            
            if (!flag) {
                flag = true;
            }

            result *= x;

            if (min > x){
                min = x;
                min_i = i;
            }
        }

        // Доп 1
        if (i & 1){
            odd_sum += x;
        }
        else {
            even_sum += x;
        }
        // Доп 2
        if (x == 0.0) {
            fault++;
            continue;
        }
        if ((i - fault) & 1){
            odd_sum_ += x;
        }
        else {
            even_sum_ += x;
        }


    }
    if (flag){
        std::cout << "Result task 1: " << result << " " << min << " " << min_i << " " << "\n";
        std::cout << "Result optional task 1: " << even_sum - odd_sum << "\n";
        std::cout << "Result optional task 2: " << even_sum_ - odd_sum_ << "\n";
    }
    else {
        std::cout << 0 << "\n";
    }   

    //  Пункт 2
    long long int input_number;
    char min_numeral = 9, max_numeral = 0, maxcount_numeral;
    std::cout << "Task 2. Enter num: ";
    std::cin >> input_number;
    long long int number = input_number, number_for_count = input_number;
    char numeral, inner_numeral;
    char counter = 0, maxcount = 0;
    while (number) {
        numeral = number % 10;
        if (numeral < min_numeral) {
            min_numeral = numeral;
        }
        if (numeral > max_numeral) {
            max_numeral = numeral;
        }
        number /= 10;
        // Доп 3
        while (number_for_count) {
            inner_numeral = number_for_count % 10;
            if (inner_numeral == numeral) {
                counter++;
            }
            number_for_count /= 10;
        }
          
        if (counter > maxcount) {
            maxcount_numeral = numeral;
        }
        number_for_count = input_number;
    }

    std::cout << "Result task 2: " << (short) max_numeral + (short) min_numeral << "\n";
    std::cout << "Result optional task 3: " << (short) maxcount_numeral << "\n";

    return 0;
}