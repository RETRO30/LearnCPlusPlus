// Для каждого варианта требуется написать соответствующие функции:

// Чтение матрицы из файла.
// Функции обработки (может быть несколько).
// Запись результата во внешний файл.
// Матрицы во всех вариантах квадратные А [N x N] с целочисленными значениями.
// Размер матрицы и значения храниться файле, N <12 на первой строке, далее через пробел.
// В программе обязательно должна присутствовать хотя бы одна процедура (например, вывод матрицы на экран).
// В этой работе, для взаимодействия с матрицей в функциях, хранить её как глобальную переменную.

// Вариант 7

// Если все элементы побочной диагонали матрицы являются наибольшими элементами своих строк, заменить элементы матрицы, содержащие цифру 0, на 0.

#include <iostream>
#include <fstream>

const int N = 12;
int matrix[N][N];
int n;

namespace task1 {

    void readMatrix() {
        std::ifstream file("assets/input.txt");
        file >> n;
        std::cout << n << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> matrix[i][j];
            }
        }
    }

    void writeMatrix() {
        std::ofstream file("assets/output.txt");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file << matrix[i][j] << " ";
            }
            file << std::endl;
        }
    }

    bool isMaxInRow(int value, int i) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > value) {
                return false;
            }
        }
        return true;
    }

    bool zeroInNum(int value) {
        while (value > 0) {
            if (value % 10 == 0) {
                return true;
            }
            value /= 10;
        }
        return false;
    }

    void editMatrix() {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (isMaxInRow(matrix[i][n - i - 1], i)) {
                flag++;
            }
        }
        if (flag == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (zeroInNum(matrix[i][j])) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }

}

int main() {
    task1::readMatrix();
    task1::editMatrix();
    task1::writeMatrix();
    return 0;
}




