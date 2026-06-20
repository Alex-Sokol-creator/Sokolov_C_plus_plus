
#include <iostream>
#include <Windows.h>

using namespace std;

enum Weekdays {
    Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun
};

struct date {
    int day; // 4 bytes
    int month; // 4 bytes
    int year; // 4 bytes
    Weekdays weekday; // 4 bytes
    char month_name[15]; // 15 bytes
}; // 4 * 4 + 15 = 31

struct person {
    char* firstName;
    char* secondName;
    char* email;
    date birthdate;
};

struct Test {
    char c;
    char b;
    int a;
};

struct fieldbits {
    unsigned char field1 : 1; // 1 bit
    unsigned char field2 : 3; // 3 bit
    unsigned char field3 : 4; // 4 bit
};

void printDate(const date& dateToPrint) {
    cout << dateToPrint.day << '.' << dateToPrint.month << '.' << '.' << dateToPrint.year << " -- " 
        << dateToPrint.weekday << ' ' << dateToPrint.month_name;
}

union Data {
    char c;
    bool b;
    int i;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Data d = { 0 };
    cout << d.c << ' ' << d.b << ' ' << d.i << '\n';

    d.c = 'h';

    cout << d.c << ' ' << d.b << ' ' << d.i << '\n';

    d.b = false;

    cout << d.c << ' ' << d.b << ' ' << d.i << '\n';

    d.b = true;

    cout << d.c << ' ' << d.b << ' ' << d.i << '\n';

    cout << sizeof(date) << " bytes\n";
    cout << sizeof(Test) << " bytes\n";
    cout << sizeof(Data) << " bytes\n";

    date today = { 20,06,2026,Sat,"Суббота" };
    printDate(today);

    date* datePtr = &today;

    cout << '\n';

    // cout << (*datePtr).day;
    cout << datePtr->day;

    date copy = today;

    today.day++;
    cout << '\n';
    printDate(copy);
    cout << '\n';
    printDate(today);
}

