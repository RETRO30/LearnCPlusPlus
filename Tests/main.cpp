#include <iostream>
#include <cmath>
#include <string>

int main()
{
    // int MATRIX[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // double pi = 3.14;
    // char c = 0b00000001;
    // std::cout << pow(2, 3) << std::endl;
    // std::cout << sqrt(4) << std::endl;
    // std::cout << acos(-1) << std::endl;
    // for (int i = 2; i >= 0; i--){
    //     std::cout << MATRIX[i][2-i] << " ";
    // }
    setlocale(LC_ALL, "Russian");
    int massive[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5-i-1; j++){
            if (massive[j] < massive[j+1]){
                int temp = massive[j];
                massive[j] = massive[j+1];
                massive[j+1] = temp;
            }
        }
    }
    char c = 'а';
    char c = 'А';
    char c = 'A'
    for (int i = 0; i < 5; i++){
        std::cout << massive[i] << " ";
    }
}