
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
T* AddVertical(T masiv, int rows, int cols, int position) {
    int index = position - 1;
    if (index < 0) {
        cout << "К сожалению, нельзя добавить столбик на такую позицию\n";
        return;
    }
    else if (index > cols) {
        int temp = cols;
        for (int i = temp; i <= index; i++) {
            T* masiv_new = new T[cols + 1];
            for (int j = 0; j < rows; j++) {
                for (int c = 0; c < cols; c++) {
                    masiv_new[j][c] = masiv[j][c];
                }
            }
            for (int j = 0; j < rows; j++) {
                masiv[i][j] = rand() % 10;
            }
            cols++;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    /*
    int** arr_3x5 = new int* [size_x];
    for (int i = 0; i < size_x; i++) {
        arr_3x5[i] = new int[size_y];
        for (int j = 0; j < size_y; j++) {
            arr_3x5[i][j] = rand() % 10;
            cout << arr_3x5[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    {
        cout << "\nFirst Task\n";

    }
}

