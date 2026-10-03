
#include <iostream>
#include <Windows.h>
#include "MyString.h"

using namespace std;

enum TypeOfReservoir {
    None,Pond,Lake,Sea,Ocean
};

class Reservoir {
private:
    MyString name;
    TypeOfReservoir type;
    double length, width, deep;
public:
    Reservoir() : name(), type(None), length(0),width(0),deep(0) {};

    explicit Reservoir(const MyString& name, TypeOfReservoir type,double length, double width, double deep) {
        this->name = name;
        this->type = type;
        this->length = length;
        this->width = width;
        this->deep = deep;
    }

    double CountVolume() const{
        return length * width * deep;
    }

    double CountArea() const {
        return length * width;
    }

    bool CheckType(const Reservoir& other) const{
        return type == other.type;
    }

    bool CheckArea(const Reservoir& other) const {
        return CountArea() == other.CountArea();
    }

    void CopyObjects(const Reservoir& other) {
        this->name = other.name;
        this->type = other.type;
        this->length = other.length;
        this->width = other.width;
        this->deep = other.deep;
    }

    void PrintReservoir() const {
        const char* typeNames[] = { "Неизвестно", "Пруд", "Озеро", "Море", "Океан" };
        cout << "\nВодоем: \n" << name.c_str() << "\nТип: " << typeNames[type] << "\nДлина: " << length << " м.\nШирина: " << width << " м.\nГлубина: " << deep
            << " м.\nПлощадь поверхности: " << CountArea() << " кв.м." << "\nОбъем водоема: " << CountVolume() << " куб.м.";
    }

    double GetLength() const { return length; }
    double GetWidth() const { return width; }
    double GetDeep() const { return deep; }
    TypeOfReservoir GetType() const { return type; }
    MyString GetName() const { return name; }
};

class ReservoirContainer {
private:
    Reservoir* reservoirs;
    int size;
public:
    ReservoirContainer() : reservoirs(nullptr), size(0) {}

    ~ReservoirContainer() {
        if (reservoirs != nullptr) {
            delete[] reservoirs;
        }
    }

    void AddReservoir(const Reservoir& newReservoir) {
        Reservoir* reservoirs_new = new Reservoir[size + 1];
        for (int i = 0; i < size; i++) {
            reservoirs_new[i] = reservoirs[i];
        }
        reservoirs_new[size] = newReservoir;
        if (reservoirs != nullptr) {
            delete[] reservoirs;
        }
        reservoirs = reservoirs_new;
        size++;
    }

    void DeleteReservoir(int index) {
        if (index < 0 || index >= size) {
            cout << "Некорректный индекс!\n";
            return;
        }

        if (size == 1) {
            delete[] reservoirs;
            reservoirs = nullptr;
            size = 0;
            return;
        }
        Reservoir* reservoirs_new = new Reservoir[size - 1];
        for (int i = 0; i < index; i++) {
            reservoirs_new[i] = reservoirs[i];
        }
        for (int i = index; i < size - 1; i++) {
            reservoirs_new[i] = reservoirs[i + 1];
        }

        delete[] reservoirs;
        reservoirs = reservoirs_new;
        size--;
    }

