
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
	char number[9];
};

void SetMashina(Mashina& car) {
	cout << "Введите цвет машины: ";
	cin.getline(car.color, 30);
	cout << "Введите модель машины: ";
	cin.getline(car.model, 30);
	cout << "Введите номер машины: ";
	cin.getline(car.number, 9);
}

void PrintMashina(Mashina& car) {
	cout << "\nЦвет машины: " << car.color;
	cout << "\nМодель машины: " << car.model;
	cout << "\nНомер машины: " << car.number;
}

void ChangeMashina(Mashina cars[], int size) {
	int number;
	cout << "Введите номер машины, которую хотите отредактировать: ";
	cin >> number;
	if (number < 1 || number > size) {
		cout << "Такой машины к сожалению нет\n";
		return;
	}
	else {
		int index = number - 1;
		cin.ignore();
		cout << "Введите новый цвет " << index + 1 << " машины: ";
		cin.getline(cars[index].color, 30);
		cout << "Введите новую модель " << index + 1 << " машины: ";
		cin.getline(cars[index].model, 30);
		cout << "Введите новый номер " << index + 1 << " машины: ";
		cin.getline(cars[index].number, 9);
	}
}

void PrintMashins(Mashina cars[], int size) {
	cout << "Вот все машины:\n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " машина: \n";
		cout << "Цвет: " << cars[i].color << '\n';
		cout << "Модель: " << cars[i].model << '\n';
		cout << "Номер: " << cars[i].number << '\n';
	}
}

void SearchMashina(Mashina cars[], int size) {
	int completed = 0;
	char number[9];
	cout << "Введите номер машины для ее поиска: ";
	cin.ignore();
	cin.getline(number, 9);
	for (int i = 0; i < size; i++) {
		if (strcmp(cars[i].number, number) == 0) {
			cout << "Машина с таким номером была найдена, ее модель это " << cars[i].model << '\n';
			completed++;
		}
	}
	if (completed == 0) {
		cout << "Машина с таким номер к сожалению не была найдена\n";
	}
}

struct Creature {
	double speed;
	int type;
	char color[30];
	union {
		double birdspeed;
		bool animalpaw;
		int iq;
	};
};

void SetCreature(Creature& creature) {
	cout << "\nЗаполнение существа\n";
	creature.type = 0;
	while (creature.type < 1 || creature.type > 3) {
		cout << "Введите тип существа (1 - птица, 2 - животное, 3 - человек): ";
		cin >> creature.type;
	}
	cout << "Введите скорость существа (км/час): ";
	cin >> creature.speed;
	if (creature.type == 3) {
		cout << "Введите IQ человека: ";
		cin >> creature.iq;
	}
	else if (creature.type == 2) {
		int choice = 0;
		while (choice != 1 && choice != 2) {
			cout << "Животное парнокопытное? (1 - да, 2 - нет): ";
			cin >> choice;
		}
		if (choice == 1) {
			creature.animalpaw = true;
		}
		else {
			creature.animalpaw = false;
		}

	}
	else {
		cout << "Введите скорость птицы: ";
		cin >> creature.birdspeed;
	}
	cin.ignore();
	cout << "Введите цвет существа: ";
	cin.getline(creature.color, 30);
}

void PrintCreature(Creature creature, int i = 0) {
	if (i == 0) {
		cout << "Вот информация про сущность:\n";
	}
	if (creature.type == 1) {
		cout << "Тип: Птица" << '\n';
	}
	else if (creature.type == 2) {
		cout << "Тип: Животное" << '\n';
	}
	else {
		cout << "Тип: Человек" << '\n';
	}
	cout << "Цвет: " << creature.color << '\n';
	cout << "Скорость: " << creature.speed << " км/час" << '\n';
	if (creature.type == 1) {
		cout << "Скорость полета птицы: " << creature.birdspeed << '\n';
	}
	else if (creature.type == 2) {
		cout << "Животное парнокопытное?: " << creature.animalpaw << '\n';
	}
	else {
		cout << "IQ у человека: " << creature.iq << '\n';
	}
}

void ChangeCreature(Creature creatures[], int size) {
	int number;
	cout << "Введите номер существа, которое хотите отредактировать: ";
	cin >> number;
	if (number < 1 || number > size) {
		cout << "Такого существа к сожалению нет\n";
		return;
	}
	else {
		int index = number - 1;
		SetCreature(creatures[index]);
	}
}

