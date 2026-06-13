
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    /*

    int size_x = 3, size_y = 5;

    // int* arr_1d = new int[10];

    int** arr_3x5 = new int* [size_x];
    for (int i = 0; i < size_x; i++) {
        arr_3x5[i] = new int[size_y];
        for (int j = 0; j < size_y; j++) {
            arr_3x5[i][j] = rand() % 10;
            cout << arr_3x5[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < size_x; i++) {
        delete[] arr_3x5[i];
    }
    delete[] arr_3x5;
    */

    /*
    int size_x = 3, size_y = 5, size_z = 4;

    int*** arr_3x5x4 = new int** [size_x];
    for (int x = 0; x < size_x; x++) {
        arr_3x5x4[x] = new int* [size_y];
        for (int y = 0; y < size_y; y++) {
            arr_3x5x4[x][y] = new int[size_z];
            for (int z = 0; z < size_z; z++) {
                arr_3x5x4[x][y][z] = rand() % 10;
                cout << arr_3x5x4[x][y][z] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            delete[] arr_3x5x4[x][y];
        }
        delete[] arr_3x5x4[x];
    }
    delete[] arr_3x5x4;
    */

    int size_x;
    cout << "Enter size of the jagged array: ";
    cin >> size_x;
    int** jaggedArr = new int* [size_x];
    int* sizes = new int[size_x];
    for (int i = 0; i < size_x; i++) {
        int size;
        cout << "Enter size of the " << i << " array in jagged array: ";
        cin >> size;
        jaggedArr[i] = new int[size];
        sizes[i] = size;
        for (int j = 0; j < size; j++) {
            jaggedArr[i][j] = rand() % 10;
            cout << jaggedArr[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << jaggedArr[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < size_x; i++) {
        delete[] jaggedArr[i];
    }
    delete[] jaggedArr;
}

