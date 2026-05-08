

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

enum Status {
    Online,Offline
};

int main()
{
    ////setlocale(0, "uk-Uk"); Тоже кириллица, но для украинского не подходит

    SetConsoleCP(1251); // Выводит кириллицу нормально
    SetConsoleOutputCP(1251);
    ////int cout = 10;

    //bool isOnline;
    //cin >> isOnline;

    //Status status = (isOnline) ? Online : Offline;

    //cout << status << '\n';

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

    //int num1, num2;
    //cin >> num1 >> num2;

    //if (num1 == num2) {
    //    cout << "Числа равные" << '\n';
    //}
    //else if (num1 > num2) {
    //    cout << "Первое число больше второго" << '\n';
    //}
    //else{
    //    cout << "Второе число больше первого" << '\n';
    //}
    //else {
    //    cout << "Числа не равные" << '\n';
    //}

    //int num;
    //cin >> num;
    //if (num > 5 && num < 15) {
    //    cout << "Число в диапазоне от 5 до 15" << '\n';
    //}
    //else {
    //    cout << "Число не в диапазоне" << '\n';
    //}

    // and - &&
    // or - ||
    // not - !

    //int userStatus;
    //cin >> userStatus;

    //if (userStatus == -1 || userStatus == 1) // Unknown or Offline
    //{
    //    cout << "Пользователь не в сети" << '\n';
    //}

    //bool isOnline = true;

    //if (isOnline == true) {
    //    cout << "Пользователь в сети" << '\n';
    //}

    //int num;
    //cin >> num;

    //cout << ((num % 2 == 0) ? "Number is edd\n" : "Number is odd\n");
    //
    //if (num % 2 == 0) {
    //    cout << "Number is edd\n";
    //}
    //else{
    //    cout << "Number is odd\n";
    //}

    int day;
    cin >> day;

    switch (day) {
    case 1: cout << "Понедельник\n"; break;
    case 2: cout << "Вторник\n"; break;
    case 3: cout << "Среда\n"; break;
    case 4: cout << "Четверг\n"; break;
    case 5: cout << "Пятница\n"; break;
    case 6: cout << "Суббота\n"; break;
    case 7: cout << "Воскресенье\n"; break;
    default: cout << "Данные некорректные\n"; break;
    }
}