void PrintCreatures(Creature creatures[], int size) {
	cout << "Вот все cущества:\n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " существо: \n";
		PrintCreature(creatures[i], i + 1);
	}
}

void SearchCreature(Creature creatures[], int size) {
	int choice = 0;
	while (choice < 1 || choice > 4) {
		cout << "По какому параметру вы хотите искать существ? (1 - скорость, 2 - тип, 3 - цвет, 4 - уникальное качество): ";
		cin >> choice;
	}
	switch (choice) {
	case 1: {
		int completed = 0;
		double searchspeed;
		cout << "Введите скорость: ";
		cin >> searchspeed;
		for (int i = 0; i < size; i++) {
			if (creatures[i].speed == searchspeed) {
				cout << "Существо с такой скоростью было найдено, у него индекс " << i << " и это ";
				if (creatures[i].type == 1) {
					cout << "птица" << '\n';
				}
				else if (creatures[i].type == 2) {
					cout << "животное" << '\n';
				}
				else {
					cout << "человек" << '\n';
				}
				completed++;
			}
		}
		if (completed == 0) {
			cout << "Существо с такой скоростью не было найдено к сожалению\n";
		}
		break;
	}
	case 2: {
		int completed = 0;
		int searchtype;
		cout << "Введите тип (1 - птица, 2 - животное, 3 - человек): ";
		cin >> searchtype;
		for (int i = 0; i < size; i++) {
			if (creatures[i].type == searchtype) {
				cout << "Существо с таким типом было найдено, у него индекс " << i << " и это ";
				if (creatures[i].type == 1) {
					cout << "птица" << '\n';
				}
				else if (creatures[i].type == 2) {
					cout << "животное" << '\n';
				}
				else {
					cout << "человек" << '\n';
				}
				completed++;
			}
		}
		if (completed == 0) {
			cout << "Существо с таким типом не было найдено к сожалению\n";
		}
		break;
	}
	case 3: {
		int completed = 0;
		char searchcolor[30];
		cin.ignore();
		cout << "Введите цвет существа: ";
		cin.getline(searchcolor,30);
		for (int i = 0; i < size; i++) {
			if (strcmp(creatures[i].color, searchcolor) == 0) {
				cout << "Существо с таким цветом было найдено, у него индекс " << i << " и это ";
				if (creatures[i].type == 1) {
					cout << "птица" << '\n';
				}
				else if (creatures[i].type == 2) {
					cout << "животное" << '\n';
				}
				else {
					cout << "человек" << '\n';
				}
				completed++;
			}
		}
		if (completed == 0) {
			cout << "Существо с таким цветом не было найдено к сожалению\n";
		}
		break;
	}
	case 4: {
		int completed = 0;
		int searchtype = 0;
		while (searchtype < 1 || searchtype > 3) {
			cout << "Введите тип (1 - птица, 2 - животное, 3 - человек): ";
			cin >> searchtype;
		}
		if (searchtype == 1) {
			double searchbirdspeed;
			cout << "Введите скорость птицы: ";
			cin >> searchbirdspeed;
			for (int i = 0; i < size; i++) {
				if (creatures[i].type == 1 && creatures[i].birdspeed == searchbirdspeed) {
					cout << "Птица с такой скоростью была найдена, и у нее индекс " << i << '\n';
					completed++;
				}
			}
		}
		else if (searchtype == 2) {
			int choice = 0;
			while (choice != 1 && choice != 2) {
				cout << "Введите, парнокопытное ли животное (1 - true, 2 - false): ";
				cin >> choice;
			}
			if (choice == 1) {
				for (int i = 0; i < size; i++) {
					if (creatures[i].type == 2 && creatures[i].animalpaw == true) {
						cout << "Парнокопытное животное есть, и у него индекс " << i << '\n';
						completed++;
					}
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					if (creatures[i].type == 2 && creatures[i].animalpaw == false) {
						cout << "Не парнокопытное животное есть, и у него индекс " << i << '\n';
						completed++;
					}
				}
			}
		}
		else {
			int searchiq;
			cout << "Введите IQ человека: ";
			cin >> searchiq;
			for (int i = 0; i < size; i++) {
				if (creatures[i].type == 3 && creatures[i].iq == searchiq) {
					cout << "Человек с таким IQ был найден, и у него индекс " << i << '\n';
					completed++;
				}
			}
		}
		if (completed == 0) {
			cout << "Существо с такой характеристикой не было найдено к сожалению\n";
		}
		break;
	}
	}
}

