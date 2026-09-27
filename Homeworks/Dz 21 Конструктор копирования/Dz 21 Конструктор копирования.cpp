
#include <iostream>
#include <Windows.h>
#include "Inventory.h"
#include "Item.h"
#include "MyString.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Тест 1: Создание предметов и заполнение инвентаря ===" << endl;

    Inventory myInventory(3);

    myInventory.setItem(0, Item("Icebringer", Weapon));
    myInventory.setItem(1, Item("Healing Elixir", Potion));
    myInventory.setItem(2, Item("Fresh Bread", Food));

    myInventory.print();
    cout << endl;

    cout << "=== Тест 2: Проверка конструктора копирования инвентаря ===" << endl;

    Inventory duplicatedInventory = myInventory;

    cout << "--- Содержимое скопированного инвентаря: ---" << endl;
    duplicatedInventory.print();
    cout << endl;

    cout << "=== Тест 3: Проверка выхода за границы массива ===" << endl;
    myInventory.setItem(5, Item("Broken Item", None));

    cout << "\nПрограмма успешно завершена без сбоев в памяти!" << endl;

}

