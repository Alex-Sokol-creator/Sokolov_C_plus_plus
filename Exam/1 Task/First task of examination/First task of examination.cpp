
#include <iostream>
#include <Windows.h>
#include "SystemLogic.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SystemLogic programm;
    programm.Run();
}

