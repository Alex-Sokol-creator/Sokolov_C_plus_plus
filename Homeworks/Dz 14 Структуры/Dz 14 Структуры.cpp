
#include <iostream>
#include <Windows.h>

using namespace std;

struct Complex {
    double intact;
    double mnima;
};

Complex Adding(Complex num1, Complex num2) {
    Complex result;
    result.intact = num1.intact + num2.intact;
    result.mnima = num1.mnima + num2.mnima;
    return result;
}

Complex TakingAway(Complex num1, Complex num2) {
    Complex result;
    result.intact = num1.intact - num2.intact;
    result.mnima = num1.mnima - num2.mnima;
    return result;
}

Complex Multiplying(Complex num1, Complex num2) {
    Complex result;
    result.intact = (num1.intact * num2.intact) - (num1.mnima * num2.mnima);
    result.mnima = (num1.intact * num2.mnima) + (num1.mnima * num2.intact);
    return result;
}

Complex Dividing(Complex num1, Complex num2) {
    Complex result;
    double divider = (num2.intact * num2.intact) + (num2.mnima * num2.mnima);
    result.intact = ((num1.intact * num2.intact) + (num1.mnima * num2.mnima)) / divider;
    result.mnima = ((num1.mnima * num2.intact) - (num1.intact * num2.mnima)) / divider;
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        cout << "\nFirst Task\n";
        Complex num1, num2;
        double num1_intant, num1_mnima, num2_intant, num2_mnima;
        int choice = 0;
        cout << "Введите целую часть 1 комплексного числа: ";
        cin >> num1_intant;
        cout << "Введите мнимую часть 1 комплексного числа: ";
        cin >> num1_mnima;
        cout << "Введите целую часть 2 комплексного числа: ";
        cin >> num2_intant;
        cout << "Введите мнимую часть 2 комплексного числа: ";
        cin >> num2_mnima;
        num1.intact = num1_intant;
        num1.mnima = num1_mnima;
        num2.intact = num2_intant;
        num2.mnima = num2_mnima;
        while (choice < 1 || choice > 4) {
            cout << "Что вы хотите с ними сделать?(1 - прибавить, 2 - отнять, 3 - умножить, 4 - поделить): ";
            cin >> choice;
        }
        switch (choice) {
        case 1: {
            Complex result = Adding(num1, num2);
            cout << "Результат прибавления этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
            break;
        }
        case 2: {
            Complex result = TakingAway(num1, num2);
            cout << "Результат отнимания этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
            break;
        }
        case 3: {
            Complex result = Multiplying(num1, num2);
            cout << "Результат умножения этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
            break;
        }
        case 4: {
            Complex result = Dividing(num1, num2);
            cout << "Результат деления этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
            break;
        }
        }
    }
}

