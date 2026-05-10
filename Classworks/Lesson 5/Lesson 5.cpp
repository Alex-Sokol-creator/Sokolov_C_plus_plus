
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//double numbers[] = { 12.5, 4.5, .05 };

	//for (double num : numbers) {
	//    cout << num << ' ';
	//}

	const int rows = 2;
	const int cols = 3;

	int matrix[rows][cols] = {
		{2,7,4},
		{4,8,-5}
	};

	cout << matrix[0][2] << '\n';
	cout << matrix[1][1] << '\n';

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << ' ';
		}
	}

	const int sizeX = 3;
	const int sizeY = 2;
	const int sizeZ = 3;


	int arr3d[sizeX][sizeY][sizeZ] = {
		{
			{2,4,5},
			{0,4,90}
		},
		{
			{-5,0,8},
			{12,54,-100}
		},
		{
			{8,-7,5},
			{90,-90,9}
		}
	};

	cout << '\n';
	cout << '\n';
	for (int i = 0; i < sizeX; i++) {
		cout << i + 1 << ":\n";
		for (int j = 0; j < sizeY; j++) {
			for (int z = 0; z < sizeZ; z++) {
				cout << arr3d[i][j][z] << ' ';
			}
			cout << '\n';
		}
	}

	const int size1 = 2;
	const int size2 = 3;
	const int size3 = 2;
	const int size4 = 2;

	int arr4d[size1][size2][size3][size4] = {
		{
			{
				{10,12},
				{-2,5}
			},
			{
				{10,12},
				{-2,5}
			},
			{
				{ 10,12 },
				{-2,5}
			}
		},
		{
			{
				{10,12},
				{-2,5}
			},
			{
				{10,12},
				{-2,5}
			},
			{
				{ 10,12 },
				{-2,5}
			}
		}
	};

	//cout << '\n';
	//cout << '\n';
	//for (int i = 0; i < sizeX; i++) {
	//	cout << i + 1 << ":\n";
	//	for (int j = 0; j < sizeY; j++) {
	//		for (int z = 0; z < sizeZ; z++) {
	//			for (int s4 = 0; s4 < size4; s4++) {
	//				cout << arr3d[i][j][z][s4] << ' ';
	//			}
	//			cout << '\n';
	//		}
	//		cout << '\n';
	//	}
	//}


}

