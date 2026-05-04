
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    //int max = 500;
    //int min = 4;

    //int randomNumber = rand();
    //int randomNumber = rand() % max; // from 0 to max
    //int randomNumber = rand() % max + 1; // from 1 to max
    //int randomNumber = rand() % (max - min + 1) + min; // from min to max

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
    
    //{
    //    cout << "\nThird Task\n";
    //    int diap1;
    //    int diap2;
    //    int sumtemp = 0;
    //    int sum = 0;
    //    cout << "Введите первую границу диапазона: ";
    //    cin >> diap1;
    //    cout << "Введите вторую границу диапазона: ";
    //    cin >> diap2;
    //    if (diap1 > diap2) {
    //        int diaptemp = diap2;
    //        diap2 = diap1;
    //        diap1 = diaptemp;
    //    }
    //    do {
    //        sumtemp = sum;
    //        sum = sumtemp + diap1;
    //        diap1++;
    //    } while (diap1 <= diap2);
    //    cout << "Сумма всех чисел в вашем диапазоне будет равна: " << sum << '\n';
    //}

    //{
    //    cout << "\nFourth Task\n";
    //    double number = 0;
    //    double sumtemp = 0;
    //    double summary;
    //    while (true) {
    //        cout << "Введите любое число (0 - для вывода суммы всех предыдущих): ";
    //        cin >> number;
    //        if (number == 0) { break; }
    //        else {
    //            summary = sumtemp + number;
    //            sumtemp = summary;
    //        }
    //    }
    //    cout << "\nСумма всех предыдущих чисел это: " << summary;
    //}

    {
        cout << "\nFifth Task\n";
        int max = 500;
        while (true) {
            cout << "Игра 'Угадай число'\n";
            int randomNumber = rand() % max + 1;
            int choice;
            int choicewin;
            int tries = 0;
            cout << "Программа загадала число от 1 до 500, сможете ли вы его угадать?\n";
            while (true) {
                cout << "Введите предполагаемое число: ";
                int usernum;
                cin >> usernum;
                if (usernum < randomNumber) {
                    cout << "Ваше число меньше чем загаданное\n";
                    tries++;
                }
                else if (usernum > randomNumber) {
                    cout << "Ваше число больше чем загаданное\n";
                    tries++;
                }
                else if (usernum == randomNumber) {
                    cout << "Вы угадали число! Поздравляем\n";
                    tries++;
                    break;
                }
                else {
                    cout << "Вы ввели не число, попробуйте снова\n";
                }
                cout << "Вы хотите продолжать отгадывать число? (0 - прекратить, любой символ - продолжить): ";
                cin >> choice;
                if (choice == 0) { break; }
            }
            if (choice == 0) 
            { 
                cout << "Загаданное число было: " << randomNumber << '\n';
                cout << "Вы потратили попыток: " << tries << '\n';
                break; 
            }
            else {
                cout << "Вы потратили попыток: " << tries << '\n';
                cout << "Хотите попробовать снова? (0 - нет, любой символ - да): ";
                cin >> choicewin;
                if (choicewin == 0) { break; }
            }
        }
    }
}


