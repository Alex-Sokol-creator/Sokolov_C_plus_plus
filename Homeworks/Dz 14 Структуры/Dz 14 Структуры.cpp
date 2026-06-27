
#include <iostream>
#include <Windows.h>

using namespace std;

struct Complex {
	double intact;
	double mnima;
};

Complex Adding(Complex num1, Complex num2) {
	Complex result;
	result.intact = num1.intact + num2.intact;
	result.mnima = num1.mnima + num2.mnima;
	return result;
}

Complex TakingAway(Complex num1, Complex num2) {
	Complex result;
	result.intact = num1.intact - num2.intact;
	result.mnima = num1.mnima - num2.mnima;
	return result;
}

Complex Multiplying(Complex num1, Complex num2) {
	Complex result;
	result.intact = (num1.intact * num2.intact) - (num1.mnima * num2.mnima);
	result.mnima = (num1.intact * num2.mnima) + (num1.mnima * num2.intact);
	return result;
}

Complex Dividing(Complex num1, Complex num2) {
	Complex result;
	double divider = (num2.intact * num2.intact) + (num2.mnima * num2.mnima);
	result.intact = ((num1.intact * num2.intact) + (num1.mnima * num2.mnima)) / divider;
	result.mnima = ((num1.mnima * num2.intact) - (num1.intact * num2.mnima)) / divider;
	return result;
}

struct Automobile {
	double length;
	double clirence;
	double volume_of_engine;
	double power_of_engine;
	double diameter;
	char color[30];
	char box_of_peredach[30];
};

void SetAutomobile(Automobile& automobile) {
	cout << "Введите длину авто: ";
	cin >> automobile.length;
	cout << "Введите клиренс авто: ";
	cin >> automobile.clirence;
	cout << "Введите объем двигателя авто: ";
	cin >> automobile.volume_of_engine;
	cout << "Введите мощность двигателя авто: ";
	cin >> automobile.power_of_engine;
	cout << "Введите диаметр колес: ";
	cin >> automobile.diameter;
	cin.ignore();
	cout << "Введите цвет авто: ";
	cin.getline(automobile.color, 30);
	cin.ignore();
	cout << "Введите тип коробки передач авто: ";
	cin.getline(automobile.box_of_peredach, 30);
}

void PrintAutomobile(Automobile& automobile) {
	cout << "\nДлина авто: " << automobile.length;
	cout << "\nКлиренс авто: " << automobile.clirence;
	cout << "\nОбъем двигателя авто: " << automobile.volume_of_engine;
	cout << "\nМощность двигателя авто: " << automobile.power_of_engine;
	cout << "\nДиаметр колес: " << automobile.diameter;
	cout << "\nЦвет авто: " << automobile.color;
	cout << "\nТип коробки передач авто: " << automobile.box_of_peredach << '\n';
}

