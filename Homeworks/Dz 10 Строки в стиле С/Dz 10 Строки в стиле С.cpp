
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void PrintMasiv(T masiv, int size) {
	cout << "Вот ваша строка: \n";
	for (int i = 0; i < size; i++) {
		cout << masiv[i];
	}
	cout << '\n';
}

char* DeleteSymbolByIndex(char stroka[], int& size, int index) {
	cout << "Идет удаление элемента из массива...\n";
	if (index < 0 || index >= size) {
		cout << "К сожалению, такого индекса нет в массиве\n";
		return stroka;
	}
	char* temp = new char[size];
	for (int i = 0; i < index; i++) {
		temp[i] = stroka[i];
	}
	for (int i = index + 1; i < size; i++) {
		temp[i - 1] = stroka[i];
	}
	size--;
	temp[size] = '\0';
	delete[] stroka;
	stroka = temp;
	return stroka;
}

char* DeleteSymbol(char stroka[], int& size, char symbol) {
	cout << "Идет удаление элемента из массива...\n";
	int newsize = 0;
	for (int i = 0; i < size; i++) {
		if (stroka[i] != symbol) {
			newsize++;
		}
	}
	char* temp = new char[newsize + 1];
	int place = 0;
	for (int i = 0; i < size; i++) {
		if (stroka[i] != symbol) {
			temp[place] = stroka[i];
			place++;
		}
	}
	temp[newsize] = '\0';
	size = newsize;
	delete[] stroka;
	stroka = temp;
	return stroka;
}

char* AddElementByIndex(char stroka[], int& size, int index, char element) {
	if (index < 0 || index > size) {
		cout << "К сожалению, такого индекса нет в массиве\n";
		return stroka;
	}
	char* temp = new char[size + 2];
	for (int i = 0; i < index; i++) {
		temp[i] = stroka[i];
	}
	temp[index] = element;
	for (int i = index; i < size; i++) {
		temp[i + 1] = stroka[i];
	}
	size++;
	temp[size] = '\0';
	delete[] stroka;
	stroka = temp;
	return stroka;
}

char* ChangingSymbol(char stroka[], int size) {
	cout << "Идет замена элемента . на ! в массиве...\n";
	for (int i = 0; i < size; i++) {
		if (stroka[i] == '.') {
			stroka[i] = '!';
		}
	}
	return stroka;
}

int SearchingSymbol(char stroka[], int size, char symbol) {
	cout << "Идет расчет количества символа в вашей строке...\n";
	int times = 0;
	for (int i = 0; i < size;i++) {
		if (stroka[i] == symbol) {
			times++;
		}
	}
	return times;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{

		cout << "\nFirst Task\n";
		char strokabeta[] = "Hello, world!";
		int size = strlen(strokabeta);
		char* stroka = new char[size + 1];
		strcpy_s(stroka, size + 1, strokabeta);
		PrintMasiv(stroka, size);
		int index;
		cout << "Элемент с каким индексом вы хотите удалить?: ";
		cin >> index;
		stroka = DeleteSymbolByIndex(stroka, size, index);
		PrintMasiv(stroka, size);
		delete[] stroka;

	}

	{

		cout << "\nSecond Task\n";
		char strokabeta[] = "Hello, world!";
		int size = strlen(strokabeta);
		char* stroka = new char[size + 1];
		strcpy_s(stroka, size + 1, strokabeta);
		PrintMasiv(stroka, size);
		char symbol;
		cout << "Какой символ вы хотите удалить из строки?: ";
		cin >> symbol;
		stroka = DeleteSymbol(stroka, size, symbol);
		PrintMasiv(stroka, size);
		delete[] stroka;

	}

	{

		cout << "\nThird Task\n";
		char strokabeta[] = "Hello, world!";
		int size = strlen(strokabeta);
		char* stroka = new char[size + 1];
		strcpy_s(stroka, size + 1, strokabeta);
		PrintMasiv(stroka, size);
		char symbol;
		cout << "Какой символ вы хотите добавить в строку?: ";
		cin >> symbol;
		int index;
		cout << "На какую позицию (индекс) вы хотите его добавить?: ";
		cin >> index;
		stroka = AddElementByIndex(stroka, size, index, symbol);
		PrintMasiv(stroka, size);
		delete[] stroka;

	}

	{

		cout << "\nFourth Task\n";
		const int buffer_size = 256;
		char buffer_enter[buffer_size];

		cout << "Введите вашу строку: ";
		cin.ignore();
		cin.getline(buffer_enter, buffer_size);
		int size = strlen(buffer_enter);
		char* stroka = new char[size + 1];
		strcpy_s(stroka, size + 1, buffer_enter);
		PrintMasiv(stroka, size);
		stroka = ChangingSymbol(stroka, size);
		PrintMasiv(stroka, size);
		delete[] stroka;

	}

	{
		cout << "\nFifth Task\n";
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "Введите вашу строку: ";
		cin.ignore();
		cin.getline(buffer_enter, buffer_size);
		int size = strlen(buffer_enter);
		char* stroka = new char[size + 1];
		strcpy_s(stroka, size + 1, buffer_enter);
		PrintMasiv(stroka, size);
		char symbol;
		cout << "Введите символ, и программа посчитает его количество в вашей строке: ";
		cin >> symbol;
		int result = SearchingSymbol(stroka, size, symbol);
		cout << "В вашей строке символ встречается вот столько раз: " << result;
		delete[] stroka;
	}
}
