
#include <iostream>
#include <Windows.h>
#include "Dog_2.h"

using namespace std;

/*
class Dog {
private:
    char* name;
    int age;
    float weight;
    int id;

    static int nextId;
public:
    Dog(const char* nameP, int ageP, float weighP) : age(ageP), weight(weighP), id(nextId) {
        name = new char[strlen(nameP) + 1];
        strcpy_s(name, strlen(nameP) + 1, nameP);

        nextId++;
    }

    ~Dog() {
        if (name != nullptr) {
            delete[] name;
        }
    }

    void Bark() const{
        cout << "BARK-BARK" << '\n';
    }

    void PrintDog() const{ // Константный метод, он используется ВСЕГДА, когда не изменяются данные в методе
        // this->name = new char[10];
        cout << "Name: " << this->name << "\nAge: " << this->age << "\nWeight: " << this->weight << "\nId: " << id << '\n';
    }

    // Методы-аксесоры
    const char* GetName() { return name; }
    int GetAge() { return age; }
    float GetWeight() { return weight; }

    static int GetNextId() {
        // cout << this->name << '\n';
        return Dog::nextId;
    }

    Dog& SetName(const char* newName) {
        if (name != nullptr) {
            delete[] name;
        }

        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);

        return *this;
    }

    Dog& SetAge(int Newage) {
        age = Newage;
        return *this;
    }

    Dog& SetWeight(float Newweight) {
        weight = Newweight;
        return *this;
    }
};

int Dog::nextId = 1;

*/



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*
    Dog dog = Dog("Yaroslav", 1, 24.5);
    Dog dog2 = Dog("Kaducei", 7, 65.0);

    dog.PrintDog();

    cout << dog.GetName() << '\n';
    cout << dog2.GetName() << '\n';

    dog.SetName("Mykyta").SetAge(10).SetWeight(33.3);

    dog.PrintDog();
    dog2.PrintDog();
    */

    Dog_2 dog = Dog_2("Yaroslav", 1, 24.5);
    Dog_2 dog2 = Dog_2("Kaducei", 7, 65.0);

    dog.PrintDog();

    cout << dog.GetName() << '\n';
    cout << dog2.GetName() << '\n';

    dog.SetName("Mykyta").SetAge(10).SetWeight(33.3);

    dog.PrintDog();
    dog2.PrintDog();
}

