
#include <iostream>
#include <Windows.h>
#include <string>

class Character {
protected:
    std::string name;
    double health;
    double shield;
public:
    Character(std::string name) : name(name), health(100), shield(50) {}

    void takeDamage(int amount) {
        if (shield >= amount) {
            shield -= amount;
        }
        else {
            amount -= shield;
            shield = 0;
            health -= amount;
        }
        std::cout << "После получения урона, у персонажа осталось: " << health << " здоровья и " << shield << " щита\n";
    }
};

class Recon : public Character {
public:
    Recon(std::string name) : Character(name) {}

    void scanArea() {
        std::cout << name << " сканирует местность: обнаружено 2 врага!\n";
    }
};

class Support : public Character {
public:
    Support(std::string name) : Character(name) {}

    void dropHeal() {
        std::cout << "Солдат поддержки " << name << " лечит союзников!\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Recon MyRecon = Recon("Ivan Franko");
    Support MySupport = Support("Taras Shevchenko");

    MyRecon.takeDamage(30);
    MySupport.takeDamage(80);
    MyRecon.scanArea();
    MySupport.dropHeal();
}

