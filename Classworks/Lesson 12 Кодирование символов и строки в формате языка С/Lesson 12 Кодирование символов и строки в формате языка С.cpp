
#include <iostream>
#include <Windows.h>

using namespace std;

void PrintArr(int* arr, int size) {
    cout << '\n';
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int* Initialization(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    return arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int* ptr = new int[5];
    delete[] ptr;

    int size = 10;
    // void* 
    int* arr = (int*)malloc(sizeof(int) * size);

    free(arr);

    int* arr2 = (int*)calloc(size, sizeof(int));
    PrintArr(arr2, size);
    Initialization(arr2, size);
    PrintArr(arr2, size);
    free(arr2);

    int* arr3 = (int*)malloc(sizeof(int) * size);
    Initialization(arr3, size);
    size = 15;  
    arr3 = (int*)realloc(arr3,size * sizeof(int));
    PrintArr(arr3, size);
    free(arr3);


}

