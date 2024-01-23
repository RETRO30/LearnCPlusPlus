#include <iostream>
#include <fstream>
#include <string.h>


int main(){
    // Работа с файлами

    const int N = 100;
    const int M = 100;


    // std::ifstream in("input.txt");

    // if (!in.is_open())
    // {
    //     std::cout << "Error open file";
    //     return -1;
    // }

    int n, m;
    int matrix[N][M];
    std::cin >> m >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            std::cin >> matrix[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;

/*
    // Строки
    char str[10] = "Hello";

    // Длина строки

    std::cout << strlen(str) << std::endl;

    // copy
    char str_copy[10];
    strcpy(str_copy, str);

    // сложение строк
    char str_concat[20];
    strcpy(str_concat, str);
    strcat(str_concat, str_copy);
*/
    return 0;
}