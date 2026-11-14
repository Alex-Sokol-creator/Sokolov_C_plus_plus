#pragma once
#include <vector>
#include <string>
#include "PIB.h"

struct TestResult {
    int test_id;
    std::string test_name;
    int correct_answers;
    double percentage;
    int grade;
};

class Guest
{
private:
    PIB personal_data;
    std::string personal_address;
    std::string phone_number;
    std::string login;
    std::string password;
    std::vector<TestResult> results;
public:
    Guest();
    Guest(const PIB& personal_data, const std::string& personal_address, const std::string& phone_number, const std::string& login, const std::string& password);

    bool CheckGuestData() const; // Проверка
    const std::string& GetLogin() const; // Геттер логина
    bool CheckPassword(const std::string& password) const; // Проверка пароля

    void AddResult(const TestResult& result);
    void ShowResults() const;
};

