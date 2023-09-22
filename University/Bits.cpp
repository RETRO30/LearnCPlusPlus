/*

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number; // Ввод числа с клавиатуры
    number |= (1 << (number - 1)); // Установка i-го бита в 1
    cout << "Bit " << number << " ustanovlen dlya 1." << endl;
    return 0;
}

*/

/*

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number; // Ввод числа с клавиатуры
    number &= ~(1 << (number - 1)); // Установка i-го бита в 0
    cout << "Bit " << number << " is set to 0." << endl;
    return 0;
}

*/

/*

#include <iostream>
#include <bitset>

int main() {
    int number;
    cin >> number; // Ввод числа с клавиатуры

    std::bitset<32> bits(number); // Создание объекта std::bitset размером 32 бита
    bool bit_value = bits[number - 1]; // Получение значения i-го бита

    if (bit_value) {
        cout << "Bit " << number << " is set to 1." << endl;
    } else {
        cout << "Bit " << number << " is set to 0." << endl;
    }

    return 0;
}

*/


/*

#include <iostream>
#include <bitset>

int main() {
    int number;
    cin >> number; // Ввод числа с клавиатуры

    std::bitset<32> bits(number); // Создание объекта std::bitset размером 32 бита
    bits.flip(); // Инверсия всех битов

    uint32_t inverted_number = bits.to_ulong(); // Преобразование объекта std::bitset в целое число

    cout << "Inverted number: " << inverted_number << endl;

    return 0;
}

*/

/*

#include <iostream>
#include <bitset>

int main() {
    int number;
    cin >> number; // Ввод числа с клавиатуры

    std::bitset<32> bits(number); // Создание объекта std::bitset размером 32 бита
    int i = 5; // Индекс i-го бита
    int j = 17; // Индекс j-го бита

    // Сдвиг битов
    bits.rotate(i, j);

    // Получение нового значения
    number = bits.to_ulong();

    cout << "New value: " << number << endl;

    return 0;
}

*/

// abc -> (abc << 1) >> 1 -> cba // Циклический сдвиг





