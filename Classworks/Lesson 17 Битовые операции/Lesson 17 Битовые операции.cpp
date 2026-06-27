
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    unsigned short number = 10;
    //0000 0000 0000 1010
    cout << (number << 1) << '\n';
    // 0000 0000 0001 0100 (умножает на 2, зсув влево)
    cout << (number >> 1) << '\n';
    // 0000 0000 0000 0101 (делит на 2, зсув направо)

    unsigned int num2 = 10;

    cout << (~number) << ' ' << (~num2) << '\n';

    // ~ - инверсия битов
    // 0000 0000 0000 1010 -> 1111 1111 1111 0101
    // 0000 0000 0000 0000 0000 0000 0000 1010 -> 1111 1111 1111 1111 1111 1111 1111 0101

    unsigned short x = 5, y = 6;
    // x = 0000 0000 0000 0101
    // y = 0000 0000 0000 0110

    cout << (x | y) << '\n';
    // | - битовое "или"
    // 0000 0000 0000 0111 = 7

    cout << (x ^ y) << '\n';
    // ^ - битовое "или", но наоборот
    // 0000 0000 0000 0011 = 3

    cout << (x & y) << '\n';
    // & - битовое "и"
    // 0000 0000 0000 0100 = 4

    x = x ^ y; // 0000 0000 0000 0011
    y = x ^ y; // 0000 0000 0000 0101
    x = x ^ y; // 0000 0000 0000 0111

    LPCWSTR message = L"Вы действительно хотите удалить этот файл?";
    LPCWSTR title = L"Подтверждение удаления";
    // ... 0001 0000 - MB_YESNO
    // ... 0010 0000 - MB_ICONWARNING
    // ... 1000 0000 - MB_DEFBUTTON2
    // ... 1011 0000
    UINT msgBoxType = MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2;
    int result = MessageBox(NULL, message, title, msgBoxType);
    if (result == IDYES) {
        cout << "User said yes" << '\n';
    }
    else if (result == IDNO) {
        cout << "User said no" << '\n';
    }
}

