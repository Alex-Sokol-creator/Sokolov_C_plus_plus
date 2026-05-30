
#include <iostream>
#include <Windows.h>

using namespace std;

void ChangeValue(int number) {
	number += 10;
}

void ChangeValue(int* number) {
	*number += 10;
}

template <typename T>
void SwapValues(T* value1, T* value2) {
	T temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

int* badfunction() {
	int number = 10;
	return &number;
}

template <typename T>
T* linearSearch(T arr[], int size, T value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return &arr[i];
		}
	}
	return nullptr;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[] = { 10,4,56,3,67 };

	int* searchelem = linearSearch(arr, 5, 3);
	if (searchelem != nullptr) {
		cout << *searchelem << '\n';
	}
	else {
		cout << "Search failed\n";
	}

	int* ptr = arr;
	cout << *(ptr + 1) << '\n';
	cout << arr[1] << '\n';

	/*
	int x = 10;
	int z = 12;
	int arr[] = { 10,12,13 };

	cout << x << '\n';
	ChangeValue(&x);
	cout << x << '\n';

	cout << x << ' ' << z << '\n';
	SwapValues(&x, &z);
	cout << x << ' ' << z << '\n';

	int* myPtr = badfunction();
	cout << myPtr << ' ' << *myPtr << '\n';

	cout << arr << '\n';
	cout << "Адрес переменной 'х' в памяти: " << &x << endl;

	int* ptr = &x; // * - оператор показателя, хранит адресс переменной в ОЗУ

	cout << "Value of pointer 'ptr': " << ptr << '\n';
	cout << "Size of pointer: " << sizeof(ptr) << '\n';
	cout << "Value stored by adress: " << *ptr << '\n'; // * - оператор розименования, можно посмотреть значение по этому адресу

	*ptr = 15; // Можно через показатель поменять значение переменной
	cout << "Value of 'x' variable: " << x << '\n';

	*ptr += 5;
	cout << "Value of 'x' variable: " << x << '\n';

	int y = -40;

	ptr = &y; // Можно перезаписать адрес в тот же показатель

	cout << "Adress of 'y' variable: " << &y << '\n';
	cout << "Value of 'ptr' pointer: " << ptr << '\n';
	cout << "Value of 'y' pointer: " << *ptr << '\n';

	double number = 15.6;

	double* ptr1 = &number;
	double*ptr2 = &number;

	cout << "Adress of 'number' variable: " << &number << '\n';
	cout << "Value of 'ptr1' pointer: " << ptr1 << '\n';
	cout << "Value of 'ptr2' pointer: " << ptr2 << '\n';

	float a = 1.3f, b = -3.4f;

	float* const ptrF = &a; // константный покажчик

	cout << *ptrF << '\n';

	*ptrF = 4.5f;
	cout << a << '\n';

	// ptrF = &b; // нельзя

	const float* ptrOnConst = &b; // показатель на константу

	cout << *ptrOnConst << '\n';

	ptrOnConst = &a;

	// *ptrOnConst = 10.5f; // нельзя

	const float PI = 3.14f;
	const float* ptrPI = &PI;

	const float* const ptrPI2 = &PI;

	*/
}

