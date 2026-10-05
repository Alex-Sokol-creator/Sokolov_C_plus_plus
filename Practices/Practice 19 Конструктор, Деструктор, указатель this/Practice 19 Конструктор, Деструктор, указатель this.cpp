
#include <iostream>
#include <Windows.h>

using namespace std;

struct Birthday {
    int day;
    int month;
    int year;
};

class Student {
private:
    char* name;
    char* surname;
    char* father_name;
    Birthday birthday;
    long long phone;
    char* Student_city;
    char* Student_country;
    char* Education_center;
    char* Education_city;
    char* Education_country;
    char* Group;
public:
    Student() : name(nullptr), surname(nullptr), father_name(nullptr), Student_city(nullptr), Student_country(nullptr), Education_center(nullptr),
        Education_city(nullptr), Education_country(nullptr), Group(nullptr){}

    Student(const char* name, const char* surname, const char* father_name, Birthday birthday, long long phone,
        const char* Student_city, const char* Student_country, const char* Education_center, const char* Education_city, const char* Education_country, const char* group)
        : name(nullptr), surname(nullptr), father_name(nullptr), Student_city(nullptr), Student_country(nullptr), Education_center(nullptr),
        Education_city(nullptr), Education_country(nullptr), Group(nullptr) {
        SetName(name);
        SetSurname(surname);
        SetFather_name(father_name);
        SetBirthday(birthday.day, birthday.month, birthday.year);
        SetPhone(phone);
        SetStudentCity(Student_city);
        SetStudentCountry(Student_country);
        SetEducationCenter(Education_center);
        SetEducationCity(Education_city);
        SetEducationCountry(Education_country);
        SetGroup(group);
    }

