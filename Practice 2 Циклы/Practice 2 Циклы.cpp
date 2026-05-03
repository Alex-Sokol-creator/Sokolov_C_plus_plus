
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int max = 10;
    int min = 4;

    int randomNumber = rand();
    //int randomNumber = rand() % max; // from 0 to max
    //int randomNumber = rand() % max + 1; // from 1 to max
    //int randomNumber = rand() % (max - min + 1) + min; // from 1 to max

    /*{
        cout << "First Task\n";
        cout << "Введите число, до которого вы хотите вывести числа: ";
        int usernum;
        int limit = 0;
        cin >> usernum;
        while (limit <= usernum) {
            cout << limit << '\n';
            limit++;
        }
    }*/

    /*{
        cout << "\nSecond Task\n";
        int diap1;
        int diap2;
        cout << "Введите первую границу диапазона: ";
        cin >> diap1;
        cout << "Введите вторую границу диапазона: ";
        cin >> diap2;
        if (diap1 > diap2) {
            int diaptemp = diap2;
            diap2 = diap1;
            diap1 = diaptemp;
        }
        cout << "Вот все парные числа с вашего диапазона: \n";
        for (int i = diap1; i <= diap2; i++) {
            if (i % 2 == 0) {
               cout << i << ' ';
            }
        }
        cout << "\nВот все непарные числа с вашего диапазона: \n";
        for (int i = diap1; i <= diap2; i++) {
            if (i % 2 != 0) {
               cout << i << ' ';
            }
        }
        cout << "\nВот все числа кратные 7 с вашего диапазона: \n";
        for (int i = diap1; i <= diap2; i++) {
            if (i % 7 == 0) {
                cout << i << ' ';
            }
        }
    }*/
    
    /*{
        cout << "\nThird Task\n";
        int diap1;
        int diap2;
        int sumtemp = 0;
        int sum = 0;
        cout << "Введите первую границу диапазона: ";
        cin >> diap1;
        cout << "Введите вторую границу диапазона: ";
        cin >> diap2;
        if (diap1 > diap2) {
            int diaptemp = diap2;
            diap2 = diap1;
            diap1 = diaptemp;
        }
        do {
            sumtemp = sum;
            sum = sumtemp + diap1;
            diap1++;
        } while (diap1 <= diap2);
        cout << "Сумма всех чисел в вашем диапазоне будет равна: " << sum << '\n';
    }*/
}


