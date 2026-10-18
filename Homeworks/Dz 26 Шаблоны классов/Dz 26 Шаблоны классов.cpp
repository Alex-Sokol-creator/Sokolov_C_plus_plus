
#include <iostream>
#include <Windows.h>
#include <string>

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
public:
    explicit Array(int capacity) : data(nullptr), size(0), capacity(capacity) {
        if (capacity > 0) data = new T[capacity];
    }
    ~Array() {
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
        size = other.size;
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

    bool empty() const { return size == 0; }

    int GetSize() const { return size; }

    void pushBack(T newElem) {
        if (size == capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            reserve(newCap);
        }

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


    void insertAt(int index, T value) {
        if (index < 0 || index > size) {
            std::cout << "Ошибка, индекс неправильный\n";
            return;
        }
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void removeAt(int index) {
        if (index < 0 || index > (size - 1)) {
            std::cout << "Ошибка, индекс неправильный\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void clear() {
        size = 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        if (arr.empty()) {
            return os << "{}";
        }
        os << "{ ";
        for (int i = 0; i < arr.size; i++) {
            os << arr.data[i];
            if (i < arr.size - 1) {
                os << ", ";
            }
        }
        return os << " }";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Array<int> a(2);
    std::cout << a << '\n';        
    a.insertAt(0, 10);
    a.insertAt(1, 30);
    a.insertAt(1, 20);             
    a.insertAt(10, 99);           
    std::cout << a << '\n';        
    a.removeAt(0);
    std::cout << a << '\n';        
    a.removeAt(5);                
    a.clear();
    std::cout << a << '\n';
}

