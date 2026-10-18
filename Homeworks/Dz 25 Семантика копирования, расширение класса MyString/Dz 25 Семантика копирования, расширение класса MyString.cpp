
#include <iostream>
#include <Windows.h>
#include "MyString.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	std::cout << "--- operator+ ---\n";
	MyString a("Hello, ");
	MyString b("world!");
	MyString c = a + b;          
	std::cout << c << std::endl;

	std::cout << "\n--- move constructor ---\n";
	MyString d = std::move(c);  
	std::cout << "d = " << d << std::endl;
	std::cout << "c length after move = " << c.GetMyStringLength() << std::endl;

	std::cout << "\n--- move assignment ---\n";
	MyString e;
	e = MyString("temporary");
	std::cout << "e = " << e << std::endl;

	std::cout << "\n--- move assignment from named object ---\n";
	MyString f("to be moved");
	e = std::move(f);      
	std::cout << "e = " << e << std::endl;
	std::cout << "f length after move = " << f.GetMyStringLength() << std::endl;  

	std::cout << "\n--- operator[] ---\n";
	std::cout << "d[0] = " << d[0] << std::endl;
	d[0] = 'J';                  
	std::cout << "d after change = " << d << std::endl;
}

