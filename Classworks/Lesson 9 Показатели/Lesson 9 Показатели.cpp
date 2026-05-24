
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x = 100;

    cout << "Адрес переменной 'х' в памяти: " << &x << endl;
}

