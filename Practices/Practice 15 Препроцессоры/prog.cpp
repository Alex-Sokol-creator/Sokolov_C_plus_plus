
#define MY_DOUBLE
#include <iostream>
#include <Windows.h>
#include "function.h"

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	/*
	const int size = 10;
	Type array[size];
	FillArrayByRandoms(array, size);
	ShowArray(array, size);
	Type min = FindMin(array, size);
	cout << "Минимум: " << min << '\n';
	Type max = FindMax(array, size);
	cout << "Максимум: " << max << '\n';
	SortArray(array, size);
	ShowArray(array, size);
	int index;
	cout << "Введите индекс, чтобы заменить элемент в массиве с ним: ";
	cin >> index;
	Type value;
	cout << "Введите новый элемент: ";
	cin >> value;
	EditArray(array, size, index, value);
	*/

	const int size = 10;
	Type array[size];

	FillArrayByRandoms(array, size);
	ShowArray(array, size);

	Type min = FindMin(array, size);
	cout << "Минимум: " << min << '\n';

	Type max = FindMax(array, size);
	cout << "Максимум: " << max << '\n';

	SortArray(array, size);
	ShowArray(array, size);

	int index;
	cout << "Введите индекс, чтобы заменить элемент в массиве с ним: ";
	cin >> index;

	Type value;
	cout << "Введите новый элемент: ";
	cin >> value;

	EditArray(array, size, index, value);

	cout << "Обновленный массив:\n";
	ShowArray(array, size);
}