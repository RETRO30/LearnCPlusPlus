#include <iostream>
#include <iomanip>
#define N_Max 10

int main() {
    // Массивы

    const int N = 10;

    int mas[N] = {1, 3, 5, 6, 9, 4, 30, 20, 2};

    int n = 9;
    // Сортировка обменами

    for (int i=0; i< n-1; i++ ){
        for (int j=i+1; j<n; j++){
            if (mas[i]%10 < mas[j]%10){
                continue;
            }
            else {
                std::swap(mas[i], mas[j]);
            }
        }
    }

    for (int i=0; i < n; i++){
        std::cout << mas[i] << std::endl;
    }

    // std::cout << sizeof(mas)/sizeof(mas[0]) << std::endl;
    // std::cout << std::size(mas) << std::endl;
    


    return 0;
}