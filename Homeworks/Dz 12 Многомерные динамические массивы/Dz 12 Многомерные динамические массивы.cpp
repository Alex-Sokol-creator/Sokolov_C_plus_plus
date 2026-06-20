
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void PrintMasiv(T** masiv, int rows, int cols) {
	cout << "Вот ваш массив: \n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << masiv[i][j] << " ";
		}
		cout << "\n";
	}
}

template <typename T>
T** AddVertical(T** masiv, int rows, int& cols, int position) {
	int index = position - 1;
	if (index < 0) {
		cout << "К сожалению, нельзя добавить столбик на такую позицию\n";
		return masiv;
	}
	T** masiv_new = new T * [rows];
	for (int i = 0; i < rows; i++) {
		masiv_new[i] = new T[cols + 1];
	}
	if (index >= cols) {
		index = cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				masiv_new[i][j] = masiv[i][j];
			}
			masiv_new[i][index] = rand() % 10;
		}
		cols++;
	}
	else if (index > 0 && index < cols) {
		for (int i = 0; i < rows; i++) {
			for (int c = 0; c < index; c++) {
				masiv_new[i][c] = masiv[i][c];
			}
		}
		for (int i = 0; i < rows; i++) {
			masiv_new[i][index] = rand() % 10;
		}
		for (int j = index; j < cols; j++) {
			for (int c = 0; c < rows; c++) {
				masiv_new[c][j + 1] = masiv[c][j];
			}
		}
		cols++;
	}
	else {
		for (int i = 0; i < rows; i++) {
			masiv_new[i][index] = rand() % 10;
		}
		for (int j = index; j < cols; j++) {
			for (int c = 0; c < rows; c++) {
				masiv_new[c][j + 1] = masiv[c][j];
			}
		}
		cols++;
	}
	for (int i = 0; i < rows; i++) {
		delete[] masiv[i];
	}
	delete[] masiv;
	masiv = masiv_new;
	return masiv;
}

template <typename T>
T** DeleteVertical(T** masiv, int rows, int& cols, int position) {
	int index = position - 1;
	if (index < 0 || index >= cols) {
		cout << "К сожалению, нельзя удалить столбик с такой позицией\n";
		return masiv;
	}

	T** masiv_new = new T * [rows];
	for (int i = 0; i < rows; i++) {
		masiv_new[i] = new T[cols - 1];
	}

	for (int i = 0; i < rows; i++) {
		for (int c = 0; c < index; c++) {
			masiv_new[i][c] = masiv[i][c];
		}
	}
	for (int j = index + 1; j < cols; j++) {
		for (int c = 0; c < rows; c++) {
			masiv_new[c][j - 1] = masiv[c][j];
		}
	}
	cols--;

	for (int i = 0; i < rows; i++) {
		delete[] masiv[i];
	}
	delete[] masiv;
	masiv = masiv_new;
	return masiv;
}

