
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /* {
        cout << "\nFirst Task\n";
        cout << "Введите число а, чтобы вывести сумму всех целых чисел от него до 500: ";
        int a;
        int sum = 0;
        cin >> a;
        for (int i = a; i < 501; i++) {
            sum += i;
        }
        cout << "Сумма всех чисел от " << a << " до 500 будет равна: " << sum;
    }*/

    /* {
        cout << "\nSecond Task\n";
        int x;
        int y;
        cout << "Введите число х для возведения в степень у: ";
        cin >> x;
        cout << "Теперь введите степень у: ";
        cin >> y;
        long long xnew = 1;
        for (int i = 0; i < y; i++) {
            xnew *= x;
        }
        cout << "После возведения числа " << x << " в степень " << y << " оно будет равняться: " << xnew;
    }*/

    /* {
        cout << "\nThird Task\n";
        int amount = 0;
        double sum = 0;
        double average = 0;
        for (int i = 1; i < 1001; i++) {
            sum += i;
            amount += 1;
        }
        average = sum / amount;
        cout << "Среднее арифметическое чисел от 1 до 1000 будет равно: " << average;
    }*/

    /* {
        cout << "\nFourth Task\n";
        cout << "Введите целое число а (от 1 до 20 включительно), чтобы найти произведение всех чисел от него до 20: ";
        int a;
        long long multiplying = 1;
        cin >> a;
        if (a < 1 || a > 20) {
            cout << "Ваше число а не попадает в указанный диапазон";
        }
        else {
            for (int i = a; i < 21; i++) {
                multiplying *= i;
            }
            cout << "Произведение всех чисел от " << a << " до 20 будет равно: " << multiplying;
        }
    }*/

    /* {
        cout << "\nFifth Task\n";
        cout << "Введите число k для вывода таблицы умножения с ним: ";
        double k;
        cin >> k;
        for (int i = 1; i <= 10; i++) {
            cout << i << " * " << k << " = " << i * k << '\n';
        }
    }*/

    /* {
        cout << "\nSixth Task\n";
        cout << "Введите целое число А для вывода чисел В: ";
        long a;
        cin >> a;
        cout << "Вот все числа В, на которые А делится без остатка на В*В и не делится без остатка на В*В*В: ";
        for (long long b = 1; b <= a; b++) {
            long long btwo = b * b;
            long long bthree = b * b * b;
            if (a % btwo == 0 && a % bthree != 0) {
                cout << b << ' ';
            }
        }
    }*/

    /* {
        cout << "\nSeventh Task\n";
        cout << "Введите целое число для вывода чисел, на которые это число будет делится без остатка: ";
        long a;
        cin >> a;
        cout << "Вот все целые числа, на которые ваше число делится без остатка: \n";
        for (long i = 1; i <= a; i++) {
            if (a % i == 0) {
                cout << i << '\n';
            }
        }
    }*/

    /* {
        cout << "\nEighth Task\n";
        cout << "Введите целое 1 число для вывода чисел, на которые это число и 2 будут делится без остатка: ";
        long a;
        long b;
        long minnum;
        cin >> a;
        cout << "Введите целое 2 число для вывода чисел, на которые это число и 1 будут делится без остатка: ";
        cin >> b;
        if (a <= b) {
            minnum = a;
        }
        else {
            minnum = b;
        }
        cout << "Вот все числа, на которые оба числа делятся без остатка: ";
        for (long i = 1; i <= minnum; i++) {
            if (a % i == 0 && b % i == 0) {
                cout << i << ' ';
            }
        }
    } */

    {
        cout << "\nNinth Task\n";

    }
}
