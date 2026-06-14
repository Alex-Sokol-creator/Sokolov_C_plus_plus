
#include <iostream>
#include <Windows.h>

using namespace std;

void FOO() {
    // empty function
}

double sum(double num1, double num2 = 10) {
    return num1 + num2;
}

double subtruct(double num1, double num2) {
    return num1 - num2;
}

/*double multiply(double num1, double num2) {
    return num1 * num2;
}
*/

double divide(double num1, double num2) {
    return num1 / num2;
}

void calcAndPrint(double num1, double num2, double (*callback)(double, double)) {
    cout << callback(num1, num2) << '\n';
}

template <typename T1, typename T2>
auto multiply(T1 value1, T2 value2) { // Return type deduction
    return value1 * value2;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    /*
    cout << FOO << '\n';
    cout << main << '\n';
    */

    /*
    cout << sum(11) << '\n';

    double (*ptr) (double, double) = sum;
    cout << ptr(10, 12) << '\n';
    */

    /*
    double (*calc[]) (double, double) = { sum,subtruct,multiply,divide };
    double num1, num2;
    cin >> num1 >> num2;
    for (int i = 0; i < 4; i++) {
        calcAndPrint(num1, num2, calc[i]);
    }
    */

    // auto decltype
    auto number = 10;
    auto number1 = 10 + 8.7;

    decltype(10 + 9.6) number2; // Не инициализируется
    decltype(10 + 9.6) number2 = 10; // Будет double

    cout << multiply(10, 12.3) << '\n';
}