    ~Student() {
        if (name != nullptr) {
            delete[] name;
        }
        if (surname != nullptr) {
            delete[] surname;
        }
        if (father_name != nullptr) {
            delete[] father_name;
        }
        if (Student_city != nullptr) {
            delete[] Student_city;
        }
        if (Student_country != nullptr) {
            delete[] Student_country;
        }
        if (Education_center != nullptr) {
            delete[] Education_center;
        }
        if (Education_city != nullptr) {
            delete[] Education_city;
        }
        if (Education_country != nullptr) {
            delete[] Education_country;
        }
        if (Group != nullptr) {
            delete[] Group;
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

    void SetBirthday(int day, int month, int year) {
        birthday.day = day;
        birthday.month = month;
        birthday.year = year;
    }

    void SetPhone(long long phone) {
        this->phone = phone;
    }

    void SetStudentCity(const char* StudentCity) {
        if (Student_city != nullptr) {
            delete[] Student_city;
        }
        Student_city = new char[strlen(StudentCity) + 1];
        strcpy_s(Student_city, strlen(StudentCity) + 1, StudentCity);
    }

    void SetStudentCountry(const char* StudentCountry) {
        if (Student_country != nullptr) {
            delete[] Student_country;
        }
        Student_country = new char[strlen(StudentCountry) + 1];
        strcpy_s(Student_country, strlen(StudentCountry) + 1, StudentCountry);
    }

    void SetEducationCenter(const char* EducationCenter) {
        if (Education_center != nullptr) {
            delete[] Education_center;
        }
        Education_center = new char[strlen(EducationCenter) + 1];
        strcpy_s(Education_center, strlen(EducationCenter) + 1, EducationCenter);
    }

    void SetEducationCity(const char* EducationCity) {
        if (Education_city != nullptr) {
            delete[] Education_city;
        }
        Education_city = new char[strlen(EducationCity) + 1];
        strcpy_s(Education_city, strlen(EducationCity) + 1, EducationCity);
    }

    void SetEducationCountry(const char* EducationCountry) {
        if (Education_country != nullptr) {
            delete[] Education_country;
        }
        Education_country = new char[strlen(EducationCountry) + 1];
        strcpy_s(Education_country, strlen(EducationCountry) + 1, EducationCountry);
    }

    void SetGroup(const char* group) {
        if (Group != nullptr) {
            delete[] Group;
        }
        Group = new char[strlen(group) + 1];
        strcpy_s(Group, strlen(group) + 1, group);
    }

    const char* GetName() const { return name; }
    const char* GetSurname() const { return surname; }
    const char* GetFather_name() const { return father_name; }
    const char* GetStudentCity() const { return Student_city; }
    const char* GetStudentCountry() const { return Student_country; }
    const char* GetEducationCenter() const { return Education_center; }
    const char* GetEducationCity() const { return Education_city; }
    const char* GetEducationCountry() const { return Education_country; }
    const char* GetGroup() const { return Group; }
    long long GetPhone() const { return phone; }
    Birthday GetBirthday() const { return birthday; }

    void PrintStudent() {
        cout << "Имя: " << name << "\nФамилия: " << surname << "\nОтчество: " << father_name << "\nДата рождения: "
            << birthday.day << "." << birthday.month << "." << birthday.year << "\nНомер телефона: " << phone
            << "\nГород студента: " << Student_city << "\nСтрана студента: " << Student_country
            << "\nОбразовательное учреждение: " << Education_center << "\nГород учреждения: "
            << Education_city << "\nСтрана учреждения: " << Education_country << "\nГруппа: " << Group << '\n';
    }
};

class Group {
private:
    Student* students;
    int size;
    char* group_name;
public:
    Group() : students(nullptr), size(0), group_name() {}

    Group(Student* new_students, int size, char* group_name) {
        this->size = size;
        if (group_name != nullptr) {
            this->group_name = new char[strlen(group_name) + 1];
            strcpy_s(this->group_name, strlen(group_name) + 1, group_name);
        }
        else {
            this->group_name = nullptr;
        }
        if (new_students != nullptr && size > 0) {
            this->students = new Student[size];
            for (int i = 0; i < size; i++) {
                this->students[i].SetName(new_students[i].GetName());
                this->students[i].SetSurname(new_students[i].GetSurname());
                this->students[i].SetFather_name(new_students[i].GetFather_name());
                this->students[i].SetBirthday(new_students[i].GetBirthday().day, new_students[i].GetBirthday().month, new_students[i].GetBirthday().year);
                this->students[i].SetPhone(new_students[i].GetPhone());
                this->students[i].SetStudentCity(new_students[i].GetStudentCity());
                this->students[i].SetStudentCountry(new_students[i].GetStudentCountry());
                this->students[i].SetEducationCenter(new_students[i].GetEducationCenter());
                this->students[i].SetEducationCity(new_students[i].GetEducationCity());
                this->students[i].SetEducationCountry(new_students[i].GetEducationCountry());
                this->students[i].SetGroup(new_students[i].GetGroup());
            }
        }
        else {
            this->students = nullptr;
            this->size = 0;
        }
    }

    ~Group() {
        if (students != nullptr) {
            delete[] students;
        }
    }

    void AddStudent(Student& newStudent) {
        Student* students_new = new Student[size + 1];
        for (int i = 0; i < size; i++) {
            students_new[i].SetName(students[i].GetName());
            students_new[i].SetSurname(students[i].GetSurname());
            students_new[i].SetFather_name(students[i].GetFather_name());
            students_new[i].SetBirthday(students[i].GetBirthday().day, students[i].GetBirthday().month, students[i].GetBirthday().year);
            students_new[i].SetPhone(students[i].GetPhone());
            students_new[i].SetStudentCity(students[i].GetStudentCity());
            students_new[i].SetStudentCountry(students[i].GetStudentCountry());
            students_new[i].SetEducationCenter(students[i].GetEducationCenter());
            students_new[i].SetEducationCity(students[i].GetEducationCity());
            students_new[i].SetEducationCountry(students[i].GetEducationCountry());
            students_new[i].SetGroup(students[i].GetGroup());
        }
        students_new[size].SetName(newStudent.GetName());
        students_new[size].SetSurname(newStudent.GetSurname());
        students_new[size].SetFather_name(newStudent.GetFather_name());
        students_new[size].SetBirthday(newStudent.GetBirthday().day, newStudent.GetBirthday().month, newStudent.GetBirthday().year);
        students_new[size].SetPhone(newStudent.GetPhone());
        students_new[size].SetStudentCity(newStudent.GetStudentCity());
        students_new[size].SetStudentCountry(newStudent.GetStudentCountry());
        students_new[size].SetEducationCenter(newStudent.GetEducationCenter());
        students_new[size].SetEducationCity(newStudent.GetEducationCity());
        students_new[size].SetEducationCountry(newStudent.GetEducationCountry());
        students_new[size].SetGroup(newStudent.GetGroup());
        if (students != nullptr) {
            delete[] students;
        }
        students = students_new;
        size++;
    }

    void DeleteStudent(int index) {
        while (index < 0 || index >= size) {
            cout << "Такой индекс недоступен, введите другой: ";
            cin >> index;
        }
        Student* students_new = new Student[size - 1];
        for (int i = 0; i < index; i++) {
            students_new[i].SetName(students[i].GetName());
            students_new[i].SetSurname(students[i].GetSurname());
            students_new[i].SetFather_name(students[i].GetFather_name());
            students_new[i].SetBirthday(students[i].GetBirthday().day, students[i].GetBirthday().month, students[i].GetBirthday().year);
            students_new[i].SetPhone(students[i].GetPhone());
            students_new[i].SetStudentCity(students[i].GetStudentCity());
            students_new[i].SetStudentCountry(students[i].GetStudentCountry());
            students_new[i].SetEducationCenter(students[i].GetEducationCenter());
            students_new[i].SetEducationCity(students[i].GetEducationCity());
            students_new[i].SetEducationCountry(students[i].GetEducationCountry());
            students_new[i].SetGroup(students[i].GetGroup());
        }
        for (int i = index; i < size - 1; i++) {
            students_new[i].SetName(students[i + 1].GetName());
            students_new[i].SetSurname(students[i + 1].GetSurname());
            students_new[i].SetFather_name(students[i + 1].GetFather_name());
            students_new[i].SetBirthday(students[i + 1].GetBirthday().day, students[i + 1].GetBirthday().month, students[i + 1].GetBirthday().year);
            students_new[i].SetPhone(students[i + 1].GetPhone());
            students_new[i].SetStudentCity(students[i + 1].GetStudentCity());
            students_new[i].SetStudentCountry(students[i + 1].GetStudentCountry());
            students_new[i].SetEducationCenter(students[i + 1].GetEducationCenter());
            students_new[i].SetEducationCity(students[i + 1].GetEducationCity());
            students_new[i].SetEducationCountry(students[i + 1].GetEducationCountry());
            students_new[i].SetGroup(students[i + 1].GetGroup());
        }
        if (students != nullptr) {
            delete[] students;
        }
        students = students_new;
        size--;
    }

    void SearchStudent(const char* nameP, const char* surnameP, const char* father_nameP) {
        int founds = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(students[i].GetName(), nameP) != 0) {
                continue;
            }
            else {
                if (strcmp(students[i].GetSurname(), surnameP) != 0) {
                    continue;
                }
                else {
                    if (strcmp(students[i].GetFather_name(), father_nameP) != 0) {
                        continue;
                    }
                    else {
                        founds = 1;
                        cout << "Студент найден, у него индекс в списке: " << i << '\n';
                    }
                }
            }
        }
        if (founds == 0) {
            cout << "К сожалению, такого студента нет в списке\n";
        }
    }