void SearchAutoDouble(Automobile masiv[], int size, double search, int choice) {
	int searchs_completed = 0;
	switch (choice) {
	case 1: {
		for (int i = 0; i < size; i++) {
			if (masiv[i].length == search) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < size; i++) {
			if (masiv[i].clirence == search) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
		break;
	}
	case 3: {
		for (int i = 0; i < size; i++) {
			if (masiv[i].volume_of_engine == search) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
		break;
	}
	case 4: {
		for (int i = 0; i < size; i++) {
			if (masiv[i].power_of_engine == search) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
		break;
	}
	case 5: {
		for (int i = 0; i < size; i++) {
			if (masiv[i].diameter == search) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
		break;
	}
	}
	if (searchs_completed == 0) {
		cout << "Данный параметр отсутствует у всех машин\n";
	}
}

void SearchAutoText(Automobile masiv[], int size, char search[], int choice) {
	int searchs_completed = 0;
	if (choice == 6) {
		for (int i = 0; i < size; i++) {
			if (strcmp(masiv[i].color, search) == 0) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			if (strcmp(masiv[i].box_of_peredach, search) == 0) {
				cout << "Параметр найден у " << i + 1 << " машины\n";
				searchs_completed++;
			}
		}
	}
	if (searchs_completed == 0) {
		cout << "Данный параметр отсутствует у всех машин\n";
	}
}

struct Book {
	char name[60];
	char author[60];
	char vidavnitstvo[65];
	char janr[25];
};

void DieBibliotek(Book books[], int size) {
	cout << "\nДобро пожаловать в программу библиотека, что вы хотите сделать?\n";
	while (true) {
		int choice = 0;
		while (choice < 1 || choice > 7) {
			cout << "Выбор: 1 - редактировать книгу, 2 - печать всех книг, 3 - поиск книги за автором, 4 - поиск книги по названию, 5 - сортировать массив по названиям книг, 6 - сортировать массив за автором, 7 - сортировать массив за изданием\n";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			int number;
			cout << "Введите номер книги, которую хотите отредактировать: ";
			cin >> number;
			if (number < 1 || number > size) {
				cout << "Такой книги к сожалению нет\n";
				break;
			}
			else {
				int index = number - 1;
				cin.ignore();
				cout << "Введите новое название " << index + 1 << " книги: ";
				cin.getline(books[index].name, 60);
				cout << "Введите нового автора " << index + 1 << " книги: ";
				cin.getline(books[index].author, 60);
				cout << "Введите новое издание " << index + 1 << " книги: ";
				cin.getline(books[index].vidavnitstvo, 65);
				cout << "Введите новый жанр " << index + 1 << " книги: ";
				cin.getline(books[index].janr, 25);
			}
			break;
		}
		case 2: {
			cout << "Вот все ваши книги:\n";
			for (int i = 0; i < size; i++) {
				cout << i + 1 << " книга: \n";
				cout << "Название: " << books[i].name << '\n';
				cout << "Автор: " << books[i].author << '\n';
				cout << "Издание: " << books[i].vidavnitstvo << '\n';
				cout << "Жанр: " << books[i].janr << '\n';
			}
			break;
		}
		case 3: {
			int completed = 0;
			char author[60];
			cout << "Введите автора для поиска его книг: ";
			cin.ignore();
			cin.getline(author, 60);
			for (int i = 0; i < size; i++) {
				if (strcmp(books[i].author, author) == 0) {
					cout << "Книга с таким автором была найдена, это " << books[i].name << '\n';
					completed++;
				}
			}
			if (completed == 0) {
				cout << "Книга с таким автором не была найдена к сожалению\n";
			}
			break;
		}
		case 4: {
			int completed = 0;
			char name[60];
			cout << "Введите название книги для ее поиска: ";
			cin.ignore();
			cin.getline(name, 60);
			for (int i = 0; i < size; i++) {
				if (strcmp(books[i].name, name) == 0) {
					cout << "Книга с таким названием была найдена, это " << books[i].name << '\n';
					completed++;
				}
			}
			if (completed == 0) {
				cout << "Книга с таким названием не была найдена к сожалению\n";
			}
			break;
		}
		case 5: {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if ((strcmp(books[j].name, books[j + 1].name) > 0)) {
						Book temp = books[j];
						books[j] = books[j + 1];
						books[j + 1] = temp;
					}
				}
			}
			cout << "Массив отсортирован по названиям\n";
			break;
		}
		case 6: {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if ((strcmp(books[j].author, books[j + 1].author) > 0)) {
						Book temp = books[j];
						books[j] = books[j + 1];
						books[j + 1] = temp;
					}
				}
			}
			cout << "Массив отсортирован за авторами\n";
			break;
		}
		case 7: {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if ((strcmp(books[j].vidavnitstvo, books[j + 1].vidavnitstvo) > 0)) {
						Book temp = books[j];
						books[j] = books[j + 1];
						books[j + 1] = temp;
					}
				}
			}
			cout << "Массив отсортирован за авторами\n";
			break;
		}
		}

		cout << "Вы хотите выйти? (1 - да, любое число - нет): ";
		int exit;
		cin >> exit;
		if (exit == 1) {
			cout << "До свидания!\n";
			break;
		}
	}
}

