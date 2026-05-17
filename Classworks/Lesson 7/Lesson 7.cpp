
#include <iostream>
#include <Windows.h>

using namespace std;


void printArray(int arr[], int size); // Прототип функции, реализацию надо отдельно
void showGreetings();
int incrementNumberNew(int);
double sum(double, double);
int sum(int, int);
void fillArrayRandom(int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	/*
	cout << showGreetings << '\n';

	showGreetings(); // Круглые скобки вызывают функцию

	const int size = 5;
	int arr[size] = { 1,2,3,4,5 };
	printArray(arr, size);
	*/

	/* {
		int number = 10;
	}

	cout << number;
	*/

	/*
	int number = 10;

	cout << &number << '\n'; // & - оператор взятия адреса

	incrementNumber(number);

	cout << number << '\n';

	number = incrementNumber2(number);
	cout << number << '\n';
	*/

	/*
	const int size = 10;
	int arr[size] = { 10,32,45,67 };
	printArray(arr, size);
	fillArrayRandom(arr, size, -20, 20);
	printArray(arr, size);

	cout << arr << '\n';
	*/

	cout << sum(10, 12) << '\n';
	cout << sum(12.5, 6.45) << '\n';
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == 10) return;
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void showGreetings() {
	cout << "======HELLO======\n";
}

int number = 10; // Глобальная переменная


void incrementNumber(int num) {
	cout << &num << '\n';
	num++;
}

int incrementNumber2(int num) {
	cout << &num << '\n';
	return (++num);
}

int sum(int num1, int num2) {
	return num1 + num2;
}

void fillArrayRandom(int arr[], int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}
}