
#include <iostream>
#include <Windows.h>
#include "Fraction.h"
#include <algorithm>
#include "Permissions.h"

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

    //Fraction f = f1 + 2;

    Fraction f = 2 + f1;

    if (f1 == f2) {
        std::cout << "f1 equals f2\n";
    }
    else {
        std::cout << "f1 is not equal to f2" << '\n';
    }

    int num1 = 10, num2 = 12;

    std::strong_ordering result = num1 <=> num2;

    // if (result == std::strong_ordering::equal) {
    if (result == 0){
        std::cout << "numbers are equal." << '\n';
    }
    else if (result < 0) {
        std::cout << "Num1 is less than num2\n";
    }
    else if (result > 0) {
        std::cout << "Num1 is greater than num2" << '\n';
    }

    if (f1 == f2) {
        std::cout << "numbers are equal." << '\n';
    }
    else if (f1 < f2) {
        std::cout << "Num1 is less than num2\n";
    }
    else if (f1 > f2){
        std::cout << "Num1 is greater than num2" << '\n';
    }

    const int size = 6;
    int numbers[size] = { 10,-9,0,100,0,-13 };
    std::sort(numbers, numbers + size);

    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << ' ';
    }

    std::cout << '\n';

    Fraction fractions[] = {
        Fraction(3,4),
        Fraction(-1,2),
        Fraction(5,4),
        Fraction(1,3)
    };

    int sizeF = sizeof(fractions) / sizeof(fractions[0]);

    std::sort(fractions, fractions + sizeF);
    for (int i = 0; i < sizeF; i++) {
        std::cout << fractions[i] << ' ';
    }

    cout << '\n';

    Permissions p1(Permissions::Read);
    Permissions p2(Permissions::Write);

    Permissions both = p1 | p2;
    both.print();

    Permissions check = both & Permissions(Permissions::Read);
    if (!check) {
        std::cout << "No rights for reading\n";
    }
    else {
        std::cout << "Have reading rights\n";
    }

    std::cout << (10 > 12 && 40 < 100) << '\n';
}