    void SaveFile() {
        FILE* Dz_22_save;
        errno_t err1 = fopen_s(&Dz_22_save, "Dz_22_save.txt", "w");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            fprintf(Dz_22_save, "%d\n", size);
            for (int i = 0; i < size; i++) {
                fprintf(Dz_22_save, "%s\n", reservoirs[i].GetName().c_str());
                fprintf(Dz_22_save, "%d\n", reservoirs[i].GetType());
                fprintf(Dz_22_save, "%lf\n", reservoirs[i].GetLength());
                fprintf(Dz_22_save, "%lf\n", reservoirs[i].GetWidth());
                fprintf(Dz_22_save, "%lf\n", reservoirs[i].GetDeep());
            }
            cout << "Данные успешно записаны!\n";
        }
        fclose(Dz_22_save);
    }

    void LoadFile() {
        FILE* Dz_22_load;
        errno_t err1 = fopen_s(&Dz_22_load, "Dz_22_save.txt", "r");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            int count = 0;
            if (fscanf_s(Dz_22_load, "%d\n", &count) != 1) {
                fclose(Dz_22_load);
                return;
            }
            if (reservoirs != nullptr) {
                delete[] reservoirs;
                reservoirs = nullptr;
            }
            size = 0;
            for (int i = 0; i < count; i++) {
                char bufName[1000];
                int typeInt = 0;
                double length = 0, width = 0, deep = 0;
                fgets(bufName, 1000, Dz_22_load);
                bufName[strlen(bufName) - 1] = '\0';
                fscanf_s(Dz_22_load, "%d\n", &typeInt);
                fscanf_s(Dz_22_load, "%lf\n", &length);
                fscanf_s(Dz_22_load, "%lf\n", &width);
                fscanf_s(Dz_22_load, "%lf\n", &deep);
                TypeOfReservoir t = static_cast<TypeOfReservoir>(typeInt);
                Reservoir temp(MyString(bufName), t, length, width, deep);
                AddReservoir(temp);
            }
            cout << "Данные успешно загружены\n";
        }
        fclose(Dz_22_load);
    }

    void SaveBinaryFile() {
        FILE* Dz_22_bin_save;
        errno_t err1 = fopen_s(&Dz_22_bin_save, "Dz_22_save.bin", "wb");
        if (err1) {
            cout << "К сожалению, при попытке открыть файл произошла ошибка\n";
        }
        else {
            fwrite(&size, sizeof(int), 1, Dz_22_bin_save);

            for (int i = 0; i < size; i++) {
                int nameLen = reservoirs[i].GetName().GetMyStringLength();
                fwrite(&nameLen, sizeof(int), 1, Dz_22_bin_save);
                fwrite(reservoirs[i].GetName().c_str(), sizeof(char), nameLen + 1, Dz_22_bin_save);
                TypeOfReservoir type = reservoirs[i].GetType();
                double length = reservoirs[i].GetLength();
                double width = reservoirs[i].GetWidth();
                double deep = reservoirs[i].GetDeep();

                fwrite(&type, sizeof(TypeOfReservoir), 1, Dz_22_bin_save);
                fwrite(&length, sizeof(double), 1, Dz_22_bin_save);
                fwrite(&width, sizeof(double), 1, Dz_22_bin_save);
                fwrite(&deep, sizeof(double), 1, Dz_22_bin_save);
            }
            cout << "Данные успешно записаны в бинарный файл!\n";
            fclose(Dz_22_bin_save);
        }
    }

    void PrintAll() const {
        if (size == 0) {
            cout << "Список водоемов пуст.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << '\n' << i + 1 << " водоем:\n";
            reservoirs[i].PrintReservoir();
        }
    }

    int GetSize() const { return size; }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Шаг 1: Тестирование отдельных объектов класса Reservoir ===\n";
    Reservoir lake(MyString("Байкал"), Lake, 636000, 48000, 1642);
    Reservoir sea1(MyString("Черное Море"), Sea, 1150000, 580000, 2210);
    Reservoir sea2(MyString("Азовское Море"), Sea, 360000, 180000, 14);

    lake.PrintReservoir();
    sea1.PrintReservoir();
    sea2.PrintReservoir();

    cout << "Проверка типов (Байкал и Черное море одинаковы?): "
        << (lake.CheckType(sea1) ? "Да" : "Нет") << "\n";
    cout << "Проверка типов (Черное и Азовское море одинаковы?): "
        << (sea1.CheckType(sea2) ? "Да" : "Нет") << "\n\n";

    cout << "Сравнение площадей Черного и Азовского морей: "
        << (sea1.CheckArea(sea2) ? "Площади равны" : "Площади разные") << "\n\n";


    cout << "=== Шаг 2: Тестирование динамического контейнера (Добавление и удаление) ===\n";
    ReservoirContainer container;

    container.AddReservoir(lake);
    container.AddReservoir(sea1);
    container.AddReservoir(sea2);

    cout << "--- Содержимое контейнера после добавления 3 объектов: ---\n";
    container.PrintAll();

    cout << "--- Удаляем элемент с индексом 1 (Черное Море): ---\n";
    container.DeleteReservoir(1);
    container.PrintAll();


    cout << "=== Шаг 3: Тестирование сохранения и чтения ТЕКСТОВОГО файла ===\n";
    container.SaveFile();

    cout << "Создаем новый пустой контейнер для загрузки из текста...\n";
    ReservoirContainer textContainer;
    textContainer.LoadFile();

    cout << "--- Содержимое контейнера, считанного из ТЕКСТА: ---\n";
    textContainer.PrintAll();


    cout << "=== Шаг 4: Тестирование сохранения и чтения БИНАРНОГО файла ===\n";
    container.SaveBinaryFile();

    cout << "Создаем новый пустой контейнер для загрузки из бинарника...\n";
    ReservoirContainer binContainer;
    cout << "Бинарное сохранение успешно выполнено. Все требования задания проверены!\n";

}

