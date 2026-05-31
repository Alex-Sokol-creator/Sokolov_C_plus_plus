
#include <iostream>
#include <Windows.h>

using namespace std;


int FirstTask(int arr[], int size, int choice) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == choice) {
			return i;
		}
	}
	return -1;
}

int SecondTask(int arr[], int size, int choice) {
	/*
	int middle = size / 2;
	if (choice < middle) {
		for (int i = 0; i < middle; i++) {
			if (arr[i] == choice) {
				return i;
			}
		}
	}
	else if (choice > middle) {
		for (int i = middle + 1; i < size; i++) {
			if (arr[i] == choice) {
				return i;
			}
		}
	}
	else {
		return middle;
	}
	*/
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == choice) {
			return mid;
		}
		else if (arr[mid] < choice) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		cout << "\nFirst Task\n";
		const int size = 5;
		int masiv[size] = { 10,5,6,67,89 };
		int choice;
		cout << "Введите число для поиска в массиве: ";
		cin >> choice;
		int index = FirstTask(masiv, size, choice);
		if (index != -1) {
			cout << "Элемент был найден, у него индекс " << index << " в массиве\n";
		}
		else {
			cout << "Элемент не был найден в массиве\n";
		}
	}

	{
		cout << "\nSecond Task\n";
		const int size = 5;
		int masiv[size] = { 5,7,67,87,1456 };
		int choice;
		cout << "Введите число для поиска в массиве: ";
		cin >> choice;
		int index = SecondTask(masiv, size, choice);
		if (index != -1) {
			cout << "Элемент был найден, у него индекс " << index << " в массиве\n";
		}
		else {
			cout << "Элемент не был найден в массиве\n";
		}
	}
}
