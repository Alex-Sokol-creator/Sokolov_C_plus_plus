#pragma once
#include <string>
#include <vector>
#include "Guest.h"
#include "Tests.h"
#include "TestAttempt.h"
#include "Admin.h"

class Files;

class Files {
public:
	void SaveGuests(const std::vector<Guest>& guests);

	void SaveTests(const Tests& tests);
	void LoadTests(Tests& tests);
};

class SystemLogic
{
private:
	std::vector<Guest> All_Guests; // массив гостей
	Admin admin; // админ
	Tests tests; // Тесты
	Files files; // Файловый менеджер
	bool admin_registered = false;
public:
	SystemLogic();
	~SystemLogic() = default;

	void Run(); // Старт программы
	void AdminRegistration(); // Регистрация админа + шифровка
	void GuestsRegistration(); // Регистрация гостей + шифрование
	bool IsLoginTaken(const std::string& login) const;
	void Uncoding(); // Расшифровка
	void Entering_the_system_guests(); // Вход гостей
	void Entering_the_system_admin(); // Вход админа

	void GuestMenu(Guest& guest); // Меню гостя
	void AdminMenu(); // Меню админа
	void StartGuestTesting(Guest& guest); // Контроль начала тестов
};