
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    const int size = 7;
    int arr[size];

    int min = -10;
    int max = 10;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    
    cout << "Unsorted array: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    //Select sort
    /*
    // Select sort
    int minIndex;
    for (int i = 0; i < size; i++) {
        minIndex = i;

        for (int j = i; j < size; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    */

    //Bubble sort
    /*
    //Bubble sort
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    */

    //Insertion sort
    /*
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }*/

    cout << "Unsorted array: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    int searchnumber;
    cout << "Enter number: ";
    cin >> searchnumber;

    int searchindex = -1;

    //Linear search
    /*for (int i = 0; i < size; i++) {
        if (arr[i] == searchnumber) {
            searchindex = i;
            break;
        }
    }*/

    //Binary search
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == searchnumber) {
            searchindex = mid;
            break;
        }
        else if (arr[mid] < searchnumber) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (searchindex == -1) { cout << "Number was not found\n"; }
    else { cout << "Number found. Index: " << searchindex << '\n'; }
}

