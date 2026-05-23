
/*#include <iostream>
#include <Windows.h>

using namespace std;

#define SQR(x) ((x) * (x))

inline double add(double a, double b) {
    return a + b;
}

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}
float sum(float a, float b, float c) {
    return a + b + c;
}

int findMax(int, int);
int findMax(int[], int);
double findMax(double,double,double);
double findMax(double[], int);

template<typename T>
T findMax(T arr[], int size);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int integers[] = { 9, -5,7,5,6,8 };
    double doubles[] = { 9.8, 6.7,5.6,7.3 };
    float floates[] = { 9.5f,6.7f,43.6f };

    //cout << SQR(10) << '\n';
    //cout << 10 * 10 << '\n';

    //for (int i = 0; i < 20; i++) {
    //    cout << add((double)i, (double)(i * 150)) + add(10,12)<< ' ';
    //    //cout << (double)i + (double)(i * 150) << ' '; 
    //}
    //cout << '\n';

    //cout << sum(10, 12) << '\n';
    //cout << sum(12.4f, 23.56f) << '\n';
    //cout << sum(12.4f, 23.56f,8.76f) << '\n';

    findMax(integers, 5);
    findMax(doubles, 4);
    findMax(floates, 3);
}

int findMax(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

//int findMax(int arr[], int size) {
//    int max = arr[0];
//    for (int i = 1; i < size; i++) {
//        if (max < arr[i]) {
//            max = arr[i];
//        }
//    }
//    return max;
//}

double findMax(double num1, double num2, double num3) {
    return (num1 > num2) ?
        ((num1 > num3) ? num1 : num3) :
        ((num2 > num3) ? num2 : num3);
}

//double findMax(double arr[], int size) {
//    int max = arr[0];
//    for (int i = 1; i < size; i++) {
//        if (max < arr[i]) {
//            max = arr[i];
//        }
//    }
//    return max;
//}

template<typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}*/



#include <iostream>
#include <Windows.h>

using namespace std;

#define SQR(x) ((x) * (x))

inline double add(double a, double b) {
    return a + b;
}

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}
float sum(float a, float b, float c) {
    return a + b + c;
}

// Удалены прототипы для int[] и double[], так как их заменяет шаблон
int findMax(int, int);
double findMax(double, double, double);

// Реализация шаблона должна быть видна компилятору до вызова
template<typename T>
T findMax(T arr[], int size) {
    T max = arr[0]; // Исправлено: тип T вместо int
    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void recursionFunction(int counter) {
    cout << counter++ << '\n';
    recursionFunction(counter);
}

int factorialIterational(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int factorialRecursion(int num) {
    if (num == 1) {
        return 1;
    }
    else {
        return num * factorialRecursion(num - 1);
    }
}

int fibonacci(int number) {
    if (number <= 1) {
        return number;
    }
    else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int integers[] = { 9, -5, 7, 5, 6, 8 };
    double doubles[] = { 9.8, 6.7, 5.6, 7.3 };
    float floates[] = { 9.5f, 6.7f, 43.6f };

    // Теперь эти вызовы используют один универсальный шаблон
    cout << "Int max: " << findMax(integers, 6) << endl;
    cout << "Double max: " << findMax(doubles, 4) << endl;
    cout << "Float max: " << findMax(floates, 3) << endl;

    //recursionFunction(0);

    cout << factorialIterational(5) << '\n';
    cout << factorialRecursion(5) << '\n';

    cout << fibonacci(5) << '\n';
}

int findMax(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

double findMax(double num1, double num2, double num3) {
    return (num1 > num2) ?
        ((num1 > num3) ? num1 : num3) :
        ((num2 > num3) ? num2 : num3);
}
