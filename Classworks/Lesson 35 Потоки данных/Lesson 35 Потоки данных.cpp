
#include <fstream>
#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::fstream f;

    f.open("test.txt", std::ios_base::app);

    f << "hello, world\n";
    // f.write("hello, world", strlen("hello, world"));

    f.close();

    f.open("test.txt", std::ios_base::in);

    char buffer[255];
    f.read(buffer, 255);

    buffer[f.gcount()] = '\0';

    std::cout << buffer << '\n';
}

