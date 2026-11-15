#include "Admin.h"
#include "Guest.h"
#include "Tests.h"
#include <iostream>
#include <string>

Admin::Admin() = default;

Admin::Admin(const PIB& personal_data, const std::string& personal_address, const std::string& phone_number, const std::string& login, const std::string& password)
    : personal_data(personal_data), personal_address(personal_address), phone_number(phone_number), login(login), password(password) {}

void Admin::ChangeLogin() {
    std::string login_new;
    std::cout << "Напишите новый логин: ";
    std::getline(std::cin, login_new);
    if (login_new.empty()) {
        std::cout << "Логин не может быть пустой!\n";
        return;
    }
    this->login = login_new;
    std::cout << "Логин администратора успешно изменен!\n";
}

void Admin::ChangePassword() {
    std::string password_new;
    std::cout << "Напишите новый пароль: ";
    std::getline(std::cin, password_new);
    if (password_new.empty()) {
        std::cout << "Пароль не может быть пустой!\n";
        return;
    }
    this->password = password_new;
    std::cout << "Пароль администратора успешно изменен!\n";
}

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
    std::cin.ignore();
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
    if (category_choice < 1 || category_choice > static_cast<int>(categories.size())) {
        std::cout << "Неверный номер категории!\n";
        return;
    }
    const Category& selected_category = categories[category_choice - 1];
    std::cout << "\n===== ТЕСТЫ КАТЕГОРИИ: " << selected_category.name << " =====\n";
    if (selected_category.tests.empty()) {
        std::cout << "В этой категории пока нет тестов.\n";
        return;
    }
    for (int i = 0; i < selected_category.tests.size(); i++) {
        const Test& test = selected_category.tests[i];
        std::cout << "\nТест №" << i + 1 << '\n' << "ID: " << test.id << '\n' << "Название: " << test.name << '\n'
            << "Количество вопросов: " << test.questions.size() << '\n';
    }
}

void Admin_Tools::AddTest(Tests& tests){
    const std::vector<Category>& categories = tests.GetCategories();
    if (categories.empty()) {
        std::cout << "\nСначала создайте категорию!\n";
        return;
    }
    std::cout << "\n===== ДОБАВЛЕНИЕ ТЕСТА =====\n";
    for (int i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].name << '\n';
    }
    int category_choice;
    std::cout << "Выберите категорию для нового теста: ";
    std::cin >> category_choice;
    std::cin.ignore();
    if (category_choice < 1 || category_choice > static_cast<int>(categories.size())) {
        std::cout << "Неверный номер категории!\n";
        return;
    }
    std::string test_name;
    std::cout << "Введите название теста: ";
    std::getline(std::cin, test_name);
    if (test_name.empty()) {
        std::cout << "Название теста не может быть пустым!\n";
        return;
    }
    int max_id = 0;
    for (const Category& category : categories) {
        for (const Test& test : category.tests) {
            if (test.id > max_id) {
                max_id = test.id;
            }
        }
    }
    Test new_test;
    new_test.id = max_id + 1;
    new_test.name = test_name;
    tests.AddTest(category_choice - 1, new_test);
    std::cout << "\nТест успешно добавлен!\n";
    std::cout << "Присвоенный ID: " << new_test.id << '\n';
}

void Admin_Tools::DeleteTest(Tests& tests){
    const std::vector<Category>& categories = tests.GetCategories();
    if (categories.empty()) {
        std::cout << "\nКатегорий пока нет.\n";
        return;
    }
    std::cout << "\n===== УДАЛЕНИЕ ТЕСТА =====\n";
    for (int i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].name << '\n';
    }
    int category_choice;
    std::cout << "Выберите категорию: ";
    std::cin >> category_choice;
    std::cin.ignore();
    if (category_choice < 1 || category_choice > static_cast<int>(categories.size())) {
        std::cout << "Неверная категория!\n";
        return;
    }
    const Category& selected_category = categories[category_choice - 1];
    if (selected_category.tests.empty()) {
        std::cout << "В этой категории нет тестов.\n";
        return;
    }
    for (int i = 0; i < selected_category.tests.size(); i++) {
        std::cout << i + 1 << ". " << selected_category.tests[i].name << " (ID: " << selected_category.tests[i].id << ")\n";
    }
    int test_choice;
    std::cout << "Выберите тест для удаления: ";
    std::cin >> test_choice;
    std::cin.ignore();
    if (test_choice < 1 || test_choice > static_cast<int>(selected_category.tests.size())) {
        std::cout << "Неверный номер теста!\n";
        return;
    }
    tests.DeleteTest(category_choice - 1, test_choice - 1);
    std::cout << "Тест успешно удалён!\n";
}

