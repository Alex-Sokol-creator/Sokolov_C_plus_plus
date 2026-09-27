
#include <iostream>
#include <Windows.h>
#include "Fraction.h"

using namespace std;

class Box {
private:
    int width;
public:
    explicit Box(int w) : width(w) {
        cout << "Box created with width: " << width << '\n';
    }

    friend void PrintBoxWidth(const Box& b);
    // friend - значит метод может брать private поля
};

void PrintBoxWidth(const Box& b) {
    cout << "Width of the box: " << b.width << '\n';
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Box box = Box(10);
    PrintBoxWidth(box);

    Fraction f1 = Fraction(4, 7);
    Fraction f2 = Fraction(3, 7);

    //Fraction sum = Fraction::add(f1, f2);
    Fraction sum = f1 + f2;

    // std::cout << sum << '\n';

    Fraction f = f1 + 2;

    Fraction f = 2 + f1;
}

