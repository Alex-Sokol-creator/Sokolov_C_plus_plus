
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void PrintMasiv(T* masiv, int size) {
	cout << "Вот ваш массив: \n";
	for (int i = 0; i < size; i++) {
		cout << masiv[i] << ' ';
	}
	cout << '\n';
}

template <typename T>
void Initialization(T* masiv, int size) {
	cout << "Идет заполнение массива...\n";
	for (int i = 0; i < size; i++) {
		masiv[i] = rand() % 20 - 10;
	}
}

template <typename T>
double Max(T* A, T* B, int size_a, int size_b) {
	T max = A[0];
	for (int i = 0; i < size_a; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	for (int i = 0; i < size_b; i++) {
		if (B[i] > max) {
			max = B[i];
		}
	}
	return max;
}

template <typename T>
double Min(T* A, T* B, int size_a, int size_b) {
	T min = A[0];
	for (int i = 0; i < size_a; i++) {
		if (A[i] < min) {
			min = A[i];
		}
	}
	for (int i = 0; i < size_b; i++) {
		if (B[i] < min) {
			min = B[i];
		}
	}
	return min;
}

template <typename T>
double Avg(T* A, T* B, int size_a, int size_b) {
	int all_size = size_a + size_b;
	double sum = 0;
	for (int i = 0; i < size_a; i++) {
		sum += A[i];
	}
	for (int i = 0; i < size_b; i++) {
		sum += B[i];
	}
	double result = sum / all_size;
	return result;
}

template <typename T>
double Action(T* A, T* B, int size_a, int size_b, double(*function)(T*, T*, int, int)) {
	return function(A, B, size_a, size_b);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int size_a, size_b, choice = 0;
	cout << "Введите размер массива А: ";
	cin >> size_a;
	int* A = new int[size_a];
	Initialization(A, size_a);
	PrintMasiv(A, size_a);
	cout << "Введите размер массива B: ";
	cin >> size_b;
	int* B = new int[size_b];
	Initialization(B, size_b);
	PrintMasiv(B, size_b);
	while (choice < 1 || choice > 3) {
		cout << "Выберите, что вы хотите сделать (1 - max, 2 - min, 3 - avg): ";
		cin >> choice;
	}
	if (choice == 1) {
		double result = Action(A, B, size_a, size_b, Max);
		cout << "Максимум в 2 массивах это " << result << '\n';
	}
	else if (choice == 2) {
		double result = Action(A, B, size_a, size_b, Min);
		cout << "Минимум в 2 массивах это " << result << '\n';
	}
	else {
		double result = Action(A, B, size_a, size_b, Avg);
		cout << "Среднее арифметическое всех чисел в 2 массивах это " << result << '\n';
	}
	delete[] A;
	delete[] B;
}

