
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

	/* {
		cout << "\nThird Task\n";
		const int N = 10;
		double numbers[N] = { 1.0,1.6,-0.9,-6.7,76.12,-2.5, 4.0, 12.3, -7.1, 0.5 };
		double sumnegative = 0, multiplying = 1, multiplyingcount = 1, sumbetweennegative = 0;
		int maxnumind = 0, minnumind = 0, numdop, firstnegative = 0, secondnegative = 0;
		for (int i = 0; i < N; i++) {
			if (numbers[i] < 0) {
				sumnegative += numbers[i];
			}
			if (numbers[maxnumind] < numbers[i]) {
				maxnumind = i;
			}
			if (numbers[minnumind] > numbers[i]) {
				minnumind = i;
			}
		}
		if (maxnumind < minnumind) {
			numdop = maxnumind;
			maxnumind = minnumind;
			minnumind = numdop;
		}
		for (int i = minnumind + 1; i < maxnumind;i++) {
			multiplying *= numbers[i];
		}
		for (int i = 1; i < N; i += 2) {
			multiplyingcount *= numbers[i];
		}
		for (int i = N - 1; i >= 0; i--) {
			if (numbers[i] < 0) {
				secondnegative = i;
				break;
			}
		}
		for (int i = 0; i < N; i++) {
			if (numbers[i] < 0) {
				firstnegative = i;
				break;
			}
		}
		for (int i = firstnegative + 1; i < secondnegative; i++) {
			sumbetweennegative += numbers[i];
		}
		if (numbers[maxnumind] > numbers[minnumind]) {
			cout << "Сумма отрицательных элементов в массиве: " << sumnegative << "\nПроизведение чисел между минимумом " << numbers[minnumind]
				<< " и максимумом " << numbers[maxnumind] << " : " << multiplying << "\nПроизведение элементов с парными номерами: " << multiplyingcount
				<< "\nСумма элементов между первый отрицательным числом " << numbers[firstnegative] << " и последним отрицательным числом "
				<< numbers[secondnegative] << " : " << sumbetweennegative << '\n';
		}
		else {
			cout << "Сумма отрицательных элементов в массиве: " << sumnegative << "\nПроизведение чисел между минимумом " << numbers[maxnumind]
				<< " и максимумом " << numbers[minnumind] << " : " << multiplying << "\nПроизведение элементов с парными номерами: " << multiplyingcount
				<< "\nСумма элементов между первый отрицательным числом " << numbers[firstnegative] << " и последним отрицательным числом "
				<< numbers[secondnegative] << " : " << sumbetweennegative << '\n';
		}
	}*/

	/*{
		cout << "\nFourth Task\n";
		int numbers[10] = { 1,2,3,4,5,6,7,8,9,10 };
		int masiv1[5] = {}, masiv2[5] = {};
		int place = 0;
		for (int i = 0; i < 5; i++) {
			masiv1[place] = numbers[i];
			place += 1;
		}
		place = 0;
		for (int i = 5; i < 10; i++) {
			masiv2[place] = numbers[i];
			place += 1;
		}
		cout << "Вот ваш 1 большой массив: ";
		for (int num : numbers) {
			cout << num << ' ';
		}
		cout << "\nА вот ваши 2 маленькие массивы: \n";
		cout << "1: ";
		for (int num : masiv1) {
			cout << num << ' ';
		}
		cout << "\n2: ";
		for (int num : masiv2) {
			cout << num << ' ';
		}
	}*/

	{
		cout << "\nFifth Task\n";

	}
}

