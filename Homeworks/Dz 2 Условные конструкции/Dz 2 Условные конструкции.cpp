

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
		int number;
		int maxnum;

		cout << "Введите 1 число: ";
		cin >> number;
		maxnum = number;
		for (int i = 2; i < 8; i++) {
			cout << "Введите " << i << " число: ";
			cin >> number;
			if (number > maxnum) {
				maxnum = number;
			}
		}
		cout << "Максимальное число из введеных вами 7 это: " << maxnum;
	}

	{
		cout << "\nSecond Task\n";
		int maxfuel = 300;
		int spending;
		double weight;
		double ab;
		double bc;
		double ac;
		char possibility = 1;
		cout << "Введите вес груза на самолете в кг: ";
		cin >> weight;
		if (weight <= 500) {
			spending = 1;
		}
		else if (weight <= 1000 && weight > 500) {
			spending = 4;
		}
		else if (weight <= 1500 && weight > 1000) {
			spending = 7;
		}
		else if (weight <= 2000 && weight > 1500) {
			spending = 9;
		}
		else {
			cout << "Самолет не может взлететь с весом более 2000 кг";
			possibility = 0;
		}
		if (possibility != 0) {
			cout << "Введите расстояние от пункта А до пункта В: ";
			cin >> ab;
			cout << "Введите расстояние от пункта B до пункта C: ";
			cin >> bc;
			double fuelab = ab * spending;
			double fuelbc = bc * spending;
			if (fuelab > maxfuel || fuelbc > maxfuel) {
				cout << "К сожалению, самолет не может преодолеть такое расстояние с таким грузом\n";
			}
			else {
				double needfuel;
				double charging = 0;
				double fuelablast = maxfuel - fuelab;
				if (fuelbc < fuelablast) {
					needfuel = fuelab + fuelbc;
				}
				else {
					charging = fuelbc - fuelablast;
					needfuel = fuelab + charging;
				}
				cout << "Так как груз весит " << weight << " кг, то расход топлива будет " << spending << "л/км,\nи для того, чтобы пролететь " << ab + bc
					<< "км, вам минимально потребуется " << needfuel << "л топлива. \nДозаправлять в пункте В надо будет " << charging << "л топлива.";
			}
		}
	}

	{
		cout << "\nThird Task\n";
		int salary = 200;
		int bonus = 200;
		double saldop1;
		double saldop2;
		double saldop3;
		double allsal1, allsal2, allsal3;
		int sells;
		cout << "Введите объемы продаж в $ 1 менеджера: ";
		cin >> sells;
		if (sells < 500) {
			saldop1 = sells * 0.03;
		}
		else if (sells < 1000 && sells >= 500) {
			saldop1 = sells * 0.05;
		}
		else if (sells >= 1000) {
			saldop1 = sells * 0.08;
		}
		cout << "Введите объемы продаж в $ 2 менеджера: ";
		cin >> sells;
		if (sells < 500) {
			saldop2 = sells * 0.03;
		}
		else if (sells < 1000 && sells >= 500) {
			saldop2 = sells * 0.05;
		}
		else if (sells >= 1000) {
			saldop2 = sells * 0.08;
		}
		cout << "Введите объемы продаж в $ 3 менеджера: ";
		cin >> sells;
		if (sells < 500) {
			saldop3 = sells * 0.03;
		}
		else if (sells < 1000 && sells >= 500) {
			saldop3 = sells * 0.05;
		}
		else if (sells >= 1000) {
			saldop3 = sells * 0.08;
		}
		allsal1 = salary + saldop1;
		allsal2 = salary + saldop2;
		allsal3 = salary + saldop3;

		double allsals[3] = { allsal1,allsal2,allsal3 };
		int bestmanager = 0;
		for (int i = 1; i < 3; i++) {
			if (allsals[bestmanager] < allsals[i]) {
				bestmanager = i;
			}
		}
		allsals[bestmanager] += bonus;
		//if (allsal1 > allsal2 && allsal1 > allsal3) {
		//	allsal1 += bonus;
		//	bestmanager = 1;
		//}
		//else if (allsal1 < allsal2 && allsal2 > allsal3) {
		//	allsal2 += bonus;
		//	bestmanager = 2;
		//}
		//else if (allsal2 < allsal3 && allsal3 > allsal1) {
		//	allsal3 += bonus;
		//	bestmanager = 3;
		//}
		cout << "У первого менеджера суммарная зарплата будет " << allsals[0] << " $, у второго " << allsals[1] << " $, а у третьего будет "
			<< allsals[2] << " $.\nЛучший менеджер это " << bestmanager + 1;
	}

	{
		cout << "\nFourth Task\n";
		int salarypercode = 50;
		int fine = 20;
		int profitwant;
		int latesnum;
		cout << "Расчет для Васи\n";
		cout << "Первый расчет. Введите желаемый доход для Васи: ";
		cin >> profitwant;
		cout << "Введите количество опазданий Васи: ";
		cin >> latesnum;
		int mustprofit = profitwant + ((latesnum / 3) * fine);
		while (mustprofit % salarypercode != 0) {
			mustprofit++;
		}
		int amountsentences = mustprofit / salarypercode * 100;
		cout << "Для того, чтобы получить " << profitwant << " $, Вася должен написать " << amountsentences << " стрч кода, так как он опоздал такое количество раз: "
			<< latesnum << '\n';

		cout << "Второй расчет. Введите желаемый доход для Васи: ";
		cin >> profitwant;
		cout << "Введите количество строчек кода, написанных Васей: ";
		int sentences;
		cin >> sentences;
		if ((sentences / 100 * salarypercode) < profitwant) {
			cout << "Вася не сможет получить такой доход, так как он написал меньше строчек кода, чем нужно для такой суммы\n";
		}
		else {
			int moneylast = (sentences / 100 * salarypercode) - profitwant;
			latesnum = (moneylast / fine * 3) + 2;
			cout << "У Васи в запасе есть " << latesnum << " опазд., чтобы получить свою зарплату\n";
		}

		cout << "Третий расчет. Введите количество строчек кода, написанных Васей: ";
		cin >> sentences;
		cout << "Введите количество опазданий Васи: ";
		cin >> latesnum;
		int sentencemoney = sentences / 100 * salarypercode;
		int latesmoney = (latesnum / 3) * fine;
		if (latesmoney >= sentencemoney) {
			cout << "Васе не заплатят денег вообще, так как он слишком много раз опаздывал\n";
		}
		else {
			cout << "Васе заплатят " << sentencemoney - latesmoney << " $, так как он опоздывал некритично\n";
		}
	}
}

