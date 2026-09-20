
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
    long long GetHomePhone() const { return home_phone_number; }
    long long GetWorkPhone() const { return work_phone_number; }
    long long GetMobilePhone() const { return mobile_phone_number; }
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
            abonents_new[i].SetName(abonents[i].GetName());
            abonents_new[i].SetSurname(abonents[i].GetSurname());
            abonents_new[i].SetFather_name(abonents[i].GetFatherName());
            abonents_new[i].SetAddInfo(abonents[i].GetAddInfo());
            abonents_new[i].SetHomePhone(abonents[i].GetHomePhone());
            abonents_new[i].SetWorkPhone(abonents[i].GetWorkPhone());
            abonents_new[i].SetMobilePhone(abonents[i].GetMobilePhone());
        }
        abonents_new[size].SetName(newAbonent.GetName());
        abonents_new[size].SetSurname(newAbonent.GetSurname());
        abonents_new[size].SetFather_name(newAbonent.GetFatherName());
        abonents_new[size].SetAddInfo(newAbonent.GetAddInfo());
        abonents_new[size].SetHomePhone(newAbonent.GetHomePhone());
        abonents_new[size].SetWorkPhone(newAbonent.GetWorkPhone());
        abonents_new[size].SetMobilePhone(newAbonent.GetMobilePhone());
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
            abonents_new[i].SetName(abonents[i].GetName());
            abonents_new[i].SetSurname(abonents[i].GetSurname());
            abonents_new[i].SetFather_name(abonents[i].GetFatherName());
            abonents_new[i].SetAddInfo(abonents[i].GetAddInfo());
            abonents_new[i].SetHomePhone(abonents[i].GetHomePhone());
            abonents_new[i].SetWorkPhone(abonents[i].GetWorkPhone());
            abonents_new[i].SetMobilePhone(abonents[i].GetMobilePhone());
        }
        for (int i = index; i < size - 1; i++) {
            abonents_new[i].SetName(abonents[i + 1].GetName());
            abonents_new[i].SetSurname(abonents[i + 1].GetSurname());
            abonents_new[i].SetFather_name(abonents[i + 1].GetFatherName());
            abonents_new[i].SetAddInfo(abonents[i + 1].GetAddInfo());
            abonents_new[i].SetHomePhone(abonents[i + 1].GetHomePhone());
            abonents_new[i].SetWorkPhone(abonents[i + 1].GetWorkPhone());
            abonents_new[i].SetMobilePhone(abonents[i + 1].GetMobilePhone());
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
            cout << i + 1 << " абонент: \n";
            cout << "Имя: " << abonents[i].GetName() << "\nФамилия: " << abonents[i].GetSurname() << "\nОтчество: " << abonents[i].GetFatherName()
                << "\nНомер домашнего телефона: " << abonents[i].GetHomePhone() << "\nНомер рабочего телефона: " << abonents[i].GetWorkPhone()
                << "\nНомер мобильного телефона: " << abonents[i].GetMobilePhone() << "\nДополнительная информация: " << abonents[i].GetAddInfo() << '\n';
        }
    }


    void SaveFile() {
        FILE* Dz_19_save;
        errno_t err1 = fopen_s(&Dz_19_save, "Dz_19_save.txt", "w");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            fprintf(Dz_19_save, "%d\n", size);
            for (int i = 0; i < size; i++) {
                fprintf(Dz_19_save, "%s\n", abonents[i].GetName());
                fprintf(Dz_19_save, "%s\n", abonents[i].GetSurname());
                fprintf(Dz_19_save, "%s\n", abonents[i].GetFatherName());
                fprintf(Dz_19_save, "%s\n", abonents[i].GetAddInfo());
                fprintf(Dz_19_save, "%lld\n", abonents[i].GetHomePhone());
                fprintf(Dz_19_save, "%lld\n", abonents[i].GetWorkPhone());
                fprintf(Dz_19_save, "%lld\n", abonents[i].GetMobilePhone());
            }
            cout << "Данные успешно записаны!\n";
        }
        fclose(Dz_19_save);
    }

    void LoadFile() {
        FILE* Dz_19_load;
        errno_t err1 = fopen_s(&Dz_19_load, "Dz_19_save.txt", "r");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            int count = 0;
            if (fscanf_s(Dz_19_load, "%d\n", &count) != 1) {
                fclose(Dz_19_load);
                return;
            }
            if (abonents != nullptr) {
                delete[] abonents;
                abonents = nullptr;
            }
            size = 0;
            for (int i = 0; i < count; i++) {
                char bufName[1000], bufSurname[1000], bufFather[1000], bufInfo[1000];
                long long home = 0, work = 0, mobile = 0;
                fgets(bufName, 1000, Dz_19_load);
                fgets(bufSurname, 1000, Dz_19_load);
                fgets(bufFather, 1000, Dz_19_load);
                fgets(bufInfo, 1000, Dz_19_load);
                bufName[strlen(bufName) - 1] = '\0';
                bufSurname[strlen(bufSurname) - 1] = '\0';
                bufFather[strlen(bufFather) - 1] = '\0';
                bufInfo[strlen(bufInfo) - 1] = '\0';
                fscanf_s(Dz_19_load, "%lld\n", &home);
                fscanf_s(Dz_19_load, "%lld\n", &work);
                fscanf_s(Dz_19_load, "%lld\n", &mobile);
                Phone_Book temp(bufName, bufSurname, bufFather, bufInfo, home, work, mobile);
                AddAbonent(temp);
            }
            cout << "Данные успешно загружены\n";
        }
        fclose(Dz_19_load);
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Phones_container book;
    int choice = 0;

    do {
        cout << "\n===== ТЕЛЕФОННАЯ КНИГА =====\n"
            << "1. Показать всех абонентов\n"
            << "2. Добавить абонента\n"
            << "3. Удалить абонента\n"
            << "4. Найти по ФИО\n"
            << "5. Сохранить в файл\n"
            << "6. Загрузить из файла\n"
            << "0. Выход\n"
            << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            book.PrintAbonents();
        }
        else if (choice == 2) {
            char name[1000], surname[1000], father[1000], info[1000];
            long long home = 0, work = 0, mobile = 0;

            cout << "Введите имя: "; cin.getline(name, 1000);
            cout << "Введите фамилию: "; cin.getline(surname, 1000);
            cout << "Введите отчество: "; cin.getline(father, 1000);
            cout << "Введите домашний телефон: "; cin >> home;
            cout << "Введите рабочий телефон: "; cin >> work;
            cout << "Введите мобильный телефон: "; cin >> mobile;
            cin.ignore();
            cout << "Введите доп. информацию: "; cin.getline(info, 1000);

            Phone_Book temp(name, surname, father, info, home, work, mobile);
            book.AddAbonent(temp);
            cout << "Абонент добавлен!\n";
        }
        else if (choice == 3) {
            int idx;
            cout << "Введите индекс для удаления: ";
            cin >> idx;
            book.DeleteAbonent(idx);
        }
        else if (choice == 4) {
            char name[1000], surname[1000], father[1000];
            cout << "Введите имя: "; cin.getline(name, 1000);
            cout << "Введите фамилию: "; cin.getline(surname, 1000);
            cout << "Введите отчество: "; cin.getline(father, 1000);
            book.SearchAbonent(name, surname, father);
        }
        else if (choice == 5) {
            book.SaveFile();
        }
        else if (choice == 6) {
            book.LoadFile();
        }
    } while (choice != 0);
}
