
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		cout << "\nFirst Task\n";
		int num;
		cout << "Введите число на проверку парности: ";
		cin >> num;
		if (num % 2 == 0) {
			cout << "Число парное";
		}
		else {
			cout << "Число не парное";
		}
	}

	{
		cout << "\nSecond Task\n";
		double num1, num2;
		cout << "Введите 1 число: ";
		cin >> num1;
		cout << "Введите 2 число: ";
		cin >> num2;
		if (num1 > num2) {
			cout << "Число " << num2 << " меньше чем " << num1;
		}
		else if (num1 < num2) {
			cout << "Число " << num1 << " меньше чем " << num2;
		}
		else {
			cout << "Числа равные";
		}
	}

	{
		cout << "\nThird Task\n";
		double num;
		cout << "Введите число: ";
		cin >> num;
		if (num > 0) {
			cout << "Число положительное";
		}
		else if (num < 0) {
			cout << "Число отрицательное";
		}
		else {
			cout << "Число равно нулю";
		}
	}

	{
		cout << "\nFourth Task\n";
		double num1, num2;
		cout << "Введите 1 число: ";
		cin >> num1;
		cout << "Введите 2 число: ";
		cin >> num2;
		if (num1 == num2) {
			cout << "Числа равные";
		}
		else {
			if (num1 > num2) {
				cout << num2 << ' ' << num1;
			}
			else {
				cout << num1 << ' ' << num2;
			}
		}
	}

	{
		cout << "\nFifth Task\n";
		int grade1, grade2, grade3, grade4, grade5;
		double average;
		cout << "Введите 5 оценок студента для проверки допуска к экзамену: \n";
		cout << "> ";
		cin >> grade1;
		cout << "> ";
		cin >> grade2;
		cout << "> ";
		cin >> grade3;
		cout << "> ";
		cin >> grade4;
		cout << "> ";
		cin >> grade5;
		average = (grade1 + grade2 + grade3 + grade4 + grade5) / 5.0;
		if (average >= 4.0) {
			cout << "Студент допускается к экзамену, так как его средний балл " << average << " , что больше или равно 4";
		}
		else {
			cout << "Студент не допускается к экзамену, так как его средний балл " << average << " , что меньше 4";
		}
	}

	{
		cout << "\nSixth Task\n";
		int num;
		cout << "Введите число: ";
		cin >> num;
		if (num % 2 == 0) {
			cout << "Так как число парное, то результат будет: " << num * 3;
		}
		else {
			cout << "Так как число не парное, то результат будет: " << num / 2;
		}
	}

	{
		cout << "\nSeventh Task\n";
		cout << "Добро пожаловать в калькулятор\n";
		double num1, num2;
		int choice, choicenum, exit;
		while (true) {
			choice = 0;
			choicenum = 0;
			exit = 0;
			cout << "Введите 1 число: ";
			cin >> num1;
			cout << "Введите 2 число: ";
			cin >> num2;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
				cout << "Введите действие, которое вы хотите сделать с числами (1 - прибавление, 2 - отнимание, 3 - умножение, 4 - деление): \n";
				cin >> choice;
			}
			if (choice == 2 || choice == 4) {
				while (choicenum != 1 && choicenum != 2) {
					cout << "От какого/какое числа/о вы хотите отнять/поделить?(От 1/2?): ";
					cin >> choicenum;
				}
			}
			switch (choice) {
			case 1: {
				cout << "Результат прибавления 2 ваших чисел будет равен: " << num1 + num2;
				break;
			}
			case 2: {
				if (choicenum == 1) {
					cout << "Результат отнимания от числа " << num1 << " будет равен: " << num1 - num2;
					break;
				}
				else {
					cout << "Результат отнимания от числа " << num2 << " будет равен: " << num2 - num1;
					break;
				}
			}
			case 3: {
				cout << "Результат умножения 2 ваших чисел будет равен: " << num1 * num2;
				break;
			}
			case 4: {
				if (choicenum == 1) {
					cout << "Результат деления числа " << num1 << " на число " << num2 << " будет равен: " << num1 / num2;
					break;
				}
				else {
					cout << "Результат деления числа " << num2 << " на число " << num1 << " будет равен: " << num2 / num1;
					break;
				}
			}
			}
			cout << "\nВыйти из калькулятора? (1 - да, 2 - нет): ";
			cin >> exit;
			if (exit == 1) {
				break;
			}
		}
	}

	{
		cout << "\nEighth Task\n";
		double num;
		int degree;
		double result = 1.0;
		cout << "Введите число, которое хотите возвести в степень: ";
		cin >> num;
		cout << "Введите степень от 0 до 7 включительно, в которую хотите возвести число: ";
		cin >> degree;
		if (degree >= 0 && degree <= 7) {
			if (degree != 0) {
				for (int i = 1; i <= degree; i++) {
					result *= num;
				}
			}
			cout << num << " в " << degree << " степени = " << result << '\n';
		}
		else {
			cout << "Эта степень не в заданном диапазоне";
		}
	}

	{
		cout << "\nBonus Task\n";
		char backgroundcolor, textcolor;
		cout << "Введите цвет фона заднего (0-черный,1-синий,2-зеленый,3-голубой,4-красный,5-фиолетовый,6-желтый,7-белый): ";
		cin >> backgroundcolor;
		cout << "Введите цвет текста (0-черный,1-синий,2-зеленый,3-голубой,4-красный,5-фиолетовый,6-желтый,7-белый): ";
		cin >> textcolor;
		string color = "color ";
		color += backgroundcolor;
		color += textcolor;
		system(color.c_str());
		cout << "Вот ваш цвет, опробуйте его\n";
	}
}

