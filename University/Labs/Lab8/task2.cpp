// Пункт 2
// Создать матрицу A [M x N] и заполнить её по правилу Aij = 10(i+1) + (j+1). Посчитать норму.
// Транспонировать матрицу и вывести на экран.
// Сравнить нормы.
// Использовать в программе только: N, M, A[M][N], B[?][?], defA, defB, temp
// Методы new, delete, и др..
// Начальные размеры и новые числа вводить с клавиатуры.

#include <iostream>

double norm(int **MATRIX, int M, int N){
    double norm = 0;
    for (int i = 0; i < M; i++){
        double sum = 0;
        for (int j = 0; j < N; j++){
            sum += MATRIX[i][j];
        }
        if (sum > norm){
            norm = sum;
        }
    }
    return norm;
}

int main(){
    int M, N;
    std::cout << "Enter M: ";
    std::cin >> M;
    std::cout << "Enter N: ";
    std::cin >> N;
    int **A = new int*[M];
    for (int i = 0; i < M; i++){
        A[i] = new int[N];
    }
    int **B = new int*[N];
    for (int i = 0; i < N; i++){
        B[i] = new int[M];
    }
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = 10 * (i + 1) + (j + 1) ;
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            B[i][j] = A[j][i];
        }
    }
    std::cout << "A: " << std::endl;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "B: " << std::endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Norm A: " << norm(A, M, N) << std::endl;
    std::cout << "Norm B: " << norm(B, N, M) << std::endl;
    std::cout << "Norm A - Norm B: " << norm(A, M, N) - norm(B, N, M) << std::endl;
    for (int i = 0; i < M; i++){
        delete[] A[i];
    }
    for (int i = 0; i < N; i++){
        delete[] B[i];
    }
}