// � ��������� ����� ������� ������� �����. ����� � ������ �����, ���������� ��� ���������� ����� ������,
// �������� �� � ������� �������� � ������� ����� ������� ������ ����� � ������� ��������� �����. 
// ���������� ����� �������� � ��� �� ����. ���� �����, ����� ��������� ����, ������ �������� ����������, ������� � ����� ����������.


#include <iostream>
#include <fstream>
#include <string>

int main() {

    const int COUNT_LETTERS = 33;
    const char alphabet[COUNT_LETTERS] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                                         '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                                            '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    char reg_delta = '�' - '�';

    std::string WORK_FILE = "assets/optional_text.txt";

    setlocale(LC_ALL, "Russian");

    std::ifstream input_file(WORK_FILE);

    if (!input_file.is_open()) {
        std::cout << "������ ������ �����." << '\n';
        return 1;
    }

    std::string input_text;
    std::string line;
    while (getline(input_file, line)) {
        input_text += line + '\n' ;
    }

    input_file.close();

    std::string result_text = "";
    std::string word = "";
    std::string repeat_letters = "";
    
    bool flag = false;
    bool is_added = false;
    bool is_letter = false;
    for (int i = 0; i < input_text.length(); i++) {
        for (int j = 0; j < 33; j++) {
            if (input_text[i] == alphabet[j] || input_text[i] == alphabet[j] + reg_delta) {
                is_letter = true;
                break;
            }
        }
        if (is_letter) {
            while (is_letter) {
                is_letter = false;
                for (int j = 0; j < 33; j++) {
                    if (input_text[i] == alphabet[j] || input_text[i] == alphabet[j] + reg_delta) {
                        word += input_text[i];
                        i++;;
                        is_letter = true;
                        break;
                    }
                }
                
            }
            i--;
            for (int k = 0; k < word.length() - 1; k++) {
                if (word[k] == word[k + 1]) {
                    flag = true;
                    for (int j = 0; j < repeat_letters.length(); j++) {
                        if (word[k] == repeat_letters[j]) {
                            is_added = true;
                            break;
                        }
                    }
                    if (!is_added) {
                        repeat_letters += word[k];
                    }
                    is_added = false;
                }
            }
            if (flag) {
                for (int j = 0; j < word.length(); j++) {
                    for (int k = 0; k < COUNT_LETTERS; k++) {
                        if (word[j] == alphabet[k]) {
                            word[j] = word[j] + reg_delta;
                            break;
                        }
                    }
                }
                result_text += word + '(' + repeat_letters + ')';
            }
            else {
                result_text += word;
            }
            flag = false;
            word = "";
            repeat_letters = "";
        }
        else {
            result_text += input_text[i];
        }
    }

    std::ofstream output_file(WORK_FILE);

    if (!output_file.is_open()) {
        std::cout << "������ ������ �����." << '\n';
        return 1;
    }

    output_file << result_text;

    output_file.close();

    return 0;
}