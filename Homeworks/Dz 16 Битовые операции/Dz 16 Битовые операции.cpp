
#include <iostream>
#include <Windows.h>

using namespace std;

char* NumToChar(int number) {
    char* result = new char[33];
    int index = 0;
    for (int i = 31; i >= 0; i--) {
        result[index] = ((number >> i) & 1) + '0';
        index++;
    }
    result[index] = '\0';
    return result;
}

char* NumToCharSixteen(int num) {
    char* result = new char[9];
    int index = 7;
    for (int i = 0; i < 8; i++) {
        int number_ready = num & 0xf;
        if (number_ready < 10) {
            result[index] = number_ready + '0';
        }
        else {
            result[index] = (number_ready - 10) + 'A';
        }
        num = num >> 4;
        index--;
    }
    result[8] = '\0';
    return result;
}

int CharToNum(char* number) {
    int size = strlen(number);
    int result = 0, degree = 0, twokoeficient = 1;
    for (int i = size - 1; i >= 0; i--) {
        int multiply = (number[i] - '0') * twokoeficient;
        result += multiply;
        twokoeficient *= 2;
    }
    return result;
}

int CharToNumSixteen(char* number) {
    int size = strlen(number);
    int result = 0, degree = 0, sixteenkoeficient = 1;
    for (int i = size - 1; i >= 0; i--) {
        int symbol;
        if (number[i] >= '0' && number[i] <= '9') {
            symbol = number[i] - '0';
        }
        else {
            symbol = (number[i] - 'A') + 10;
        }
        int multiply = symbol * sixteenkoeficient;
        result += multiply;
        sixteenkoeficient *= 16;
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\nFirst Task\n";
    int number;
    cout << "Введите целое число, чтобы перевести его в двоичный формат: ";
    cin >> number;
    char* result = NumToChar(number);
    cout << "После конвертации ваше число будет таким: " << result << '\n';
    delete[] result;

    cout << "\nSecond Task\n";
    cout << "Введите целое число, чтобы перевести его в 16-й формат: ";
    cin >> number;
    result = NumToCharSixteen(number);
    cout << "После конвертации ваше число будет таким: " << result << '\n';
    delete[] result;

    cout << "\nThird Task\n";
    char number_str[40];
    cin.ignore();
    cout << "Введите число в двоичном формате, чтобы перевести его в десятичный формат: ";
    cin.getline(number_str, 40);
    int result_num = CharToNum(number_str);
    cout << "После конвертации ваше число будет таким: " << result_num << '\n';

    cout << "\nFourth Task\n";
    cout << "Введите число в 16-м формате, чтобы перевести его в десятичный формат: ";
    cin.getline(number_str, 40);
    result_num = CharToNumSixteen(number_str);
    cout << "После конвертации ваше число будет таким: " << result_num << '\n';
}
