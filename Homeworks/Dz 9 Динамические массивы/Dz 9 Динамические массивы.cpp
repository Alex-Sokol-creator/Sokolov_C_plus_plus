
#include <iostream>
#include <Windows.h>

using namespace std;

/*
int* AddGrade(int* grades, int& size, int newGrade) {
	int* temp = new int[size + 1];
	for (int i = 0; i < size;i++) {
		temp[i] = grades[i];
	}
	temp[size] = newGrade;
	size++;
	delete[] grades;
	grades = temp;
	return grades;
}*/

template <typename T>
T* GiveMemory(int size) {
	return new T[size];
}

template <typename T>
void Initialization(T* masiv, int size) {
	for (int i = 0; i < size; i++) {
		masiv[i] = rand() % 100;
	}
}

template <typename T>
void PrintMasiv(T* masiv, int size) {
	cout << "Вот ваш динамический массив: \n";
	for (int i = 0; i < size; i++) {
		cout << masiv[i] << ' ';
	}
	cout << '\n';
}

template <typename T>
void DeleteMemory(T* masiv) {
	cout << "\nМассив с адресом " << masiv << " удаляется из динамической памяти";
	delete[] masiv;
}

template <typename T>
T* AddElement(T* masiv, int& size, T element) {
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = masiv[i];
	}
	temp[size] = element;
	size++;
	delete[] masiv;
	masiv = temp;
	return masiv;
}

template <typename T>
T* AddElementByIndex(T* masiv, int& size, int index, T element) {
	if (index < 0 || index > size) {
		cout << "К сожалению, такого индекса нет в массиве\n";
		return masiv;
	}
	T* temp = new T[size + 1];
	for (int i = 0; i < index; i++) {
		temp[i] = masiv[i];
	}
	temp[index] = element;
	for (int i = index; i < size; i++) {
		temp[i + 1] = masiv[i];
	}
	size++;
	delete[] masiv;
	masiv = temp;
	return masiv;
}

template <typename T>
T* DeleteElementByIndex(T* masiv, int& size, int index) {
	if (index < 0 || index >= size) {
		cout << "К сожалению, такого индекса нет в массиве\n";
		return masiv;
	}
	T* temp = new T[size - 1];
	for (int i = 0; i < index; i++) {
		temp[i] = masiv[i];
	}
	for (int i = index + 1; i < size; i++) {
		temp[i - 1] = masiv[i];
	}
	size--;
	delete[] masiv;
	masiv = temp;
	return masiv;
}

template <typename T>
T* DeleteSimpleNumbers(T* masiv, int& size) {
	int countofsimples = 0;
	int countofsimplessize = 0;
	T* masivofsimplesindexes = new T[countofsimplessize];
	for (int i = 0; i < size; i++) {
		int countdividers = 0;
		for (int j = 1; j <= masiv[i]; j++) {
			if (masiv[i] % j == 0) {
				countdividers++;
			}
		}
		if (countdividers == 2) {
			countofsimples++;
			T* temp = new T[countofsimplessize + 1];
			for (int c = 0; c < countofsimplessize; c++) {
				temp[c] = masivofsimplesindexes[c];
			}
			temp[countofsimplessize] = i;
			countofsimplessize++;
			delete[] masivofsimplesindexes;
			masivofsimplesindexes = temp;
		}
	}
	int newsize = size - countofsimples;
	int oldsize = size;
	size = newsize;
	T* newmasiv = new T[newsize];
	int place = 0;
	for (int i = 0; i < oldsize; i++) {
		int checking = 0;
		for (int c = 0; c < countofsimplessize;c++) {
			if (i == masivofsimplesindexes[c]) {
				checking = -1;
				break;
			}
		}
		if (checking != -1) {
			newmasiv[place] = masiv[i];
			place++;
		}
	}
	delete[] masivofsimplesindexes;
	delete[] masiv;
	return newmasiv;
}

