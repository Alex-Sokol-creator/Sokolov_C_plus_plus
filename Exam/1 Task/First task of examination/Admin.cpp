#include "Admin.h"
#include <iostream>
#include <string>

Admin::Admin() = default;

Admin::Admin(const PIB& personal_data, const std::string& personal_address, const std::string& phone_number, const std::string& login, const std::string& password)
    : personal_data(personal_data), personal_address(personal_address), phone_number(phone_number), login(login), password(password) {}

const std::string& Admin::GetLogin() const {
    return login;
}

bool Admin::CheckPassword(const std::string& password) const {
    return this->password == password;
}