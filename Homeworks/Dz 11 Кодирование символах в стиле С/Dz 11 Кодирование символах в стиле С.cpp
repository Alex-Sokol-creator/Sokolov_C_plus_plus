
#include <iostream>
#include <Windows.h>

using namespace std;

void SymbolsCount(char* stroka) {
    int letters = 0, figures = 0, symbols = 0;
    for (int i = 0; stroka[i] != '\0'; i++) {
        if (stroka[i] >= '0' && stroka[i] <= '9') {
            figures++;
        }
        else if ((stroka[i] >= 'A' && stroka[i] <= 'Z') || (stroka[i] >= 'a' && stroka[i] <= 'z')) {
            letters++;
        }
        else {
            symbols++;
        }
    }
    cout << "В вашей строке: \n" << figures << " чисел/числа/число\n" << letters << " букв/буква/буквы\nи " << symbols << " символов/символа/символ\n";
}

int mystrcmp(const char* str1, const char* str2) {
    /*
    int size1 = 0, size2 = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        size1 += str1[i];
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        size2 += str2[i];
    }
    if (size1 > size2) {
        return 1;
    }
    else if (size1 < size2) {
        return -1;
    }
    else {
        return 0;
    }
    */
    int i = 0;

    while (str1[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }

    if (str1[i] > str2[i]) {
        return 1;
    }
    else if (str1[i] < str2[i]) {
        return -1;
    }
    else {
        return 0;
    }
}

int StringToNumber(char* str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        result += str[i];
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        cout << "\nFirst Task\n";
        const int buffer_size = 256;
        char buffer_enter[buffer_size];
        cout << "Введите вашу строку (по английски): ";
        // cin.ignore();
        cin.getline(buffer_enter, buffer_size);
        int size = strlen(buffer_enter);
        char* stroka = new char[size + 1];
        strcpy_s(stroka, size + 1, buffer_enter);
        SymbolsCount(stroka);
        delete[] stroka;
    }

    {
        cout << "\nSecond Task\n";
        const int buffer_size = 256;
        char buffer_enter[buffer_size];
        cout << "Введите вашу 1 строку (по английски): ";
        cin.getline(buffer_enter, buffer_size);
        int size1 = strlen(buffer_enter);
        char* stroka1 = new char[size1 + 1];
        strcpy_s(stroka1, size1 + 1, buffer_enter);

        cout << "Введите вашу 2 строку (по английски): ";
        cin.getline(buffer_enter, buffer_size);
        int size2 = strlen(buffer_enter);
        char* stroka2 = new char[size2 + 1];
        strcpy_s(stroka2, size2 + 1, buffer_enter);
        int result = mystrcmp(stroka1,stroka2);
        if (result == 0) {
            cout << "Строки равные\n";
        }
        else if (result == 1) {
            cout << "Первая строка больше за вторую\n";
        }
        else {
            cout << "Вторая строка больше за первую\n";
        }
    }

    {
        const int buffer_size = 256;
        char buffer_enter[buffer_size];
        cout << "Введите вашу строку: ";
        cin.getline(buffer_enter, buffer_size);
        int size1 = strlen(buffer_enter);
        char* stroka = new char[size1 + 1];
        strcpy_s(stroka, size1 + 1, buffer_enter);
        int result = StringToNumber(stroka);
        cout << "После конвертации вашей строки в число, получилось: " << result << '\n';
    }
}

