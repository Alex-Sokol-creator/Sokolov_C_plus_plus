
#include <iostream>
#include <Windows.h>
#include <string>
#include "CyberPunkClasses.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Netrunner player(5, 100);

    VendingMachine vendingMachine;
    SmartDoor door;

    CyborgGuard guard(100);

    std::cout << "=== Взлом умных дверей ===\n";
    player.breachProtocol(door);

    std::cout << "\n=== Взлом торгового автомата ===\n";
    player.breachProtocol(vendingMachine);

    std::cout << "\n=== Взлом киборга ===\n";
    player.breachProtocol(guard);

    if (guard.isHacked()) {
        std::cout << "Киборг успешно отключен!\n";
    }
    else {
        std::cout << "Недостаточный уровень навыка для отключения киборга!\n";
    }

    std::cout << "\nЗдоровье хакера: " << player.GetHealth() << '\n';
}

