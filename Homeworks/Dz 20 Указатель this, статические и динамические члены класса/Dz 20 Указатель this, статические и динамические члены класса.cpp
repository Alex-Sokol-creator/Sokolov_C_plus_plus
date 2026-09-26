
#include <iostream>
#include <Windows.h>
#include "Player.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "--- 1. ПРОВЕРКА СТАТИЧЕСКОГО СЧЕТЧИКА НА СТАРТЕ ---\n";
    cout << "Всего игроков на сервере: " << Player::GetAmountOfPlayers() << '\n';

    cout << "--- 2. СОЗДАНИЕ ИГРОКОВ РАЗНЫМИ КОНСТРУКТОРАМИ ---\n";
    Player player1;
    Player player2("Aragorn", 80, 5);

    player1.printStats();
    player2.printStats();
    cout << "Всего игроков на сервере: " << Player::GetAmountOfPlayers() << '\n';

    cout << "--- 3. ТЕСТИРОВАНИЕ ИГРОВОЙ ЛОГИКИ ---\n";
    cout << "Aragorn получил 30 единиц урона...\n";
    player2.takeDamage(30);
    cout << "Текущее здоровье: " << player2.GetHealth() << " HP\n";

    cout << "Лечим Aragorn на 100 единиц (проверка лимита в 100 HP)...\n";
    player2.heal(100);
    cout << "Текущее здоровье: " << player2.GetHealth() << " HP\n";

    cout << "Повышаем уровень первому игроку...\n";
    player1.levelUp();
    cout << "Новый уровень player1: " << player1.GetLevel() << '\n';

    cout << "--- 4. ТЕСТИРОВАНИЕ СЕТТЕРА ИМЕНИ (ДИНАМИЧЕСКАЯ ПАМЯТЬ) ---\n";
    cout << "Меняем имя первому игроку с 'Unknown' на 'Legolas'...\n";
    player1.SetNickname("Legolas");
    player1.printStats();
    cout << '\n';

    cout << "--- 5. ПРОВЕРКА РАБОТЫ ДЕСТРУКТОРА И СЧЕТЧИКА ---\n";
    cout << "Игроков до создания временного персонажа: " << Player::GetAmountOfPlayers() << '\n';
    {
        Player tempPlayer("Gimli", 100, 10);
        cout << "Игроков внутри блока { }: " << Player::GetAmountOfPlayers() << '\n';
    }

    cout << "Игроков после закрытия блока (Gimli удален): " << Player::GetAmountOfPlayers() << '\n';

    cout << "Программа завершена. Остальные игроки удалятся при закрытии...\n";

}

