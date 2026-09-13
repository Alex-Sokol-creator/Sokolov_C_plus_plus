
#include <iostream>
#include <Windows.h>

#define MAX_NAME_LEN 50

using namespace std;

class Monkey {
private:
    char* name = nullptr;
    int age;
public:
    //Monkey() {

    //}

    
    //Monkey() {
    //    SetName("Jhon");
    //    SetAge(1);
    //}

    //Monkey(const char* initialName) {
    //    SetName(initialName);
    //    SetAge(1);
    //}

    //Monkey(int initialAge) {
    //    SetName("Jhon");
    //    SetAge(initialAge);
    //}

    //Monkey(const char* initialName, int initialAge) {
    //    SetName(initialName);
    //    SetAge(initialAge);
    //}
    

    Monkey() : Monkey("Jhon",1){ }
    Monkey(const char* initialName) : Monkey(initialName, 1){ }
    Monkey(int initialAge) : Monkey("Jhon",initialAge){ }
    
    Monkey(const char* initialName, int initialAge) : age(initialAge){
        SetName(initialName);
    }

    ~Monkey() {
        cout << name << " died :(" << '\n';
        if (name != nullptr) {
            delete[] name;
        }
    }

    void SetName(const char* newName) {
        if (newName == nullptr) {
            strcpy_s(name, strlen("Jhon"), "Jhon");
        }
        else {
            if (name != nullptr) {
                delete[] name;
            }
            name = new char[strlen(newName) + 1];
            strcpy_s(name, strlen(newName) + 1, newName);
        }
    }
    void SetAge(int newAge) {
        age = age < newAge ? newAge : age;
    }

    const char* const GetName() {
        return name;
    }
    int GetAge() {
        return age;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Monkey monkey1 = Monkey("Sasha", 17);
    Monkey monkey2;

    // monkey1.SetName("Sasha");

    // cout << monkey1.GetName() << '\n';

    // cout << monkey1.GetAge() << '\n';

    cout << monkey2.GetName() << '\n';

    cout << monkey2.GetAge() << '\n';

    Monkey* dynamicMonkey = new Monkey("CyberKing", 13);

    delete dynamicMonkey;

    Monkey* monkeys = new Monkey[3];
    for (int i = 0; i < 3; i++) {
        cout << monkeys[i].GetName() << ' ' << monkeys[i].GetAge() << '\n';
    }
    delete[] monkeys;
}

