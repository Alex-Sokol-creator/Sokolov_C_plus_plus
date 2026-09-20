#include "Dog_2.h"
#include <iostream>

int Dog_2::nextId = 1;

Dog_2::Dog_2(const char* nameP, int ageP, float weighP) : age(ageP), weight(weighP), id(nextId) {
    this->name = new char[strlen(nameP) + 1];
    strcpy_s(this->name, strlen(nameP) + 1, nameP);
    nextId++;
}

Dog_2::~Dog_2() {
    if (name != nullptr) {
        delete[] name;
    }
}

void Dog_2::Bark() const {
    std::cout << "BARK-BARK" << '\n';
}

void Dog_2::PrintDog() const {
    std::cout << "Name: " << this->name << "\nAge: " << this->age << "\nWeight: " << this->weight << "\nId: " << id << '\n';
}

// Реализация геттеров (хорошей практикой будет сделать их const)
const char* Dog_2::GetName() const { return name; }
int Dog_2::GetAge() const { return age; }
float Dog_2::GetWeight() const { return weight; }

// Убрано слово static перед функцией
int Dog_2::GetNextId() {
    return Dog_2::nextId;
}

Dog_2& Dog_2::SetName(const char* newName) {
    if (name != nullptr) {
        delete[] name;
    }
    name = new char[strlen(newName) + 1];
    strcpy_s(name, strlen(newName) + 1, newName);
    return *this;
}

Dog_2& Dog_2::SetAge(int Newage) {
    age = Newage;
    return *this;
}

Dog_2& Dog_2::SetWeight(float Newweight) {
    weight = Newweight;
    return *this;
}
