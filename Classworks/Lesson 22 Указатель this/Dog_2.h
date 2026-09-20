#pragma once

class Dog_2
{
private:
    char* name;
    int age;
    float weight;
    int id;

    static int nextId;

public:
    // Только объявляем конструктор и деструктор
    Dog_2(const char* nameP, int ageP, float weighP);
    ~Dog_2();

    void Bark() const;
    void PrintDog() const;

    // Геттеры (оставляем только объявление, реализацию переносим в .cpp)
    const char* GetName() const;
    int GetAge() const;
    float GetWeight() const;

    // Статический метод (static пишется только тут!)
    static int GetNextId();

    // Сеттеры
    Dog_2& SetName(const char* newName);
    Dog_2& SetAge(int Newage);
    Dog_2& SetWeight(float Newweight); // Добавлена точка с запятой
}; // Добавлена точка с запятой
