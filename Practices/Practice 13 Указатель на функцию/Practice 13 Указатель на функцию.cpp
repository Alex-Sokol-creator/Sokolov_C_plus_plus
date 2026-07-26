
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
T sum(T num1, T num2) {
    return num1 + num2;
}

template <typename T>
T subtruct(T num1, T num2) {
    return num1 - num2;
}

template <typename T>
T multiply(T num1, T num2) {
    return num1 * num2;
}


template <typename T>
T divide(T num1, T num2) {
    return num1 / num2;
}

template <typename T>
void calcAndPrint(T num1, T num2, T (*callback)(T, T)) {
    cout << callback(num1, num2) << '\n';
}

template <typename T>
void UnionOfMasivs(T* A, T* B, T* C, int sizeABC) {
    for (int i = 0; i < sizeABC; i++) {
        C[i] = A[i] + B[i];
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    cout << "\nFirst Task\n";
    double (*calculation[48]) (double, double) = { nullptr };
    calculation['+'] = { sum };
    calculation['-'] = { subtruct };
    calculation['*'] = { multiply };
    calculation['/'] = { divide };

    double num1, num2;
    char operation;
    cout << "Введите 1 число: ";
    cin >> num1;
    cout << "Введите 2 число: ";
    cin >> num2;
    cout << "Введите операцию, которую хотите произвести с данными числами (+,-,*,/): ";
    cin >> operation;
    cout << "После расчетов, ваш результат будет: ";
    calcAndPrint(num1, num2, calculation[operation]);
    
    cout << "\nSecond Task\n";
    const int sizeABC = 10;
    int min = -100, max = 100;
    int A[sizeABC], B[sizeABC], C[sizeABC];
    for (int i = 0; i < sizeABC; i++) {
        A[i] = min + rand() % (max - min + 1);
        B[i] = min + rand() % (max - min + 1);
    }
    UnionOfMasivs(A, B, C, sizeABC);
    cout << "Суммы попарных элементов в массивах А и Б были занесены в массив С, вот они: \n";
    for (int i = 0; i < sizeABC; i++) {
        cout << "Сумма " << i + 1 << " элементов: " << C[i] << '\n';
    }
}

