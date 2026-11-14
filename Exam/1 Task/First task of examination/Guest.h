#pragma once
#include <vector>
#include <string>
#include "PIB.h"

class Tests;

class Guest
{
private:
    PIB personal_data;
    std::string personal_address;
    std::string phone_number;
    std::string login;
    std::string password;
public:
    Guest();
    Guest(const PIB& personal_data, const std::string& personal_address, const std::string& phone_number, const std::string& login, const std::string& password);

    bool CheckGuestData() const; // Проверка
    void StartTesting(Tests& tests); // Контроль начала тестов
};

