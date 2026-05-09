

#include <iostream>
#include <Windows.h>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
	    cout << "\nFirst Task\n";
	    double income[12] = {};
	    double incomeenter;
	    double averageincome = 0;
	    double sumincome = 0;
	    int monthmax, monthmin;
	    for (int i = 0; i < 12; i++) {
	        incomeenter = 0;
	        cout << "Введите прибыль фирмы за " << i+1 << " месяц: ";
	        cin >> incomeenter;
	        income[i] = incomeenter;
	    }
	    double minincome = income[0];
		double maxincome = income[0];
	    for (int i = 0; i < 12; i++) {
	        if (income[i] > maxincome) {
	            maxincome = income[i];
	            monthmax = i;
	        }
	        if (income[i] < minincome) {
	            minincome = income[i];
	            monthmin = i;
	        }
	        sumincome += income[i];
	    }
	    averageincome = sumincome / 12;
	    cout << "Общая прибыль фирмы за год составила: " << sumincome << " , наилучший доход был в " << monthmax+1 << " месяце и составил "
	        << maxincome << ", а наихудший был в " << monthmin+1 << " месяце, и составил " << minincome
	        << " . Средняя прибыль в месяц составила " << averageincome << '\n';
	}

	{
	    cout << "\nSecond Task\n";
	    int masiv[10] = {1,2,3,4,5,6,7,8,9,10};
	    cout << "Элементы массива задом наперед: ";
	    for (int i = 9; i > -1; i--) {
	        cout << masiv[i] << ' ';
	    }
	}

	{
		cout << "\nThird Task\n";
		int fiveangle[5] = {};
		int side;
		for (int i = 0; i < 5; i++) {
			cout << "Введите " << i+1 << " сторону пятиугольника: ";
			cin >> side;
			fiveangle[i] = side;
		}
		int perimeter = 0;
		for (int i = 0; i < 5; i++) { 
			perimeter += fiveangle[i];
		}
		cout << "Периметр пятиугольника будет равен: " << perimeter;
	}

	{
		cout << "\nFourth Task\n";
		int masiv[9] = { 0, -11, 0, 12, 54, 0, 0, -40, 11 };
		int masivnew[9] = {};
		int place = 0;
		for (int i = 0; i < 9; i++) {
			if (masiv[i] != 0) {
				masivnew[place] = masiv[i];
				place++;
			}
		}
		for (int i = place; i < 9; i++) {
			masivnew[i] = -1;
		}
		cout << "Сужение массива: ";
		for (int num : masivnew) {
			cout << num << ' ';
		}
	}

	{
		cout << "\nFifth Task\n";
		int masiv1[5] = { 10, 0, 52, -10, -44 };
		int masiv2[5] = { 54, 0, -100, 12, 4 };
		int masivall[10] = {};
		int place = 0;
		for (int i = 0; i < 5; i++) {
			if (masiv1[i] > 0) {
				masivall[place] = masiv1[i];
				place++;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (masiv2[i] > 0) {
				masivall[place] = masiv2[i];
				place++;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (masiv1[i] == 0) {
				masivall[place] = masiv1[i];
				place++;
			}
			if (masiv2[i] == 0) {
				masivall[place] = masiv2[i];
				place++;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (masiv1[i] < 0) {
				masivall[place] = masiv1[i];
				place++;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (masiv2[i] < 0) {
				masivall[place] = masiv2[i];
				place++;
			}
		}
		cout << "Отформатированный массив с 10 элементами: ";
		for (int num : masivall) {
			cout << num << ' ';
		}
	}
}

