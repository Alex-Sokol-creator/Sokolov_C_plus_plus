
#include <iostream>
#include <Windows.h>

class IntArray {
    int* arr;
    int size;
public:
    IntArray():size(0),arr(nullptr){}
    explicit IntArray(int size) : size(size) {
        arr = new int[size] {0};
    }

    ~IntArray() {
        if (arr != nullptr) delete[] arr;
    }

    IntArray(const IntArray& other) : size(other.size) {
        if (other.size > 0) {
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        else {
            arr = nullptr;
        }
    }
    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this;

        if (arr != nullptr) delete[] arr;

        size = other.size;

        if (size != 0) {
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        else {
            arr = nullptr;
        }

        return *this;
    }

    IntArray(IntArray&& other) noexcept
        : arr(other.arr), size(other.size) {
        std::cout << "[LOG]: Move constuctor\n";
        other.arr = nullptr;
        other.size = 0;
    }
    IntArray& operator=(IntArray&& other) noexcept {
        std::cout << "[LOG]: Move operator\n";
        if (this != &other) return *this;

        if (arr != nullptr) delete[] arr;

        arr = other.arr;
        size = other.size;

        other.arr = nullptr;
        other.size = 0;

        return *this;
    }

    int operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
};

//Фабричная функция
IntArray createFilledArray(int size) {
    IntArray newArr(size);
    for (int i = 0; i < size; i++) {
        newArr[i] = i + 1;
    }
    return newArr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*
    int size = 0;

    std::cout << "Enter size: ";
    std::cin >> size;
    int* arr = new int[size];

    delete[] arr;

    IntArray arr1(5);
    IntArray arr2(arr1);

    IntArray arr3(4);

    arr3 = arr2;

    IntArray newArr = createFilledArray(5);

    std::cout << newArr[3] << '\n';
    */

    IntArray arr1(5);
    for (int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }

    // IntArray arr2 = std::move(arr1);

    IntArray arr2 = createFilledArray(5);
}

