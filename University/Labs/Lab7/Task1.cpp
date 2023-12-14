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

    bool readMatrix() {
        std::ifstream file("assets/input.txt");
        if (!file.is_open()) {
            std::cout << "File not found" << std::endl;
            return false;
        }
        file >> n;
        std::cout << n << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
        return true;
    }

    bool writeMatrix() {
        std::ofstream file("assets/output.txt");
        if (!file.is_open()) {
            std::cout << "File couldn't open" << std::endl;
            return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file << matrix[i][j] << " ";
            }
            file << std::endl;
        }
        file.close();
        return true;
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
        value = abs(value);
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
    bool all_correct = false;
    all_correct = task1::readMatrix();
    if (!all_correct) {
        std::cout << "Error while reading file";
        return 0;
    }
    task1::editMatrix();
    
    all_correct = task1::writeMatrix();

    if (!all_correct) {
        std::cout << "Error while writing file";
    }
    return 0;
}




