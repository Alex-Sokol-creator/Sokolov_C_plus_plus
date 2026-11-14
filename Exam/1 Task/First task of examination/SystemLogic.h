#pragma once
#include <vector>
#include "Guest.h"
#include "Tests.h"
#include "Admin.h"

class Files;

class Files {
public:
	void SaveGuests(const std::vector<Guest>& guests);
	// void LoadGuests();

	void SaveTests(const Tests& tests);
	// void LoadTests();

	void SaveResults();
	// void LoadResults();
};

class SystemLogic
{
private:
	std::vector<Guest> All_Guests; // массив гостей
	Admin admin; // админ
	Tests tests;
	Files files;
public:
	SystemLogic();
	~SystemLogic() = default;

	void Run(); // Старт программы
	void AdminRegistration(); // Регистрация админа + шифровка
	void GuestsRegistration(); // Регистрация гостей + шифрование
	void Uncoding(); // Расшифровка
	void Entering_the_system_guests(); // Вход гостей
	void Entering_the_system_admin(); // Вход админа

};