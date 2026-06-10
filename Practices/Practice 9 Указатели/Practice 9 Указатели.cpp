
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void Initialization(T masiv, int size) {
    for (int i = 0; i < size; i++) {
        masiv[i] = rand() % 100;
    }
}

template <typename T>
void PrintMasiv(T masiv, int size) {
    cout << "\nВот ваш массив: ";
    for (int i = 0; i < size; i++) {
        cout << masiv[i] << ' ';
    }
    cout << '\n';
}

template <typename T>
void SortMasiv(T masiv, int size, bool boolmean = false) {
    cout << "\nИдет сортировка массива...\n";
    if (boolmean == true) {
        for (int i = 1; i < size; i++) {
            int temp = masiv[i];
            int j = i - 1;

            while (j >= 0 && masiv[j] < temp) {
                masiv[j + 1] = masiv[j];
                j--;
            }

            masiv[j + 1] = temp;
        }
    }
    else {
        for (int i = 1; i < size; i++) {
            int temp = masiv[i];
            int j = i - 1;

            while (j >= 0 && masiv[j] > temp) {
                masiv[j + 1] = masiv[j];
                j--;
            }

            masiv[j + 1] = temp;
        }
    }
}

template <typename T>
void SortDevideMasiv(T masiv, int size) {
    cout << "\nИдет сортировка массива...\n";
    int middle = size / 2;
    for (int i = 1; i < middle; i++) {
        int temp = masiv[i];
        int j = i - 1;

        while (j >= 0 && masiv[j] < temp) {
            masiv[j + 1] = masiv[j];
            j--;
        }

        masiv[j + 1] = temp;
    }
    for (int i = middle + 1; i < size; i++) {
        int temp = masiv[i];
        int j = i - 1;

        while (j >= middle && masiv[j] > temp) {
            masiv[j + 1] = masiv[j];
            j--;
        }

        masiv[j + 1] = temp;
    }
}

void SortMasivBetweenNegatives(int masiv[], int size) {
    cout << "\nИдет сортировка массива...\n";
    int leftborder = -1, rightborder = -1;
    for (int i = 0; i < size; i++) {
        if (masiv[i] < 0) {
            leftborder = i;
            break;
        }
    }
    if (leftborder == -1) {
        return;
    }
    for (int i = size - 1; i > leftborder; i--) {
        if (masiv[i] < 0) {
            rightborder = i;
            break;
        }
    }
    for (int i = leftborder + 1; i < rightborder; i++) {
        int temp = masiv[i];
        int j = i - 1;

        while (j >= leftborder + 1 && masiv[j] > temp) {
            masiv[j + 1] = masiv[j];
            j--;
        }

        masiv[j + 1] = temp;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    {
        cout << "\nFirst Task\n";
        const int size = 10;
        int masiv[size];
        Initialization(masiv, size);
        PrintMasiv(masiv, size);
        SortMasiv(masiv, size, true);
        PrintMasiv(masiv, size);
    }

    {
        cout << "\nSecond Task\n";
        const int size = 10;
        int masiv[size];
        Initialization(masiv, size);
        PrintMasiv(masiv, size);
        SortDevideMasiv(masiv, size);
        PrintMasiv(masiv, size);
    }

    {
        cout << "\nThird Task\n";
        const int size = 10;
        int masiv[size], min = -20, max = 20;
        for (int i = 0; i < size; i++) {
            masiv[i] = min + rand() % (max - min + 1);
        }
        PrintMasiv(masiv, size);
        SortMasivBetweenNegatives(masiv, size);
        PrintMasiv(masiv, size);
    }
}
