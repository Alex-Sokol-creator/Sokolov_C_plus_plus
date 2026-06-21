
#include <iostream>
#include <Windows.h>

using namespace std;

#define PI 3.14 // Макрос
#define SQR(X) ((X) * (X))

// #undef PI

#define FOREVER while(true)
#define BEGIN {
#define END }
#define ENDLINE ;

#pragma warning(disable:4996)

#include "Point.h"

int main()
{
    // Регион (для скрытия)
#pragma region Encoding
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#pragma endregion

    /*
    cout << PI << '\n';
    cout << 3.14 << '\n';

    cout << SQR(10) << '\n';
    cout << 10 * 10 << '\n';
    */

    /*FOREVER BEGIN
        cout << 'H' << '\n' ENDLINE
    END*/

    /*
    char str[] = "fdfhdfhghghaghfafzgff3fffsgd'fdhfhdfhgh;fdgyggr"\
        "asdddfvdfdfhdfdrerregdffd";
    cout << str << '\n';
    */
/*
#ifdef SQR // Будет только в том случае, если будет указана SQR
    cout << SQR(10) << '\n';
#endif
*/


//#if __cplusplus < 202002L
//#error "Нужна версия 20 и выше"
//#endif

    /*
    char* dest = new char[10];
    char source[] = "123456789";

    strcpy(dest, source);
    delete[] dest;
    */
    

    Point p1, p2;

    cout << "Enter first point: ";
    inputPoint(p1);
    cout << "Enter second point: ";
    inputPoint(p2);

    cout << "Point 1: ";
    printPoint(p1);
    cout << '\n';
    cout << "Point 2: ";
    printPoint(p2);
    cout << '\n';

    double distance = calculateDistance(p1, p2);
    cout << "Distance: " << distance << '\n';
    Point midpoint = findMidpoint(p1, p2);
    cout << "Midpoint: ";
    printPoint(midpoint);
    cout << '\n';
}

