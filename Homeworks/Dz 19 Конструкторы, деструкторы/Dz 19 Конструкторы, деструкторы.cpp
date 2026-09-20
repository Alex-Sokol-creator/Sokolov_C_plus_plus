
#include <iostream>
#include <Windows.h>

using namespace std;

class Phone_Book {
private:
    char* name;
    char* surname;
    char* father_name;
    long long home_phone_number;
    long long work_phone_number;
    long long mobile_phone_number;
    char* additional_info;
public:
    Phone_Book() : name(nullptr), surname(nullptr), father_name(nullptr),
        additional_info(nullptr), home_phone_number(0),
        work_phone_number(0), mobile_phone_number(0) {
    }

    Phone_Book(const char* initialName, const char* initialSurname, const char* initialFather_name, const char* initialAdd_info, long long initial_home_num,
        long long initial_work_num, long long initial_mobile_num) : name(nullptr), surname(nullptr), father_name(nullptr), additional_info(nullptr) {
        SetName(initialName);
        SetSurname(initialSurname);
        SetFather_name(initialFather_name);
        SetHomePhone(initial_home_num);
        SetWorkPhone(initial_work_num);
        SetMobilePhone(initial_mobile_num);
        SetAddInfo(initialAdd_info);
    }

    ~Phone_Book() {
        if (name != nullptr) {
            delete[] name;
        }
        if (surname != nullptr) {
            delete[] surname;
        }
        if (father_name != nullptr) {
            delete[] father_name;
        }
        if (additional_info != nullptr) {
            delete[] additional_info;
        }
    }


    void SetName(const char* newName) {
        if (name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }

    void SetSurname(const char* newSurname) {
        if (surname != nullptr) {
            delete[] surname;
        }
        surname = new char[strlen(newSurname) + 1];
        strcpy_s(surname, strlen(newSurname) + 1, newSurname);
    }

    void SetFather_name(const char* newFather_name) {
        if (father_name != nullptr) {
            delete[] father_name;
        }
        father_name = new char[strlen(newFather_name) + 1];
        strcpy_s(father_name, strlen(newFather_name) + 1, newFather_name);
    }

    void SetHomePhone(long long number) { home_phone_number = number; }

    void SetWorkPhone(long long number) { work_phone_number = number; }

    void SetMobilePhone(long long number) { mobile_phone_number = number; }

    void SetAddInfo(const char* AddInfo) {
        if (additional_info != nullptr) {
            delete[] additional_info;
        }
        additional_info = new char[strlen(AddInfo) + 1];
        strcpy_s(additional_info, strlen(AddInfo) + 1, AddInfo);
    }


    const char* GetName() const { return name; }
    const char* GetSurname() const { return surname; }
    const char* GetFatherName() const { return father_name; }
    const char* GetAddInfo() const { return additional_info; }
    long long GetHomePhone() { return home_phone_number; }
    long long GetWorkPhone() { return work_phone_number; }
    long long GetMobilePhone() { return mobile_phone_number; }
};

class Phones_container {
private:
    Phone_Book* abonents;
    int size;
public:
    Phones_container() : abonents(nullptr), size(0) {}

    ~Phones_container() {
        if (abonents != nullptr) {
            delete[] abonents;
        }
    }

    void AddAbonent(Phone_Book& newAbonent) {
        Phone_Book* abonents_new = new Phone_Book[size + 1];
        for (int i = 0; i < size; i++) {
            abonents_new[i] = abonents[i];
        }
        abonents_new[size] = newAbonent;
        if (abonents != nullptr) {
            delete[] abonents;
        }
        abonents = abonents_new;
        size++;
    }

    void DeleteAbonent(int index) {
        while (index < 0 || index >= size) {
            cout << "Такой индекс недоступен, введите другой: ";
            cin >> index;
        }
        Phone_Book* abonents_new = new Phone_Book[size - 1];
        for (int i = 0; i < index; i++) {
            abonents_new[i] = abonents[i];
        }
        for (int i = index; i < size - 1; i++) {
            abonents_new[i] = abonents[i + 1];
        }
        if (abonents != nullptr) {
            delete[] abonents;
        }
        abonents = abonents_new;
        size--;
    }

    void SearchAbonent(const char* nameP, const char* surnameP, const char* father_nameP) {
        int founds = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(abonents[i].GetName(), nameP) != 0) {
                continue;
            }
            else {
                if (strcmp(abonents[i].GetSurname(), surnameP) != 0) {
                    continue;
                }
                else {
                    if (strcmp(abonents[i].GetFatherName(), father_nameP) != 0) {
                        continue;
                    }
                    else {
                        founds = 1;
                        cout << "Абонент найден, у него индекс в списке: " << i << '\n';
                    }
                }
            }
        }
        if (founds == 0) {
            cout << "К сожалению, такого абонента нет в списке\n";
        }
    }

    void PrintAbonents() {
        cout << "Вот список всех абонентов: \n";
        for (int i = 0; i < size; i++) {
            cout << i << " абонент: \n";
            cout << "Имя: " << abonents[i].GetName() << "\nФамилия: " << abonents[i].GetSurname() << "\nОтчество: " << abonents[i].GetFatherName()
                << "\nНомер домашнего телефона: " << abonents[i].GetHomePhone() << "\nНомер рабочего телефона: " << abonents[i].GetWorkPhone()
                << "\nНомер мобильного телефона: " << abonents[i].GetMobilePhone() << "\nДополнительная информация: " << abonents[i].GetAddInfo() << '\n';
        }
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


}
