#include "Admin.h"
#include "Guest.h"
#include "Tests.h"
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

Admin_Tools& Admin::GetTools(){
    return tools;
}

void Admin_Tools::ShowGuests(const std::vector<Guest>& guests) const{
    if (guests.empty()) {
        std::cout << "\nСписок гостей пуст.\n";
        return;
    }
    std::cout << "\n===== СПИСОК ЗАРЕГИСТРИРОВАННЫХ ГОСТЕЙ =====\n";
    for (int i = 0; i < guests.size(); i++) {
        std::cout << "\nГость №" << i + 1 << '\n' << "Логин: " << guests[i].GetLogin() << '\n';
    }
}

void Admin_Tools::AddGuest(std::vector<Guest>& guests){
    PIB personal_data;
    std::string personal_address;
    std::string phone_number;
    std::string login;
    std::string password;
    std::cin.ignore();
    std::cout << "\n===== ДОБАВЛЕНИЕ ГОСТЯ =====\n";
    std::cout << "Введите имя: ";
    std::getline(std::cin, personal_data.name);
    std::cout << "Введите фамилию: ";
    std::getline(std::cin, personal_data.surname);
    std::cout << "Введите отчество: ";
    std::getline(std::cin, personal_data.fathers_name);
    std::cout << "Введите адрес: ";
    std::getline(std::cin, personal_address);
    std::cout << "Введите номер телефона: ";
    std::getline(std::cin, phone_number);
    std::cout << "Придумайте логин: ";
    std::getline(std::cin, login);
    for (const Guest& guest : guests) {
        if (guest.GetLogin() == login) {
            std::cout << "Ошибка! Такой логин уже существует.\n";
            return;
        }
    }
    std::cout << "Придумайте пароль: ";
    std::getline(std::cin, password);
    Guest new_guest(
        personal_data,
        personal_address,
        phone_number,
        login,
        password
    );
    if (new_guest.CheckGuestData() != true) {
        std::cout << "Ошибка! Заполните все обязательные поля.\n";
        return;
    }
    guests.push_back(new_guest);
    std::cout << "\nГость успешно добавлен!\n";
}

void Admin_Tools::DeleteGuest(std::vector<Guest>& guests){
    if (guests.empty()) {
        std::cout << "\nСписок гостей пуст.\n";
        return;
    }
    std::cout << "\n===== УДАЛЕНИЕ ГОСТЯ =====\n";
    for (int i = 0; i < guests.size(); i++) {
        std::cout << i + 1 << ". " << guests[i].GetLogin() << '\n';
    }
    int choice;
    std::cout << "\nВыберите номер гостя для удаления: ";
    std::cin >> choice;
    if (choice < 1 || choice > guests.size()) {
        std::cout << "Неверный номер гостя, повторите попытку\n";
        return;
    }
    guests.erase(guests.begin() + (choice - 1));
    std::cout << "Гость успешно удалён!\n";
}

void Admin_Tools::ModifyGuest(std::vector<Guest>& guests){
    if (guests.empty()) {
        std::cout << "\nСписок гостей пуст.\n";
        return;
    }
    std::cout << "\n===== ИЗМЕНЕНИЕ ДАННЫХ ГОСТЯ =====\n";
    for (int i = 0; i < guests.size(); i++) {
        std::cout << i + 1 << ". " << guests[i].GetLogin() << '\n';
    }
    int guest_choice;
    std::cout << "Выберите номер гостя: ";
    std::cin >> guest_choice;
    if (guest_choice < 1 || guest_choice > static_cast<int>(guests.size())) {
        std::cout << "Неверный номер гостя!\n";
        return;
    }
    Guest& selected_guest = guests[guest_choice - 1];
    int field_choice;
    std::cout << "\nВыбран гость: " << selected_guest.GetLogin() << '\n';
    std::cout << "\nЧто хотите изменить?\n";
    std::cout << "1. Имя\n";
    std::cout << "2. Фамилию\n";
    std::cout << "3. Отчество\n";
    std::cout << "4. Адрес\n";
    std::cout << "5. Номер телефона\n";
    std::cout << "6. Логин\n";
    std::cout << "7. Пароль\n";
    std::cout << "Ваш выбор: ";
    std::cin >> field_choice;
    std::string new_value;
    std::cout << "Введите новое значение: ";
    std::getline(std::cin, new_value);
    if (new_value.empty()) {
        std::cout << "Новое значение не может быть пустым!\n";
        return;
    }
    switch (field_choice) {
    case 1:
        selected_guest.SetName(new_value);
        break;

    case 2:
        selected_guest.SetSurname(new_value);
        break;

    case 3:
        selected_guest.SetFathersName(new_value);
        break;

    case 4:
        selected_guest.SetAddress(new_value);
        break;

    case 5:
        selected_guest.SetPhoneNumber(new_value);
        break;

    case 6:
        for (const Guest& guest : guests) {
            if (guest.GetLogin() == new_value) {
                std::cout << "Такой логин уже занят!\n";
                return;
            }
        }
        selected_guest.SetLogin(new_value);
        break;

    case 7:
        selected_guest.SetPassword(new_value);
        break;

    default:
        std::cout << "Неверный пункт меню!\n";
        return;
    }
    std::cout << "\nДанные гостя успешно изменены!\n";
}

