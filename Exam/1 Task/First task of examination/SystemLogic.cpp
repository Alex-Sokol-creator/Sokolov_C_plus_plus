#include "SystemLogic.h"
#include <iostream>
#include <vector>
#include <string>


SystemLogic::SystemLogic(){
    Category C_plus_plus;
    C_plus_plus.name = "C++";
    Test C_plus_plus_test;
    C_plus_plus_test.id = 1;
    C_plus_plus_test.name = "Основы C++";
    Question C_plus_plus_q1;
    C_plus_plus_q1.text = "Какой оператор используется для вывода данных в C++?";
    C_plus_plus_q1.answers = {
        {"std::cin", false},
        {"std::cout", true},
        {"std::input", false},
        {"std::print", false}
    };
    Question C_plus_plus_q2;
    C_plus_plus_q2.text = "Какой тип данных используется для хранения целых чисел?";
    C_plus_plus_q2.answers = {
        {"double", false},
        {"char", false},
        {"int", true},
        {"bool", false}
    };
    C_plus_plus_test.questions.push_back(C_plus_plus_q1);
    C_plus_plus_test.questions.push_back(C_plus_plus_q2);
    C_plus_plus.tests.push_back(C_plus_plus_test);


    Category General_knowledges;
    General_knowledges.name = "Общие знания";
    Test General_knowledges_test;
    General_knowledges_test.id = 2;
    General_knowledges_test.name = "Простые вопросы";
    Question General_knowledges_q1;
    General_knowledges_q1.text = "Сколько планет в Солнечной системе?";
    General_knowledges_q1.answers = {
        {"7", false},
        {"8", true},
        {"9", false},
        {"10", false}
    };
    Question General_knowledges_q2;
    General_knowledges_q2.text = "Какой океан является самым большим?";
    General_knowledges_q2.answers = {
        {"Атлантический", false},
        {"Индийский", false},
        {"Тихий", true},
        {"Северный Ледовитый", false}
    };
    General_knowledges_test.questions.push_back(General_knowledges_q1);
    General_knowledges_test.questions.push_back(General_knowledges_q2);
    General_knowledges.tests.push_back(General_knowledges_test);
    tests.AddCategory(C_plus_plus);
    tests.AddCategory(General_knowledges);
}


void SystemLogic::Run()
{
    int choice = 0;
    do {
        std::cout << "\n========== Система тестирования ==========\n";
        std::cout << "1. Регистрация гостя\n";
        std::cout << "2. Вход гостя\n";
        std::cout << "3. Вход администратора\n";
        std::cout << "4. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:{
            GuestsRegistration();
            break;
        }
        case 2:{
            Entering_the_system_guests();
            break;
        }
        case 3:{
            Entering_the_system_admin();
            break;
        }
        case 4: {
            std::cout << "Завершение программы...\n";
            break;
        }
        default:
            std::cout << "Неверный выбор!\n";
            break;
        }
    } while (choice != 4);
}

void SystemLogic::GuestsRegistration()
{
    PIB personal_data;
    std::string personal_address;
    std::string phone_number;
    std::string login;
    std::string password;
    std::cout << "\n===== РЕГИСТРАЦИЯ ГОСТЯ =====\n";
    std::cout << "Введите имя: ";
    std::cin >> personal_data.name;
    std::cout << "Введите фамилию: ";
    std::cin >> personal_data.surname;
    std::cout << "Введите отчество: ";
    std::cin >> personal_data.fathers_name;
    std::cin.ignore();
    std::cout << "Введите адрес: ";
    std::getline(std::cin, personal_address);
    std::cout << "Введите номер телефона: ";
    std::getline(std::cin, phone_number);
    std::cout << "Придумайте логин: ";
    std::getline(std::cin, login);
    if (IsLoginTaken(login)) {
        std::cout << "Такой логин уже существует!\n";
        return;
    }
    std::cout << "Придумайте пароль: ";
    std::getline(std::cin, password);
    Guest new_guest(personal_data, personal_address, phone_number, login, password);
    if (new_guest.CheckGuestData() != true) {
        std::cout << "Ошибка! Заполните все обязательные данные.\n";
        return;
    }
    All_Guests.push_back(new_guest);
    std::cout << "\nРегистрация успешно завершена!\n";
}


void SystemLogic::Entering_the_system_guests() {
    std::string login_entered;
    std::string password_entered;
    std::cout << "Введите логин для входа в систему: ";
    std::getline(std::cin, login_entered);
    bool founded = false;
    int guest_index = 0;
    for (const Guest& guest : All_Guests) {
        if (guest.GetLogin() == login_entered) {
            founded = true;
            break;
        }
        guest_index++;
    }
    if (founded == true) {
        std::cout << "Введите пароль для входа в систему: ";
        std::getline(std::cin, password_entered);
        if (All_Guests[guest_index].CheckPassword(password_entered)) {
            std::cout << "Авторизация произошла успешно\n";
            GuestMenu(All_Guests[guest_index]);
        }
        else {
            std::cout << "Пароль неверный, повторите попытку авторизации\n";
            return;
        }
    }
    else {
        std::cout << "К сожалению такого логина нет в нашей базе данных, повторите попытку или же зарегистрируйтесь\n";
        return;
    }
}


void SystemLogic::GuestMenu(Guest& guest)
{
    int choice = 0;
    do
    {
        std::cout << "\n===== ГОСТЕВОЕ МЕНЮ =====\n";
        std::cout << "1. Начать тест\n";
        std::cout << "2. Предыдущие результаты\n";
        std::cout << "3. Вернуться в главное меню\n";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            StartGuestTesting(guest);
            break;

        case 2:
            guest.ShowResults();
            break;

        case 3:
            break;

        default:
            std::cout << "Повторите выбор\n";
        }

    } while (choice != 3);
}

bool SystemLogic::IsLoginTaken(const std::string& login) const {
    for (const Guest& guest : All_Guests){
        if (guest.GetLogin() == login) {
            return true;
        }
    }
    return false;
}

void SystemLogic::StartGuestTesting(Guest& guest)
{
    const Category* category = tests.ChooseCategory();
    if (category == nullptr) {
        return;
    }
    const Test* selected_test = tests.ChooseTest(*category);
    if (selected_test == nullptr) {
        return;
    }
    TestAttempt attempt;
    attempt.StartTest(*selected_test);

    if (attempt.IsFinished()) {
        TestResult result{
            selected_test->id,
            selected_test->name,
            attempt.GetCorrectAnswers(),
            attempt.GetRightPercentage(),
            attempt.GetResultGrade() };
    guest.AddResult(result);
    std::cout << "\nРезультат успешно добавлен в вашу историю!\n";
    }
    else {
        std::cout << "\nРезультат не сохранён, поскольку тест не был завершён.\n";
    }

    // Позже здесь сохраним результат гостя
}