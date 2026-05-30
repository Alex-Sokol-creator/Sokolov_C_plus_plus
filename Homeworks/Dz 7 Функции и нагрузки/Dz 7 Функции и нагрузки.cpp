
#include <iostream>
#include <Windows.h>

using namespace std;

const int size2 = 3;

// Task 1

void matrixsort(int matrix[][size2], int size) {
	cout << "Происходит сортировка массива\n";
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			int temp = matrix[i][j];
			int c = j - 1;

			while (c >= 0 && matrix[i][c] > temp) {
				matrix[i][c + 1] = matrix[i][c];
				c--;
			}

			matrix[i][c + 1] = temp;
		}
	}
	cout << "Массив отсортирован, вот он: \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

void matrixsort(double matrix[][size2], int size) {
	cout << "Происходит сортировка массива\n";
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			double temp = matrix[i][j];
			int c = j - 1;

			while (c >= 0 && matrix[i][c] > temp) {
				matrix[i][c + 1] = matrix[i][c];
				c--;
			}

			matrix[i][c + 1] = temp;
		}
	}
	cout << "Массив отсортирован, вот он: \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

void matrixsort(char matrix[][size2], int size) {
	cout << "Происходит сортировка массива\n";
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			char temp = matrix[i][j];
			int c = j - 1;

			while (c >= 0 && matrix[i][c] > temp) {
				matrix[i][c + 1] = matrix[i][c];
				c--;
			}

			matrix[i][c + 1] = temp;
		}
	}
	cout << "Массив отсортирован, вот он: \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

void matrixekstremums(int matrix[][size2], int size) {
	int maxnum = matrix[0][0], minnum = matrix[0][0], step = 0;
	for (int i = 0; i < size; i++) {
		if (matrix[i][step] > maxnum) {
			maxnum = matrix[i][step];
		}
		if (matrix[i][step] < minnum) {
			minnum = matrix[i][step];
		}
		step++;
	}
	cout << "Максимум в вашей матрице на главной диагонали это " << maxnum << ", а минимум это " << minnum << '\n';
	matrixsort(matrix, size);
}

void matrixekstremums(double matrix[][size2], int size) {
	double maxnum = matrix[0][0], minnum = matrix[0][0];
	int step = 0;
	for (int i = 0; i < size; i++) {
		if (matrix[i][step] > maxnum) {
			maxnum = matrix[i][step];
		}
		if (matrix[i][step] < minnum) {
			minnum = matrix[i][step];
		}
		step++;
	}
	cout << "Максимум в вашей матрице на главной диагонали это " << maxnum << ", а минимум это " << minnum << '\n';
	matrixsort(matrix, size);
}

void matrixekstremums(char matrix[][size2], int size) {
	char maxnum = matrix[0][0], minnum = matrix[0][0];
	int step = 0;
	for (int i = 0; i < size; i++) {
		if (matrix[i][step] > maxnum) {
			maxnum = matrix[i][step];
		}
		if (matrix[i][step] < minnum) {
			minnum = matrix[i][step];
		}
		step++;
	}
	cout << "Максимум в вашей матрице на главной диагонали это " << maxnum << ", а минимум это " << minnum << '\n';
	matrixsort(matrix, size);
}

template <typename T>
void matrixshow(T matrix[][size2], int size) {
	cout << "Вот ваша матрица: \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	matrixekstremums(matrix, size);
}

/*template <typename T>
void matrixinputdata(T matrix[][size2], int size) {
	cout << '\n';
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = T(rand() % 100);
		}
	}
	matrixshow(matrix, size);
}*/

void matrixinputdata(int matrix[][size2], int size) {
	cout << '\n';
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
	matrixshow(matrix, size);
}

void matrixinputdata(double matrix[][size2], int size) {
	cout << '\n';
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 100 / 2.0;
		}
	}
	matrixshow(matrix, size);
}

void matrixinputdata(char matrix[][size2], int size) {
	cout << '\n';
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 'a' + (rand() % 26);
		}
	}
	matrixshow(matrix, size);
}


// Task 2

int SecondTask(int num1, int num2, int devider = 1, int deviderresult = 1) {
	int minnum;
	if (num1 > num2) {
		minnum = num2;
	}
	else {
		minnum = num1;
	}

	if ((num1 % devider == 0) && (num2 % devider == 0)) {
		deviderresult = devider;
	}
	if (devider == minnum) {
		return deviderresult;
	}

	return SecondTask(num1, num2, devider += 1, deviderresult);
}



// Task 3

int GameCode(int number[4], int size, int tries = 0, int cows = 0, int bulls = 0, int input = 0) {
	cows = 0;
	bulls = 0;
	tries += 1;
	int userdata[4] = {};
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i + 1 << " предпологаемое число: ";
		cin >> input;
		userdata[i] = input;
	}
	int usercopy[4] = {};
	int numbercopy[4] = {};
	for (int i = 0; i < size; i++) {
		usercopy[i] = userdata[i];
		numbercopy[i] = number[i];
	}
	for (int i = 0; i < size; i++) {;
		if (usercopy[i] == numbercopy[i]) {
			cows += 1;
			usercopy[i] = 10;
			numbercopy[i] = 10;
		}
	}
	if (cows == 4) {
		return tries;
	}
	for (int i = 0; i < size; i++) {
		if (usercopy[i] == 10) {
			continue;
		}
		for (int j = 0; j < size; j++) {
			if (usercopy[i] == numbercopy[j] && (i != j)) {
				bulls += 1;
				numbercopy[j] = 10;
				break;
			}
		}
	}
	cout << "У вас " << bulls << " бык. и " << cows << " коров.\n";
	return GameCode(number, size, tries, cows, bulls, input);
}

int Bulls_Cows_Start(int arr[4], int size) {
	int min = 0,max = 9;
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}
	cout << "Программа загадала 4-х значное число, попробуйте его угадать\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return GameCode(arr, size);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	{
		cout << "\nFirst Task\n";
		const int size = 3;
		int masivint[size][size] = {};
		double masivdouble[size][size] = {};
		char masivchar[size][size] = {};
		matrixinputdata(masivint, size);
		matrixinputdata(masivdouble, size);
		matrixinputdata(masivchar, size);
	}

	{
		cout << "\nSecond Task\n";
		int number1 = 146, number2 = 264;
		cout << "Идет поиск НОД для 2 чисел\n";
		cout << "НОД для этих 2 чисел будет равно: " << SecondTask(number1, number2) << '\n';
	}

	{
		cout << "\nThird Task\n";
		const int size = 4;
		int number[size] = {};
		int result = Bulls_Cows_Start(number, size);
		cout << "Ура, вы угадали число!\n";
		cout << "Вы потратили " << result << " попыток";
	}
}
