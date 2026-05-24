
#include <iostream>
#include <Windows.h>

using namespace std;

double degreecount(double num, int degree) {
	if (degree >= 0) {
		double result = num;
		if (degree == 0) {
			return 1;
		}
		return result * degreecount(num, degree -= 1);
	}
	else {
		double result = num;
		int degreegood = degree * -1;
		if (degree == 0) {
			return 1;
		}
		double degreenum = result * degreecount(num, degreegood -= 1);
		return (1 / degreenum);
	}
}

void starconsole(int count) {
	char symbol = '*';
	if (count == 0) {
		return;
	}
	cout << symbol << ' ';
	starconsole(count - 1);
}

long summary(long a, long b) {
	if (a > b) { // Это включая границы
		return 0;
	}
	int firstnum = a;
	a++;
	return firstnum + summary(a, b);

	/*
	a++
	if (a == b) { // Это НЕ включая границы
		return 0;
	}
	return a + summary(a, b);
	*/
}

int position(int arr[], int sizearr, int nextstep = 0, int minsum = 0, int minindex = 0) {
	int sum = 0;
	if (nextstep > sizearr - 10) {
		return minindex;
	}
	for (int i = 0; i < 10; i++) {
		sum += arr[nextstep + i];
	}
	if (nextstep == 0) {
		minsum = sum;
	}
	if (minsum > sum) {
		minsum = sum;
		minindex = nextstep;
	}
	return position(arr, sizearr, nextstep += 1, minsum, minindex);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	{
		cout << "\nFirst Task\n";
		double number;
		int degree;
		cout << "Введите число, которое хотите возвести в степень: ";
		cin >> number;
		cout << "Введите степень, в которую хотите возвести число: ";
		cin >> degree;
		cout << "После возведения числа " << number << " в степень " << degree << " оно будет равно: " << degreecount(number, degree);
	}

	{
		cout << "\nSecond Task\n";
		cout << "Пример вывода: \n";
		starconsole(6);
		int starcount;
		cout << "\nВведите количество звездочек, которые нужно вывести в ряд: ";
		cin >> starcount;
		cout << "Вот ваш ряд из звездочек: \n";
		starconsole(starcount);
	}

	{
		cout << "\nThird Task\n";
		long diap1, diap2;
		cout << "Пример работы функции: \n";
		cout << "Сумма чисел от 2 до 10 будет равна: " << summary(2, 10) << '\n';
		cout << "Введите от какого числа вывести сумму чисел: ";
		cin >> diap1;
		cout << "Введите до какого числа вывести сумму чисел: ";
		cin >> diap2;
		cout << "Сумма чисел от " << diap1 << " до " << diap2 << " будет равна: " << summary(diap1, diap2);
	}

	{
		cout << "\nFourth Task\n";
		const int size = 100;
		int masiv[size];
		for (int i = 0; i < size; i++) {
			masiv[i] = rand();
		}
		cout << "Вот массив: \n";
		for (int i = 0; i < size; i++) {
			cout << i + 1 << " элемент: " << masiv[i] << '\n';
		}

		cout << "Элемент, с которого начинается последовательность чисел с наименьшей суммой в массиве имеет индекс: " << position(masiv, size)
			<< "\nЕго номер это " << position(masiv, size) + 1;
	}
}

