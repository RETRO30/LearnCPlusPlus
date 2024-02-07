// Задать целые значения N и M рандомно из диапазона [3;3+K], где K – номер варианта. И определить нецелочисленную матрицу А[N][M].
// Все значения матрицы кроме главного и побочного пояса* заполнить числами из диапазона (-0,1;0,1) \ {0} ** с 3-мя знаками после запятой.
// В ячейках главного пояса указать свой вариант, в ячейках побочного – минус вариант, в пересечении нули.
// Для заполнения использовать одну функцию,
//  которая возвращает после заполнения строку вида «Аа» где символ соответствует букве из алфавита с номером К+5 (Например для варианта 1 это строка «Ее»).
// Добавить в программу процедуру вывода матрицы на экран. Полученную строку записать в файл out.txt

// Алфавит: АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

std::string fillMatrix(double **MATRIX, int N, int M){
        int mainZoneStart;
        int mainZoneEnd;
        int sideZoneStart;
        int sideZoneEnd;

        if (M % 2 == 0) {
                mainZoneStart = M / 2 - 1;
                mainZoneEnd = M / 2;
        }
        else {
                mainZoneStart = M / 2;
                mainZoneEnd = M / 2;
        }
        if (N % 2 == 0) {
                sideZoneStart = N / 2 - 1;
                sideZoneEnd = N / 2;
        }
        else {
                sideZoneStart = N / 2;
                sideZoneEnd = N / 2;
        }
        std::cout << "mainZoneStart = " << mainZoneStart << std::endl;
        std::cout << "mainZoneEnd = " << mainZoneEnd << std::endl;
        std::cout << "sideZoneStart = " << sideZoneStart << std::endl;
        std::cout << "sideZoneEnd = " << sideZoneEnd << std::endl;
        int sign;
        for (int y = 0; y < M; y++){
                for (int x = 0; x < N; x++){
                        if (y >= mainZoneStart && y <= mainZoneEnd && x >= sideZoneStart && x <= sideZoneEnd) {
                                MATRIX[y][x] = 0;
                        }
                        else if (y >= mainZoneStart && y <= mainZoneEnd) {
                                MATRIX[y][x] = 7;
                        }
                        else if (x >= sideZoneStart && x <= sideZoneEnd) {
                                MATRIX[y][x] = -7;
                        }
                        else {
                                sign = rand() % 2;
                                MATRIX[y][x] = ((double)(rand() % 99 + 1) / 1000) * (sign == 1 ? 1 : -1);       
                        }
                }
        }
        std::string result = "Кк";
        return result;
}

void printMatrix(double **MATRIX, int N, int M){
        for (int y = 0; y < M; y++){
                for (int x = 0; x < N; x++){
                        std::cout << MATRIX[y][x] << " ";
                }
                std::cout << std::endl;
        }
}


int main() {
        std::setlocale(LC_ALL, "Russian");

        srand(time(0));

        int K = 7;
        int N = (rand() % (K)) + 3;
        int M = (rand() % (K)) + 3;
        std::cout << "N = " << N << std::endl;
        std::cout << "M = " << M << std::endl;
        double **MATRIX = new double*[M];
        for (int i = 0; i < M; i++){
            MATRIX[i] = new double[N];
        }

        std::string result = fillMatrix(MATRIX, N, M);

        printMatrix(MATRIX, N, M);

        std::cout << result << std::endl;


        std::ofstream out("out.txt");
        if (!out.is_open()){
                std::cout << "Error: file not open" << std::endl;
        }
        else {
                out << result;
                out.close();
        }

        
        for (int i = 0; i < N; i++){
            delete[] MATRIX[i];
        }
        delete[] MATRIX;
        return 0;
}