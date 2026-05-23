
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	/*
	for (int i = 1; i < size; i++) {
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = temp;
	}*/

	{
		cout << "\nFirst Task\n";
		const int size = 5;
		long long mobilephones[size] = { 3801234567,3705869854,3698745126,1522356587,1321254787 };
		long long homephones[size] = { 9443654789,98745621,457456221,8765874512,9824512360 };
		int choice;
		cout << "Справочник\n";
		while (true) {
			choice = 0;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
				cout << "Что вы хотите сделать? (1 - отсортировать по мобильным номерам,2 - отсортировать по домашним номерам,\n3 - вывести список пользователей, 4 - выход): ";
				cin >> choice;
			}
			switch (choice) {
			case 1: {
				for (int i = 0; i < size; i++) {
					for (int j = size - 1; j > i; j--) {
						if (mobilephones[j - 1] > mobilephones[j]) {
							long long temp = mobilephones[j - 1];
							long long temp2 = homephones[j - 1];
							mobilephones[j - 1] = mobilephones[j];
							homephones[j - 1] = homephones[j];
							mobilephones[j] = temp;
							homephones[j] = temp2;
						}
					}
				}
				cout << "Вот отсортированный массив мобильных телефонов по возрастанию: \n";
				for (long long phone : mobilephones) {
					cout << phone << ' ';
				}
				cout << "\nВот отсортированный массив домашних телефонов в соответствии с мобильными: \n";
				for (long long phone : homephones) {
					cout << phone << ' ';
				}
				cout << '\n';
				break;
			}
			case 2: {
				for (int i = 0; i < size; i++) {
					for (int j = size - 1; j > i; j--) {
						if (homephones[j - 1] > homephones[j]) {
							long long temp = homephones[j - 1];
							long long temp2 = mobilephones[j - 1];
							mobilephones[j - 1] = mobilephones[j];
							homephones[j - 1] = homephones[j];
							homephones[j] = temp;
							mobilephones[j] = temp2;
						}
					}
				}
				cout << "Вот отсортированный массив мобильных телефонов в соответствии с домашними: \n";
				for (long long phone : mobilephones) {
					cout << phone << ' ';
				}
				cout << "\nВот отсортированный массив домашних телефонов по возрастанию: \n";
				for (long long phone : homephones) {
					cout << phone << ' ';
				}
				cout << '\n';
				break;
			}
			case 3: {
				cout << "Вот список пользователей (их телефоны):\n";
				for (int i = 0; i < size; i++) {
					cout << i + 1 << " пользователь по списку: ";
					cout << "Мобильный номер: " << mobilephones[i] << "  Домашний номер: " << homephones[i] << '\n';
				}
				break;
			}
			}
			if (choice == 4) {
				cout << "До свидания\n"; break;
			}
		}
	}

	{
		cout << "\nSecond Task\n";
		const int size = 8;
		int max = 500, min = 0, changes = 1;
		int masiv[size] = {};
		for (int i = 0; i < size; i++) {
			masiv[i] = rand() % (max - min + 1) + min;
		}
		for (int i = 0; i < size; i++) {
			changes = 0;
			for (int j = size - 1; j > i; j--) {
				if (masiv[j - 1] > masiv[j]) {
					int temp = masiv[j - 1];
					masiv[j - 1] = masiv[j];
					masiv[j] = temp;
					changes += 1;
				}
			}
			if (changes == 0) {
				break;
			}
		}
		cout << "Масив отсортирован, вот он: \n";
		for (int num : masiv) {
			cout << num << ' ';
		}
	}

	{
		cout << "\nThird Task\n";
		const int size = 10;
		int oladushki[size] = { 4,67,76,12,345,6,7,89,90,23 };
		int maxolad, maxoladindex;
		int stop = size, start = 0;
		/*while ((stop - start) != 1) {
			maxolad = oladushki[start];
			maxoladindex = start;
			for (int i = start; i < size; i++) {
				if (maxolad < oladushki[i]) {
					maxolad = oladushki[i];
					maxoladindex = i;
				}
			}
			if (maxoladindex == 0) {
				start += 1;
				continue;
			}
			int placestart = maxoladindex;
			int placeend = size-1;
			//for (int i = maxoladindex; i < size-maxoladindex-1; i++) {
			//	int temp = oladushki[size - place];
			//	oladushki[size - place] = oladushki[i];
			//	oladushki[i] = temp;
			//	place += 1;
			//}

			while (placestart < placeend) {
				int temp = oladushki[placeend];
				oladushki[placeend] = oladushki[placestart];
				oladushki[placestart] = temp;
				placestart += 1;
				placeend -= 1;
			}
			int startback = start;
			placeend = size - 1;
			while (startback < placeend) {
				int temp = oladushki[startback];
				oladushki[startback] = oladushki[placeend];
				oladushki[placeend] = temp;
				startback += 1;
				placeend -= 1;
			}
			start += 1;
		}*/

		while (stop > 1) {
			maxolad = oladushki[0];
			maxoladindex = 0;
			for (int i = 1; i < stop; i++) {
				if (maxolad < oladushki[i]) {
					maxolad = oladushki[i];
					maxoladindex = i;
				}
			}
			if (maxoladindex == stop - 1) {
				stop -= 1;
				continue;
			}
			int placestart = 0;
			int placeend = maxoladindex;

			while (placestart < placeend) {
				int temp = oladushki[placestart];
				oladushki[placestart] = oladushki[placeend];
				oladushki[placeend] = temp;
				placestart += 1;
				placeend -= 1;
			}
			int startback = 0;
			placeend = stop - 1;
			while (startback < placeend) {
				int temp = oladushki[startback];
				oladushki[startback] = oladushki[placeend];
				oladushki[placeend] = temp;
				startback += 1;
				placeend -= 1;
			}
			stop -= 1;
		}

		cout << "Оладушки отсортированны, вот они по возрастанию радиусов снизу: \n";
		for (int olad : oladushki) {
			cout << olad << '\n';
		}
	}
}
