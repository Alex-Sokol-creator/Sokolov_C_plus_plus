
#include <iostream>
#include <Windows.h>

using namespace std;

void EnterToTab(char* stroka) {
    int size = strlen(stroka);
    for (int i = 0; i < size; i++) {
        if (stroka[i] == ' ') {
            stroka[i] = '\t';
        }
    }
}

void CountElements(char* stroka) {
    int size = strlen(stroka);
    int figures = 0, letters = 0, symbols = 0;
    for (int i = 0; i < size; i++) {
        if (stroka[i] >= 48 && stroka[i] <= 57) {
            figures++;
        }
        else if ((stroka[i] >= 65 && stroka[i] <= 90) || (stroka[i] >= 97 && stroka[i] <= 122)) {
            letters++;
        }
        else {
            symbols++;
        }
    }
    cout << "В вашей строке:\n" << figures << " цифр\n" << letters << " букв\n" << symbols << " символов";
}

void CountWords(char* stroka) {
    int words = 0, check = 0, position = 0;
    /*
    for (int i = position; stroka[i] != '\0'; i++) {
        if ((stroka[i] >= 65 && stroka[i] <= 90) || (stroka[i] >= 97 && stroka[i] <= 122)) {
            for (int j = i; stroka[j] != '\0'; j++) {
                if (stroka[j] == ' ') {
                    position = j;
                    words++;
                    break;
                }
            }
        }
    }
    */

    for (int i = 0; stroka[i] != '\0'; i++) {
        if ((stroka[i] >= 65 && stroka[i] <= 90) || (stroka[i] >= 97 && stroka[i] <= 122)) {
            if (check == 0) {
                words++;
                check = 1;
            }
        }
        else {
            check = 0;
        }
    }
    cout << "В вашей строке столько слов: " << words;
}

void CheckPalindrom(char* stroka) {
    int check = 0, size = strlen(stroka); 
    int back = size - 1;
    int half = size / 2;
    for (int i = 0; i < half; i++) {
        if (stroka[i] != stroka[back]) {
            check = 1;
            break;
        }
        else {
            back--;
        }
    }
    if (check == 0) {
        cout << "Ваша строка является палиндромом";
    }
    else {
        cout << "Ваша строка не является палиндромом";
    }
}


int mystrlen(const char* str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        result++;
    }
    return result;
}

char* mystrcpy(char* str1, const char* str2) {
    int position = 0;
    for (int i = 0; str2[i] != '\0'; i++) {
        str1[i] = str2[i];
        position++;
    }
    str1[position] = '\0';
    return str1;
}

char* mystrcat(char* str1, const char* str2) {
    int size1 = mystrlen(str1);
    int position = size1 + 1;
    str1[size1] = str2[0];
    for (int i = 1; str2[i] != '\0'; i++) {
        str1[position] = str2[i];
        position++;
    }
    str1[position] = '\0';
    return str1;
}

char* mystrchr(char* str, char symbol) {
    char* result = 0;
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol) {
            result = &str[i];
            check = 1;
            break;
        }
    }
    if (check == 1) {
        return result;
    }
    else {
        return 0;
    }
}

char* mystrstr(char* str1, char* str2) {
    char* result = 0;
    int check = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        int index1 = i;
        int index2 = 0;
        while (str1[index1] != '\0' && str2[index2] != '\0' && str1[index1] == str2[index2]) {
            index1++;
            index2++;
        }
        if (str2[index2] == '\0') {
            result = &str1[i];
            check = 1;
            break;
        }
    }
    if (check == 1) {
        return result;
    }
    else {
        return 0;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        cout << "\nFirst Task\n";
        char stroka[] = "В Папуа-Новой Гвинее живут аборигены племена Асаро";
        cout << stroka << '\n';
        EnterToTab(stroka);
        cout << stroka;
    }

    {
        cout << "\nSecond Task\n";
        char stroka[] = "The Asaro tribespeople live in Papua New Guinea.";
        cout << stroka << '\n';
        CountElements(stroka);
    }

    {
        cout << "\nThird Task\n";
        char stroka[] = "The Asaro tribespeople live in Papua New Guinea.";
        cout << stroka << '\n';
        CountWords(stroka);
    }

    {
        cout << "\nFourth Task\n";
        char stroka[] = "racecar racecar";
        cout << stroka << '\n';
        CheckPalindrom(stroka);
    }

    {
        cout << "\nFifth Task\n";
        char str1[100] = "В Папуа-Новой Гвинее живут аборигены";
        char str2[] = "А именно племя Асаро";
        char understr1[] = "Гвинее";
        char symbol = 'Г';

        cout << "1 строка: " << str1 << '\n';
        cout << "2 строка" << str2 << '\n';
        cout << "Длина 1 строки: " << mystrlen(str1) << '\n';
        cout << "Длина 2 строки: " << mystrlen(str2) << '\n';
        cout << "Поиск элемента Г в строках: \n";
        char* result1 = mystrchr(str1, symbol);
        cout << "1 строка: ";
        if (result1 == 0) {
            cout << "К сожалению, такой символ не был найден\n";
        }
        else {
            cout << result1 << '\n';
        }
        result1 = mystrchr(str2, symbol);
        cout << "2 строка: ";
        if (result1 == 0) {
            cout << "К сожалению, такой символ не был найден\n";
        }
        else {
            cout << result1 << '\n';
        }
        cout << "Поиск подстроки в строке 1: \n";
        result1 = mystrstr(str1, understr1);
        cout << "Результат: ";
        if (result1 == 0) {
            cout << "К сожалению, такая подстрока не была найдена\n";
        }
        else {
            cout << result1 << '\n';
        }
        cout << "Присоединение строки 2 к строке 1: \n";
        cout << "Результат: " << mystrcat(str1, str2) << '\n';
        cout << "Копирование строки 2 к строке 1: \n";
        cout << "Результат: " << mystrcpy(str1, str2) << '\n';
    }
}

