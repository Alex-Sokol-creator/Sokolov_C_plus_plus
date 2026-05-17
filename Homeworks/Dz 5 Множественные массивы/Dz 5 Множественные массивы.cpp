
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	{
		cout << "\nFirst Task\n";
		const int size = 3;
		// int masiv[size][size];
		int masiv[1][size];
		int num1, num2, num3, numindex = 0;
		cout << "Введите 1 число для заполнения двухмерного массива: ";
		cin >> num1;
		/*
		cout << "Введите 2 число для заполнения двухмерного массива: ";
		cin >> num2;
		cout << "Введите 3 число для заполнения двухмерного массива: ";
		cin >> num3;
		int numbers[3] = { num1,num2,num3 };
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j == 0) {
					masiv[i][j] = numbers[numindex];
				}
				else {
					masiv[i][j] = masiv[i][j - 1] * 2;
				}
			}
			numindex += 1;
		}*/

		/*
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				masiv[i][0] = num1;
			}
			else {
				masiv[i][0] = masiv[i - 1][0] * 2;
			}
		}*/

		/*
		cout << "Вот ваш итоговый массив: \n";
		for (int i = 0; i < size; i++) {
			for (int num : masiv[i]) {
				cout << num << ' ';
			}
			cout << '\n';
		}*/

		for (int j = 0; j < size; j++) {
			if (j == 0) {
				masiv[0][j] = num1;
			}
			else {
				masiv[0][j] = masiv[0][j - 1] * 2;
			}
		}

		cout << "Вот ваш итоговый массив: \n";
		for (int num : masiv[0]) {
			cout << num << ' ';
		}
	}


	{
		cout << "\nSecond Task\n";
		const int size = 3;
		// int masiv[size][size];
		int masiv[1][size];
		int num1, num2, num3, numindex = 0;
		cout << "Введите 1 число для заполнения двухмерного массива: ";
		cin >> num1;
		/*
		cout << "Введите 2 число для заполнения двухмерного массива: ";
		cin >> num2;
		cout << "Введите 3 число для заполнения двухмерного массива: ";
		cin >> num3;
		int numbers[3] = { num1,num2,num3 };
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j == 0) {
					masiv[i][j] = numbers[numindex];
				}
				else {
					masiv[i][j] = masiv[i][j - 1] + 1;
				}
			}
			numindex += 1;
		}*/

		/*
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				masiv[i][0] = num1;
			}
			else {
				masiv[i][0] = masiv[i - 1][0] + 1;
			}
		}*/

		/*
		cout << "Вот ваш итоговый массив: \n";
		for (int i = 0; i < size; i++) {
			for (int num : masiv[i]) {
				cout << num << ' ';
			}
			cout << '\n';
		}*/

		for (int j = 0; j < size; j++) {
			if (j == 0) {
				masiv[0][j] = num1;
			}
			else {
				masiv[0][j] = masiv[0][j - 1] + 1;
			}
		}

		cout << "Вот ваш итоговый массив: \n";
		for (int num : masiv[0]) {
			cout << num << ' ';
		}
	}

	{
		cout << "\nThird Task\n";
		int masiv[3][6];
		int max = 35;
		int min = -15;
		int move;
		int destination = 0;
		int end;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				masiv[i][j] = rand() % (max - min + 1) + min;
			}
		}
		cout << "Вот изначальный массив: \n";
		for (int i = 0; i < 3; i++) {
			for (int num : masiv[i]) {
				cout << num << ' ';
			}
			cout << '\n';
		}
		while (true) {
			destination = 0;
			while (destination != 1 && destination != 2 && destination != 3 && destination != 4) {
				cout << "Введите направление смещения (1 - влево, 2 - вправо, 3 - вверх, 4 - вниз): ";
				cin >> destination;
			}
			cout << "Введите, на сколько сместить массив: ";
			cin >> move;
			int temp;
			switch (destination) {
			case 1: {
				for (int i = 0; i < move; i++) {
					for (int j = 0; j < 3; j++) {
						temp = masiv[j][0];
						for (int t = 0; t < 5; t++) {
							masiv[j][t] = masiv[j][t + 1];
						}
						masiv[j][5] = temp;
					}
				}
				break;
			}
			case 2: {
				for (int i = 0; i < move; i++) {
					for (int j = 0; j < 3; j++) {
						temp = masiv[j][5];
						for (int t = 5; t > 0; t--) {
							//if (t == 5) {
							//	temp = masiv[j][t - 1];
							//	masiv[j][t - 1] = masiv[j][t];
							//}
							//else if (t == 0) {
							//	masiv[j][5] = temp;
							//}
							//else {
							//	masiv[j][t - 1] = temp;
							//	temp = masiv[j][t - 1];
							//}
							masiv[j][t] = masiv[j][t - 1];
						}
						masiv[j][0] = temp;
					}
				}
				break;
			}
			case 3: {
				for (int i = 0; i < move; i++) {
					for (int t = 0; t < 6; t++) {
						temp = masiv[0][t];
						for (int j = 0; j < 2; j++) {
							masiv[j][t] = masiv[j + 1][t];
						}
						masiv[2][t] = temp;
					}
				}
				break;
			}
			case 4: {
				for (int i = 0; i < move; i++) {
					for (int t = 0; t < 6; t++) {
						temp = masiv[2][t];
						for (int j = 2; j > 0; j--) {
							masiv[j][t] = masiv[j - 1][t];
						}
						masiv[0][t] = temp;
					}
				}
				break;
			}
			}
			cout << "Вот отформатированный массив: \n";
			for (int i = 0; i < 3; i++) {
				for (int num : masiv[i]) {
					cout << num << ' ';
				}
				cout << '\n';
			}
			cout << "Завершить программу? (0 - да, 1 - нет): ";
			cin >> end;
			if (end == 0) {
				break;
			}
		}
	}
}

