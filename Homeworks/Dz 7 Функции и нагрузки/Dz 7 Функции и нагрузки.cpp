
#include <iostream>
#include <Windows.h>

using namespace std;

const int size2 = 3;

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

template <typename T>
void matrixinputdata(T matrix[][size2], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = T(rand() % 100);
		}
	}
	matrixshow(matrix, size);
}

void matrixinputdata(char matrix[][size2], int size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = num;
			num++;
		}
	}
	matrixshow(matrix, size);
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
}
