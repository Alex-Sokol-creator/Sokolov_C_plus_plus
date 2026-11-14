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