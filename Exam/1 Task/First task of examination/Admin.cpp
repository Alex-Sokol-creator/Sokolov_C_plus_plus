#include "Admin.h"
#include <iostream>
#include <string>

const std::string& Admin::GetLogin() const {
    return login;
}

bool Admin::CheckPassword(const std::string& password) const {
    return this->password == password;
}