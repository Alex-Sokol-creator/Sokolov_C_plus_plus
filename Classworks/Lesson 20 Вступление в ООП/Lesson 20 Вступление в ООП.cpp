
#include <iostream>
#include <Windows.h>

#define MAX_NAME_LEN 30

using namespace std;

class Student {
private:
    char name[MAX_NAME_LEN];
    int assessments[5];
    int assessmentsCount = 5;

public:
    Student(const char* nameP, int assessmentsP[], int assessmentsCountP) {
        strcpy_s(name, MAX_NAME_LEN, nameP);
        for (int i = 0; i < assessmentsCount; i++) {
            assessments[i] = assessmentsP[i];
        }
    }

    int getAvgAssesment() {
        int sum = assessments[0];
        for (int i = 1; i < assessmentsCount; i++) {
            sum += assessments[i];
        }
        return sum / assessmentsCount;
    }
};

class Cat {
private:
    char nickname[MAX_NAME_LEN];
    int age;
public:
    void AskForFood() {
        while (true) {
            cout << "MIAAAAAAAAAAAAWWWWWWWW" << '\n';
        }
    }
    void MakePurr() {
        cout << "prrrr" << '\n';
    }
    void PrintCat() {
        cout << "Name: " << nickname << '\n';
        cout << "Age: " << age << '\n';
    }

    // Setters - Модификаторы
    void SetNickname(const char* newNickname) {
        strcpy_s(nickname, MAX_NAME_LEN, newNickname);
    }

    void SetAge(int newAge) {
        age = newAge > age ? newAge : age;
    }

    // Getters - инспекторы
    const char* const GetNickname() {
        return nickname;
    }
    int GetAge() {
        return age;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int assessments[5] = { 10,12,4,12,8 };
    Student student1 = Student{ "Mykola Tarasenko",assessments,5 };

    cout << student1.getAvgAssesment() << '\n';

    Cat myCat = Cat();
    myCat.SetNickname("Roma");
    myCat.SetAge(3);

    myCat.PrintCat();

    Cat mykolacat = Cat();
    mykolacat.SetNickname("Mars");
    mykolacat.SetAge(2);
    mykolacat.PrintCat();

    cout << myCat.GetNickname() << '\n';
    cout << myCat.GetAge() << '\n';
}

