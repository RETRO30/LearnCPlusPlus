#include <iostream>
#include <math.h>
#define INT_MIN (-2147483647 - 1)

// Вариант 7

// Дана последовательность натуральных чисел {A1, A2, …, AK}. Упорядочить её по возрастанию, если первое число больше последнего.
// Ввести размеры и заполнить матрицу T [M x N] целыми числами. Найти столбец с максимальной суммой чисел и обнулить его.
// Доп.

// Упорядочить пункт 1 по возрастанию суммы цифр.
// Пункт 1 с условием: Если есть три разных числа с одинаковой суммой цифр.
// Проверить является ли введенное число простым. Если нет – вывести все делители.

int main(){
    // Пункт 1.
    const int N = 20;
    const int N_matrix = 10;
    int array[N], sorted_array[N], sorted_array_[N];
    
    
    // int n;
    // std::cout << "Enter n: ";
    // std::cin >> n;

    // std::cout << "Enter massive:\n";

    // for (int i = 0; i<n; i++){
    //     std::cin >> array[i];
    //     sorted_array[i] = array[i];
    //     sorted_array_[i] = array[i];

    // }

    // if (array[0] > array[n-1]){
    //     int tmp = 0;
    //     for (int i = 0; i < n - 1; i++){
    //         for (int j = 0; j < n - i - 1; j++){
    //             if (sorted_array[j] > sorted_array[j+1]){
    //                 tmp = sorted_array[j];
    //                 sorted_array[j] = sorted_array[j+1];
    //                 sorted_array[j+1] = tmp;
    //             }
    //         }
    //     }
    // }
    // // Вывод
    // std::cout << "\nMassive: ";
    // std::cout << "[";
    // for (int i = 0; i < n-1; i++){
    //     std::cout << array[i] << ", ";
    // }
    // std::cout << array[n-1] << "]\n";
    // std::cout << "Sorted massive: ";
    // std::cout << "[";
    // for (int i = 0; i < n-1; i++){
    //     std::cout << sorted_array[i] << ", ";
    // }
    // std::cout << sorted_array[n-1] << "]\n";

    // // Доп 1.
    // if (array[0] < array[n-1]) {
    //     int sum_digit_massive[N];
    //     int tmp = 0;
    //     int sum_digit = 0;
    //     for (int i = 0; i < n; i++){
    //         tmp = sorted_array[i];
    //         while (tmp){
    //             sum_digit += abs(tmp % 10);
    //             tmp /= 10;
    //         }
    //         sum_digit_massive[i] = sum_digit;
    //         sum_digit = 0;
    //     }
    //     for (int i = 0; i < n - 1; i++){
    //         for (int j = 0; j < n - i - 1; j++){
    //             if (sum_digit_massive[j] > sum_digit_massive[j+1]){
    //                 tmp = sorted_array[j];
    //                 sorted_array[j] = sorted_array[j+1];
    //                 sorted_array[j+1] = tmp;
    //                 tmp = sum_digit_massive[j];
    //                 sum_digit_massive[j] = sum_digit_massive[j+1];
    //                 sum_digit_massive[j+1] = tmp;
    //             }
    //         }
    //     }
    // }
    // // Вывод
    // std::cout << "Sorted massive (optional 1.): ";
    // std::cout << "[";
    // for (int i = 0; i < n-1; i++){
    //     std::cout << sorted_array[i] << ", ";
    // }
    // std::cout << sorted_array[n-1] << "]\n";

    // // Доп 2.
    // if (array[0] < array[n-1]) {
    //     int sum_digit_massive[N];
    //     int tmp = 0;
    //     int sum_digit = 0;
    //     for (int i = 0; i < n; i++){
    //         tmp = sorted_array_[i];
    //         while (tmp){
    //             sum_digit += tmp % 10;
    //             tmp /= 10;
    //         }
    //         sum_digit_massive[i] = sum_digit;
    //         sum_digit = 0;
    //     }

    //     int sum_digits_table[3][N];
    //     int len_sum_digits_tabel = 0;
    //     bool flag = false;
    //     for (int i = 0; i < n; i++){
    //         flag = false;
    //         for (int j = 0; j < len_sum_digits_tabel; j++){
    //             if (sum_digit_massive[i] == sum_digits_table[0][j]){
    //                 flag = true;
    //                 if (sorted_array_[i] != sum_digits_table[2][j]){
    //                     sum_digits_table[1][j]++;
    //                     sum_digits_table[2][j] = sorted_array_[i];
    //                 break;
    //                 }
    //             }
    //         }
    //         if (!flag){
    //             len_sum_digits_tabel++;
    //             sum_digits_table[0][len_sum_digits_tabel] = sum_digit_massive[i];
    //             sum_digits_table[1][len_sum_digits_tabel] = 1;
    //             sum_digits_table[2][len_sum_digits_tabel] = sorted_array_[i];
    //         }
    //     }
    //     flag = false;
    //     for (int i=0; i<len_sum_digits_tabel; i++) {
    //         if (sum_digits_table[1][i] >= 3){
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if (flag){
    //         for (int i = 0; i < n - 1; i++){
    //             for (int j = 0; j < n - i - 1; j++){
    //                 if (sorted_array_[j] > sorted_array_[j+1]){
    //                     tmp = sorted_array_[j];
    //                     sorted_array_[j] = sorted_array_[j+1];
    //                     sorted_array_[j+1] = tmp;
    //                 }
    //             }    
    //         }
    //     }
    // }
    // // Вывод
    // std::cout << "Sorted massive (optional 2.): ";
    // std::cout << "[";
    // for (int i = 0; i < n-1; i++){
    //     std::cout << sorted_array[i] << ", ";
    // }
    // std::cout << sorted_array[n-1] << "]\n";

    // // Пункт 2.
    // short matrix[N_matrix][N_matrix];
    // short nn, mm;
    // std::cout << "\nEnter n and m: ";     
    // std::cin >> nn >> mm;
    // std::cout << "\nEnter matrix:\n";
    // for (int i = 0; i < nn; i++){
    //     for (int j = 0; j < mm; j++){
    //         std::cin >> matrix[i][j]; 
    //     }
    // }

    // int column_sum = 0, max_column_sum = INT_MIN;
    // short max_column_index = 0;
    // for (int j = 0; j < mm; j++) {
    //     for (int i = 0; i < nn; i++){
    //         column_sum += matrix[i][j];
    //     }
    //     if (column_sum > max_column_sum){
    //         max_column_sum = column_sum;
    //         max_column_index = j;
    //         column_sum = 0;
    //     }
    // }
    // for (int i = 0; i < nn; i++) {
    //     matrix[i][max_column_index] = 0;
    // }

    // std::cout << "\nResult matrix: \n";

    // for (int i = 0; i < nn; i++){
    //     for (int j = 0; j < mm; j++){
    //         std::cout << matrix[i][j] << ' '; 
    //     }
    //     std::cout << '\n';
    // }

    // Доп 3.
    int num;
    std::cout << "\nEnter num: ";
    std::cin >> num;

    int dividers[N];
    int len_dividers = 0;
    for (int i = 1; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            dividers[len_dividers] = i;
            dividers[len_dividers+1] = num/i;
            len_dividers += 2;
        }
    }
    if (len_dividers == 2 && num > 1){
        std::cout << "\nIs prime.";
    }
    else {
        std::cout << "\nIs not prime: ";
        for (int i = 0; i < len_dividers; i++){
            std::cout << dividers[i] << " ";
        }
    }
}
