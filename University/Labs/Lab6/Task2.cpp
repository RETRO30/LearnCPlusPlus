#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
#include <windows.h>

// � ������ 2 ����� �� �������� �� ���������, �� ����� ���һ � ���� ������� �����������.
// �������� �����\�����\����� N ��������� � �����. ����� ������� � ��������� �����.
// ������������ �����: text.txt ��� �������� ������, input.txt ��� ������� �������� (N � �.�.), result.txt ��� ������.
// ����������� ����� � �������, ������� �������� ����, ����� �����/����� ��������� � ����������.
// ���� �������: �, �, �, �, �, �, �, �, �, �, �, �.
// ���� ���������: �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �.
// �� ��������������� ��������/������� ����� ������� ������ �������� �������.

// ������� 7

// 2. ��� ����, ���������� ������� �����. ����� � ������ N (N <= 10) ����� ������� ����, ���������� �����-���� ����� ��� ����.
//     �������� ��������� ����� � ��������� ���� � ������� �� �������� �����.
//     ��� ��������� ����� ������ ���� �������.
//

int main()
{
    std::setlocale(LC_ALL, "Russian");

    const int COUNT_LETTERS = 33;
    const char alphabet[COUNT_LETTERS] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                                          '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                                          '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    char reg_delta = '�' - '�';

    std::ifstream input_file("assets/input.txt");
    std::ifstream text_file("assets/text.txt");
    std::ofstream result_file("assets/result.txt");

    if (!input_file.is_open() || !text_file.is_open() || !result_file.is_open())
    {
        result_file << "������ ������ �����." << std::endl;
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
    // ��� �������
    // while (symbol != '\n')
    // {
    //     symbol = std::cin.get();
    // ��� �����
    while (!text_file.eof())
    {
        text_file.get(symbol);
        is_letter = false;
        for (int j = 0; j < COUNT_LETTERS; j++)
        {
            if (symbol == alphabet[j] || symbol == (alphabet[j] + reg_delta) || symbol == '�')
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
                    if (symbol == alphabet[j] || symbol == (alphabet[j] + reg_delta) || symbol == '�')
                    {
                        word += symbol;
                        count_letters_in_word[j]++;
                        // ��� �������
                        // symbol = std::cin.get();
                        // ��� �����
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