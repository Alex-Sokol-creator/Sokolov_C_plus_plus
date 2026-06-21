
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
	T** new_masiv = new T * [new_rows];
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

template <typename T>
void Telephone(T***& masiv, const int rows = 2, int& cols = 0) {
	cout << "Добро пожаловать в телефонную книгу\n";
	int exit = 0;
	while (exit != 1) {
		int action = 0;
		while (action != 1 && action != 2 && action != 3) {
			cout << "Что вы хотите сделать? (1 - поиск контакта, 2 - записать новый контакт, 3 - вывести телефонную книгу): ";
			cin >> action;
		}
		if (action == 1) {
			int search_choice = 0;
			while (search_choice != 1 && search_choice != 2) {
				cout << "Вы хотите искать по имени или по номеру телефона?(выбор соответственный): ";
				cin >> search_choice;
			}
			if (search_choice == 1) {
				cout << "Введите имя контакта: ";
				char buffer[1000];
				cin.ignore();
				cin.getline(buffer, 1000);
				int size = strlen(buffer) + 1;
				char* name = new char[size];
				strcpy_s(name, size, buffer);
				int result = 0;
				for (int i = 0; i < cols; i++) {
					if (masiv[0][i] != nullptr && strcmp(name, masiv[0][i]) == 0) {
						cout << "Контакт " << name << " найден под номером " << i + 1 << " , у него номер " << masiv[1][i] << '\n';
						result = 1;
						break;
					}
				}
				if (result == 0) {
					cout << "К сожалению, контакт " << name << " отсутствует\n";
				}
			}
			else {
				cout << "Введите номер контакта: ";
				char buffer[50];
				cin.ignore();
				cin.getline(buffer, 50);
				int size = strlen(buffer) + 1;
				char* number = new char[size];
				strcpy_s(number, size, buffer);
				int result = 0;
				for (int i = 0; i < cols; i++) {
					if (masiv[1][i] != nullptr && strcmp(number, masiv[1][i]) == 0) {
						cout << "Контакт с телефоном " << number << " найден под номером " << i + 1 
							<< " , у него имя " << masiv[0][i] << '\n';
						result = 1;
						break;
					}
				}
				if (result == 0) {
					cout << "К сожалению, контакт с телефоном " << number << " отсутствует\n";
				}
			}
		}
		else if (action == 2) {
			T*** masiv_new = new T * *[rows];
			for (int i = 0; i < rows; i++) {
				masiv_new[i] = new T* [cols + 1];
			}
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					masiv_new[i][j] = masiv[i][j];
				}
				masiv_new[i][cols] = nullptr;
			}
			if (masiv != nullptr) {
				for (int i = 0; i < rows; i++) {
					delete[] masiv[i];
				}
				delete[] masiv;
			}
			masiv = masiv_new;
			cols++;
			cout << "Введите имя контакта: ";
			char buffer[1000];
			cin.ignore();
			cin.getline(buffer, 1000);
			int size = strlen(buffer) + 1;
			char* name = new char[size];
			strcpy_s(name, size, buffer);
			masiv[0][cols - 1] = name;
			cout << "Введите номер контакта: ";
			cin.getline(buffer, 1000);
			size = strlen(buffer) + 1;
			char* number = new char[size];
			strcpy_s(number, size, buffer);
			masiv[1][cols - 1] = number;
			cout << "Контакт с именем " << name << " и телефоном " << number << " записан";
		}
		else {
			cout << "Вот ваша телефонная книга: \n";
			for (int i = 0; i < cols; i++) {
				for (int j = 0; j < rows; j++) {
					cout << masiv[j][i] << " ";
				}
				cout << "\n";
			}
		}
		cout << "\nХотите завершить программу?(1 - да, любое число - нет): ";
		cin >> exit;
	}
	cout << "До свидания!\n";
}

void CountEverything(int rows, int cols, int& everything) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			everything++;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	
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
		int cols = 0;
		char*** phoneBook = new char** [rows];
		for (int i = 0; i < rows; i++) {
			phoneBook[i] = nullptr;
		}
		Telephone(phoneBook, rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				delete[] phoneBook[i][j];
			}
			delete[] phoneBook[i];
		}
		delete[] phoneBook;
	}

	{
		cout << "\nSixth Task\n";
		const int count = 5;
		char** surnames = new char* [count];
		cout << "Введите 5 фамилий студентов:\n";
		cin.ignore();
		for (int i = 0; i < count; i++) {
			char buffer[50];
			cout << i + 1 << " студент: ";
			cin.getline(buffer, 50);
			int size = strlen(buffer) + 1;
			surnames[i] = new char[size];
			strcpy_s(surnames[i], size, buffer);
		}
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (strlen(surnames[j]) > strlen(surnames[j + 1])) {
					char* temp = surnames[j + 1];
					surnames[j + 1] = surnames[j];
					surnames[j] = temp;
				}
			}
		}
		cout << "\nФамилии студентов по возрастанию:\n";
		for (int i = 0; i < count; i++) {
			cout << surnames[i] << '\n';
		}
		for (int i = 0; i < count; i++) {
			delete[] surnames[i];
		}
		delete[] surnames;
	}

	{
		cout << "\nSeventh Task\n";
		int rows_a, rows_b, rows_c, cols_a, cols_b, cols_c;
		cout << "Введите количество строк для массива А: ";
		cin >> rows_a;
		cout << "Введите количество колонок для массива А: ";
		cin >> cols_a;
		int** A = new int* [rows_a];
		cout << "Вот массив А: \n";
		for (int i = 0; i < rows_a; i++) {
			A[i] = new int[cols_a];
			for (int j = 0; j < cols_a; j++) {
				A[i][j] = rand() % 41 - 20;
				cout << A[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "Введите количество строк для массива B: ";
		cin >> rows_b;
		cout << "Введите количество колонок для массива B: ";
		cin >> cols_b;
		int** B = new int* [rows_b];
		cout << "Вот массив B: \n";
		for (int i = 0; i < rows_b; i++) {
			B[i] = new int[cols_b];
			for (int j = 0; j < cols_b; j++) {
				B[i][j] = rand() % 41 - 20;
				cout << B[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "Введите количество строк для массива C: ";
		cin >> rows_c;
		cout << "Введите количество колонок для массива C: ";
		cin >> cols_c;
		int** C = new int* [rows_c];
		cout << "Вот массив C: \n";
		for (int i = 0; i < rows_c; i++) {
			C[i] = new int[cols_c];
			for (int j = 0; j < cols_c; j++) {
				C[i][j] = rand() % 41 - 20;
				cout << A[i][j] << ' ';
			}
			cout << "\n";
		}

		int uniques = 0, everything = 0;
		CountEverything(rows_a, cols_a, everything);
		CountEverything(rows_b, cols_b, everything);
		CountEverything(rows_c, cols_c, everything);
		int all_elements
	}
}

