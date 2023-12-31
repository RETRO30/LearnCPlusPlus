#include <iostream>


// ����� 1 ��������� ��� ������������� string � ������� ������ � ���������.
// ��������� ������ ������ ���� � ����. ��������� ������� � ��������� ������.
// ��������� ������� �� �����. ��� ���� ��������� ����� 6 ������� �� ����� ������� ������� � ��� ��� �������� ����� � �������� ������ ����������.
// � ������ 2 ����� �� �������� �� ���������, �� ����� ���һ � ���� ������� �����������.
// �������� �����\�����\����� N ��������� � �����. ����� ������� � ��������� �����.
// ������������ �����: text.txt ��� �������� ������, input.txt ��� ������� �������� (N � �.�.), result.txt ��� ������.
// ����������� ����� � �������, ������� �������� ����, ����� �����/����� ��������� � ����������.
// ���� �������: �, �, �, �, �, �, �, �, �, �, �, �.
// ���� ���������: �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �, �.
// �� ��������������� ��������/������� ����� ������� ������ �������� �������.

// ������� 7

// 1. ���� ������ ������ �� ����� 100 ��������. �������� � ��� ��� ������� ����� �� ��� � �������� ��������. ������ ������� �������� �� �����.
// 2. ��� ����, ���������� ������� �����. ����� � ������ N (N ? 10) ����� ������� ����, ���������� �����-���� ����� ��� ����. 
//     �������� ��������� ����� � ��������� ���� � ������� �� �������� �����. 
//     ��� ��������� ����� ������ ���� �������. 

int main() {

    setlocale(LC_ALL, "Rus");


    // ���������������
    const int count_volwes = 12, count_consontants = 21;
    const char vowels[count_volwes] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    const char consonants[count_consontants] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                           '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    char reg_delta = '�' - '�'; 

    char input_string[100] = "���� ������ ������ � �� Ḩ��� 100 ��������.";

    std::cout << "������� ������:\n" << input_string << '\n';
    
    int len_string = 0;
    while (input_string[len_string] != '\0') {
        len_string++;
    }

    for (int i = 0; i < len_string; i++){
        for (int j = 0; j < 12; j++){
            if (input_string[i] == vowels[j]){
                input_string[i] = '�';
            }
            else if (input_string[i] == (vowels[j] + reg_delta) || input_string[i] == '�') {
                input_string[i] = '�';
            }
        }
    }

    std::cout << "���������� ������:\n" << input_string << '\n';

    std::cout << "\n������� ���������: \n";

    for (int i = '�'; i < '�'; i++)
  {
    std::cout << char(i) << " = " << i << std::endl;
    std::cout << char(i + reg_delta) << " = " << i + reg_delta << std::endl;
  }

  std::cout << '�' << " = " << (int)('�') << std::endl;
  std::cout << char(184) << " = " << 184 << std::endl;

  for (int i = 33; i <= 47; i++)
  {
    std::cout << char(i) << " = " << i << std::endl;
  }

    return 0;
}
