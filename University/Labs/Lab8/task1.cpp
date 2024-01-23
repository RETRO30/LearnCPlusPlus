// Пункт 1

// Создать массив {A1, A2, …, AK} и заполнить его по правилу Ai = i.
// Запросить пользователя значение S (целое, ≠0) и изменить размеры по правилу K = K+S.
// Случай S < 0: вывести на экран сообщение о срезе и показать результат.
// Случай S > 0: согласно варианту.
// Использовать в программе только: K, A[K], S, tempб, flag, dop1?, dop2? + итераторы циклов
// Методы calloc, malloc, realloc, free, и др..





#include <iostream>
#include <math.h>

// Вариант 7
// Если среди новых чисел не встретилась 1, заменить последнее на 999.
int task1(){
    int K;
    std::cout << "Enter K: ";
    std::cin >> K;
    if (K < 0) {
        std::cout << "Error: K < 0" << std::endl; 
        system("pause");
        return 0;
    }
    int S;
    int *A = (int*)malloc(K*sizeof(int));
    for (int i = 0; i < K; i++){
        A[i] = i+1;
    }
    std::cout << "Enter S: ";
    std::cin >> S;
    if (S < 0 && K <= abs(S)) {
        std::cout << "Error: K + S < 0" << std::endl; 
        free(A);
        system("pause");
        return 0;
    }

    K += S;
    A = (int*)realloc(A, K*sizeof(int));

    if (S < 0){
        std::cout << "Slice: ";
        for (int i = 0; i < K; i++){
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (S > 0){
        std::cout << "Enter " << S << " numbers: ";
        for (int i = K-S; i < K; i++){
            std::cin >> A[i];
        }
        bool flag = false;
        for (int i = K-S; i < K; i++){
            if (A[i] == 1){
                flag = true;
                break;
            }
        }
        if (!flag) {
            A[K-1] = 999;
        }
        for (int i = 0; i < K; i++){
            std::cout << A[i] << " ";
        }
    }
    std::cout << std::endl;
    free(A);
    system("pause");
    return 0;
}

//Вариант 6
// Если среди новых чисел есть отрицательное, прибавить ко всем новым числам 5.
int dop1(){
    int K = 10;
    int S;
    int *A = (int*)calloc(K, sizeof(int));
    for (int i = 0; i < K; i++){
        A[i] = i;
    }
    std::cout << "Enter S: ";
    std::cin >> S;
    if (S < 0 && K <= abs(S)) {
        std::cout << "Error: K + S < 0" << std::endl; 
        free(A);
        system("pause");
        return 0;
    }

    K += S;
    A = (int*)realloc(A, K*sizeof(int));

    if (S < 0){
        std::cout << "Slice: ";
        for (int i = 0; i < K; i++){
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (S > 0){
        std::cout << "Enter " << S << " numbers: ";
        for (int i = K-S; i < K; i++){
            std::cin >> A[i];
        }
        bool flag = false;
        for (int i = K-S; i < K; i++){
            if (A[i] < 0){
                flag = true;
                break;
            }
        }
        if (!flag) {
            for (int i = K-S; i < K; i++){
                A[i] += 5;
            }
        }
        for (int i = 0; i < K; i++){
            std::cout << A[i] << " ";
        }
    }
    std::cout << std::endl;
    free(A);
    system("pause");
    return 0;
}


// Вариант 1
// Если среди новых чисел есть 0, сделать все четные значения нулями.
int dop2(){
    int K = 10;
    int S;
    int *A = (int*)malloc(K*sizeof(int));
    for (int i = 0; i < K; i++){
        A[i] = i;
    }
    std::cout << "Enter S: ";
    std::cin >> S;
    if (S < 0 && K <= abs(S)) {
        std::cout << "Error: K + S < 0" << std::endl; 
        free(A);
        system("pause");
        return 0;
    }

    K += S;
    A = (int*)realloc(A, K*sizeof(int));

    if (S < 0){
        std::cout << "Slice: ";
        for (int i = 0; i < K; i++){
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (S > 0){
        std::cout << "Enter " << S << " numbers: ";
        for (int i = K-S; i < K; i++){
            std::cin >> A[i];
        }
        bool flag = false;
        for (int i = K-S; i < K; i++){
            if (A[i] == 0){
                flag = true;
                break;
            }
        }
        if (flag) {
            for (int i = K-S; i < K; i++){
                if (A[i] % 2 == 0){
                    A[i] = 0;
                }
            }
        }
        for (int i = 0; i < K; i++){
            std::cout << A[i] << " ";
        }
    }
    std::cout << std::endl;
    free(A);
    system("pause");
    return 0;
}

int main(){
    task1();
    // dop1();
    // dop2();
   return 0;
}