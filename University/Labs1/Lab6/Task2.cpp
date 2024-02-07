#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
#include <windows.h>

// В пункте 2 слова по регистру не различать, те слова «КоТ» и «кот» считать одинаковыми.
// Заданные буквы\слова\число N считывать и файла. Текст хранить в отдельном файле.
// Использовать имена: text.txt для хранения текста, input.txt для входных значений (N и т.д.), result.txt для вывода.
// Дублировать вывод в консоль, сделать вариацию кода, когда слово/буквы вводиться с клавиатуры.
// Наши гласные: а, е, ё, и, о, у, ъ, ы, ь, э, ю, я.
// Наши согласные: б, в, г, д, ж, з, й, к, л, м, н, п, р, с, т, ф, х, ц, ч, ш, щ.
// Во вспомогательных массивах/строках можно хранить только строчные символы.

// Вариант 7

// 2. Дан файл, содержащий русский текст. Найти в тексте N (N <= 10) самых длинных слов, содержащих какую-либо букву три раза.
//     Записать найденные слова в текстовый файл в порядке не убывания длины.
//     Все найденные слова должны быть разными.
//

const int count_valid_symbols = 44;
const char valid_symbols[count_valid_symbols] = {'а', 'е', 'ё', 'и', 'о', 'у', 'ъ', 'ы', 'ь', 'э', 'ю', 'я',
                                    'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м',
                                    'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ',
                                    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'};

namespace task2 {
    bool is_valid_symbol(char symbol) {
        for (int i = 0; i < count_valid_symbols; i++) {
            if (symbol == valid_symbols[i]) {
                return true;
            }
        }
        return false;
    }
}


int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::ifstream input_file("assets/input.txt");
    std::ifstream text_file("assets/text.txt");
    std::ofstream result_file("assets/result.txt");

    if (!input_file.is_open() || !text_file.is_open() || !result_file.is_open())
    {
        result_file << "Ошибка чтения файла." << std::endl;
        return 1;
    }
    short n;
    input_file >> n;
    input_file.close();

    std::string max_words[10] = {"", "", "", "", "", "", "", "", "", ""};
    std::string word;
    bool is_letter;
    bool word_in_words;
    bool is_valid_word;
    bool is_all_num;

    int count_symbols_in_word[count_valid_symbols];

    for (int i = 0; i < count_valid_symbols; i++) {
        count_symbols_in_word[i] = 0;
    }

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // while (std::cin >> word) {
    while (text_file >> word) {
        for (int i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }

        is_all_num = true;
        for (int i = 0; i < word.length(); i++) {
            if (!isdigit(word[i]) && word[i] != '-') {
                is_all_num = false;
                break;
            }
        }

        if (!is_all_num) {
            while (word.length() > 0 && (!task2::is_valid_symbol(word[word.length() - 1]) || isdigit(word[word.length() - 1]) || word[word.length() - 1] == '-')) {
                word.erase(word.length() - 1, 1);
            } 
        }
        else {
            while (word.length() > 0 && (!task2::is_valid_symbol(word[word.length() - 1]) || word[word.length() - 1] == '-')) {
                word.erase(word.length() - 1, 1);
            } 
        }

        

        while (word.length() > 0 && (!task2::is_valid_symbol(word[0]) || word[0] == '-')) {
            word.erase(0, 1);
        }


        is_valid_word = true;
        for (int i = 0; i < word.length(); i++) {
            if (!task2::is_valid_symbol(word[i])) {
                is_valid_word = false;
                break;
            }
        }
        if (is_valid_word){
            for (int i = 0; i < word.length(); i++) {
                for (int j = 0; j < count_valid_symbols; j++) {
                    if (word[i] == valid_symbols[j]) {
                        count_symbols_in_word[j]++;
                    }
                }
            }
            is_valid_word = false;
            for (int i = 0; i < count_valid_symbols; i++) {
                if (count_symbols_in_word[i] >= 3) {
                    is_valid_word = true;
                    break;
                }
            }
            if (is_valid_word) {
                word_in_words = false;
                for (int i = 0; i < n; i++) {
                    if (word.length() > max_words[i].length()) {
                        for (int j = 0; j < n; j++) {
                            if (word == max_words[j]) {
                                word_in_words = true;
                                break;
                            }
                        }
                        if (!word_in_words) {
                            for (int j = n - 1; j > i; j--) {
                                max_words[j] = max_words[j - 1];
                            }
                            max_words[i] = word;
                            break;
                        }
                        else {
                            word_in_words = false;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     if (max_words[i] != "") {
        //         std::cout << max_words[i] << std::endl;
        //     }
        // }
        for (int i = 0; i < count_valid_symbols; i++) {
            count_symbols_in_word[i] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        if (max_words[i] != "") {
            result_file << max_words[i] << std::endl;
            std::cout << max_words[i] << std::endl;
        }
    }

    text_file.close();
    result_file.close();
    return 0;
}