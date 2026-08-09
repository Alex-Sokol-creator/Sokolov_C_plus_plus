#include <iostream>
#include <Windows.h>

using namespace std;

void FillArrayByRandomsInt(int array[], int size) {
	cout << "Массив заполняется случайными значениями\n";
	for (int i = 0; i < size; i++) {
		array[i] = rand();
	}
	cout << "Массив заполнен\n";
}

void FillArrayByRandomsDouble(double array[], int size) {
	cout << "Массив заполняется случайными значениями\n";
	for (int i = 0; i < size; i++) {
		array[i] = (rand() % 100) + (rand() % 100) / 100.0;
	}
	cout << "Массив заполнен\n";
}

void FillArrayByRandomsChar(char array[], int size) {
	cout << "Массив заполняется случайными значениями\n";
	for (int i = 0; i < size; i++) {
		array[i] = 'a' + (rand() % 26);;
	}
	cout << "Массив заполнен\n";
}

void ShowArrayInt(int array[], int size) {
	cout << "Вот все элементы массива: \n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " элемент: " << array[i] << '\n';
	}
}

void ShowArrayDouble(double array[], int size) {
	cout << "Вот все элементы массива: \n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " элемент: " << array[i] << '\n';
	}
}

void ShowArrayChar(char array[], int size) {
	cout << "Вот все элементы массива: \n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " элемент: " << array[i] << '\n';
	}
}

int FindMinInt(int array[], int size) {
	cout << "Идет поиск минимального значения в массиве...\n";
	int min = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	cout << "Минимальное значение найдено\n";
	return min;
}

double FindMinDouble(double array[], int size) {
	cout << "Идет поиск минимального значения в массиве...\n";
	double min = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	cout << "Минимальное значение найдено\n";
	return min;
}

char FindMinChar(char array[], int size) {
	cout << "Идет поиск минимального значения в массиве...\n";
	char min = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	cout << "Минимальное значение найдено\n";
	return min;
}

int FindMaxInt(int array[], int size) {
	cout << "Идет поиск максимального значения в массиве...\n";
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	cout << "Максимальное значение найдено\n";
	return max;
}

double FindMaxDouble(double array[], int size) {
	cout << "Идет поиск максимального значения в массиве...\n";
	double max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	cout << "Максимальное значение найдено\n";
	return max;
}

char FindMaxChar(char array[], int size) {
	cout << "Идет поиск максимального значения в массиве...\n";
	char max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	cout << "Максимальное значение найдено\n";
	return max;
}

void SortArrayInt(int array[], int size) {
	cout << "Идет сортировка массива...\n";
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	cout << "Массив отсортирован\n";
}

void SortArrayDouble(double array[], int size) {
	cout << "Идет сортировка массива...\n";
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				double temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	cout << "Массив отсортирован\n";
}

void SortArrayChar(char array[], int size) {
	cout << "Идет сортировка массива...\n";
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				char temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	cout << "Массив отсортирован\n";
}

void EditArrayInt(int array[], int size , int index, int value) {
	if (index >= size || index < 0) {
		cout << "К сожалению, по такому индексу нельзя заменить элемент\n";
		return;
	}
	else {
		array[index] = value;
	}
}

void EditArrayDouble(double array[], int size, int index, double value) {
	if (index >= size || index < 0) {
		cout << "К сожалению, по такому индексу нельзя заменить элемент\n";
		return;
	}
	else {
		array[index] = value;
	}
}

void EditArrayChar(char array[], int size, int index, char value) {
	if (index >= size || index < 0) {
		cout << "К сожалению, по такому индексу нельзя заменить элемент\n";
		return;
	}
	else {
		array[index] = value;
	}
}
