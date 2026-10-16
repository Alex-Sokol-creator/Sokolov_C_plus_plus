
#include <iostream>
#include <Windows.h>
#include "MyString.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MyString empty;                      
    MyString str("Hello");               
    MyString copy(str);                  
    empty = str;                         

    str[0] = 'h';                        
    const MyString constStr("Test");     
    char ch = constStr[1];               

    std::cout << "String: " << str.c_str() << ", Char: " << ch << "\n";
}

