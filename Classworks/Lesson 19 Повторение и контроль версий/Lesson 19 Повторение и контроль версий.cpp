
#include <iostream>
#include <Windows.h>

using namespace std;

int GlobalVar = 10;

int sum(int a, int b) {
    return a + b;
}

void swapValues(int* first, int* second) {
    int temp = *second;
    *second = *first;
    *first = temp;
}

void PrintArr(int* arr, int size) {
    /*
    *arr = 12;

    arr = &size;
    */

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

void swapValuesByLinks(int& first, int& second) {
    int temp = second;
    second = first;
    first = temp;
}

void printUserData(const User& user) {

}

struct Date {
    int day, month, year;
};

struct User {
    char* firstname;
    char* secondName;
    char* city;
    char* country;
    char* email;
    char* username;
    char* password;
    Date birthday;
};

int main()
{
    /*
    int localvar = 12;

    int* ptr = &GlobalVar;

    cout << ptr << '\n';

    cout << *ptr << '\n';
    *ptr = 16;
    cout << GlobalVar << '\n';
    cout << "Hello World!\n";

    double* ptrD = nullptr;
    if (ptrD != nullptr) {
        cout << *ptrD << '\n';
    }
    else {
        cout << "Pointer is null\n";
    }

    double d = 45.65;
    double d2 = 65.34;
    double* const ptrD2 = &d;

    // ptrD2 = &d2;
    *ptrD2 = 78.65;

    const int* ptrConst = nullptr;

    ptrConst = &localvar;

    //*ptrConst = 56;

    const double constvalue = 3.14;
    const double* ptrReg = &constvalue;

    cout << *ptrConst << '\n';
    */

    int f = 10, s = 12;
    swapValues(&f, &s);
    cout << f << ' ' << s << '\n';

    int arr[] = { 10,12,34,45 };
    PrintArr(arr, 4);

    int GradesCount;

    cout << "Enter grades count: ";
    cin >> GradesCount;

    int* gradesArr = new int[GradesCount];

    delete[] gradesArr;

    int& ref = GradesCount;
    cout << '\n' << GradesCount << '\n';

    swapValuesByLinks(f, s);
}