void Admin_Tools::ManageTests(Tests& tests){
    int choice = 0;
    do {
        std::cout << "\n===== УПРАВЛЕНИЕ ТЕСТАМИ =====\n";
        std::cout << "1. Просмотреть тесты\n";
        std::cout << "2. Добавить тест\n";
        std::cout << "3. Удалить тест\n";
        std::cout << "4. Добавить вопрос\n";
        std::cout << "5. Вернуться назад\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:
            ShowTests(tests);
            break;
        case 2:
            AddTest(tests);
            break;
        case 3:
            DeleteTest(tests);
            break;
        case 4:
            AddQuestion(tests);
            break;
        case 5:
            std::cout << "Возвращаемся назад...\n";
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 5);
}

void Admin_Tools::AddQuestion(Tests& tests) {
    const auto& categories = tests.GetCategories();
    if (categories.empty()) {
        std::cout << "Нет доступных категорий!\n";
        return;
    }
    std::cout << "\nВыберите категорию:\n";
    for (int i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].name << '\n';
    }
    int category_choice;
    std::cout << "Ваш выбор: ";
    std::cin >> category_choice;
    if (category_choice < 1 || category_choice > categories.size()) {
        std::cout << "Неверный выбор!\n";
        return;
    }
    int category_index = category_choice - 1;
    if (categories[category_index].tests.empty()) {
        std::cout << "В этой категории нет тестов!\n";
        return;
    }
    std::cout << "\nВыберите тест:\n";
    for (int i = 0; i < categories[category_index].tests.size(); i++) {
        std::cout << i + 1 << ". " << categories[category_index].tests[i].name << '\n';
    }
    int test_choice;
    std::cout << "Ваш выбор: ";
    std::cin >> test_choice;
    if (test_choice < 1 || test_choice > categories[category_index].tests.size()) {
        std::cout << "Неверный выбор!\n";
        return;
    }
    int test_index = test_choice - 1;
    std::cin.ignore();
    Question question;
    std::cout << "\nВведите текст вопроса: ";
    std::getline(std::cin, question.text);
    if (question.text.empty()) {
        std::cout << "Вопрос не может быть пустым!\n";
        return;
    }
    int answer_count;
    std::cout << "Введите количество вариантов ответа (от 2 до 6): ";
    std::cin >> answer_count;
    if (answer_count < 2 || answer_count > 6) {
        std::cout << "Недопустимое количество ответов!\n";
        return;
    }
    std::cin.ignore();
    for (int i = 0; i < answer_count; i++) {
        Answer answer;
        std::cout << "Введите вариант ответа " << i + 1 << ": ";
        std::getline(std::cin, answer.text);
        if (answer.text.empty()) {
            std::cout << "Ответ не может быть пустым!\n";
            return;
        }
        answer.is_correct = false;
        question.answers.push_back(answer);
    }
    int correct_choice;
    std::cout << "\nВведите номер правильного ответа (1-" << answer_count << "): ";
    std::cin >> correct_choice;
    if (correct_choice < 1 || correct_choice > answer_count) {
        std::cout << "Неверный номер ответа!\n";
        return;
    }
    question.answers[correct_choice - 1].is_correct = true;
    tests.AddQuestion(category_index, test_index, question);
    std::cout << "\nВопрос успешно добавлен!\n";
}

void Admin_Tools::ShowStatistics(Tests& tests) const {
    const auto& categories = tests.GetCategories();
    int total_tests = 0;
    int total_questions = 0;
    for (const Category& category : categories) {
        total_tests += static_cast<int>(category.tests.size());
        for (const Test& test : category.tests) {
            total_questions += static_cast<int>(test.questions.size());
        }
    }
    std::cout << "\n========== СТАТИСТИКА СИСТЕМЫ ==========\n";
    std::cout << "Количество категорий: " << categories.size() << '\n';
    std::cout << "Количество тестов: " << total_tests << '\n';
    std::cout << "Количество вопросов: " << total_questions << '\n';
}


const PIB& Admin::GetPersonalData() const {
    return personal_data;
}

const std::string& Admin::GetAddress() const {
    return personal_address;
}

const std::string& Admin::GetPhoneNumber() const {
    return phone_number;
}

const std::string& Admin::GetPassword() const {
    return password;
}