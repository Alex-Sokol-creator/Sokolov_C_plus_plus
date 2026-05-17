
#include <iostream>
#include <Windows.h>

using namespace std;

void firsttask(int N, int K, char symbol) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << symbol << ' ';
		}
		cout << '\n';
	}
}

void secondtask(int number) {
	int result = 1;
	if (number >= 0) {
		for (int i = 1; i <= number; i++) {
			result *= i;
		}
		cout << "Вот ваш факториал числа " << number << ": " << result;
	}
	else {
		cout << "Невозможно найти факториал отрицательного числа";
	}
}

int secondtask2(int number) {
	int result = 1;
	for (int i = 1; i <= number; i++) {
		result *= i;
	}
	return (result);
}

int thirdtask(int number) {
	int countdividers = 0;
	for (int i = 1; i <= number; i++) {
		if (number % i == 0) {
			countdividers += 1;
		}
	}
	if (countdividers == 2) {
		return (1);
	}
	else {
		return(0);
	}
}

int fourthtask(int number) {
	int result = 1;
	for (int i = 1; i <= 3; i++) {
		result *= number;
	}
	return (result);
}

double fifthtask(double number1, double number2) {
	if (number1 > number2) {
		return (number1);
	}
	else {
		return (number2);
	}
}

bool sixthtask(double number) {
	if (number >= 0) {
		return (true);
	}
	else {
		return (false);
	}
}

void seventhtask(double masiv[], int size) {
	double maxnum = masiv[0], minnum = masiv[0];
	int maxindex = 0, minindex = 0;
	for (int i = 0; i < size; i++) {
		if (masiv[i] > maxnum) {
			maxnum = masiv[i];
			maxindex = i;
		}
		if (masiv[i] < minnum) {
			minnum = masiv[i];
			minindex = i;
		}
	}
	cout << "Максимальное число в массиве это " << maxnum << " с индексом " << maxindex << " ,а минимальное число это " << minnum
		<< " с индексом " << minindex;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
	{
		cout << "\nFirst Task\n";
		int k, n;
		char sym;
		cout << "Введите ширину прямоугольника: ";
		cin >> k;
		cout << "Введите высоту прямоугольника: ";
		cin >> n;
		cout << "Введите символ, для заполнения прямоугольника: ";
		cin >> sym;
		cout << "Вот ваш прямоугольник: \n";
		firsttask(n, k, sym);
	}
	*/

	/* {
		cout << "\nSecond Task\n";
		int num;
		cout << "Введите число для нахождения его факториала: ";
		cin >> num;
		// secondtask(num);
		cout << "Вот ваш факториал числа " << num << ": " << secondtask2(num);
	}*/

	/* {
	   cout << "\nThird Task\n";
	   int num;
	   cout << "Введите число на проверку простоты: ";
	   cin >> num;
	   if (thirdtask(num) == 1) {
		   cout << "Ваше число простое, так как делится только на себя и на 1";
	   }
	   else {
		   cout << "Ваше число не простое, так как оно не делится только на себя и на 1";
	   }
   }*/

   /* {
	   cout << "\nFourth Task\n";
	   int num;
	   cout << "Введите число для возведения его в куб: ";
	   cin >> num;
	   cout << "Ваше число в кубе будет: " << fourthtask(num);
   }*/

   /* {
	   cout << "\nFifth Task\n";
	   double num1, num2;
	   cout << "Введите 1 число: ";
	   cin >> num1;
	   cout << "Введите 2 число: ";
	   cin >> num2;
	   if (num1 == num2) {
		   cout << "Числа равные";
	   }
	   else {
		   cout << "Наибольшее число из 2 это: " << fifthtask(num1, num2);
	   }

   }*/

	/* {
		cout << "\nSixth Task\n";
		int num;
		cout << "Введите число: ";
		cin >> num;
		if (sixthtask(num) == true) {
			cout << "Результат функции: true";
		}
		else {
			cout << "Результат функции: false";
		}

	}*/

	/* {
		cout << "\nSeventh Task\n";
		const int size = 5;
		double masiv[size];
		double num;
		cout << "Заполните массив из 5 элементов\n";
		for (int i = 0; i < size; i++) {
			cout << "Введите " << i+1 << " число для записывания его в массив: ";
			cin >> num;
			masiv[i] = num;
		}
		seventhtask(masiv,size);
	}*/

	{
		cout << "\nEight Task\n";

	}
}

