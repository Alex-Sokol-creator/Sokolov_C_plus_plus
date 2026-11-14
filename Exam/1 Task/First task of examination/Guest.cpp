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