void Admin_Tools::AddCategory(Tests& tests){
    std::string category_name;
    std::cout << "\n===== ДОБАВЛЕНИЕ КАТЕГОРИИ =====\n";
    std::cout << "Введите название категории: ";
    std::getline(std::cin, category_name);
    if (category_name.empty()) {
        std::cout << "Название категории не может быть пустым!\n";
        return;
    }
    const std::vector<Category>& categories = tests.GetCategories();
    for (const Category& category : categories) {
        if (category.name == category_name) {
            std::cout << "Такая категория уже существует!\n";
            return;
        }
    }
    Category new_category;
    new_category.name = category_name;
    tests.AddCategory(new_category);
    std::cout << "Категория успешно добавлена!\n";
}

void Admin_Tools::DeleteCategory(Tests& tests){
    const std::vector<Category>& categories = tests.GetCategories();
    if (categories.empty()) {
        std::cout << "\nКатегорий для удаления нет\n";
        return;
    }
    ShowCategories(tests);
    int choice;
    std::cout << "\nВыберите номер категории для удаления: ";
    std::cin >> choice;
    std::cin.ignore();
    if (choice < 1 || choice > static_cast<int>(categories.size())) {
        std::cout << "Неверный номер категории!\n";
        return;
    }
    tests.DeleteCategory(choice - 1);
    std::cout << "Категория успешно удалена!\n";
}


void Admin_Tools::ShowCategories(const Tests& tests) const{
    const std::vector<Category>& categories = tests.GetCategories();
    if (categories.empty()) {
        std::cout << "\nКатегорий пока нет.\n";
        return;
    }
    std::cout << "\n===== СПИСОК КАТЕГОРИЙ =====\n";
    for (int i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].name << " | Количество тестов: " << categories[i].tests.size() << '\n';
    }
}

void Admin_Tools::ManageCategories(Tests& tests){
    int choice = 0;
    do {
        std::cout << "\n===== УПРАВЛЕНИЕ КАТЕГОРИЯМИ =====\n";
        std::cout << "1. Просмотреть категории\n";
        std::cout << "2. Добавить категорию\n";
        std::cout << "3. Удалить категорию\n";
        std::cout << "4. Вернуться назад\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:
            ShowCategories(tests);
            break;
        case 2:
            AddCategory(tests);
            break;
        case 3:
            DeleteCategory(tests);
            break;
        case 4:
            std::cout << "Возвращаемся в меню администратора...\n";
            break;
        default:
            std::cout << "Неверный выбор, повторите попытку\n";
        }

    } while (choice != 4);
}

void Admin_Tools::ShowTests(const Tests& tests) const{
    const std::vector<Category>& categories = tests.GetCategories();
    if (categories.empty()) {
        std::cout << "\nКатегорий пока нет.\n";
        return;
    }
    int category_choice;
    std::cout << "\n===== ВЫБОР КАТЕГОРИИ =====\n";
    for (int i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].name << '\n';
    }
    std::cout << "Выберите категорию: ";
    std::cin >> category_choice;
    std::cin.ignore();
    if (category_choice < 1 ||
        category_choice > static_cast<int>(categories.size())) {
        std::cout << "Неверный номер категории!\n";
        return;
    }

    const Category& selected_category = categories[category_choice - 1];

    std::cout << "\n===== ТЕСТЫ КАТЕГОРИИ: "
        << selected_category.name << " =====\n";

    if (selected_category.tests.empty()) {
        std::cout << "В этой категории пока нет тестов.\n";
        return;
    }

    for (size_t i = 0; i < selected_category.tests.size(); i++) {
        const Test& test = selected_category.tests[i];

        std::cout << "\nТест №" << i + 1 << '\n';
        std::cout << "ID: " << test.id << '\n';
        std::cout << "Название: " << test.name << '\n';
        std::cout << "Количество вопросов: "
            << test.questions.size() << '\n';
    }
}