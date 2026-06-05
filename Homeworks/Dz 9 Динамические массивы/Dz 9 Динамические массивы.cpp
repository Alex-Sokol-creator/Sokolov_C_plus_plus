
#include <iostream>
#include <Windows.h>;

using namespace std;

/*
int* AddGrade(int* grades, int& size, int newGrade) {
    int* temp = new int[size + 1];
    for (int i = 0; i < size;i++) {
        temp[i] = grades[i];
    }
    temp[size] = newGrade;
    size++;
    delete[] grades;
    grades = temp;
    return grades;
}*/

template <typename T>
T* GiveMemory(int size) {
    return new T[size];
}

template <typename T>
void Initialization(T* masiv, int size) {
    for (int i = 0; i < size; i++) {
        masiv[i] = rand();
    }
}

template <typename T>
void PrintMasiv(T* masiv, int size) {
    cout << "Вот ваш динамический массив: \n";
    for (int i = 0; i < size; i++) {
        cout << masiv[i] << ' ';
    }
}

template <typename T>
void DeleteMemory(T* masiv) {
    cout << "\nМассив удаляется из динамической памяти";
    delete[] masiv;
}

template <typename T>
T* AddElement(T* masiv, int& size,T element) {
    T* temp = new T[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = masiv[i];
    }
    temp[size] = element;
    size++;
    delete[] masiv;
    masiv = temp;
    return masiv;
}

template <typename T>
T* AddElementByIndex(T* masiv, int& size,int index,T element) {
    if (index < 0 || index > size) {
        cout << "К сожалению, такого индекса нет в массиве\n";
        return masiv;
    }
    T* temp = new T[size + 1];
    for (int i = 0; i < index; i++) {
        temp[i] = masiv[i];
    }
    temp[index] = element;
    for (int i = index; i < size; i++) {
        temp[i + 1] = masiv[i];
    }
    size++;
    delete[] masiv;
    masiv = temp;
    return masiv;
}

template <typename T>
T* DeleteElementByIndex(T* masiv, int& size,int index) {
    if (index < 0 || index >= size) {
        cout << "К сожалению, такого индекса нет в массиве\n";
        return masiv;
    }
    T* temp = new T[size - 1];
    for (int i = 0; i < index; i++) {
        temp[i] = masiv[i];
    }
    for (int i = index + 1; i < size; i++) {
        temp[i - 1] = masiv[i];
    }
    size--;
    delete[] masiv;
    masiv = temp;
    return masiv;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    {
        cout << "\nFirst Task\n";
        int size = 6;
        int num,index;
        int* masiv = GiveMemory<int>(size);
        Initialization(masiv, size);
        PrintMasiv(masiv, size);
        cout << "\nКакое число вы хотите добавить в конец массива?: ";
        cin >> num;
        masiv = AddElement(masiv, size, num);
        PrintMasiv(masiv, size);
        cout << "\nВ какой индекс вставить ваше число?: ";
        cin >> index;
        cout << "Напишите число, которое хотите вставить: ";
        cin >> num;
        masiv = AddElementByIndex(masiv, size, index, num);
        PrintMasiv(masiv, size);
        cout << "\nКакой индекс у элемента, который вы хотите удалить?: ";
        cin >> index;
        masiv = DeleteElementByIndex(masiv, size, index);
        PrintMasiv(masiv,size);
        DeleteMemory(masiv);
    }
}

