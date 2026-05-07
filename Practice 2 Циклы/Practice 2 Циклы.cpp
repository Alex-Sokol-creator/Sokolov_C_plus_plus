
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	//int max = 500;
	//int min = 4;

	//int randomNumber = rand();
	//int randomNumber = rand() % max; // from 0 to max
	//int randomNumber = rand() % max + 1; // from 1 to max
	//int randomNumber = rand() % (max - min + 1) + min; // from min to max

	/*{
		cout << "First Task\n";
		cout << "Введите число, до которого вы хотите вывести числа: ";
		int usernum;
		int limit = 0;
		cin >> usernum;
		while (limit <= usernum) {
			cout << limit << '\n';
			limit++;
		}
	}*/

	/*{
		cout << "\nSecond Task\n";
		int diap1;
		int diap2;
		cout << "Введите первую границу диапазона: ";
		cin >> diap1;
		cout << "Введите вторую границу диапазона: ";
		cin >> diap2;
		if (diap1 > diap2) {
			int diaptemp = diap2;
			diap2 = diap1;
			diap1 = diaptemp;
		}
		cout << "Вот все парные числа с вашего диапазона: \n";
		for (int i = diap1; i <= diap2; i++) {
			if (i % 2 == 0) {
			   cout << i << ' ';
			}
		}
		cout << "\nВот все непарные числа с вашего диапазона: \n";
		for (int i = diap1; i <= diap2; i++) {
			if (i % 2 != 0) {
			   cout << i << ' ';
			}
		}
		cout << "\nВот все числа кратные 7 с вашего диапазона: \n";
		for (int i = diap1; i <= diap2; i++) {
			if (i % 7 == 0) {
				cout << i << ' ';
			}
		}
	}*/

	//{
	//    cout << "\nThird Task\n";
	//    int diap1;
	//    int diap2;
	//    int sumtemp = 0;
	//    int sum = 0;
	//    cout << "Введите первую границу диапазона: ";
	//    cin >> diap1;
	//    cout << "Введите вторую границу диапазона: ";
	//    cin >> diap2;
	//    if (diap1 > diap2) {
	//        int diaptemp = diap2;
	//        diap2 = diap1;
	//        diap1 = diaptemp;
	//    }
	//    do {
	//        sumtemp = sum;
	//        sum = sumtemp + diap1;
	//        diap1++;
	//    } while (diap1 <= diap2);
	//    cout << "Сумма всех чисел в вашем диапазоне будет равна: " << sum << '\n';
	//}

	//{
	//    cout << "\nFourth Task\n";
	//    double number = 0;
	//    double sumtemp = 0;
	//    double summary;
	//    while (true) {
	//        cout << "Введите любое число (0 - для вывода суммы всех предыдущих): ";
	//        cin >> number;
	//        if (number == 0) { break; }
	//        else {
	//            summary = sumtemp + number;
	//            sumtemp = summary;
	//        }
	//    }
	//    cout << "\nСумма всех предыдущих чисел это: " << summary;
	//}

	//{
	//	cout << "\nFifth Task\n";
	//	int max = 500;
	//	while (true) {
	//		cout << "Игра 'Угадай число'\n";
	//		int randomNumber = rand() % max + 1;
	//		int choice;
	//		int choicewin;
	//		int tries = 0;
	//		cout << "Программа загадала число от 1 до 500, сможете ли вы его угадать?\n";
	//		while (true) {
	//			cout << "Введите предполагаемое число: ";
	//			int usernum;
	//			cin >> usernum;
	//			if (usernum < randomNumber) {
	//				cout << "Ваше число меньше чем загаданное\n";
	//				tries++;
	//			}
	//			else if (usernum > randomNumber) {
	//				cout << "Ваше число больше чем загаданное\n";
	//				tries++;
	//			}
	//			else if (usernum == randomNumber) {
	//				cout << "Вы угадали число! Поздравляем\n";
	//				tries++;
	//				break;
	//			}
	//			else {
	//				cout << "Вы ввели не число, попробуйте снова\n";
	//			}
	//			cout << "Вы хотите продолжать отгадывать число? (0 - прекратить, 1 - продолжить): ";
	//			cin >> choice;
	//			if (choice == 0) { break; }
	//		}
	//		if (choice == 0)
	//		{
	//			cout << "Загаданное число было: " << randomNumber << '\n';
	//			cout << "Вы потратили попыток: " << tries << '\n';
	//			break;
	//		}
	//		else {
	//			cout << "Вы потратили попыток: " << tries << '\n';
	//			cout << "Хотите попробовать снова? (0 - нет, 1 - да): ";
	//			cin >> choicewin;
	//			if (choicewin == 0) {
	//				cout << "До свидания!\n";
	//				break;
	//			}
	//		}
	//	}
	//}

	{
		cout << "\nSixth Task\n";
		while (true) {
			cout << "Добро пожаловать в программу конвертации валют\n";
			int choice;
			int choicemoney1;
			int choicemoney2;
			double amountmoney;
			double amountmoneyeur;
			double amountmoneyusd;
			double amountmoneygbp;
			double amountmoneypln;
			double eurprice = 51.85;
			double usdprice = 44.15;
			double gbpprice = 59.53;
			double plnprice = 12.08;
			cout << "Какую операцию вы хотите выбрать? (1 - посмотреть курсы валют, 2 - конвертировать валюту, 3 - выход из программы): ";
			cin >> choice;
			switch (choice) {
			case 1: {
				cout << "По состоянию на 6 мая 2026 года, чтобы купить 1 иностранную валюту, в гривне надо заплатить: \n";
				cout << "Евро EUR: 51,85 грн\n";
				cout << "Доллар USD: 44,15 грн\n";
				cout << "Фунт Стерлингов GBP: 59,53 грн\n";
				cout << "Польский злотый PLN: 12,08 грн\n";
				break;
			}
			case 2: {
				cout << "Из какой валюты вы хотите провести конвертацию? (1 - UAN, 2 - EUR, 3 - USD, 4 - GBP, 5 - PLN): ";
				cin >> choicemoney1;
				cout << "Введите сколько валюты вы хотите конвертировать: ";
				cin >> amountmoney;
				if (choicemoney1 == 2) {
					amountmoneyeur = amountmoney * eurprice;
				}
				switch (choicemoney1) {
				case 1: {
					cout << "В какую валюту вы хотите конвертировать? (1 - EUR, 2 - USD, 3 - GBP, 4 - PLN): ";
					cin >> choicemoney2;
					switch (choicemoney2) {
					case 1: {
						double convertation;
						convertation = amountmoney / eurprice;
						cout << "За " << amountmoney << " грн вы получите по курсу 51,85: " << convertation << " евро\n";
						break;
					}
					case 2: {
						double convertation;
						convertation = amountmoney / usdprice;
						cout << "За " << amountmoney << " грн вы получите по курсу 44,15: " << convertation << " долларов\n";
						break;
					}
					case 3: {
						double convertation;
						convertation = amountmoney / gbpprice;
						cout << "За " << amountmoney << " грн вы получите по курсу 59,53: " << convertation << " фунтов\n";
						break;
					}
					case 4: {
						double convertation;
						convertation = amountmoney / plnprice;
						cout << "За " << amountmoney << " грн вы получите по курсу 12,08: " << convertation << " злотых\n";
						break;
					}
					default: cout << "Вы ввели недоступный знак\n";
					}
					break;
				}
				}
			}
			case 3: { break; }
			}
		}
	}
}


