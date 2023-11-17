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

int main()
{
    std::setlocale(LC_ALL, "Russian");

    const int COUNT_LETTERS = 33;
    const char alphabet[COUNT_LETTERS] = {'а', 'е', 'ё', 'и', 'о', 'у', 'ъ', 'ы', 'ь', 'э', 'ю', 'я',
                                          'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м',
                                          'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ'};
    char reg_delta = 'А' - 'а';

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
    std::string word = "";
    bool is_letter;
    bool word_in_words;
    bool flag;
    char symbol;

    int count_letters_in_word[COUNT_LETTERS];

    for (int i = 0; i < COUNT_LETTERS; i++)
    {
        count_letters_in_word[i] = 0;
    }

    int i = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // для консоли
    // while (symbol != '\n')
    // {
    //     symbol = std::cin.get();
    // для файла
    while (!text_file.eof())
    {
        text_file.get(symbol);
        is_letter = false;
        for (int j = 0; j < COUNT_LETTERS; j++)
        {
            if (symbol == alphabet[j] || symbol == (alphabet[j] + reg_delta) || symbol == 'Ё')
            {
                is_letter = true;
                break;
            }
        }
        if (is_letter)
        {
            while (is_letter)
            {
                is_letter = false;
                for (int j = 0; j < COUNT_LETTERS; j++)
                {
                    if (symbol == alphabet[j] || symbol == (alphabet[j] + reg_delta) || symbol == 'Ё')
                    {
                        word += symbol;
                        count_letters_in_word[j]++;
                        // для консоли
                        // symbol = std::cin.get();
                        // для файла
                        text_file.get(symbol);
                        is_letter = true;
                        break;
                    }
                }
            }
            flag = false;
            for (int j = 0; j < COUNT_LETTERS; j++)
            {
                if (count_letters_in_word[j] >= 3)
                {   
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                word_in_words = false;
                for (int j = 0; j < n; j++)
                {
                    if (word == max_words[j])
                    {
                        word_in_words = true;
                        break;
                    }
                }
                if (!word_in_words)
                {
                    for (int j = n; j > 0; j--)
                    {
                        if (word.length() > max_words[j].length())
                        {
                            for (int k = 0; k < j; k++)
                            {
                                max_words[k] = max_words[k + 1];
                            }
                            max_words[j] = word;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < COUNT_LETTERS; i++)
            {
                count_letters_in_word[i] = 0;
            }
            word = "";
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