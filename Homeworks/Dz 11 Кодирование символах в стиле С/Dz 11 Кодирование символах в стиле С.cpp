
#include <iostream>
#include <Windows.h>

using namespace std;

void SymbolsCount(char* stroka) {
	int letters = 0, figures = 0, symbols = 0;
	for (int i = 0; stroka[i] != '\0'; i++) {
		if (stroka[i] >= '0' && stroka[i] <= '9') {
			figures++;
		}
		else if ((stroka[i] >= 'A' && stroka[i] <= 'Z') || (stroka[i] >= 'a' && stroka[i] <= 'z')) {
			letters++;
		}
		else {
			symbols++;
		}
	}
	cout << "В вашей строке: \n" << figures << " чисел/числа/число\n" << letters << " букв/буква/буквы\nи " << symbols << " символов/символа/символ\n";
}

int mystrcmp(const char* str1, const char* str2) {
	/*
	int size1 = 0, size2 = 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		size1 += str1[i];
	}
	for (int i = 0; str2[i] != '\0'; i++) {
		size2 += str2[i];
	}
	if (size1 > size2) {
		return 1;
	}
	else if (size1 < size2) {
		return -1;
	}
	else {
		return 0;
	}
	*/
	int i = 0;

	while (str1[i] != '\0' && str1[i] == str2[i]) {
		i++;
	}

	if (str1[i] > str2[i]) {
		return 1;
	}
	else if (str1[i] < str2[i]) {
		return -1;
	}
	else {
		return 0;
	}
}

int StringToNumber(char* str) {
	/*
	int result = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		result += str[i];
	}
	return result;
	*/

	int result = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + (str[i] - '0');
		}
		else {
			if (str[i] != '-' || (i > 0 && str[i] == '-')) {
				break;
			}
		}
	}
	if (str[0] == '-') {
		result = -result;
	}
	return result;

	/*
	int result = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + (str[i] - '0');
		}
		else if (i == 0 && str[i] == '-'){
			continue;
		}
		else{
			continue;
		}
	}
	if (str[0] == '-') {
		result = -result;
	}
	return result;
	*/
}

char* NumberToString(int number) {
	int size = 0;
	int numbercopy = number;
	if (numbercopy == 0) {
		size = 1;
	}
	else {
		if (numbercopy < 0) {
			size++;
			numbercopy = -numbercopy;
		}
		while (numbercopy > 0) {
			size++;
			numbercopy = numbercopy / 10;
		}
	}
	char* stroka = new char[size + 1];
	if (number < 0) {
		stroka[size] = '\0';
		stroka[0] = '-';
		int number_positive = -number;
		for (int i = size - 1; i > 0; i--) {
			stroka[i] = number_positive % 10 + '0';
			number_positive = number_positive / 10;
		}
	}
	else {
		stroka[size] = '\0';
		for (int i = size - 1; i >= 0; i--) {
			stroka[i] = number % 10 + '0';
			number = number / 10;
		}
		//for (int i = 0; i < size / 2; i++) {
		//	char temp = stroka[i];
		//	stroka[i] = stroka[size - i - 1];
		//	stroka[size - i - 1] = temp;
		//}
	}
	return stroka;
}

char* Uppercase(char* str1) {
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] >= 'a' && str1[i] <= 'z') {
			str1[i] = str1[i] - 32;
		}
	}
	return str1;
}

char* Lowercase(char* str1) {
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') {
			str1[i] = str1[i] + 32;
		}
	}
	return str1;
}

char* mystrrev(char* str) {
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
	}
	char* str_new = new char[size + 1];
	for (int i = 0; i < size; i++) {
		str_new[i] = str[i];
	}
	for (int i = 0; i < size / 2; i++) {
		char temp = str_new[i];
		str_new[i] = str_new[size - i - 1];
		str_new[size - i - 1] = temp;
	}
	str_new[size] = '\0';
	return str_new;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		cout << "\nFirst Task\n";
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "Введите вашу строку (по английски): ";
		// cin.ignore();
		cin.getline(buffer_enter, buffer_size);
		int size = strlen(buffer_enter);
		char* stroka = new char[size + 1];
		strcpy_s(stroka, size + 1, buffer_enter);
		SymbolsCount(stroka);
		delete[] stroka;
	}

	{
		cout << "\nSecond Task\n";
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "Введите вашу 1 строку (по английски): ";
		cin.getline(buffer_enter, buffer_size);
		int size1 = strlen(buffer_enter);
		char* stroka1 = new char[size1 + 1];
		strcpy_s(stroka1, size1 + 1, buffer_enter);

		cout << "Введите вашу 2 строку (по английски): ";
		cin.getline(buffer_enter, buffer_size);
		int size2 = strlen(buffer_enter);
		char* stroka2 = new char[size2 + 1];
		strcpy_s(stroka2, size2 + 1, buffer_enter);
		int result = mystrcmp(stroka1, stroka2);
		if (result == 0) {
			cout << "Строки равные\n";
		}
		else if (result == 1) {
			cout << "Первая строка больше за вторую\n";
		}
		else {
			cout << "Вторая строка больше за первую\n";
		}
		delete[] stroka1;
		delete[] stroka2;
	}

	{
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "\nВведите вашу строку для конвертации в число: ";
		cin.getline(buffer_enter, buffer_size);
		int size1 = strlen(buffer_enter);
		char* stroka = new char[size1 + 1];
		strcpy_s(stroka, size1 + 1, buffer_enter);
		int result = StringToNumber(stroka);
		cout << "После конвертации вашей строки в число, получилось: " << result << '\n';
		delete[] stroka;
	}

	{
		int number;
		cout << "\nВведите ваше число для конвертации в строку: ";
		cin >> number;
		cin.ignore();
		char* stroka = NumberToString(number);
		cout << "После конвертации вашего числа в строку, получилось: " << stroka << '\n';
		delete[] stroka;
	}

	{
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "\nВведите вашу строку для ее перевода в верхний регистр: ";
		cin.getline(buffer_enter, buffer_size);
		int size1 = strlen(buffer_enter);
		char* stroka = new char[size1 + 1];
		strcpy_s(stroka, size1 + 1, buffer_enter);
		char* result = Uppercase(stroka);
		cout << "\nПосле перевода вашей строки в верхний регистр, получилось: " << result << '\n';
		delete[] stroka;
	}

	{
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "\nВведите вашу строку для ее перевода в нижний регистр: ";
		cin.getline(buffer_enter, buffer_size);
		int size1 = strlen(buffer_enter);
		char* stroka = new char[size1 + 1];
		strcpy_s(stroka, size1 + 1, buffer_enter);
		char* result = Lowercase(stroka);
		cout << "\nПосле перевода вашей строки в нижний регистр, получилось: " << result << '\n';
		delete[] stroka;
	}

	{
		const int buffer_size = 256;
		char buffer_enter[buffer_size];
		cout << "\nВведите вашу строку для ее реверса: ";
		cin.getline(buffer_enter, buffer_size);
		int size1 = strlen(buffer_enter);
		char* stroka = new char[size1 + 1];
		strcpy_s(stroka, size1 + 1, buffer_enter);
		char* result = mystrrev(stroka);
		cout << "После реверса вашей строки, получилось: " << result << '\n';
		delete[] stroka;
		delete[] result;
	}
}

