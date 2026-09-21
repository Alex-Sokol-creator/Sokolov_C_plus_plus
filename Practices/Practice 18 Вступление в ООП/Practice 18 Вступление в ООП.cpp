
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
    Student(const char* name, const char* surname, const char* father_name, Birthday birthday, long long phone,
        const char* Student_city, const char* Student_country,const char* Education_center, const char* Education_city, const char* Education_country, const char* group)
    : name(nullptr),surname(nullptr),father_name(nullptr),Student_city(nullptr), Student_country(nullptr), Education_center(nullptr),
        Education_city(nullptr), Education_country(nullptr),Group(nullptr){
        SetName(name);
        SetSurname(surname);
        SetFather_name(father_name);
        SetBirthday(birthday.day,birthday.month,birthday.year);
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

class Point {
private:
    double x;
    double y;
    double z;
public:
    Point() {
        SetX();
        SetY();
        SetZ();
    }

    void SetX() {
        double x;
        cout << "Введите значение Х для точки: ";
        cin >> x;
        this->x = x;
    }

    void SetY() {
        double y;
        cout << "Введите значение Y для точки: ";
        cin >> y;
        this->y = y;
    }

    void SetZ() {
        double z;
        cout << "Введите значение Z для точки: ";
        cin >> z;
        this->z = z;
    }

    void PrintPoint() {
        cout << "Координата Х: " << x << "\nКоордината Y: " << y << "\nКоордината Z: " << z << '\n';
    }

    const double GetX() const { return x; }
    const double GetY() const { return y; }
    const double GetZ() const { return z; }

    void SaveFile() {
        FILE* Pr_18_point_save;
        errno_t err1 = fopen_s(&Pr_18_point_save, "Pr_18_point_save.txt", "w");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            fprintf(Pr_18_point_save, "%f %f %f\n", x, y, z);
            cout << "Данные успешно записаны!\n";
        }
        fclose(Pr_18_point_save);
    }

    void LoadFile() {
        FILE* Pr_18_point_load;
        errno_t err1 = fopen_s(&Pr_18_point_load, "Pr_18_point_save.txt", "r");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            fscanf_s(Pr_18_point_load, "%lf %lf %lf", &x, &y, &z);
            cout << "Данные успешно загружены\n";
        }
        fclose(Pr_18_point_load);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Birthday bday = { 15, 10, 2005 };

    cout << "--- Создание студента через конструктор ---" << endl;
    Student student("Иван", "Петров", "Сергеевич", bday, 380931234567,
        "Киев", "Украина", "КНУ", "Киев", "Украина", "КН-21");

    student.PrintStudent();
    cout << "\n=========================================\n" << endl;

    cout << "--- Изменение данных (Сеттеры) ---" << endl;
    student.SetName("Александр");
    student.SetGroup("КН-22");
    student.SetBirthday(20, 11, 2004);

    student.PrintStudent();
    cout << "\n=========================================\n" << endl;

    cout << "--- Получение отдельных данных (Геттеры) ---" << endl;
    cout << "Имя студента: " << student.GetName() << endl;
    cout << "Номер группы: " << student.GetGroup() << endl;

    Birthday currentBday = student.GetBirthday();
    cout << "Год рождения: " << currentBday.year << endl;



    cout << "--- Шаг 1: Создание точки и ввод координат ---" << endl;
    Point myPoint;

    cout << "\nПроверяем введенные данные:" << endl;
    myPoint.PrintPoint();
    cout << "=========================================\n" << endl;


    cout << "--- Шаг 2: Сохранение точки в файл ---" << endl;
    myPoint.SaveFile();
    cout << "=========================================\n" << endl;


    cout << "--- Шаг 3: Изменение координат (Сеттеры) ---" << endl;
    cout << "Давайте изменим координаты этой же точки через консоль:" << endl;
    myPoint.SetX();
    myPoint.SetY();
    myPoint.SetZ();

    cout << "\nТекущее (измененное) состояние точки:" << endl;
    myPoint.PrintPoint();
    cout << "=========================================\n" << endl;


    cout << "--- Шаг 4: Восстановление данных из файла ---" << endl;
    cout << "Загружаем старые координаты обратно..." << endl;
    myPoint.LoadFile();

    cout << "\nСостояние точки после загрузки (должны вернуться первые значения):" << endl;
    myPoint.PrintPoint();
    cout << "=========================================\n" << endl;
}

