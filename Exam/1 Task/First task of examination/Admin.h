#pragma once
#include <vector>
#include <string>
#include "PIB.h"

class Tests;
class Guest;

class Admin_Tools {
public:
	void AddGuest(std::vector<Guest>& guests);
	void DeleteGuest(Guest& guest);
	void ModifyGuest(Guest& guest);
	void AddCategory(Tests& tests);
	void DeleteCategory(Tests& tests);
	void AddTest(Tests& tests);
	void AddQuestion(Tests& tests);
	void ShowStatistics(Tests& tests) const;
	void ImportText();
	void ExportText();
};

class Admin
{
private:
	PIB personal_data;
	std::string personal_adress;
	std::string phone_number;
	std::string login;
	std::string password;
	Admin_Tools tools;
public:
	Admin();
	Admin(const PIB& personal_data, const std::string& personal_address, const std::string& phone_number, const std::string& login, const std::string& password);

	void ChangeLogin();
	void ChangePassword();
};

