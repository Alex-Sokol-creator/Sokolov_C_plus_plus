
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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

    {
        cout << "\nFirst Task\n";
        const int size = 5;
        long long mobilephones[size] = { 3801234567,3705869854,3698745126,1522356587,1321254787 };
        long long homephones[size] = { 9443654789,98745621,457456221,8765874512,9824512360 };
        int choice;
        cout << "Справочник\n";
        while (true) {
            choice = 0;
            while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
                cout << "Что вы хотите сделать? (1 - отсортировать по мобильным номерам,2 - отсортировать по домашним номерам,\n3 - вывести список пользователей, 4 - выход): ";
                cin >> choice;
            }
            switch (choice) {
            case 1: {
                for (int i = 0; i < size; i++) {
                    for (int j = size - 1; j > i; j--) {
                        if (mobilephones[j - 1] > mobilephones[j]) {
                            long long temp = mobilephones[j - 1];
                            long long temp2 = homephones[j - 1];
                            mobilephones[j - 1] = mobilephones[j];
                            homephones[j - 1] = homephones[j];
                            mobilephones[j] = temp;
                            homephones[j] = temp2;
                        }
                    }
                }
                cout << "Вот отсортированный массив мобильных телефонов по возрастанию: \n";
                for (long long phone : mobilephones) {
                    cout << phone << ' ';
                }
                cout << "\nВот отсортированный массив домашних телефонов в соответствии с мобильными: \n";
                for (long long phone : homephones) {
                    cout << phone << ' ';
                }
                cout << '\n';
                break;
            }
            case 2: {
                for (int i = 0; i < size; i++) {
                    for (int j = size - 1; j > i; j--) {
                        if (homephones[j - 1] > homephones[j]) {
                            long long temp = homephones[j - 1];
                            long long temp2 = mobilephones[j - 1];
                            mobilephones[j - 1] = mobilephones[j];
                            homephones[j - 1] = homephones[j];
                            homephones[j] = temp;
                            mobilephones[j] = temp2;
                        }
                    }
                }
                cout << "Вот отсортированный массив мобильных телефонов в соответствии с домашними: \n";
                for (long long phone : mobilephones) {
                    cout << phone << ' ';
                }
                cout << "\nВот отсортированный массив домашних телефонов по возрастанию: \n";
                for (long long phone : homephones) {
                    cout << phone << ' ';
                }
                cout << '\n';
                break;
            }
            }
        }
    }
}