    void PrintStudents() {
        cout << "Вот список всех студентов: \n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " студент: \n";
            cout << "Имя: " << students[i].GetName() << "\nФамилия: " << students[i].GetSurname() << "\nОтчество: " << students[i].GetFather_name()
                << "\nДата рождения: " << students[i].GetBirthday().day << "." << students[i].GetBirthday().month << "." << students[i].GetBirthday().year
                << "\nНомер телефона: " << students[i].GetPhone() << "\nГород студента: " << students[i].GetStudentCity()
                << "\nСтрана студента: " << students[i].GetStudentCountry() << "\nОбразовательное учреждение: " << students[i].GetEducationCenter()
                << "\nГород учреждения: " << students[i].GetEducationCity() << "\nСтрана учреждения: " << students[i].GetEducationCountry()
                << "\nГруппа: " << students[i].GetGroup() << '\n';
        }
    }


    void SaveFile() {
        FILE* Practice_19_save;
        errno_t err1 = fopen_s(&Practice_19_save, "Practice_19_save.txt", "w");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            fprintf(Practice_19_save, "%d\n", size);
            for (int i = 0; i < size; i++) {
                fprintf(Practice_19_save, "%s\n", students[i].GetName());
                fprintf(Practice_19_save, "%s\n", students[i].GetSurname());
                fprintf(Practice_19_save, "%s\n", students[i].GetFather_name());
                fprintf(Practice_19_save, "%d\n", students[i].GetBirthday().day);
                fprintf(Practice_19_save, "%d\n", students[i].GetBirthday().month);
                fprintf(Practice_19_save, "%d\n", students[i].GetBirthday().year);
                fprintf(Practice_19_save, "%lld\n", students[i].GetPhone());
                fprintf(Practice_19_save, "%s\n", students[i].GetStudentCity());
                fprintf(Practice_19_save, "%s\n", students[i].GetStudentCountry());
                fprintf(Practice_19_save, "%s\n", students[i].GetEducationCenter());
                fprintf(Practice_19_save, "%s\n", students[i].GetEducationCity());
                fprintf(Practice_19_save, "%s\n", students[i].GetEducationCountry());
                fprintf(Practice_19_save, "%s\n", students[i].GetGroup());
            }
            cout << "Данные успешно записаны!\n";
        }
        fclose(Practice_19_save);
    }

    void LoadFile() {
        FILE* Practice_19_load;
        errno_t err1 = fopen_s(&Practice_19_load, "Practice_19_save.txt", "r");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            int count = 0;
            if (fscanf_s(Practice_19_load, "%d\n", &count) != 1) {
                fclose(Practice_19_load);
                return;
            }
            if (students != nullptr) {
                delete[] students;
                students = nullptr;
            }
            size = 0;
            for (int i = 0; i < count; i++) {
                char bufName[1000], bufSurname[1000], bufFather[1000];
                char bufStudentCity[1000], bufStudentCountry[1000], bufEdCenter[1000], bufEdCity[1000], bufEdCountry[1000], bufGroup[1000];
                Birthday bday = { 0, 0, 0 };
                long long phone = 0;

                fgets(bufName, 1000, Practice_19_load);
                fgets(bufSurname, 1000, Practice_19_load);
                fgets(bufFather, 1000, Practice_19_load);

                fscanf_s(Practice_19_load, "%d\n", &bday.day);
                fscanf_s(Practice_19_load, "%d\n", &bday.month);
                fscanf_s(Practice_19_load, "%d\n", &bday.year);
                fscanf_s(Practice_19_load, "%lld\n", &phone);

                fgets(bufStudentCity, 1000, Practice_19_load);
                fgets(bufStudentCountry, 1000, Practice_19_load);
                fgets(bufEdCenter, 1000, Practice_19_load);
                fgets(bufEdCity, 1000, Practice_19_load);
                fgets(bufEdCountry, 1000, Practice_19_load);
                fgets(bufGroup, 1000, Practice_19_load);

                bufName[strlen(bufName) - 1] = '\0';
                bufSurname[strlen(bufSurname) - 1] = '\0';
                bufFather[strlen(bufFather) - 1] = '\0';
                bufStudentCity[strlen(bufStudentCity) - 1] = '\0';
                bufStudentCountry[strlen(bufStudentCountry) - 1] = '\0';
                bufEdCenter[strlen(bufEdCenter) - 1] = '\0';
                bufEdCity[strlen(bufEdCity) - 1] = '\0';
                bufEdCountry[strlen(bufEdCountry) - 1] = '\0';
                bufGroup[strlen(bufGroup) - 1] = '\0';
                Student temp(bufName, bufSurname, bufFather, bday, phone, bufStudentCity, bufStudentCountry, bufEdCenter, bufEdCity, bufEdCountry, bufGroup);
                AddStudent(temp);
            }
            cout << "Данные успешно загружены\n";
        }
        fclose(Practice_19_load);
    }

    void SetGroup_Name(const char* newGroup_name) {
        if (group_name != nullptr) {
            delete[] group_name;
        }
        group_name = new char[strlen(newGroup_name) + 1];
        strcpy_s(group_name, strlen(newGroup_name) + 1, newGroup_name);
    }

    const char* GetGroup_name() const { return group_name; }

    int GetSize() const { return size; }

    Student* GetStudents() const { return students; }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Group* myGroup = nullptr;
    int choice;

    do {
        cout << "\n--- МЕНЮ ТЕСТИРОВАНИЯ КЛАССА GROUP ---\n";
        cout << "1. Создать новую группу\n";
        cout << "2. Добавить студента\n";
        cout << "3. Удалить студента\n";
        cout << "4. Отобразить информацию о студентах группы\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1) {
            if (myGroup != nullptr) {
                delete myGroup;
            }
            char gName[100];
            cout << "Введите название новой группы: ";
            cin.ignore();
            cin.getline(gName, 100);
            myGroup = new Group();
            myGroup->SetGroup_Name(gName);

            cout << "Группа \"" << myGroup->GetGroup_name() << "\" успешно создана!\n";
        }
        else if (choice == 2) {
            if (myGroup == nullptr) {
                cout << "Ошибка! Сначала необходимо создать группу (Пункт 1).\n";
                continue;
            }
            char name[100], surname[100], fname[100];
            char city[100], country[100], edCenter[100], edCity[100], edCountry[100];
            Birthday bday;
            long long phone;

            cin.ignore();
            cout << "Введите имя студента: "; cin.getline(name, 100);
            cout << "Введите фамилию: "; cin.getline(surname, 100);
            cout << "Введите отчество: "; cin.getline(fname, 100);
            cout << "День рождения (день месяц год через пробел): "; cin >> bday.day >> bday.month >> bday.year;
            cout << "Номер телефона: "; cin >> phone;
            cin.ignore();
            cout << "Город проживания студента: "; cin.getline(city, 100);
            cout << "Страна проживания студента: "; cin.getline(country, 100);
            cout << "Название учебного заведения: "; cin.getline(edCenter, 100);
            cout << "Город учебного заведения: "; cin.getline(edCity, 100);
            cout << "Страна учебного заведения: "; cin.getline(edCountry, 100);

            Student temp(name, surname, fname, bday, phone, city, country, edCenter, edCity, edCountry, myGroup->GetGroup_name());
            myGroup->AddStudent(temp);
            cout << "Студент успешно добавлен в динамический массив группы!\n";
        }
        else if (choice == 3) {
            if (myGroup == nullptr || myGroup->GetSize() == 0) {
                cout << "Ошибка! Группа пуста или еще не создана.\n";
                continue;
            }
            int index;
            cout << "Введите порядковый номер студента для удаления (1-" << myGroup->GetSize() << "): ";
            cin >> index;

            myGroup->DeleteStudent(index - 1);
            cout << "Операция удаления завершена.\n";
        }
        else if (choice == 4) {
            if (myGroup == nullptr) {
                cout << "Ошибка! Группа еще не создана.\n";
                continue;
            }
            if (myGroup->GetSize() == 0) {
                cout << "Группа \"" << myGroup->GetGroup_name() << "\" создана, но в ней пока нет студентов.\n";
            }
            else {
                myGroup->PrintStudents();
            }
        }

    } while (choice != 0);

    if (myGroup != nullptr) {
        delete myGroup;
    }

}
