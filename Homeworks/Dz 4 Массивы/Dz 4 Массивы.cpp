
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int maxdiap = 25;
	int maxrand = 10000;

	/* {
		cout << "\nFirst Task\n";
		const int size = 25;
		int numbers[size] = {};
		for (int i = 0; i < size; i++) {
			int numrand = rand() % maxrand;
			numbers[i] = numrand;
		}
		int maxnum = numbers[0], minnum = numbers[0];
		cout << "Вот ваш массив: \n";
		for (int num : numbers) {
			cout << num << '\n';
		}
		for (int i = 0; i < size; i++) {
			if (numbers[i] > maxnum) {
				maxnum = numbers[i];
			}
			if (numbers[i] < minnum) {
				minnum = numbers[i];
			}
		}
		cout << "Максимальное число в массиве это: " << maxnum << '\n';
		cout << "Минимальное число в массиве это: " << minnum << '\n';
	}*/

	/* {
		cout << "\nSecond Task\n";
		double income[12] = {};
		double incomeenter;
		int diapstart;
		int diapend;
		for (int i = 0; i < 12; i++) {
			incomeenter = 0;
			cout << "Введите прибыль фирмы за " << i + 1 << " месяц: ";
			cin >> incomeenter;
			income[i] = incomeenter;
		}
		cout << "Введите месяц, с которого начать искать максимум и минимум: ";
		cin >> diapstart;
		cout << "Введите месяц, которым закончить искать максимум и минимум: ";
		cin >> diapend;
		double minincome = income[diapstart-1];
		double maxincome = income[diapstart-1];
		int monthmax = diapstart-1, monthmin = diapstart-1;
		for (int i = diapstart-1; i < diapend; i++) {
			if (income[i] > maxincome) {
				maxincome = income[i];
				monthmax = i;
			}
			if (income[i] < minincome) {
				minincome = income[i];
				monthmin = i;
			}
		}
		cout << "Наилучший доход был в " << monthmax + 1 << " месяце и составил " << maxincome << ", а наихудший был в "
			<< monthmin + 1 << " месяце, и составил " << minincome << '\n';
	}*/

	{
		cout << "\nThird Task\n";
		const int size = 10;
		double numbers[size] = { 1.0,1.6,-0.9,-6.7,76.12,-2.5, 4.0, 12.3, -7.1, 0.5 };

	}
}

