#include "Guest.h"
#include <iostream>

Guest::Guest() : personal_data{}, personal_address(""), phone_number(""), login(""), password("") {}

Guest::Guest(
    const PIB& personal_data,
    const std::string& personal_address,
    const std::string& phone_number,
    const std::string& login,
    const std::string& password
) : personal_data(personal_data), personal_address(personal_address), phone_number(phone_number), login(login), password(password) {}

bool Guest::CheckGuestData() const
{
    if (personal_data.name.empty())
        return false;
    if (personal_data.surname.empty())
        return false;
    if (login.empty())
        return false;
    if (password.empty())
        return false;
    if (phone_number.empty())
        return false;
    return true;
}

const std::string& Guest::GetLogin() const{
    return login;
}

bool Guest::CheckPassword(const std::string& password) const{
    return this->password == password;
}

void Guest::AddResult(const TestResult& result){
    results.push_back(result);
}

void Guest::ShowResults() const{
    if (results.empty()) {
        std::cout << "У вас пока нет пройденных тестов.\n";
        return;
    }
    std::cout << "\n========== ИСТОРИЯ РЕЗУЛЬТАТОВ ==========\n";
    for (const TestResult& result : results) {
        std::cout << "\nТест: " << result.test_name << '\n' << "ID теста: " << result.test_id << '\n' << "Правильных ответов: " << result.correct_answers << '\n'
            << "Процент правильных ответов: " << result.percentage << "%\n" << "Оценка: " << result.grade << "/12\n";
    }
}

void Guest::SetName(const std::string& name) {
    personal_data.name = name;
}

void Guest::SetSurname(const std::string& surname) {
    personal_data.surname = surname;
}

void Guest::SetFathersName(const std::string& fathers_name) {
    personal_data.fathers_name = fathers_name;
}

void Guest::SetAddress(const std::string& address) {
    personal_address = address;
}

void Guest::SetPhoneNumber(const std::string& phone_number) {
    this->phone_number = phone_number;
}

void Guest::SetLogin(const std::string& login) {
    this->login = login;
}

void Guest::SetPassword(const std::string& password) {
    this->password = password;
}


const PIB& Guest::GetPersonalData() const {
    return personal_data;
}

const std::string& Guest::GetAddress() const {
    return personal_address;
}

const std::string& Guest::GetPhoneNumber() const {
    return phone_number;
}

const std::string& Guest::GetPassword() const {
    return password;
}

const std::vector<TestResult>& Guest::GetResults() const {
    return results;
}