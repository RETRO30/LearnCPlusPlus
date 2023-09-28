#include <iostream>
#include <string>

int main(){
    unsigned short int i, j;
    unsigned short int bit_i, bit_j;
    unsigned char rotate, reverse, transp_i_to_j;
    
    //unsigned char X = 7;
    // 7 = 00000111
    unsigned char X = 98; 
    // 98 = 01100010
    //unsigned char X = 241; 
    // 241 = 11110001

    // Ввод
    std::cout << "Enter i index (0-7): ";
    std::cin >> i;
    std::cout << "Enter j index (0-7): ";
    std::cin >> j;

    // Значение i-ого элемента
    bit_i = ((X >> i) % 2);

    
    //Инверсия
    reverse = X ^ (char)255;

    // Поменять биты местами
    bit_j = (X >> j) & 1;
    transp_i_to_j = X;
    transp_i_to_j ^= (bit_i << i) ^ (bit_j << j);

    // Перевернуть битовую цепочку
    unsigned char tmp = X;
    for (int i = 0; i < 8; i++) {
        rotate = (rotate << 1) | (tmp & 1);
        tmp >>= 1;
    }

    // Вывод
    std::cout << "Task 1: " << (int)bit_i << std::endl;
    std::cout << "Task 2: " << (int)reverse << std::endl;
    std::cout << "Task 3: " << (int)transp_i_to_j << std::endl;
    std::cout << "Task 4: " << (int)rotate << std::endl;
}