struct Student {
	char surname[30];
	char group[10];
	int grades[5];
};

void AddStudent(Student students[], int size) {
	cin.ignore();
	int index = size - 1;
	char surname_new[30], group_new[10];
	cout << "Введите фамилию нового студента: ";
	cin.getline(surname_new, 30);
	strcpy_s(students[index].surname, surname_new);
	cin.ignore();
	cout << "Введите группу студента: ";
	cin.getline(group_new, 10);
	strcpy_s(students[index].group, group_new);
	for (int i = 0; i < 5; i++) {
		cout << "Введите " << i + 1 << " оценку студента: ";
		cin >> students[index].grades[i];
	}
	cout << "Студент " << students[index].surname << " успешно записан";
}

void ChangeSizeStudent(Student*& students, int& size) {
	int choice = 0;
	while (choice != 1 && choice != 2) {
		cout << "Что вы хотите сделать с массивом? (1 - добавить студента в конец, 2 - удалить конкретного студента): ";
		cin >> choice;
	}
	if (choice == 1) {
		Student* students_new = new Student[size + 1];
		for (int i = 0; i < size; i++) {
			strcpy_s(students_new[i].surname, students[i].surname);
			strcpy_s(students_new[i].group, students[i].group);
			for (int j = 0; j < 5; j++) {
				students_new[i].grades[j] = students[i].grades[j];
			}
		}
		AddStudent(students_new, size + 1);
		delete[] students;
		students = students_new;
	}
	else {
		int position = 0;
		while (position < 1 || position > size) {
			cout << "Студента под каким номером вы хотите удалить?: ";
			cin >> position;
		}
		int index = position - 1;
		Student* students_new = new Student[size - 1];
		for (int i = 0; i < index; i++) {
			strcpy_s(students_new[i].surname, students[i].surname);
			strcpy_s(students_new[i].group, students[i].group);
			for (int j = 0; j < 5; j++) {
				students_new[i].grades[j] = students[i].grades[j];
			}
		}
		for (int i = index + 1; i < size; i++) {
			strcpy_s(students_new[i - 1].surname, students[i].surname);
			strcpy_s(students_new[i - 1].group, students[i].group);
			for (int j = 0; j < 5; j++) {
				students_new[i - 1].grades[j] = students[i].grades[j];
			}
		}
		delete[] students;
		students = students_new;
	}
}

void PrintStudentsByGrades(Student students[], int size) {
	cout << "\nСейчас будут выводиться отличники и двоечники\n";
	cout << "Список отличников: \n";
	for (int i = 0; i < size; i++) {
		int count_of_good = 0;
		for (int j = 0; j < 5; j++) {
			if (students[i].grades[j] >= 10) {
				count_of_good++;
			}
		}
		if (count_of_good >= 4) {
			cout << "Студент " << students[i].surname << " является отличником\n";
		}
	}
	cout << "Список двоечников: \n";
	for (int i = 0; i < size; i++) {
		int count_of_bad = 0;
		for (int j = 0; j < 5; j++) {
			if (students[i].grades[j] == 2 || students[i].grades[j] == 3) {
				count_of_bad++;
			}
		}
		if (count_of_bad >= 3) {
			cout << "Студент " << students[i].surname << " является двоечником\n";
		}
	}
}

struct Man_Date {
	int day;
	int month;
	int year;
};

struct Man {
	char surname[30];
	char name[20];
	int age;
	Man_Date birthday;
};

