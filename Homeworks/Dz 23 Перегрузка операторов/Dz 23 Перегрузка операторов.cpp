
#include <iostream>
#include <Windows.h>
#include "Fraction.h"



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction f1(1, 2);
    Fraction f2(2, 3);
    int num = 3;

    std::cout << "=== ТЕСТ ЗАВДАННЯ 1 (МНОЖЕННЯ) ===\n";
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << " \t(Ожидается: 1/3)\n";
    std::cout << f1 << " * " << num << " = " << (f1 * num) << " \t(Ожидается: 3/2)\n";
    std::cout << num << " * " << f1 << " = " << (num * f1) << " \t(Ожидается: 3/2)\n\n";

    std::cout << "=== ТЕСТ ЗАВДАННЯ 2 (ДІЛЕННЯ) ===\n";
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << " \t(Ожидается: 3/4)\n";
    std::cout << f1 << " / " << num << " = " << (f1 / num) << " \t(Ожидается: 1/6)\n";
    std::cout << num << " / " << f2 << " = " << (num / f2) << " \t(Ожидается: 9/2)\n";
}

