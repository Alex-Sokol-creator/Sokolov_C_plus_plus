
#include <iostream>
#include <Windows.h>

using namespace std;

enum Breed {
    MaineCoon, Siamese, Sphynx
};

class Cat {
private:
    char* name = nullptr;
    int age;
    const Breed breed;
    mutable int getNameCounter = 0;
public:
    Cat(const char* name, int age,Breed breed) : age(age), breed(breed) {
        if (name != nullptr) {
            int nameSize = strlen(name) + 1;
            this->name = new char[nameSize];
            strcpy_s(this->name, nameSize, name);
        }
    }

    Cat(const Cat& other) : age(other.age), breed(other.breed) {
        if (other.name != nullptr) {
            int nameSize = strlen(other.name) + 1;
            name = new char[nameSize];
            strcpy_s(name, nameSize, other.name);
        }
    }

    ~Cat() {
        if (name != nullptr) {
            delete[] name;
        }
    }

    const char* GetName() const{
        getNameCounter++;
        return name;
    }

    int GetAge() const{
        return age;
    }

    void SetName(const char* newName) {
        if (name != nullptr) {
            delete[] name;
        }
        if (newName != nullptr) {
            int nameSize = strlen(newName) + 1;
            name = new char[nameSize];
            strcpy_s(name, nameSize, newName);
        }
    }

    void SetAge(int newAge) {
        age = newAge > age ? newAge : age;
    }

    //void SetBreed(Breed newBreed) {
    //    breed = newBreed;
    //}
};

void PrintCat(Cat cat) {
    cout << cat.GetName() << ' ' << cat.GetAge() << " y.o.\n";
}

class StringBuffer {
private:
    char* buffer;
    int capacity;
public:
    StringBuffer(int size) {
        capacity = size;
        buffer = new char[capacity];
        cout << "Buffer created with size: " << capacity << '\n';
    }
    ~StringBuffer() {
        delete[] buffer;
    }
};

void ProcessBuffer(const StringBuffer& buf) {
    cout << "Processing buffer...\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // cout << 14 + 0.67 << '\n';

    // ProcessBuffer(40);

    StringBuffer myBuf(100);
    ProcessBuffer(myBuf);

    // const Cat cat = Cat("Catl", 10, MaineCoon);

    // char* name = cat.GetName();
    // name[1] = 'C';

    // cout << cat.GetName() << '\n';
    // PrintCat(cat);
}

