
#include <iostream>
#include <Windows.h>

/*
int sum(int num1, int num2) {
    return num1 + num2;
}

double sum(double num1, double num2) {
    return num1 + num2;
}
*/
/*
template<typename T>
T sum(T num1, T num2) {
    return num1 + num2;
}
*/

template<typename T>
class Box {
private:
    T value;
public:
    Box(T value) : value(value){}
    T GetValue() const { return value; }
};

template <typename T, typename U>
class PairBox {
private:
    T first;
    U second;
public:
    PairBox(T f, U s) : first(f), second(s) {}
    void printPair() {
        std::cout << "First: " << first << '\n' << "Second: " << second << '\n';
    }
};

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
public:
    explicit Array(int capacity) : capacity(capacity) {
        if (capacity == 0) data == nullptr;
        else data = new T[size];
        size = 0;
    }
    ~Array(){
        if (data != nullptr) delete[] data;
    }

    Array(const Array& other) : size(other.size), capacity(other.capacity) {
        if (capacity == 0) data = nullptr;
        else {
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
    }

    Array& operator=(const Array& other) {
        if (this == &other) return *this;

        size = other.size;
        if (capacity == 0) data = nullptr;
        else {
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    Array(Array&& other) {
        size = int.size;
        data = other.data;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    Array& operator=(Array&& other) {
        if (this == &other) return *this;
        if (data != nullptr) delete[] data;

        size = other.size;
        data = other.data;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    T operator[](int index) const {
        return data[index];
    }

    T& operator[](int index) {
        return data[index];
    }

    int GetSize() const { return size; }

    void pushBack(T newElem) {
        if (size == capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            reserve(newCap);
        }

        
        /*
        int newSize = size + 1;
        T* temp = new T[newSize];

        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        temp[size] = newElem;
        delete[] data;
        data = temp;
        size = newSize;
        */

        data[size++] = newElem;
    }

    void reserve(int newCapacity) {
        if (newCapacity <= capacity) return;

        T* temp = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity = newCapacity;
    }

    void popBack() {
        --size;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*
    std::cout << sum(10, 12) << '\n';
    std::cout << sum(3.4, 7.5) << '\n';
    std::cout << sum('u', '5') << '\n';
    std::string str = "hello";
    std::string str2 = " world!";
    std::cout << sum(str, str2) << '\n';

    std::cout << 10 + 12 << '\n';
    std::cout << str + str2 << '\n';
    */

    Box<int> boxInt(10);
    std::cout << boxInt.GetValue() << '\n';

    Box<std::string> boxString("Hello world!");
    std::cout << boxString.GetValue() << '\n';

    PairBox<int, double> pair(10, 45.6);
    pair.printPair();

    int* arr = new int[5] {0};

    int* temp = new int[6];

    for (int i = 0; i < 5; i++) {
        temp[i] = arr[i];
    }

    //temp[5] = 10;
    //delete[] arr;
    //arr = temp;
    //temp = nullptr;

    //delete[] arr;

    Array<int> a1(4);
    Array<int> a2(5);

    a2 = a1;

    std::cout << a2[1] << '\n';

    Array<double> arrayD(6);

    arrayD.pushBack(5.6);
    arrayD.pushBack(-7.32);

    for (int i = 0; i < arrayD.GetSize();i++) {
        arrayD[i] = 3.4;
    }

    for (int i = 0; i < arrayD.GetSize();i++) {
        std::cout << arrayD[i] << '\n';
    }

    Array<int> arrayD2(0);

    for (int i = 0; i < 100; i++) {
        arrayD2.pushBack(i);
    }

    for (int i = 0; i < arrayD2.GetSize();i++) {
        std::cout << arrayD2[i] << '\n';
    }
}

