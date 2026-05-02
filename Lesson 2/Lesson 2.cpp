

#include <iostream>
#include <Windows.h>

enum Color {
    Red = 5,
    Green = 10,
    Blue = 15,
    Purple = 20
};

namespace MyNamespace {
    enum Status {
        Unknown = -1,
        Online = 1,
        Offline = 0
    };
    int intVar;
    double doubleVar;
};

using namespace std;

int main()
{
    ////setlocale(0, "uk-Uk"); Тоже кириллица, но для украинского не подходит

    SetConsoleCP(1251); // Выводит кириллицу нормально
    SetConsoleOutputCP(1251);
    ////int cout = 10;

    //cout << "Привет мир" << '\n';

    //MyNamespace::Status userStatus = MyNamespace::Online;

    //Color color = Red;

    //cout << sizeof(color) << '\n';

    //cout << color << '\n';

    //cout << color << '\n';

    //int integer = (int)7.8;

    //cout << main << '\n';

    //int integer = 7.8;

    //cout << 10 / (double)3 << '\n';

    //cout << (integer == 7) << '\n';

    //cout << typeid(integer).name() << ' ' << integer << '\n';

    int num1, num2;
    cin >> num1 >> num2;

    if (num1 == num2) {
        cout << "Числа равные" << '\n';
    }
    else if (num1 > num2) {
        cout << "Первое число больше второго" << '\n';
    }
    else{
        cout << "Второе число больше первого" << '\n';
    }
    //else {
    //    cout << "Числа не равные" << '\n';
    //}

}