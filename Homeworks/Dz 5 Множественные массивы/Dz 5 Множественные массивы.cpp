
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        cout << "\nFirst Task\n";
        const int size = 3;
        int masiv[size][size];
        int num1, num2, num3, numindex = 0;
        cout << "Введите 1 число для заполнения двухмерного массива: ";
        cin >> num1;
        /*
        cout << "Введите 2 число для заполнения двухмерного массива: ";
        cin >> num2;
        cout << "Введите 3 число для заполнения двухмерного массива: ";
        cin >> num3;
        int numbers[3] = { num1,num2,num3 };
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j == 0) {
                    masiv[i][j] = numbers[numindex];
                }
                else {
                    masiv[i][j] = masiv[i][j - 1] * 2;
                }
            }
            numindex += 1;
        }*/
        cout << "Вот ваш итоговый массив: \n";
        for (int i = 0; i < size; i++) {
            for (int num : masiv[i]) {
                cout << num << ' ';
            }
            cout << '\n';
        }
    }
}

