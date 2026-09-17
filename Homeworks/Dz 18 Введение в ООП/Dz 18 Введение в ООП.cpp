
#include <iostream>
#include <Windows.h>

using namespace std;

class Fraction {
private:
    double nominator;
    double denominator;
public:
    
    void SetFraction(double nom_vod, double denom_vod) {
            if (denom_vod == 0) {
                cout << "Знаменатель равен 0, такое невозможно, введите заново: ";
                while (denom_vod == 0) {
                    cin >> denom_vod;
                }
            }
            nominator = nom_vod;
            denominator = denom_vod;
    }

    void InputValues() {
        double nom_vod, denom_vod;
        cout << "Введите числитель: ";
        cin >> nom_vod;
        cout << "Введите знаменатель: ";
        cin >> denom_vod;
        if (denom_vod == 0) {
            cout << "Знаменатель равен 0, такое невозможно, введите заново: ";
            while (denom_vod == 0) {
                cin >> denom_vod;
            }
        }
        nominator = nom_vod;
        denominator = denom_vod;
        cout << "Переменные успешно записаны\n";
    }

    void PrintFraction() {
        cout << nominator << " / " << denominator << '\n';
    }

    Fraction FractionAdd(Fraction second_fr) {
        double new_nominator = (nominator * second_fr.denominator + second_fr.nominator * denominator);
        double new_denominator = denominator * second_fr.denominator;
        Fraction result;
        result.SetFraction(new_nominator, new_denominator);
        return result;
    }
 
    Fraction FractionMinus(Fraction second_fr) {
        int choice = 0;
        while (choice != 1 && choice != 2) {
            cout << "От какого числа вы хотите отнимать? (1/2): ";
            cin >> choice;
        }
        if (choice == 1) {
            double new_nominator = (nominator * second_fr.denominator - second_fr.nominator * denominator);
            double new_denominator = denominator * second_fr.denominator;
            Fraction result;
            result.SetFraction(new_nominator, new_denominator);
            return result;
        }
        else {
            double new_nominator = (second_fr.nominator * denominator - nominator * second_fr.denominator);
            double new_denominator = denominator * second_fr.denominator;
            Fraction result;
            result.SetFraction(new_nominator, new_denominator);
            return result;
        }
    }

    Fraction FractionMultiply(Fraction second_fr) {
        double new_nominator = nominator * second_fr.nominator;
        double new_denominator = denominator * second_fr.denominator;
        Fraction result;
        result.SetFraction(new_nominator, new_denominator);
        return result;
    }

    Fraction FractionDivide(Fraction second_fr) {
        int choice = 0;
        while (choice != 1 && choice != 2) {
            cout << "Какое число вы хотите делить? (1/2): ";
            cin >> choice;
        }
        if (choice == 1) {
            double new_nominator = nominator * second_fr.denominator;
            double new_denominator = denominator * second_fr.nominator;
            Fraction result;
            result.SetFraction(new_nominator, new_denominator);
            return result;
        }
        else {
            double new_nominator = second_fr.nominator * denominator;
            double new_denominator = second_fr.denominator * nominator;
            Fraction result;
            result.SetFraction(new_nominator, new_denominator);
            return result;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction f1, f2;

    cout << "Введите первую дробь:\n";
    f1.InputValues();

    cout << "Введите вторую дробь\n";
    f2.InputValues();

    cout << "Вот ваши дроби:\n";
    cout << "Дробь 1: ";
    f1.PrintFraction();
    cout << "Дробь 2: ";
    f2.PrintFraction();

    cout << "При добавлении ваших дробей, будет такая:\n";
    Fraction resultAdd = f1.FractionAdd(f2);
    resultAdd.PrintFraction();

    cout << "При умножении ваших дробей, будет такая:\n";
    Fraction resultMultiply = f1.FractionMultiply(f2);
    resultMultiply.PrintFraction();

    cout << "При отнимании ваших дробей, будет такая:\n";
    Fraction resultMinus = f1.FractionMinus(f2);
    resultMinus.PrintFraction();

    cout << "При делении ваших дробей, будет такая:\n";
    Fraction resultDivide = f1.FractionDivide(f2);
    resultDivide.PrintFraction();

}