struct Mashina {
	char color[30];
	char model[30];
	char number[30];
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		cout << "\nFirst Task\n";
		Complex num1, num2;
		double num1_intant, num1_mnima, num2_intant, num2_mnima;
		int choice = 0;
		cout << "Введите целую часть 1 комплексного числа: ";
		cin >> num1_intant;
		cout << "Введите мнимую часть 1 комплексного числа: ";
		cin >> num1_mnima;
		cout << "Введите целую часть 2 комплексного числа: ";
		cin >> num2_intant;
		cout << "Введите мнимую часть 2 комплексного числа: ";
		cin >> num2_mnima;
		num1.intact = num1_intant;
		num1.mnima = num1_mnima;
		num2.intact = num2_intant;
		num2.mnima = num2_mnima;
		while (choice < 1 || choice > 4) {
			cout << "Что вы хотите с ними сделать?(1 - прибавить, 2 - отнять, 3 - умножить, 4 - поделить): ";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			Complex result = Adding(num1, num2);
			cout << "Результат прибавления этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
			break;
		}
		case 2: {
			Complex result = TakingAway(num1, num2);
			cout << "Результат отнимания этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
			break;
		}
		case 3: {
			Complex result = Multiplying(num1, num2);
			cout << "Результат умножения этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
			break;
		}
		case 4: {
			Complex result = Dividing(num1, num2);
			cout << "Результат деления этих 2 чисел равен: " << result.intact << " + " << result.mnima << "i\n";
			break;
		}
		}
	}

	{
		cout << "\nSecond Task\n";
		const int size = 2;
		Automobile masiv[size];
		for (int i = 0; i < size; i++) {
			cout << "Заполнение машины номер " << i + 1 << ": \n";
			SetAutomobile(masiv[i]);
		}
		for (int i = 0; i < size; i++) {
			cout << "Вот параметры машины номер " << i + 1 << ": \n";
			PrintAutomobile(masiv[i]);
		}
		int choice = 0;
		cout << "По какому параметру искать?\n";
		while (choice < 1 || choice > 7) {
			cout << "1-Длина, 2-Клиренс, 3-Объем, 4-Мощность, 5-Диаметр, 6-Цвет, 7-Коробка: ";
			cin >> choice;
		}
		if (choice >= 1 && choice < 6) {
			double meaning;
			cout << "Введите значение, которое хотите найти: ";
			cin >> meaning;
			SearchAutoDouble(masiv, size, meaning, choice);
		}
		else {
			char meaning[100];
			cout << "Введите то, что хотите найти: ";
			cin.ignore();
			cin.getline(meaning, 100);
			SearchAutoText(masiv, size, meaning, choice);
		}
	}

	{
		cout << "\nThird Task\n";
		const int size = 10;
		Book books[size] = {
			{"Кобзарь", "Тарас Шевченко", "Веселка", "Поэзия"},
			{"Мастер и Маргарита", "Михаил Булгаков", "Азбука", "Роман"},
			{"1984", "Джордж Оруэлл", "АСТ", "Антиутопия"},
			{"Гарри Поттер", "Джоан Роулинг", "Росмэн", "Фэнтези"},
			{"Идиот", "Федор Достоевский", "Эксмо", "Классика"},
			{"Маленький принц", "Антуан де Сент-Экзюпери", "Детская литература", "Сказка"},
			{"Три товарища", "Эрих Мария Ремарк", "АСТ", "Роман"},
			{"Тень сумерек", "Джордж Оруэлл", "Веселка", "Фантастика"},
			{"Захар Беркут", "Иван Франко", "Просвита", "Повесть"},
			{"Кайдашева семья", "Иван Нечуй-Левицкий", "Веселка", "Повесть"}
		};
		DieBibliotek(books, size);
	}

	{

	}
}

