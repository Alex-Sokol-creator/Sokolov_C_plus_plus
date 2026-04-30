// MyFirstCPPProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> // Включение библиотеки ввода и вывода

int main() // Вход в программу
{
    // строчный комментарий
    // Test

    int number = 10;
    long lNumber = 1212121;
    long long llNumber = 84322183743473464;

    float fNumber = 18.6f;
    double dNumber = 18.3848545;

    char symbol = '\n';

    bool booleanValue = true;

    int variable;

    variable = 10;

    const float PI = 3.14;

    //PI = 78.6;

    variable++;
    std::cout << variable << '\n';
    variable++;
    std::cout << variable << '\n';
    std::cout << variable++ << '\n';
    std::cout << variable << '\n';

    std::cout << "Hello World!\n";

    std::cin >> variable;

    std::cout << variable << '\n';

    std::cout << 10 << ' ' << 78 << ' ' << 9.8 << '\n';

    std::cout << true << '\n';

    std::cout << 10 + 12 << '\n';
    std::cout << 10 - 12 << '\n';
    std::cout << 10 / 12 << '\n';
    std::cout << 10 * 12 << '\n';
    std::cout << 10 % 12 << '\n';

    std::cout << (10 == 12) << '\n';
    std::cout << (10 != 12) << '\n';
    std::cout << (10 > 12) << '\n';
    std::cout << (10 < 12) << '\n';
    std::cout << (10 >= 12) << '\n';
    std::cout << (10 <= 12) << '\n';
}

/*
    Это проект С++
    Это многострочный комментарий
    Здесь я могу писать все что захочу
*/