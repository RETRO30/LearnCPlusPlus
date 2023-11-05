#include <fstream>
#include <string>
#include <cctype>

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

int main() {
    std::setlocale(LC_ALL, "Russian");

    const int COUNT_LETTERS = 33;
    const char alphabet[COUNT_LETTERS] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                                         '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                                            '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    char reg_delta = 'A'-'a';

    std::ifstream input_file("assets/input.txt");
    std::ifstream text_file("assets/text.txt");
    std::ofstream result_file("assets/result.txt");

    if (!input_file.is_open() || !text_file.is_open() || !result_file.is_open()) {
        result_file << "������ ������ �����." << std::endl;
        return 1;
    }
    
    short n;
    input_file >> n;
    input_file.close();
    
    std::string text;
    std::string line;
    while (getline(text_file, line)) {
        text += ' ' + line;
    }
    input_file.close();

    const int N_WORDS = 1000;

    std::string word = "";
    std::string words[N_WORDS];
    short len_words = 0;
    bool is_letter;
    bool word_in_words;
    int count_letters_in_word[COUNT_LETTERS];

    for (int i = 0; i < COUNT_LETTERS; i++) {
        count_letters_in_word[i] = 0;
    }

    for (int i = 0; i < text.length(); i++) {
        // ������ ��� ������� ����
        is_letter = false;
        for (int j = 0; j < COUNT_LETTERS; j++) {
            if (text[i] == alphabet[j] || text[i] == alphabet[j] + reg_delta) {
                count_letters_in_word[j]++;
                is_letter = true;
                break;
            }
        }
        if (is_letter == true) {
            word += tolower(text[i]);
        }
        else if (word != ""){
            word_in_words = false;
            for (int j = 0; j < len_words; j++) {
                if (word == words[j]) {
                    word_in_words = true;
                    break;
                }
            }
            if (word_in_words == false) {
                for (int j = 0; j < COUNT_LETTERS; j++) {
                    if (count_letters_in_word[j] >= 3) {
                        words[len_words] = word;
                        len_words++;
                        break;
                    }
                }
            }
            for (int j = 0; j < COUNT_LETTERS; j++) {
                count_letters_in_word[j] = 0;
            }
            word = "";
        }
    }


    std::string temp;
    for (int i = 0; i < len_words; i++) {
        for (int j = 0; j < len_words - i; j++) {
            if (words[j].length() < words[j+1].length()) {
                std::string temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }

    n = (n > len_words) ? len_words : n;
    for (int i = 0; i < n; i++) {
        result_file << words[i] << std::endl;
    }
    return 0;
}