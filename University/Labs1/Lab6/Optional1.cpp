#include <fstream>
#include <string>
#include <iostream>

// Файл (cod.txt) содержит закодированные слова вида «2н 3р 1а» в расшифрованном виде это «нн ррр а».
// Написать программу, которая может кодировать/декодировать такие файлы. Результат выполнения должен быть записан в этом же файле.

int main() {

    setlocale(LC_ALL, "Russian");

    std::ifstream input_file("assets/cod.txt");

    if (!input_file.is_open()) {
        std::cout << "Ошибка чтения файла." << '\n';
        return 1;
    }

    std::string input_line;
    getline(input_file, input_line);

    input_file.close();

    int action;

    std::cout << "Строка в файле: " << input_line << '\n';

    std::cout << "Выберите действие: 0 - декодировать, 1 - кодировать: ";
    std::cin >> action;

    std::string result_line;

    switch (action) {
        case 0: {
            int multipler = 0;
            for (int i = 0; i < input_line.length(); i++) {
                if (isalpha(input_line[i]) || (input_line[i] >= 'А' && input_line[i] <= 'я') || input_line[i] == 'ё' || input_line[i] == 'Ё') {
                    for (int j = 0; j < multipler; j++) {
                        result_line += input_line[i];
                    }
                    result_line += ' ';
                    multipler = 0;
                } 
                else if (isdigit(input_line[i])) {
                    multipler = multipler * 10 + abs(input_line[i] - '0');
                }
                else {
                    multipler = 0;
                }
            }
            break;
        }        
        case 1:
            for (int i = 0; i < input_line.length(); i++) {
                if (isalpha(input_line[i]) || (input_line[i] >= 'А' && input_line[i] <= 'я') || input_line[i] == 'ё' || input_line[i] == 'Ё') {
                    int counter = 1;
                    while (input_line[i] == input_line[i + 1]) {
                        counter++;
                        i++;
                    }
                    result_line += std::to_string(counter) + input_line[i] + ' ';
                }
            }
            break;
        default:
            std::cout << "Неверный ввод." << '\n';
            return 1;
    }

    std::ofstream result_file("assets/cod.txt");

     if (!result_file.is_open()) {
        std::cout << "Ошибка чтения файла." << '\n';
        return 1;
    }

    result_file << result_line;
    
    result_file.close();

    return 0;
}