template <typename T>
T** MoveRows(T** masiv, int rows, int cols, int wayrows, int moverows) {
	switch (wayrows) {
	case 1: {
		for (int i = 0; i < moverows; i++) {
			for (int j = 0; j < cols; j++) {
				T temp = masiv[0][j];
				for (int c = 0; c < rows - 1; c++) {
					masiv[c][j] = masiv[c + 1][j];
				}
				masiv[rows - 1][j] = temp;
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < moverows; i++) {
			for (int j = 0; j < cols; j++) {
				T temp = masiv[rows - 1][j];
				for (int c = rows - 1; c > 0; c--) {
					masiv[c][j] = masiv[c - 1][j];
				}
				masiv[0][j] = temp;
			}
		}
		break;
	}
	}
	return masiv;
}

template <typename T>
T** MoveCols(T** masiv, int rows, int cols, int waycols, int movecols) {
	switch (waycols) {
	case 1: {
		for (int i = 0; i < movecols; i++) {
			for (int j = 0; j < rows; j++) {
				T temp = masiv[j][0];
				for (int c = 0; c < cols - 1; c++) {
					masiv[j][c] = masiv[j][c + 1];
				}
				masiv[j][cols - 1] = temp;
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < movecols; i++) {
			for (int j = 0; j < rows; j++) {
				T temp = masiv[j][cols - 1];
				for (int c = cols - 1; c > 0; c--) {
					masiv[j][c] = masiv[j][c - 1];
				}
				masiv[j][0] = temp;
			}
		}
		break;
	}
	}
	return masiv;
}

template <typename T>
T** MovingMasiv(T** masiv, int rows, int cols, int wayrows = 0, int waycols = 0, int choice = 0) {
	while (wayrows != 1 && wayrows != 2) {
		cout << "В какую сторону вы хотите сдвинуть строки? (1 - наверх, 2 - вниз): ";
		cin >> wayrows;
	}
	int moverows = -1;
	while (moverows < 0) {
		cout << "Насколько вы хотите сдвинуть?: ";
		cin >> moverows;
	}
	while (choice != 1 && choice != 2) {
		cout << "Вы хотите сдвигать колонки? (1 - да, 2 - нет): ";
		cin >> choice;
	}
	if (choice == 1) {
		while (waycols != 1 && waycols != 2) {
			cout << "В какую сторону вы хотите сдвинуть колонки? (1 - влево, 2 - вправо): ";
			cin >> waycols;
		}
		int movecols = -1;
		while (movecols < 0) {
			cout << "Насколько вы хотите сдвинуть?: ";
			cin >> movecols;
		}
		masiv = MoveRows(masiv, rows, cols, wayrows, moverows);
		masiv = MoveCols(masiv, rows, cols, waycols, movecols);
	}
	else {
		masiv = MoveRows(masiv, rows, cols, wayrows, moverows);
	}
	cout << "Производятся указаные операции...\n";
	return masiv;
}

template <typename T>
T** Transposition(T** masiv, int& rows, int& cols) {
	cout << "Идет транспонирование массива...\n";
	int new_rows = cols;
	int new_cols = rows;
	T** new_masiv = new T* [new_rows];
	for (int i = 0; i < new_rows; i++) {
		new_masiv[i] = new T[new_cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			new_masiv[j][i] = masiv[i][j];
		}
	}
	int old_rows = rows;
	rows = new_rows;
	cols = new_cols;
	for (int i = 0; i < old_rows; i++) {
		delete[] masiv[i];
	}
	delete[] masiv;
	return new_masiv;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	/*
	int** arr_3x5 = new int* [size_x];
	for (int i = 0; i < size_x; i++) {
		arr_3x5[i] = new int[size_y];
		for (int j = 0; j < size_y; j++) {
			arr_3x5[i][j] = rand() % 10;
			cout << arr_3x5[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	{
		cout << "\nFirst Task\n";
		int rows = 3, cols = 3;
		int** arr_3x3 = new int* [rows];
		cout << "Вот ваш изначальный массив: \n";
		for (int i = 0; i < rows; i++) {
			arr_3x3[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				arr_3x3[i][j] = rand() % 10;
				cout << arr_3x3[i][j] << ' ';
			}
			cout << '\n';
		}
		int col_enter;
		cout << "На какую позицию вы хотите добавить столбик?: ";
		cin >> col_enter;
		arr_3x3 = AddVertical(arr_3x3, rows, cols, col_enter);
		PrintMasiv(arr_3x3, rows, cols);
		for (int i = 0; i < rows; i++) {
			delete[] arr_3x3[i];
		}
		delete[] arr_3x3;
	}

	{
		cout << "\nSecond Task\n";
		int rows = 3, cols = 3;
		int** arr_3x3 = new int* [rows];
		cout << "Вот ваш изначальный массив: \n";
		for (int i = 0; i < rows; i++) {
			arr_3x3[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				arr_3x3[i][j] = rand() % 10;
				cout << arr_3x3[i][j] << ' ';
			}
			cout << '\n';
		}
		int col_enter;
		cout << "С какой позиции вы хотите удалить столбик?: ";
		cin >> col_enter;
		arr_3x3 = DeleteVertical(arr_3x3, rows, cols, col_enter);
		PrintMasiv(arr_3x3, rows, cols);
		for (int i = 0; i < rows; i++) {
			delete[] arr_3x3[i];
		}
		delete[] arr_3x3;
	}

	{
		cout << "\nThird Task\n";
		int M, N;
		cout << "Введите, сколько строчек будет в вашем массиве: ";
		cin >> M;
		cout << "Введите, сколько столбиков будет в вашем массиве: ";
		cin >> N;
		int** masiv = new int* [M];
		cout << "Вот ваш изначальный массив: \n";
		for (int i = 0; i < M; i++) {
			masiv[i] = new int[N];
			for (int j = 0; j < N; j++) {
				masiv[i][j] = rand() % 10;
				cout << masiv[i][j] << ' ';
			}
			cout << '\n';
		}
		masiv = MovingMasiv(masiv, M, N);
		PrintMasiv(masiv, M, N);
		for (int i = 0; i < M; i++) {
			delete[] masiv[i];
		}
		delete[] masiv;
	}

	{
		cout << "\nFourth Task\n";
		int rows, cols;
		cout << "Введите, сколько строчек будет в вашем массиве: ";
		cin >> rows;
		cout << "Введите, сколько столбиков будет в вашем массиве: ";
		cin >> cols;
		int** masiv = new int* [rows];
		cout << "Вот ваш изначальный массив: \n";
		for (int i = 0; i < rows; i++) {
			masiv[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				masiv[i][j] = rand() % 10;
				cout << masiv[i][j] << ' ';
			}
			cout << '\n';
		}
		masiv = Transposition(masiv, rows, cols);
		PrintMasiv(masiv, rows, cols);
		for (int i = 0; i < rows; i++) {
			delete[] masiv[i];
		}
		delete[] masiv;
	}

	{
		cout << "\nFifth Task\n";
		const int rows = 2;
		int cols;

	}
}