template <typename T>
void SortMasiv(T* masiv, int size) {
	int countofpluses = 0, countofnegatives = 0, countofzeros = 0;
	int countofplusessize = 0, countofnegativessize = 0, countofzerossize = 0;
	T* masivofplusesindexes = new T[countofplusessize];
	T* masivofnegativesindexes = new T[countofnegativessize];
	T* masivofzerosindexes = new T[countofzerossize];
	for (int i = 0; i < size; i++) {
		if (masiv[i] > 0) {
			countofpluses++;
			T* temp = new T[countofplusessize + 1];
			for (int c = 0; c < countofplusessize; c++) {
				temp[c] = masivofplusesindexes[c];
			}
			temp[countofplusessize] = i;
			countofplusessize++;
			delete[] masivofplusesindexes;
			masivofplusesindexes = temp;
		}
		else if (masiv[i] < 0) {
			countofnegatives++;
			T* temp = new T[countofnegativessize + 1];
			for (int c = 0; c < countofnegativessize; c++) {
				temp[c] = masivofnegativesindexes[c];
			}
			temp[countofnegativessize] = i;
			countofnegativessize++;
			delete[] masivofnegativesindexes;
			masivofnegativesindexes = temp;
		}
		else {
			countofzeros++;
			T* temp = new T[countofzerossize + 1];
			for (int c = 0; c < countofzerossize; c++) {
				temp[c] = masivofzerosindexes[c];
			}
			temp[countofzerossize] = i;
			countofzerossize++;
			delete[] masivofzerosindexes;
			masivofzerosindexes = temp;
		}
	}
	int newsizeofpluses = size - (countofnegatives + countofzeros);
	int newsizeofnegatives = size - (countofpluses + countofzeros);
	int newsizeofzeros = size - (countofnegatives + countofpluses);
	T* newmasivofpluses = new T[newsizeofpluses];
	T* newmasivofnegatives = new T[newsizeofnegatives];
	T* newmasivofzeros = new T[newsizeofzeros];
	int placeofpluses = 0, placeofnegatives = 0, placeofzeros = 0;
	for (int i = 0; i < size; i++) {
		int checking = 0;
		for (int c = 0; c < countofnegativessize;c++) {
			if (i == masivofnegativesindexes[c]) {
				checking = -1;
				break;
			}
		}
		if (checking != -1) {
			for (int c = 0; c < countofzerossize;c++) {
				if (i == masivofzerosindexes[c]) {
					checking = -1;
					break;
				}
			}
			if (checking != -1) {
				newmasivofpluses[placeofpluses] = masiv[i];
				placeofpluses++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		int checking = 0;
		for (int c = 0; c < countofplusessize;c++) {
			if (i == masivofplusesindexes[c]) {
				checking = -1;
				break;
			}
		}
		if (checking != -1) {
			for (int c = 0; c < countofzerossize;c++) {
				if (i == masivofzerosindexes[c]) {
					checking = -1;
					break;
				}
			}
			if (checking != -1) {
				newmasivofnegatives[placeofnegatives] = masiv[i];
				placeofnegatives++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		int checking = 0;
		for (int c = 0; c < countofnegativessize;c++) {
			if (i == masivofnegativesindexes[c]) {
				checking = -1;
				break;
			}
		}
		if (checking != -1) {
			for (int c = 0; c < countofplusessize;c++) {
				if (i == masivofplusesindexes[c]) {
					checking = -1;
					break;
				}
			}
			if (checking != -1) {
				newmasivofzeros[placeofzeros] = masiv[i];
				placeofzeros++;
			}
		}
	}
	PrintMasiv(newmasivofpluses, newsizeofpluses);
	PrintMasiv(newmasivofnegatives, newsizeofnegatives);
	PrintMasiv(newmasivofzeros, newsizeofzeros);
	DeleteMemory(newmasivofpluses);
	DeleteMemory(newmasivofnegatives);
	DeleteMemory(newmasivofzeros);
	delete[] masivofplusesindexes;
	delete[] masivofnegativesindexes;
	delete[] masivofzerosindexes;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	{
		cout << "\nFirst Task\n";
		int size = 6;
		int num, index;
		int* masiv = GiveMemory<int>(size);
		Initialization(masiv, size);
		PrintMasiv(masiv, size);
		cout << "Какое число вы хотите добавить в конец массива?: ";
		cin >> num;
		masiv = AddElement(masiv, size, num);
		PrintMasiv(masiv, size);
		cout << "В какой индекс вставить ваше число?: ";
		cin >> index;
		cout << "Напишите число, которое хотите вставить: ";
		cin >> num;
		masiv = AddElementByIndex(masiv, size, index, num);
		PrintMasiv(masiv, size);
		cout << "Какой индекс у элемента, который вы хотите удалить?: ";
		cin >> index;
		masiv = DeleteElementByIndex(masiv, size, index);
		PrintMasiv(masiv, size);
		DeleteMemory(masiv);
	}

	{
		cout << "\nSecond Task\n";
		int size = 14;
		int* masiv = new int[size];
		Initialization(masiv, size);
		int* result = DeleteSimpleNumbers(masiv, size);
		PrintMasiv(result, size);
		DeleteMemory(result);
	}

	{
		cout << "\nThird Task\n";
		const int size = 14;
		int masiv[size] = {10,5,-12,-67,0,42,0,12,-76,-1990,0,14,1487,1234};
		cout << "Вот изначальный массив: \n";
		for (int i = 0; i < size; i++) {
			cout << masiv[i] << ' ';
		}
		cout << "\nВот 3 отсортированных массива: \n";
		SortMasiv(masiv, size);
	}
}