void Man_app(Man*& men, int& size) {
	cout << "Добро пожаловать в Man App\n";
	while (true) {
		int choice = 0;
		while (choice < 1 || choice > 5) {
			cout << "Что вы хотите сделать?\n1: Вывести информацию про людей\n2: Вывести список именинников месяца\n3: Добавить или убрать запись о человеке\n4: Поиск по фамилии и имени\n5: Редактировать запись о человеке\nВаш выбор: ";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			int choice_1 = 0;
			while (choice_1 != 1 && choice_1 != 2) {
				cout << "Перед выводом отсортировать людей по:\n1: Именам\n2: Фамилиям\nВаш выбор: ";
				cin >> choice_1;
			}
			if (choice_1 == 1) {
				cout << "Вот информация про людей, отсортированных по именам: \n";
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - i - 1; j++) {
						if ((strcmp(men[j].name, men[j + 1].name) > 0)) {
							Man temp = men[j];
							men[j] = men[j + 1];
							men[j + 1] = temp;
						}
					}
				}
				for (int i = 0; i < size; i++) {
					cout << i + 1 << " человек:\n";
					cout << "Имя: " << men[i].name << "\nФамилия: " << men[i].surname << "\nВозраст: " << men[i].age << "\nДата рождения: " << men[i].birthday.day << "." << men[i].birthday.month << "." << men[i].birthday.year << '\n';
				}
			}
			else {
				cout << "Вот информация про людей, отсортированных по фамилиям: \n";
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - i - 1; j++) {
						if ((strcmp(men[j].surname, men[j + 1].surname) > 0)) {
							Man temp = men[j];
							men[j] = men[j + 1];
							men[j + 1] = temp;
						}
					}
				}
				for (int i = 0; i < size; i++) {
					cout << i + 1 << " человек:\n";
					cout << "Имя: " << men[i].name << "\nФамилия: " << men[i].surname << "\nВозраст: " << men[i].age << "\nДата рождения: " << men[i].birthday.day << "." << men[i].birthday.month << "." << men[i].birthday.year << '\n';
				}
			}
			break;
		}
		case 2: {
			int choice_2 = 0;
			while (choice_2 < 1 || choice_2 > 12) {
				cout << "Введите порядковый номер месяца, чтобы вывести именинников, которые в нем родились: ";
				cin >> choice_2;
			}
			cout << "Вот все именинники " << choice_2 << " месяца: \n";
			for (int i = 0; i < size; i++) {
				if (men[i].birthday.month == choice_2) {
					cout << men[i].name << ' ' << men[i].surname << " - " << men[i].birthday.day << "." << men[i].birthday.month << "." << men[i].birthday.year << '\n';
				}
			}
			break;
		}
		case 3: {
			int choice_3 = 0;
			while (choice_3 != 1 && choice_3 != 2) {
				cout << "Вы хотите: \n1: Добавить запись о человеке в конец\n2: Убрать конкретную запись о человеке\nВаш выбор: ";
				cin >> choice_3;
			}
			if (choice_3 == 1) {
				Man* men_new = new Man[size + 1];
				for (int i = 0; i < size; i++) {
					strcpy_s(men_new[i].surname, men[i].surname);
					strcpy_s(men_new[i].name, men[i].name);
					men_new[i].age = men[i].age;
					men_new[i].birthday.day = men[i].birthday.day;
					men_new[i].birthday.month = men[i].birthday.month;
					men_new[i].birthday.year = men[i].birthday.year;
				}
				int index = size;
				char surname_new[30], name_new[20];
				int age_new = -1, day_new = 0,month_new = 0,year_new = 0;
				cin.ignore();
				cout << "Введите имя нового человека: ";
				cin.getline(name_new, 20);
				strcpy_s(men_new[index].name, name_new);
				cout << "Введите фамилию нового человека: ";
				cin.getline(surname_new, 30);
				strcpy_s(men_new[index].surname, surname_new);
				while (age_new < 0 || age_new > 200) {
					cout << "Введите возраст человека: ";
					cin >> age_new;
				}
				men_new[index].age = age_new;
				cout << "Введите дату рождения человека: ";
				while (day_new < 1 || day_new > 31) {
					cout << "День: ";
					cin >> day_new;
				}
				while (month_new < 1 || month_new > 12) {
					cout << "Месяц: ";
					cin >> month_new;
				}
				cout << "Год: ";
				cin >> year_new;
				men_new[index].birthday.day = day_new, men_new[index].birthday.month = month_new, men_new[index].birthday.year = year_new;
				cout << "Человек с фамилией " << men_new[index].surname << " успешно записан";
				delete[] men;
				size++;
				men = men_new;
			}
			else {
				int position = 0;
				while (position < 1 || position > size) {
					cout << "Человека под каким номером вы хотите удалить?: ";
					cin >> position;
				}
				int index = position - 1;
				Man* men_new = new Man[size - 1];
				for (int i = 0; i < index; i++) {
					strcpy_s(men_new[i].name, men[i].name);
					strcpy_s(men_new[i].surname, men[i].surname);
					men_new[i].age = men[i].age;
					men_new[i].birthday.day = men[i].birthday.day;
					men_new[i].birthday.month = men[i].birthday.month;
					men_new[i].birthday.year = men[i].birthday.year;
				}
				for (int i = index + 1; i < size; i++) {
					strcpy_s(men_new[i - 1].name, men[i].name);
					strcpy_s(men_new[i - 1].surname, men[i].surname);
					men_new[i - 1].age = men[i].age;
					men_new[i - 1].birthday.day = men[i].birthday.day;
					men_new[i - 1].birthday.month = men[i].birthday.month;
					men_new[i - 1].birthday.year = men[i].birthday.year;
				}
				delete[] men;
				size--;
				men = men_new;
			}
			break;
		}
		case 4: {
			cin.ignore();
			int completed = 0;
			char search_name[20], search_surname[30];
			cout << "Введите имя человека для поиска: ";
			cin.getline(search_name, 20);
			cout << "Введите фамилию человека для поиска: ";
			cin.getline(search_surname, 30);
			for (int i = 0; i < size; i++) {
				if (strcmp(men[i].name, search_name) == 0 && strcmp(men[i].surname, search_surname) == 0) {
					cout << "Человек с таким именем и фамилией найден, он записан в системе под номером " << i + 1 << '\n';
					completed++;
				}
			}
			if (completed == 0) {
				cout << "К сожалению, человека с таким именем и фамилией нет в системе\n";
			}
			break;
		}
		case 5: {
			int choice_5 = 0;
			while (choice_5 < 1 || choice_5 > size) {
				cout << "Под каким номером человек, которого вы хотите отредактировать?: ";
				cin >> choice_5;
			}
			int index = choice_5 - 1;
			char surname_new[30], name_new[20];
			int age_new = -1, day_new = 0, month_new = 0, year_new = 0;
			cin.ignore();
			cout << "Введите имя человека: ";
			cin.getline(name_new, 20);
			strcpy_s(men[index].name, name_new);
			cout << "Введите фамилию человека: ";
			cin.getline(surname_new, 30);
			strcpy_s(men[index].surname, surname_new);
			while (age_new < 0 || age_new > 200) {
				cout << "Введите возраст человека: ";
				cin >> age_new;
			}
			men[index].age = age_new;
			cout << "Введите дату рождения человека: ";
			while (day_new < 1 || day_new > 31) {
				cout << "День: ";
				cin >> day_new;
			}
			while (month_new < 1 || month_new > 12) {
				cout << "Месяц: ";
				cin >> month_new;
			}
			cout << "Год: ";
			cin >> year_new;
			men[index].birthday.day = day_new, men[index].birthday.month = month_new, men[index].birthday.year = year_new;
			cout << "Человек был успешно перезаписан";
			break;
		}
		}

		int exit;
		cout << "\nВы хотите выйти? (1 - да, любое число - нет): ";
		cin >> exit;
		if (exit == 1) {
			cout << "До свидания!";
			break;
		}
	}
}

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
		cout << "\nFourth Task\n";
		const int size = 10;

		Mashina cars[size] = {
		{"Красный", "Audi A4", "12345"},
		{"Черный", "BMW X5", "BOSSMAN"},
		{"Белый", "Toyota Camry", "77777"},
		{"Синий", "Ford Focus", "FOCUS99"},
		{"Серый", "Mercedes E200", "55555"},
		{"Желтый", "Porsche 911", "FASTCAR"},
		{"Зеленый", "Skoda Octavia", "44321"},
		{"Серебристый", "Honda Civic", "HONDA7"},
		{"Оранжевый", "Nissan Leaf", "ECODRIVE"},
		{"Коричневый", "Volvo XC90", "10101"}
		};

		int choice;
		while (true) {
			cout << "\nЧто вы хотите сделать?: \n";
			cout << "1. Заполнить одну отдельную машину\n";
			cout << "2. Печать одной машины\n";
			cout << "3. Редактировать любую машину из 10\n";
			cout << "4. Печать всех 10 машин\n";
			cout << "5. Поиск машины по номеру\n";
			cout << "0. Выход\n";
			cout << "Выберите действие: ";

			cin >> choice;

			switch (choice) {
			case 1: {
				cin.ignore();
				cout << "\nЗаполнение машины: \n";
				SetMashina(cars[0]);
				break;
			}
			case 2: {
				cout << "\nПечать машины: \n";
				PrintMashina(cars[0]);
				break;
			}
			case 3: {
				ChangeMashina(cars, size);
				break;
			}
			case 4: {
				PrintMashins(cars, size);
				break;
			}
			case 5: {
				SearchMashina(cars, size);
				break;
			}
			}
			if (choice == 0) {
				break;
			}
		}
		cout << "\nДо свидания!\n";
	}

	{
		cout << "\nFifth Task\n";

		Creature army[10] = {
			{ 15.5,  1, "Серый",      {.birdspeed = 60.0} },   // Голубь
			{ 45.0,  2, "Коричневый", {.animalpaw = true} },  // Олень
			{  5.0,  3, "Белый",      {.iq = 120} },          // Программист
			{ 22.0,  1, "Черный",     {.birdspeed = 85.5} },   // Ворон
			{ 50.0,  2, "Пятнистый",  {.animalpaw = true} },  // Корова
			{  6.5,  3, "Загорелый",  {.iq = 95} },           // Спортсмен
			{320.0,  1, "Пестрый",    {.birdspeed = 320.0} }, // Сапсан
			{ 12.0,  2, "Розовый",    {.animalpaw = true} },  // Свинья
			{  4.0,  3, "Рыжий",      {.iq = 140} },          // Ученый
			{ 60.0,  2, "Рыжий",      {.animalpaw = false} }  // Лев (не парнокопытный)
		};

		Creature human;
		SetCreature(human);
		PrintCreature(human);

		PrintCreatures(army, 10);
		ChangeCreature(army, 10);
		PrintCreatures(army, 10);
		SearchCreature(army, 10);
	}

	{
		cout << "\nSixth Task\n";
		int size = 5;
		Student* army_students = new Student[size];

		strcpy_s(army_students[0].surname, "Иванов");
		strcpy_s(army_students[0].group, "КИ-21-1");
		army_students[0].grades[0] = 12; army_students[0].grades[1] = 12; army_students[0].grades[2] = 12; army_students[0].grades[3] = 12; army_students[0].grades[4] = 12;

		strcpy_s(army_students[1].surname, "Петров");
		strcpy_s(army_students[1].group, "КИ-21-1");
		army_students[1].grades[0] = 10; army_students[1].grades[1] = 10; army_students[1].grades[2] = 10; army_students[1].grades[3] = 10; army_students[1].grades[4] = 8;

		strcpy_s(army_students[2].surname, "Сидоров");
		strcpy_s(army_students[2].group, "КИ-21-2");
		army_students[2].grades[0] = 9; army_students[2].grades[1] = 8; army_students[2].grades[2] = 7; army_students[2].grades[3] = 9; army_students[2].grades[4] = 8;

		strcpy_s(army_students[3].surname, "Коваленко");
		strcpy_s(army_students[3].group, "КИ-21-2");
		army_students[3].grades[0] = 3; army_students[3].grades[1] = 3; army_students[3].grades[2] = 3; army_students[3].grades[3] = 9; army_students[3].grades[4] = 9;

		strcpy_s(army_students[4].surname, "Шевченко");
		strcpy_s(army_students[4].group, "КИ-21-1");
		army_students[4].grades[0] = 2; army_students[4].grades[1] = 2; army_students[4].grades[2] = 3; army_students[4].grades[3] = 3; army_students[4].grades[4] = 10;

		PrintStudentsByGrades(army_students, size);

		ChangeSizeStudent(army_students, size);

		PrintStudentsByGrades(army_students, size);

		delete[] army_students;
	}

	{
		cout << "\nSeventh Task\n";

		int current_size = 3;

		Man* database = new Man[current_size];

		strcpy_s(database[0].name, "Иван");
		strcpy_s(database[0].surname, "Иванов");
		database[0].age = 20;
		database[0].birthday = { 15, 8, 2006 }; // день, месяц, год

		strcpy_s(database[1].name, "Анна");
		strcpy_s(database[1].surname, "Петрова");
		database[1].age = 22;
		database[1].birthday = { 5, 12, 2004 };

		strcpy_s(database[2].name, "Алексей");
		strcpy_s(database[2].surname, "Сидоров");
		database[2].age = 19;
		database[2].birthday = { 28, 8, 2007 };

		Man_app(database, current_size);

		delete[] database;
	}
}