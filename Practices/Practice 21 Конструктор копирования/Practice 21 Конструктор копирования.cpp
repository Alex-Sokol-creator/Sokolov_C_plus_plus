
#include <iostream>
#include <Windows.h>
#include "MyString.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Test 1: Default Constructor ===" << endl;
    MyString strEmpty;
    cout << "Length: " << strEmpty.GetMyStringLength() << endl;
    if (strEmpty.c_str() == nullptr) {
        cout << "String pointer is correctly set to nullptr." << endl;
    }
    cout << endl;

    cout << "=== Test 2: Constructor with parameters ===" << endl;
    MyString strHello("Hello, C++ World!");
    cout << "Text: " << strHello.c_str() << endl;
    cout << "Length: " << strHello.GetMyStringLength() << endl;
    cout << endl;

    cout << "=== Test 3: Copy Constructor ===" << endl;
    MyString strCopy = strHello;
    cout << "Copied Text: " << strCopy.c_str() << endl;
    cout << "Copied Length: " << strCopy.GetMyStringLength() << endl;
    cout << endl;

    cout << "=== Test 4: Copying an Empty Object ===" << endl;
    MyString strEmptyCopy = strEmpty;
    cout << "Empty Copy Length: " << strEmptyCopy.GetMyStringLength() << endl;
    if (strEmptyCopy.c_str() == nullptr) {
        cout << "Empty copy pointer is also nullptr. Protection works!" << endl;
    }
    cout << endl;
}

